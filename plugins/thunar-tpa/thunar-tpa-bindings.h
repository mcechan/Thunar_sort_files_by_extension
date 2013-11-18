/* Generated by dbus-binding-tool; do not edit! */

#include <glib.h>
#include <dbus/dbus-glib.h>

G_BEGIN_DECLS

#ifndef DBUS_GLIB_CLIENT_WRAPPERS_org_xfce_Trash
#define DBUS_GLIB_CLIENT_WRAPPERS_org_xfce_Trash

static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_xfce_Trash_display_trash (DBusGProxy *proxy, const char * IN_display, GError **error)

{
  return dbus_g_proxy_call (proxy, "DisplayTrash", error, G_TYPE_STRING, IN_display, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_xfce_Trash_display_trash_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_xfce_Trash_display_trash_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_xfce_Trash_display_trash_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_xfce_Trash_display_trash_async (DBusGProxy *proxy, const char * IN_display, org_xfce_Trash_display_trash_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "DisplayTrash", org_xfce_Trash_display_trash_async_callback, stuff, g_free, G_TYPE_STRING, IN_display, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_xfce_Trash_empty_trash (DBusGProxy *proxy, const char * IN_display, GError **error)

{
  return dbus_g_proxy_call (proxy, "EmptyTrash", error, G_TYPE_STRING, IN_display, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_xfce_Trash_empty_trash_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_xfce_Trash_empty_trash_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_xfce_Trash_empty_trash_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_xfce_Trash_empty_trash_async (DBusGProxy *proxy, const char * IN_display, org_xfce_Trash_empty_trash_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "EmptyTrash", org_xfce_Trash_empty_trash_async_callback, stuff, g_free, G_TYPE_STRING, IN_display, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_xfce_Trash_move_to_trash (DBusGProxy *proxy, const char ** IN_filenames, const char * IN_display, GError **error)

{
  return dbus_g_proxy_call (proxy, "MoveToTrash", error, G_TYPE_STRV, IN_filenames, G_TYPE_STRING, IN_display, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_xfce_Trash_move_to_trash_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_xfce_Trash_move_to_trash_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_xfce_Trash_move_to_trash_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_xfce_Trash_move_to_trash_async (DBusGProxy *proxy, const char ** IN_filenames, const char * IN_display, org_xfce_Trash_move_to_trash_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "MoveToTrash", org_xfce_Trash_move_to_trash_async_callback, stuff, g_free, G_TYPE_STRV, IN_filenames, G_TYPE_STRING, IN_display, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_xfce_Trash_query_trash (DBusGProxy *proxy, gboolean* OUT_full, GError **error)

{
  return dbus_g_proxy_call (proxy, "QueryTrash", error, G_TYPE_INVALID, G_TYPE_BOOLEAN, OUT_full, G_TYPE_INVALID);
}

typedef void (*org_xfce_Trash_query_trash_reply) (DBusGProxy *proxy, gboolean OUT_full, GError *error, gpointer userdata);

static void
org_xfce_Trash_query_trash_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  gboolean OUT_full;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_BOOLEAN, &OUT_full, G_TYPE_INVALID);
  (*(org_xfce_Trash_query_trash_reply)data->cb) (proxy, OUT_full, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_xfce_Trash_query_trash_async (DBusGProxy *proxy, org_xfce_Trash_query_trash_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "QueryTrash", org_xfce_Trash_query_trash_async_callback, stuff, g_free, G_TYPE_INVALID);
}
#endif /* defined DBUS_GLIB_CLIENT_WRAPPERS_org_xfce_Trash */

G_END_DECLS
