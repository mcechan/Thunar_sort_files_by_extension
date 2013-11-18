/* $Id: thunar-gtk-extensions.c 22937 2006-08-29 17:13:38Z benny $ */
/*-
 * Copyright (c) 2005-2006 Benedikt Meurer <benny@xfce.org>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef HAVE_STDARG_H
#include <stdarg.h>
#endif

#include <exo/exo.h>

#include <thunar/thunar-gtk-extensions.h>
#include <thunar/thunar-private.h>



/**
 * thunar_gtk_action_set_tooltip:
 * @action : a #GtkAction.
 * @format : the format string for the tooltip.
 * @...    : the parameters for @format.
 *
 * Convenience function to set a tooltip for a #GtkAction.
 **/
void
thunar_gtk_action_set_tooltip (GtkAction   *action,
                               const gchar *format,
                               ...)
{
  va_list var_args;
  gchar  *tooltip;

  _thunar_return_if_fail (g_utf8_validate (format, -1, NULL));
  _thunar_return_if_fail (GTK_IS_ACTION (action));

  /* determine the tooltip */
  va_start (var_args, format);
  tooltip = g_strdup_vprintf (format, var_args);
  va_end (var_args);

  /* setup the tooltip for the action */
  g_object_set (G_OBJECT (action), "tooltip", tooltip, NULL);

  /* release the tooltip */
  g_free (tooltip);
}



/**
 * thunar_gtk_action_group_set_action_sensitive:
 * @action_group : a #GtkActionGroup.
 * @action_name  : the name of a #GtkAction in @action_group.
 * @sensitive    : the new sensitivity.
 *
 * Convenience function to change the sensitivity of an action
 * in @action_group (whose name is @action_name) to @sensitive.
 **/
void
thunar_gtk_action_group_set_action_sensitive (GtkActionGroup *action_group,
                                              const gchar    *action_name,
                                              gboolean        sensitive)
{
  GtkAction *action;

  _thunar_return_if_fail (GTK_IS_ACTION_GROUP (action_group));
  _thunar_return_if_fail (action_name != NULL && *action_name != '\0');

  /* query the action from the group */
  action = gtk_action_group_get_action (action_group, action_name);

  /* apply the sensitivity to the action */
#if GTK_CHECK_VERSION(2,6,0)
  gtk_action_set_sensitive (action, sensitive);
#else
  g_object_set (G_OBJECT (action), "sensitive", sensitive, NULL);
#endif
}



/**
 * thunar_gtk_icon_factory_insert_icon:
 * @icon_factory : a #GtkIconFactory.
 * @stock_id     : the stock id of the icon to be inserted.
 * @icon_name    : the name of the themed icon or an absolute
 *                 path to an icon file.
 *
 * Inserts an entry into the @icon_factory, with the specified
 * @stock_id, for the given @icon_name, which can be either an
 * icon name (of a themed icon) or an absolute path to an icon
 * file.
 **/
void
thunar_gtk_icon_factory_insert_icon (GtkIconFactory *icon_factory,
                                     const gchar    *stock_id,
                                     const gchar    *icon_name)
{
  GtkIconSource *icon_source;
  GtkIconSet    *icon_set;

  _thunar_return_if_fail (GTK_IS_ICON_FACTORY (icon_factory));
  _thunar_return_if_fail (icon_name != NULL);
  _thunar_return_if_fail (stock_id != NULL);

  icon_set = gtk_icon_set_new ();
  icon_source = gtk_icon_source_new ();
  if (G_UNLIKELY (g_path_is_absolute (icon_name)))
    gtk_icon_source_set_filename (icon_source, icon_name);
  else
    gtk_icon_source_set_icon_name (icon_source, icon_name);
  gtk_icon_set_add_source (icon_set, icon_source);
  gtk_icon_factory_add (icon_factory, stock_id, icon_set);
  gtk_icon_source_free (icon_source);
  gtk_icon_set_unref (icon_set);
}



/**
 * thunar_gtk_label_set_a11y_relation:
 * @label  : a #GtkLabel.
 * @widget : a #GtkWidget.
 *
 * Sets the %ATK_RELATION_LABEL_FOR relation on @label for @widget, which means
 * accessiblity tools will identify @label as descriptive item for the specified
 * @widget.
 **/
void
thunar_gtk_label_set_a11y_relation (GtkLabel  *label,
                                    GtkWidget *widget)
{
  AtkRelationSet *relations;
  AtkRelation    *relation;
  AtkObject      *object;

  _thunar_return_if_fail (GTK_IS_WIDGET (widget));
  _thunar_return_if_fail (GTK_IS_LABEL (label));

  object = gtk_widget_get_accessible (widget);
  relations = atk_object_ref_relation_set (gtk_widget_get_accessible (GTK_WIDGET (label)));
  relation = atk_relation_new (&object, 1, ATK_RELATION_LABEL_FOR);
  atk_relation_set_add (relations, relation);
  g_object_unref (G_OBJECT (relation));
}



/**
 * thunar_gtk_menu_run:
 * @menu          : a #GtkMenu.
 * @parent        : either a #GtkWidget or a #GdkScreen which determines the screen
 *                  on which to run the @menu. May also be %NULL, which means that
 *                  the screen of @menu will not be altered.
 * @func          : a user supplied function used to position the menu, or %NULL.
 * @data          : user supplied data to be passed to @func.
 * @button        : the mouse button which was pressed to initiate the event.
 * @activate_time : the time at which the activation event occurred.
 *
 * A simple wrapper around gtk_menu_popup(), which runs the @menu in a separate
 * main loop and returns only after the @menu was deactivated.
 *
 * This method automatically takes over the floating reference of @menu if any and
 * releases it on return. That means if you created the menu via gtk_menu_new() you'll
 * not need to take care of destroying the menu later.
 **/
void
thunar_gtk_menu_run (GtkMenu            *menu,
                     gpointer            parent,
                     GtkMenuPositionFunc func,
                     gpointer            data,
                     guint               button,
                     guint32             activate_time)
{
  GMainLoop *loop;
  guint      signal_id;

  _thunar_return_if_fail (parent == NULL || GDK_IS_SCREEN (parent) || GTK_IS_WIDGET (parent));
  _thunar_return_if_fail (GTK_IS_MENU (menu));

  /* take over the floating reference on the menu */
  exo_gtk_object_ref_sink (GTK_OBJECT (menu));

  /* place the menu on the same screen as the parent */
  if (G_UNLIKELY (parent != NULL && GDK_IS_SCREEN (parent)))
    gtk_menu_set_screen (menu, GDK_SCREEN (parent));
  else if (G_LIKELY (parent != NULL && GTK_IS_WIDGET (parent)))
    gtk_menu_set_screen (menu, gtk_widget_get_screen (GTK_WIDGET (parent)));

  /* run an internal main loop */
  gtk_grab_add (GTK_WIDGET (menu));
  loop = g_main_loop_new (NULL, FALSE);
  signal_id = g_signal_connect_swapped (G_OBJECT (menu), "deactivate", G_CALLBACK (g_main_loop_quit), loop);
  gtk_menu_popup (menu, NULL, NULL, func, data, button, activate_time);
  g_main_loop_run (loop);
  g_signal_handler_disconnect (G_OBJECT (menu), signal_id);
  g_main_loop_unref (loop);
  gtk_grab_remove (GTK_WIDGET (menu));

  /* release the menu reference */
  g_object_unref (G_OBJECT (menu));
}



/**
 * thunar_gtk_ui_manager_get_action_by_name:
 * @ui_manager  : a #GtkUIManager.
 * @action_name : the name of a #GtkAction in @ui_manager.
 *
 * Looks up the #GtkAction with the given @action_name in all
 * #GtkActionGroup<!---->s associated with @ui_manager. Returns
 * %NULL if no such #GtkAction exists in @ui_manager.
 *
 * Return value: the #GtkAction of the given @action_name in
 *               @ui_manager or %NULL.
 **/
GtkAction*
thunar_gtk_ui_manager_get_action_by_name (GtkUIManager *ui_manager,
                                          const gchar  *action_name)
{
  GtkAction *action;
  GList     *lp;

  _thunar_return_val_if_fail (GTK_IS_UI_MANAGER (ui_manager), NULL);
  _thunar_return_val_if_fail (action_name != NULL, NULL);

  /* check all action groups associated with the ui manager */
  for (lp = gtk_ui_manager_get_action_groups (ui_manager); lp != NULL; lp = lp->next)
    {
      action = gtk_action_group_get_action (lp->data, action_name);
      if (G_LIKELY (action != NULL))
        return action;
    }

  return NULL;
}



/**
 * thunar_gtk_widget_set_tooltip:
 * @widget : a #GtkWidget for which to set the tooltip.
 * @format : a printf(3)-style format string.
 * @...    : additional arguments for @format.
 *
 * Sets the tooltip for the @widget to a string generated
 * from the @format and the additional arguments in @...<!--->,
 * utilizing the shared #GtkTooltips instance.
 **/
void
thunar_gtk_widget_set_tooltip (GtkWidget   *widget,
                               const gchar *format,
                               ...)
{
  static GtkTooltips *tooltips = NULL;
  va_list             var_args;
  gchar              *tooltip;

  _thunar_return_if_fail (GTK_IS_WIDGET (widget));
  _thunar_return_if_fail (g_utf8_validate (format, -1, NULL));

  /* allocate the shared tooltips on-demand */
  if (G_UNLIKELY (tooltips == NULL))
    tooltips = gtk_tooltips_new ();

  /* determine the tooltip */
  va_start (var_args, format);
  tooltip = g_strdup_vprintf (format, var_args);
  va_end (var_args);

  /* setup the tooltip for the widget */
  gtk_tooltips_set_tip (tooltips, widget, tooltip, NULL);

  /* release the tooltip */
  g_free (tooltip);
}



