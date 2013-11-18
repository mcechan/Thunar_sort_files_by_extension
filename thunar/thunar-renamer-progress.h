/* $Id: thunar-renamer-progress.h 20528 2006-03-24 13:10:04Z benny $ */
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

#ifndef __THUNAR_RENAMER_PROGRESS_H__
#define __THUNAR_RENAMER_PROGRESS_H__

#include <thunar/thunar-renamer-pair.h>

G_BEGIN_DECLS;

typedef struct _ThunarRenamerProgressClass ThunarRenamerProgressClass;
typedef struct _ThunarRenamerProgress      ThunarRenamerProgress;

#define THUNAR_TYPE_RENAMER_PROGRESS            (thunar_renamer_progress_get_type ())
#define THUNAR_RENAMER_PROGRESS(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), THUNAR_TYPE_RENAMER_PROGRESS, ThunarRenamerProgress))
#define THUNAR_RENAMER_PROGRESS_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), THUNAR_TYPE_RENAMER_PROGRESS, ThunarRenamerProgressClass))
#define THUNAR_IS_RENAMER_PROGRESS(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THUNAR_TYPE_RENAMER_PROGRESS))
#define THUNAR_IS_RENAMER_PROGRESS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), THUNAR_TYPE_RENAMER_PROGRESS))
#define THUNAR_RENAMER_PROGRESS_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), THUNAR_TYPE_RENAMER_PROGRESS, ThunarRenamerProgressClass))

GType      thunar_renamer_progress_get_type (void) G_GNUC_CONST;

GtkWidget *thunar_renamer_progress_new      (void) G_GNUC_MALLOC;

void       thunar_renamer_progress_cancel   (ThunarRenamerProgress *renamer_progress);

gboolean   thunar_renamer_progress_running  (ThunarRenamerProgress *renamer_progress);

void       thunar_renamer_progress_run      (ThunarRenamerProgress *renamer_progress,
                                             GList                 *pair_list);

G_END_DECLS;

#endif /* !__THUNAR_RENAMER_PROGRESS_H__ */
