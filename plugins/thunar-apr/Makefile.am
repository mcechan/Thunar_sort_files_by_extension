# $Id: Makefile.am 24675 2007-01-20 20:37:43Z benny $

INCLUDES =								\
	-I$(top_builddir)						\
	-I$(top_builddir)/plugins					\
	-I$(top_srcdir)							\
	-I$(top_srcdir)/plugins						\
	-DG_LOG_DOMAIN=\"thunar-apr\"					\
	-DPACKAGE_LOCALE_DIR=\"$(localedir)\"				\
	$(PLATFORM_CPPFLAGS)

extensionsdir = $(libdir)/thunarx-$(THUNAR_VERSION_API)
extensions_LTLIBRARIES =						\
	thunar-apr.la

thunar_apr_la_SOURCES =							\
	thunar-apr-abstract-page.c					\
	thunar-apr-abstract-page.h					\
	thunar-apr-desktop-page.c					\
	thunar-apr-desktop-page.h					\
	thunar-apr-image-page.c						\
	thunar-apr-image-page.h						\
	thunar-apr-plugin.c						\
	thunar-apr-private.c						\
	thunar-apr-private.h						\
	thunar-apr-provider.c						\
	thunar-apr-provider.h

thunar_apr_la_CFLAGS =							\
	$(EXIF_CFLAGS)							\
	$(EXO_CFLAGS)							\
	$(PLATFORM_CFLAGS)

thunar_apr_la_LDFLAGS =							\
	-avoid-version							\
	-export-dynamic							\
	-module								\
	$(PLATFORM_LDFLAGS)

thunar_apr_la_LIBADD =							\
	$(EXIF_LIBS)

EXTRA_DIST =								\
	README

# vi:set ts=8 sw=8 noet ai nocindent syntax=automake:
