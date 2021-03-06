/* $Id: thunar-create-dialog.h 19639 2006-01-28 23:04:50Z benny $ */
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

#ifndef __THUNAR_CREATE_DIALOG_H__
#define __THUNAR_CREATE_DIALOG_H__

#include <thunar-vfs/thunar-vfs.h>

G_BEGIN_DECLS;

typedef struct _ThunarCreateDialogClass ThunarCreateDialogClass;
typedef struct _ThunarCreateDialog      ThunarCreateDialog;

#define THUNAR_TYPE_CREATE_DIALOG             (thunar_create_dialog_get_type ())
#define THUNAR_CREATE_DIALOG(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), THUNAR_TYPE_CREATE_DIALOG, ThunarCreateDialog))
#define THUNAR_CREATE_DIALOG_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), THUNAR_TYPE_CREATE_DIALOG, ThunarCreateDialogClass))
#define THUNAR_IS_CREATE_DIALOG(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THUNAR_TYPE_CREATE_DIALOG))
#define THUNAR_IS_CREATE_DIALOG_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), THUNAR_TYPE_CREATE_DIALOG))
#define THUNAR_CREATE_DIALOG_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), THUNAR_TYPE_CREATE_DIALOG, ThunarCreateDialogClass))

GType              thunar_create_dialog_get_type      (void) G_GNUC_CONST;

GtkWidget         *thunar_create_dialog_new           (void) G_GNUC_MALLOC;

const gchar       *thunar_create_dialog_get_filename  (const ThunarCreateDialog *dialog);
void               thunar_create_dialog_set_filename  (ThunarCreateDialog       *dialog,
                                                       const gchar              *filename);

ThunarVfsMimeInfo *thunar_create_dialog_get_mime_info (const ThunarCreateDialog *dialog);
void               thunar_create_dialog_set_mime_info (ThunarCreateDialog       *dialog,
                                                       ThunarVfsMimeInfo        *mime_info);

gchar             *thunar_show_create_dialog          (GtkWidget                *parent,
                                                       ThunarVfsMimeInfo        *mime_info,
                                                       const gchar              *filename,
                                                       const gchar              *title) G_GNUC_MALLOC;

G_END_DECLS;

#endif /* !__THUNAR_CREATE_DIALOG_H__ */
