/* main.c generated by valac 0.34.0.3-63fa6, the Vala compiler
 * generated from main.vala, do not modify */

/* -*- Mode: vala; indent-tabs-mode: t; c-basic-offset: 2; tab-width: 8 -*- */
/*
 * Copyright (C) 2011 Alexander Larsson <alexl@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gi18n-lib.h>
#include <config.h>
#include <clutter-gtk/clutter-gtk.h>
#include <gtk/gtk.h>
#include <gio/gio.h>


#define CONTACTS_TYPE_APP (contacts_app_get_type ())
#define CONTACTS_APP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONTACTS_TYPE_APP, ContactsApp))
#define CONTACTS_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONTACTS_TYPE_APP, ContactsAppClass))
#define CONTACTS_IS_APP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONTACTS_TYPE_APP))
#define CONTACTS_IS_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONTACTS_TYPE_APP))
#define CONTACTS_APP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONTACTS_TYPE_APP, ContactsAppClass))

typedef struct _ContactsApp ContactsApp;
typedef struct _ContactsAppClass ContactsAppClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))



gint _vala_main (gchar** args, int args_length1);
GType contacts_app_get_type (void) G_GNUC_CONST;
ContactsApp* contacts_app_new (void);
ContactsApp* contacts_app_construct (GType object_type);


gint _vala_main (gchar** args, int args_length1) {
	gint result = 0;
	ContactsApp* app = NULL;
	ContactsApp* _tmp0_ = NULL;
	ContactsApp* _tmp1_ = NULL;
	gchar** _tmp2_ = NULL;
	gint _tmp2__length1 = 0;
	bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);
	gtk_clutter_init (&args_length1, &args);
	_tmp0_ = contacts_app_new ();
	app = _tmp0_;
	_tmp1_ = app;
	_tmp2_ = args;
	_tmp2__length1 = args_length1;
	g_application_run ((GApplication*) _tmp1_, _tmp2__length1, _tmp2_);
	_g_object_unref0 (app);
	app = NULL;
	result = 0;
	_g_object_unref0 (app);
	return result;
}


int main (int argc, char ** argv) {
#if !GLIB_CHECK_VERSION (2,35,0)
	g_type_init ();
#endif
	return _vala_main (argv, argc);
}



