/* main.c generated by valac 0.20.0.5-3c0efc, the Vala compiler
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
#include <libnotify/notify.h>
#include <cheese/cheese-gtk.h>
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
ContactsApp* contacts_app_new (void);
ContactsApp* contacts_app_construct (GType object_type);
GType contacts_app_get_type (void) G_GNUC_CONST;


gint _vala_main (gchar** args, int args_length1) {
	gint result = 0;
	const gchar* _tmp0_ = NULL;
	ContactsApp* _tmp1_;
	ContactsApp* app;
	ContactsApp* _tmp2_;
	gchar** _tmp3_;
	gint _tmp3__length1;
	bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);
	_tmp0_ = _ ("Contacts");
	notify_init (_tmp0_);
	cheese_gtk_init (&args_length1, &args);
	_tmp1_ = contacts_app_new ();
	app = _tmp1_;
	_tmp2_ = app;
	_tmp3_ = args;
	_tmp3__length1 = args_length1;
	g_application_run ((GApplication*) _tmp2_, _tmp3__length1, _tmp3_);
	_g_object_unref0 (app);
	app = NULL;
	result = 0;
	_g_object_unref0 (app);
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return _vala_main (argv, argc);
}



