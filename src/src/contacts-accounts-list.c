/* contacts-accounts-list.c generated by valac 0.26.0.27-f1f8, the Vala compiler
 * generated from contacts-accounts-list.vala, do not modify */

/* -*- Mode: vala; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 8 -*- */
/*
 * Copyright (C) 2011 Erick Pérez Castellanos <erick.red@gmail.com>
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
#include <gtk/gtk.h>
#include <folks/folks.h>
#include <libedataserver/libedataserver.h>
#include <folks/folks-eds.h>
#include <contacts-esd-setup.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <glib/gi18n-lib.h>


#define CONTACTS_TYPE_ACCOUNTS_LIST (contacts_accounts_list_get_type ())
#define CONTACTS_ACCOUNTS_LIST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONTACTS_TYPE_ACCOUNTS_LIST, ContactsAccountsList))
#define CONTACTS_ACCOUNTS_LIST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONTACTS_TYPE_ACCOUNTS_LIST, ContactsAccountsListClass))
#define CONTACTS_IS_ACCOUNTS_LIST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONTACTS_TYPE_ACCOUNTS_LIST))
#define CONTACTS_IS_ACCOUNTS_LIST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONTACTS_TYPE_ACCOUNTS_LIST))
#define CONTACTS_ACCOUNTS_LIST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONTACTS_TYPE_ACCOUNTS_LIST, ContactsAccountsListClass))

typedef struct _ContactsAccountsList ContactsAccountsList;
typedef struct _ContactsAccountsListClass ContactsAccountsListClass;
typedef struct _ContactsAccountsListPrivate ContactsAccountsListPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_list_free0(var) ((var == NULL) ? NULL : (var = (g_list_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define CONTACTS_TYPE_APP (contacts_app_get_type ())
#define CONTACTS_APP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONTACTS_TYPE_APP, ContactsApp))
#define CONTACTS_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONTACTS_TYPE_APP, ContactsAppClass))
#define CONTACTS_IS_APP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONTACTS_TYPE_APP))
#define CONTACTS_IS_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONTACTS_TYPE_APP))
#define CONTACTS_APP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONTACTS_TYPE_APP, ContactsAppClass))

typedef struct _ContactsApp ContactsApp;
typedef struct _ContactsAppClass ContactsAppClass;
typedef struct _ContactsAppPrivate ContactsAppPrivate;

#define CONTACTS_TYPE_STORE (contacts_store_get_type ())
#define CONTACTS_STORE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONTACTS_TYPE_STORE, ContactsStore))
#define CONTACTS_STORE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONTACTS_TYPE_STORE, ContactsStoreClass))
#define CONTACTS_IS_STORE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONTACTS_TYPE_STORE))
#define CONTACTS_IS_STORE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONTACTS_TYPE_STORE))
#define CONTACTS_STORE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONTACTS_TYPE_STORE, ContactsStoreClass))

typedef struct _ContactsStore ContactsStore;
typedef struct _ContactsStoreClass ContactsStoreClass;

#define CONTACTS_TYPE_WINDOW (contacts_window_get_type ())
#define CONTACTS_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONTACTS_TYPE_WINDOW, ContactsWindow))
#define CONTACTS_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONTACTS_TYPE_WINDOW, ContactsWindowClass))
#define CONTACTS_IS_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONTACTS_TYPE_WINDOW))
#define CONTACTS_IS_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONTACTS_TYPE_WINDOW))
#define CONTACTS_WINDOW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONTACTS_TYPE_WINDOW, ContactsWindowClass))

typedef struct _ContactsWindow ContactsWindow;
typedef struct _ContactsWindowClass ContactsWindowClass;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _ContactsAccountsList {
	GtkGrid parent_instance;
	ContactsAccountsListPrivate * priv;
	FolksPersonaStore* selected_store;
};

struct _ContactsAccountsListClass {
	GtkGridClass parent_class;
};

struct _ContactsAccountsListPrivate {
	GtkListBox* accounts_view;
	GtkListBoxRow* last_selected_row;
	GtkButton* add_account_button;
};

struct _ContactsApp {
	GtkApplication parent_instance;
	ContactsAppPrivate * priv;
	GSettings* settings;
	ContactsStore* contacts_store;
	ContactsWindow* window;
};

struct _ContactsAppClass {
	GtkApplicationClass parent_class;
};


static gpointer contacts_accounts_list_parent_class = NULL;
extern ContactsApp* contacts_app_app;

GType contacts_accounts_list_get_type (void) G_GNUC_CONST;
#define CONTACTS_ACCOUNTS_LIST_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), CONTACTS_TYPE_ACCOUNTS_LIST, ContactsAccountsListPrivate))
enum  {
	CONTACTS_ACCOUNTS_LIST_DUMMY_PROPERTY
};
static void contacts_accounts_list_row_activated (ContactsAccountsList* self, GtkListBoxRow* row);
void contacts_accounts_list_update_contents (ContactsAccountsList* self, gboolean select_active);
FolksPersonaStore** contacts_app_get_eds_address_books (int* result_length1);
gchar* contacts_contact_format_persona_store_name (FolksPersonaStore* store);
GType contacts_app_get_type (void) G_GNUC_CONST;
GType contacts_store_get_type (void) G_GNUC_CONST;
GType contacts_window_get_type (void) G_GNUC_CONST;
FolksIndividualAggregator* contacts_store_get_aggregator (ContactsStore* self);
ContactsAccountsList* contacts_accounts_list_new (void);
ContactsAccountsList* contacts_accounts_list_construct (GType object_type);
static GObject * contacts_accounts_list_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
void contacts_add_separator (GtkListBoxRow* row, GtkListBoxRow* before_row);
static void _contacts_add_separator_gtk_list_box_update_header_func (GtkListBoxRow* row, GtkListBoxRow* before, gpointer self);
static void _contacts_accounts_list___lambda91_ (ContactsAccountsList* self);
static void __contacts_accounts_list___lambda91__gtk_button_clicked (GtkButton* _sender, gpointer self);
static void _contacts_accounts_list_row_activated_gtk_list_box_row_activated (GtkListBox* _sender, GtkListBoxRow* row, gpointer self);
static void contacts_accounts_list_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void contacts_accounts_list_row_activated (ContactsAccountsList* self, GtkListBoxRow* row) {
	GtkListBoxRow* _tmp0_ = NULL;
	gboolean _tmp1_ = FALSE;
	GtkListBoxRow* _tmp2_ = NULL;
	GtkGrid* row_data = NULL;
	GtkListBoxRow* _tmp5_ = NULL;
	GtkWidget* _tmp6_ = NULL;
	GtkGrid* _tmp7_ = NULL;
	GtkImage* checkmark = NULL;
	GtkImage* _tmp8_ = NULL;
	GtkImage* _tmp9_ = NULL;
	GtkImage* _tmp10_ = NULL;
	GtkGrid* _tmp11_ = NULL;
	GtkImage* _tmp12_ = NULL;
	GtkListBoxRow* _tmp13_ = NULL;
	GtkListBoxRow* _tmp20_ = NULL;
	GtkListBoxRow* _tmp21_ = NULL;
	GtkGrid* _tmp22_ = NULL;
	gconstpointer _tmp23_ = NULL;
	FolksPersonaStore* _tmp24_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = row;
	if (_tmp0_ == NULL) {
		return;
	}
	_tmp2_ = self->priv->last_selected_row;
	if (_tmp2_ != NULL) {
		GtkListBoxRow* _tmp3_ = NULL;
		GtkListBoxRow* _tmp4_ = NULL;
		_tmp3_ = self->priv->last_selected_row;
		_tmp4_ = row;
		_tmp1_ = _tmp3_ == _tmp4_;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		return;
	}
	_tmp5_ = row;
	_tmp6_ = gtk_bin_get_child (G_TYPE_CHECK_INSTANCE_TYPE (_tmp5_, gtk_bin_get_type ()) ? ((GtkBin*) _tmp5_) : NULL);
	_tmp7_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp6_, gtk_grid_get_type ()) ? ((GtkGrid*) _tmp6_) : NULL);
	row_data = _tmp7_;
	_tmp8_ = (GtkImage*) gtk_image_new_from_icon_name ("object-select-symbolic", GTK_ICON_SIZE_MENU);
	g_object_ref_sink (_tmp8_);
	checkmark = _tmp8_;
	_tmp9_ = checkmark;
	g_object_set ((GObject*) _tmp9_, "margin-end", 12, "valign", GTK_ALIGN_CENTER, "halign", GTK_ALIGN_END, "vexpand", TRUE, "hexpand", TRUE, NULL);
	_tmp10_ = checkmark;
	gtk_widget_show ((GtkWidget*) _tmp10_);
	_tmp11_ = row_data;
	_tmp12_ = checkmark;
	gtk_grid_attach (_tmp11_, (GtkWidget*) _tmp12_, 2, 0, 1, 2);
	_tmp13_ = self->priv->last_selected_row;
	if (_tmp13_ != NULL) {
		GtkGrid* last_row_data = NULL;
		GtkListBoxRow* _tmp14_ = NULL;
		GtkWidget* _tmp15_ = NULL;
		GtkGrid* _tmp16_ = NULL;
		GtkGrid* _tmp17_ = NULL;
		_tmp14_ = self->priv->last_selected_row;
		_tmp15_ = gtk_bin_get_child (G_TYPE_CHECK_INSTANCE_TYPE (_tmp14_, gtk_bin_get_type ()) ? ((GtkBin*) _tmp14_) : NULL);
		_tmp16_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp15_, gtk_grid_get_type ()) ? ((GtkGrid*) _tmp15_) : NULL);
		last_row_data = _tmp16_;
		_tmp17_ = last_row_data;
		if (_tmp17_ != NULL) {
			GtkGrid* _tmp18_ = NULL;
			GtkWidget* _tmp19_ = NULL;
			_tmp18_ = last_row_data;
			_tmp19_ = gtk_grid_get_child_at (_tmp18_, 2, 0);
			gtk_widget_destroy (_tmp19_);
		}
		_g_object_unref0 (last_row_data);
	}
	_tmp20_ = row;
	_tmp21_ = _g_object_ref0 (_tmp20_);
	_g_object_unref0 (self->priv->last_selected_row);
	self->priv->last_selected_row = _tmp21_;
	_tmp22_ = row_data;
	_tmp23_ = g_object_get_data ((GObject*) _tmp22_, "store");
	_tmp24_ = _g_object_ref0 ((FolksPersonaStore*) _tmp23_);
	_g_object_unref0 (self->selected_store);
	self->selected_store = _tmp24_;
	g_signal_emit_by_name (self, "account-selected");
	_g_object_unref0 (checkmark);
	_g_object_unref0 (row_data);
}


void contacts_accounts_list_update_contents (ContactsAccountsList* self, gboolean select_active) {
	GtkListBox* _tmp0_ = NULL;
	GList* _tmp1_ = NULL;
	FolksPersonaStore* local_store = NULL;
	gint _tmp3_ = 0;
	FolksPersonaStore** _tmp4_ = NULL;
	FolksPersonaStore* _tmp84_ = NULL;
	GtkListBox* _tmp114_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->accounts_view;
	_tmp1_ = gtk_container_get_children ((GtkContainer*) _tmp0_);
	{
		GList* child_collection = NULL;
		GList* child_it = NULL;
		child_collection = _tmp1_;
		for (child_it = child_collection; child_it != NULL; child_it = child_it->next) {
			GtkWidget* child = NULL;
			child = (GtkWidget*) child_it->data;
			{
				GtkWidget* _tmp2_ = NULL;
				_tmp2_ = child;
				gtk_widget_destroy (_tmp2_);
			}
		}
		_g_list_free0 (child_collection);
	}
	local_store = NULL;
	_tmp4_ = contacts_app_get_eds_address_books (&_tmp3_);
	{
		FolksPersonaStore** persona_store_collection = NULL;
		gint persona_store_collection_length1 = 0;
		gint _persona_store_collection_size_ = 0;
		gint persona_store_it = 0;
		persona_store_collection = _tmp4_;
		persona_store_collection_length1 = _tmp3_;
		for (persona_store_it = 0; persona_store_it < _tmp3_; persona_store_it = persona_store_it + 1) {
			FolksPersonaStore* _tmp5_ = NULL;
			FolksPersonaStore* persona_store = NULL;
			_tmp5_ = _g_object_ref0 (persona_store_collection[persona_store_it]);
			persona_store = _tmp5_;
			{
				FolksPersonaStore* _tmp6_ = NULL;
				const gchar* _tmp7_ = NULL;
				const gchar* _tmp8_ = NULL;
				ESource* source = NULL;
				FolksPersonaStore* _tmp11_ = NULL;
				ESource* _tmp12_ = NULL;
				ESource* _tmp13_ = NULL;
				ESource* _tmp14_ = NULL;
				ESource* parent_source = NULL;
				ESourceRegistry* _tmp15_ = NULL;
				ESource* _tmp16_ = NULL;
				const gchar* _tmp17_ = NULL;
				const gchar* _tmp18_ = NULL;
				ESource* _tmp19_ = NULL;
				gchar* provider_name = NULL;
				FolksPersonaStore* _tmp20_ = NULL;
				gchar* _tmp21_ = NULL;
				gchar* source_account_id = NULL;
				gchar* _tmp22_ = NULL;
				ESource* _tmp23_ = NULL;
				gboolean _tmp24_ = FALSE;
				GtkGrid* row_data = NULL;
				GtkGrid* _tmp32_ = NULL;
				GtkGrid* _tmp33_ = NULL;
				FolksPersonaStore* _tmp34_ = NULL;
				FolksPersonaStore* _tmp35_ = NULL;
				GtkGrid* _tmp36_ = NULL;
				GtkGrid* _tmp37_ = NULL;
				GtkGrid* _tmp38_ = NULL;
				GtkGrid* _tmp39_ = NULL;
				const gchar* _tmp40_ = NULL;
				GtkLabel* provider_label = NULL;
				const gchar* _tmp49_ = NULL;
				GtkLabel* _tmp50_ = NULL;
				GtkLabel* _tmp51_ = NULL;
				GtkLabel* _tmp52_ = NULL;
				GtkLabel* _tmp53_ = NULL;
				GtkGrid* _tmp54_ = NULL;
				GtkLabel* _tmp55_ = NULL;
				gchar* account_name = NULL;
				ESource* _tmp56_ = NULL;
				const gchar* _tmp57_ = NULL;
				const gchar* _tmp58_ = NULL;
				gchar* _tmp59_ = NULL;
				GtkLabel* account_label = NULL;
				const gchar* _tmp60_ = NULL;
				GtkLabel* _tmp61_ = NULL;
				GtkLabel* _tmp62_ = NULL;
				GtkLabel* _tmp63_ = NULL;
				GtkLabel* _tmp64_ = NULL;
				GtkLabel* _tmp65_ = NULL;
				GtkStyleContext* _tmp66_ = NULL;
				GtkGrid* _tmp67_ = NULL;
				GtkLabel* _tmp68_ = NULL;
				GtkListBox* _tmp69_ = NULL;
				GtkGrid* _tmp70_ = NULL;
				gboolean _tmp71_ = FALSE;
				gboolean _tmp72_ = FALSE;
				_tmp6_ = persona_store;
				_tmp7_ = folks_persona_store_get_id (_tmp6_);
				_tmp8_ = _tmp7_;
				if (g_strcmp0 (_tmp8_, "system-address-book") == 0) {
					FolksPersonaStore* _tmp9_ = NULL;
					FolksPersonaStore* _tmp10_ = NULL;
					_tmp9_ = persona_store;
					_tmp10_ = _g_object_ref0 (_tmp9_);
					_g_object_unref0 (local_store);
					local_store = _tmp10_;
					_g_object_unref0 (persona_store);
					continue;
				}
				_tmp11_ = persona_store;
				_tmp12_ = edsf_persona_store_get_source (G_TYPE_CHECK_INSTANCE_TYPE (_tmp11_, EDSF_TYPE_PERSONA_STORE) ? ((EdsfPersonaStore*) _tmp11_) : NULL);
				_tmp13_ = _tmp12_;
				_tmp14_ = _g_object_ref0 (_tmp13_);
				source = _tmp14_;
				_tmp15_ = eds_source_registry;
				_tmp16_ = source;
				_tmp17_ = e_source_get_parent (_tmp16_);
				_tmp18_ = _tmp17_;
				_tmp19_ = e_source_registry_ref_source (_tmp15_, _tmp18_);
				parent_source = _tmp19_;
				_tmp20_ = persona_store;
				_tmp21_ = contacts_contact_format_persona_store_name (_tmp20_);
				provider_name = _tmp21_;
				_tmp22_ = g_strdup ("");
				source_account_id = _tmp22_;
				_tmp23_ = parent_source;
				_tmp24_ = e_source_has_extension (_tmp23_, E_SOURCE_EXTENSION_GOA);
				if (_tmp24_) {
					ESourceGoa* goa_source_ext = NULL;
					ESource* _tmp25_ = NULL;
					ESourceExtension* _tmp26_ = NULL;
					ESourceGoa* _tmp27_ = NULL;
					ESourceGoa* _tmp28_ = NULL;
					const gchar* _tmp29_ = NULL;
					const gchar* _tmp30_ = NULL;
					gchar* _tmp31_ = NULL;
					_tmp25_ = parent_source;
					_tmp26_ = e_source_get_extension (_tmp25_, E_SOURCE_EXTENSION_GOA);
					_tmp27_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp26_, e_source_goa_get_type ()) ? ((ESourceGoa*) _tmp26_) : NULL);
					goa_source_ext = _tmp27_;
					_tmp28_ = goa_source_ext;
					_tmp29_ = e_source_goa_get_account_id (_tmp28_);
					_tmp30_ = _tmp29_;
					_tmp31_ = g_strdup (_tmp30_);
					_g_free0 (source_account_id);
					source_account_id = _tmp31_;
					_g_object_unref0 (goa_source_ext);
				}
				_tmp32_ = (GtkGrid*) gtk_grid_new ();
				g_object_ref_sink (_tmp32_);
				row_data = _tmp32_;
				_tmp33_ = row_data;
				_tmp34_ = persona_store;
				_tmp35_ = _g_object_ref0 (_tmp34_);
				g_object_set_data_full ((GObject*) _tmp33_, "store", _tmp35_, g_object_unref);
				_tmp36_ = row_data;
				g_object_set ((GtkWidget*) _tmp36_, "margin", 6, NULL);
				_tmp37_ = row_data;
				gtk_widget_set_margin_start ((GtkWidget*) _tmp37_, 5);
				_tmp38_ = row_data;
				gtk_grid_set_row_spacing (_tmp38_, (guint) 1);
				_tmp39_ = row_data;
				gtk_grid_set_column_spacing (_tmp39_, (guint) 10);
				_tmp40_ = source_account_id;
				if (g_strcmp0 (_tmp40_, "") != 0) {
					GtkWidget* provider_image = NULL;
					const gchar* _tmp41_ = NULL;
					GtkWidget* _tmp42_ = NULL;
					GtkWidget* _tmp43_ = NULL;
					GtkGrid* _tmp44_ = NULL;
					GtkWidget* _tmp45_ = NULL;
					_tmp41_ = source_account_id;
					_tmp42_ = contacts_get_icon_for_goa_account (_tmp41_);
					_tmp43_ = _g_object_ref0 (_tmp42_);
					provider_image = _tmp43_;
					_tmp44_ = row_data;
					_tmp45_ = provider_image;
					gtk_grid_attach (_tmp44_, _tmp45_, 0, 0, 1, 2);
					_g_object_unref0 (provider_image);
				} else {
					GtkImage* provider_image = NULL;
					GtkImage* _tmp46_ = NULL;
					GtkGrid* _tmp47_ = NULL;
					GtkImage* _tmp48_ = NULL;
					_tmp46_ = (GtkImage*) gtk_image_new_from_icon_name ("x-office-address-book", GTK_ICON_SIZE_DIALOG);
					g_object_ref_sink (_tmp46_);
					provider_image = _tmp46_;
					_tmp47_ = row_data;
					_tmp48_ = provider_image;
					gtk_grid_attach (_tmp47_, (GtkWidget*) _tmp48_, 0, 0, 1, 2);
					_g_object_unref0 (provider_image);
				}
				_tmp49_ = provider_name;
				_tmp50_ = (GtkLabel*) gtk_label_new (_tmp49_);
				g_object_ref_sink (_tmp50_);
				provider_label = _tmp50_;
				_tmp51_ = provider_label;
				gtk_widget_set_halign ((GtkWidget*) _tmp51_, GTK_ALIGN_START);
				_tmp52_ = provider_label;
				gtk_widget_set_hexpand ((GtkWidget*) _tmp52_, TRUE);
				_tmp53_ = provider_label;
				gtk_widget_set_valign ((GtkWidget*) _tmp53_, GTK_ALIGN_END);
				_tmp54_ = row_data;
				_tmp55_ = provider_label;
				gtk_grid_attach (_tmp54_, (GtkWidget*) _tmp55_, 1, 0, 1, 1);
				_tmp56_ = parent_source;
				_tmp57_ = e_source_get_display_name (_tmp56_);
				_tmp58_ = _tmp57_;
				_tmp59_ = g_strdup (_tmp58_);
				account_name = _tmp59_;
				_tmp60_ = account_name;
				_tmp61_ = (GtkLabel*) gtk_label_new (_tmp60_);
				g_object_ref_sink (_tmp61_);
				account_label = _tmp61_;
				_tmp62_ = account_label;
				gtk_widget_set_halign ((GtkWidget*) _tmp62_, GTK_ALIGN_START);
				_tmp63_ = account_label;
				gtk_widget_set_hexpand ((GtkWidget*) _tmp63_, TRUE);
				_tmp64_ = account_label;
				gtk_widget_set_valign ((GtkWidget*) _tmp64_, GTK_ALIGN_START);
				_tmp65_ = account_label;
				_tmp66_ = gtk_widget_get_style_context ((GtkWidget*) _tmp65_);
				gtk_style_context_add_class (_tmp66_, "dim-label");
				_tmp67_ = row_data;
				_tmp68_ = account_label;
				gtk_grid_attach (_tmp67_, (GtkWidget*) _tmp68_, 1, 1, 1, 1);
				_tmp69_ = self->priv->accounts_view;
				_tmp70_ = row_data;
				gtk_container_add ((GtkContainer*) _tmp69_, (GtkWidget*) _tmp70_);
				_tmp72_ = select_active;
				if (_tmp72_) {
					FolksPersonaStore* _tmp73_ = NULL;
					ContactsApp* _tmp74_ = NULL;
					ContactsStore* _tmp75_ = NULL;
					FolksIndividualAggregator* _tmp76_ = NULL;
					FolksIndividualAggregator* _tmp77_ = NULL;
					FolksPersonaStore* _tmp78_ = NULL;
					FolksPersonaStore* _tmp79_ = NULL;
					_tmp73_ = persona_store;
					_tmp74_ = contacts_app_app;
					_tmp75_ = _tmp74_->contacts_store;
					_tmp76_ = contacts_store_get_aggregator (_tmp75_);
					_tmp77_ = _tmp76_;
					_tmp78_ = folks_individual_aggregator_get_primary_store (_tmp77_);
					_tmp79_ = _tmp78_;
					_tmp71_ = _tmp73_ == _tmp79_;
				} else {
					_tmp71_ = FALSE;
				}
				if (_tmp71_) {
					GtkListBoxRow* row = NULL;
					GtkGrid* _tmp80_ = NULL;
					GtkContainer* _tmp81_ = NULL;
					GtkListBoxRow* _tmp82_ = NULL;
					GtkListBoxRow* _tmp83_ = NULL;
					_tmp80_ = row_data;
					_tmp81_ = (GtkContainer*) gtk_widget_get_parent ((GtkWidget*) _tmp80_);
					_tmp82_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp81_, gtk_list_box_row_get_type ()) ? ((GtkListBoxRow*) _tmp81_) : NULL);
					row = _tmp82_;
					_tmp83_ = row;
					contacts_accounts_list_row_activated (self, _tmp83_);
					_g_object_unref0 (row);
				}
				_g_object_unref0 (account_label);
				_g_free0 (account_name);
				_g_object_unref0 (provider_label);
				_g_object_unref0 (row_data);
				_g_free0 (source_account_id);
				_g_free0 (provider_name);
				_g_object_unref0 (parent_source);
				_g_object_unref0 (source);
				_g_object_unref0 (persona_store);
			}
		}
		persona_store_collection = (_vala_array_free (persona_store_collection, persona_store_collection_length1, (GDestroyNotify) g_object_unref), NULL);
	}
	_tmp84_ = local_store;
	if (_tmp84_ != NULL) {
		GtkGrid* local_data = NULL;
		GtkGrid* _tmp85_ = NULL;
		GtkGrid* _tmp86_ = NULL;
		GtkGrid* _tmp87_ = NULL;
		GtkGrid* _tmp88_ = NULL;
		GtkGrid* _tmp89_ = NULL;
		FolksPersonaStore* _tmp90_ = NULL;
		FolksPersonaStore* _tmp91_ = NULL;
		GtkImage* provider_image = NULL;
		GtkImage* _tmp92_ = NULL;
		GtkGrid* _tmp93_ = NULL;
		GtkImage* _tmp94_ = NULL;
		GtkLabel* local_label = NULL;
		const gchar* _tmp95_ = NULL;
		GtkLabel* _tmp96_ = NULL;
		GtkGrid* _tmp97_ = NULL;
		GtkLabel* _tmp98_ = NULL;
		GtkListBox* _tmp99_ = NULL;
		GtkGrid* _tmp100_ = NULL;
		gboolean _tmp101_ = FALSE;
		gboolean _tmp102_ = FALSE;
		_tmp85_ = (GtkGrid*) gtk_grid_new ();
		g_object_ref_sink (_tmp85_);
		local_data = _tmp85_;
		_tmp86_ = local_data;
		g_object_set ((GtkWidget*) _tmp86_, "margin", 6, NULL);
		_tmp87_ = local_data;
		gtk_widget_set_margin_start ((GtkWidget*) _tmp87_, 5);
		_tmp88_ = local_data;
		gtk_grid_set_column_spacing (_tmp88_, (guint) 10);
		_tmp89_ = local_data;
		_tmp90_ = local_store;
		_tmp91_ = _g_object_ref0 (_tmp90_);
		g_object_set_data_full ((GObject*) _tmp89_, "store", _tmp91_, g_object_unref);
		_tmp92_ = (GtkImage*) gtk_image_new_from_icon_name ("x-office-address-book", GTK_ICON_SIZE_DIALOG);
		g_object_ref_sink (_tmp92_);
		provider_image = _tmp92_;
		_tmp93_ = local_data;
		_tmp94_ = provider_image;
		gtk_container_add ((GtkContainer*) _tmp93_, (GtkWidget*) _tmp94_);
		_tmp95_ = _ ("Local Address Book");
		_tmp96_ = (GtkLabel*) gtk_label_new (_tmp95_);
		g_object_ref_sink (_tmp96_);
		local_label = _tmp96_;
		_tmp97_ = local_data;
		_tmp98_ = local_label;
		gtk_container_add ((GtkContainer*) _tmp97_, (GtkWidget*) _tmp98_);
		_tmp99_ = self->priv->accounts_view;
		_tmp100_ = local_data;
		gtk_container_add ((GtkContainer*) _tmp99_, (GtkWidget*) _tmp100_);
		_tmp102_ = select_active;
		if (_tmp102_) {
			FolksPersonaStore* _tmp103_ = NULL;
			ContactsApp* _tmp104_ = NULL;
			ContactsStore* _tmp105_ = NULL;
			FolksIndividualAggregator* _tmp106_ = NULL;
			FolksIndividualAggregator* _tmp107_ = NULL;
			FolksPersonaStore* _tmp108_ = NULL;
			FolksPersonaStore* _tmp109_ = NULL;
			_tmp103_ = local_store;
			_tmp104_ = contacts_app_app;
			_tmp105_ = _tmp104_->contacts_store;
			_tmp106_ = contacts_store_get_aggregator (_tmp105_);
			_tmp107_ = _tmp106_;
			_tmp108_ = folks_individual_aggregator_get_primary_store (_tmp107_);
			_tmp109_ = _tmp108_;
			_tmp101_ = _tmp103_ == _tmp109_;
		} else {
			_tmp101_ = FALSE;
		}
		if (_tmp101_) {
			GtkListBoxRow* row = NULL;
			GtkGrid* _tmp110_ = NULL;
			GtkContainer* _tmp111_ = NULL;
			GtkListBoxRow* _tmp112_ = NULL;
			GtkListBoxRow* _tmp113_ = NULL;
			_tmp110_ = local_data;
			_tmp111_ = (GtkContainer*) gtk_widget_get_parent ((GtkWidget*) _tmp110_);
			_tmp112_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp111_, gtk_list_box_row_get_type ()) ? ((GtkListBoxRow*) _tmp111_) : NULL);
			row = _tmp112_;
			_tmp113_ = row;
			contacts_accounts_list_row_activated (self, _tmp113_);
			_g_object_unref0 (row);
		}
		_g_object_unref0 (local_label);
		_g_object_unref0 (provider_image);
		_g_object_unref0 (local_data);
	}
	_tmp114_ = self->priv->accounts_view;
	gtk_widget_show_all ((GtkWidget*) _tmp114_);
	_g_object_unref0 (local_store);
}


ContactsAccountsList* contacts_accounts_list_construct (GType object_type) {
	ContactsAccountsList * self = NULL;
	self = (ContactsAccountsList*) g_object_new (object_type, NULL);
	return self;
}


ContactsAccountsList* contacts_accounts_list_new (void) {
	return contacts_accounts_list_construct (CONTACTS_TYPE_ACCOUNTS_LIST);
}


static void _contacts_add_separator_gtk_list_box_update_header_func (GtkListBoxRow* row, GtkListBoxRow* before, gpointer self) {
	contacts_add_separator (row, before);
}


static void _contacts_accounts_list___lambda91_ (ContactsAccountsList* self) {
	GError * _inner_error_ = NULL;
	{
		g_spawn_command_line_async ("gnome-control-center online-accounts", &_inner_error_);
		if (G_UNLIKELY (_inner_error_ != NULL)) {
			goto __catch37_g_error;
		}
	}
	goto __finally37;
	__catch37_g_error:
	{
		GError* e = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_g_error_free0 (e);
	}
	__finally37:
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void __contacts_accounts_list___lambda91__gtk_button_clicked (GtkButton* _sender, gpointer self) {
	_contacts_accounts_list___lambda91_ ((ContactsAccountsList*) self);
}


static void _contacts_accounts_list_row_activated_gtk_list_box_row_activated (GtkListBox* _sender, GtkListBoxRow* row, gpointer self) {
	contacts_accounts_list_row_activated ((ContactsAccountsList*) self, row);
}


static GObject * contacts_accounts_list_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	ContactsAccountsList * self;
	GtkListBox* _tmp0_ = NULL;
	GtkListBox* _tmp1_ = NULL;
	GtkListBox* _tmp2_ = NULL;
	GtkListBox* _tmp3_ = NULL;
	GtkScrolledWindow* scrolled = NULL;
	GtkScrolledWindow* _tmp4_ = NULL;
	GtkScrolledWindow* _tmp5_ = NULL;
	GtkScrolledWindow* _tmp6_ = NULL;
	GtkScrolledWindow* _tmp7_ = NULL;
	GtkScrolledWindow* _tmp8_ = NULL;
	GtkListBox* _tmp9_ = NULL;
	const gchar* _tmp10_ = NULL;
	GtkButton* _tmp11_ = NULL;
	GtkButton* _tmp12_ = NULL;
	GtkStyleContext* _tmp13_ = NULL;
	GtkButton* _tmp14_ = NULL;
	GtkWidget* _tmp15_ = NULL;
	GtkButton* _tmp16_ = NULL;
	GtkWidget* _tmp17_ = NULL;
	GtkButton* _tmp18_ = NULL;
	GtkWidget* _tmp19_ = NULL;
	GtkButton* _tmp20_ = NULL;
	GtkWidget* _tmp21_ = NULL;
	GtkButton* _tmp22_ = NULL;
	GtkScrolledWindow* _tmp23_ = NULL;
	GtkButton* _tmp24_ = NULL;
	GtkListBox* _tmp25_ = NULL;
	parent_class = G_OBJECT_CLASS (contacts_accounts_list_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, CONTACTS_TYPE_ACCOUNTS_LIST, ContactsAccountsList);
	gtk_orientable_set_orientation ((GtkOrientable*) self, GTK_ORIENTATION_VERTICAL);
	gtk_grid_set_row_spacing ((GtkGrid*) self, (guint) 12);
	_g_object_unref0 (self->selected_store);
	self->selected_store = NULL;
	_tmp0_ = (GtkListBox*) gtk_list_box_new ();
	g_object_ref_sink (_tmp0_);
	_g_object_unref0 (self->priv->accounts_view);
	self->priv->accounts_view = _tmp0_;
	_tmp1_ = self->priv->accounts_view;
	gtk_list_box_set_selection_mode (_tmp1_, GTK_SELECTION_NONE);
	_tmp2_ = self->priv->accounts_view;
	gtk_widget_set_size_request ((GtkWidget*) _tmp2_, 372, -1);
	_tmp3_ = self->priv->accounts_view;
	gtk_list_box_set_header_func (_tmp3_, _contacts_add_separator_gtk_list_box_update_header_func, NULL, NULL);
	_tmp4_ = (GtkScrolledWindow*) gtk_scrolled_window_new (NULL, NULL);
	g_object_ref_sink (_tmp4_);
	scrolled = _tmp4_;
	_tmp5_ = scrolled;
	gtk_scrolled_window_set_min_content_height (_tmp5_, 210);
	_tmp6_ = scrolled;
	gtk_scrolled_window_set_policy (_tmp6_, GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
	_tmp7_ = scrolled;
	gtk_scrolled_window_set_shadow_type (_tmp7_, GTK_SHADOW_IN);
	_tmp8_ = scrolled;
	_tmp9_ = self->priv->accounts_view;
	gtk_container_add ((GtkContainer*) _tmp8_, (GtkWidget*) _tmp9_);
	_tmp10_ = _ ("Online Accounts");
	_tmp11_ = (GtkButton*) gtk_button_new_with_label (_tmp10_);
	g_object_ref_sink (_tmp11_);
	_g_object_unref0 (self->priv->add_account_button);
	self->priv->add_account_button = _tmp11_;
	_tmp12_ = self->priv->add_account_button;
	_tmp13_ = gtk_widget_get_style_context ((GtkWidget*) _tmp12_);
	gtk_style_context_add_class (_tmp13_, GTK_STYLE_CLASS_RAISED);
	_tmp14_ = self->priv->add_account_button;
	_tmp15_ = gtk_bin_get_child ((GtkBin*) _tmp14_);
	gtk_widget_set_margin_start (_tmp15_, 6);
	_tmp16_ = self->priv->add_account_button;
	_tmp17_ = gtk_bin_get_child ((GtkBin*) _tmp16_);
	gtk_widget_set_margin_end (_tmp17_, 6);
	_tmp18_ = self->priv->add_account_button;
	_tmp19_ = gtk_bin_get_child ((GtkBin*) _tmp18_);
	gtk_widget_set_margin_top (_tmp19_, 3);
	_tmp20_ = self->priv->add_account_button;
	_tmp21_ = gtk_bin_get_child ((GtkBin*) _tmp20_);
	gtk_widget_set_margin_bottom (_tmp21_, 3);
	_tmp22_ = self->priv->add_account_button;
	g_signal_connect_object (_tmp22_, "clicked", (GCallback) __contacts_accounts_list___lambda91__gtk_button_clicked, self, 0);
	_tmp23_ = scrolled;
	gtk_container_add ((GtkContainer*) self, (GtkWidget*) _tmp23_);
	_tmp24_ = self->priv->add_account_button;
	gtk_container_add ((GtkContainer*) self, (GtkWidget*) _tmp24_);
	gtk_widget_show_all ((GtkWidget*) self);
	_tmp25_ = self->priv->accounts_view;
	g_signal_connect_object (_tmp25_, "row-activated", (GCallback) _contacts_accounts_list_row_activated_gtk_list_box_row_activated, self, 0);
	_g_object_unref0 (scrolled);
	return obj;
}


static void contacts_accounts_list_class_init (ContactsAccountsListClass * klass) {
	contacts_accounts_list_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (ContactsAccountsListPrivate));
	G_OBJECT_CLASS (klass)->constructor = contacts_accounts_list_constructor;
	G_OBJECT_CLASS (klass)->finalize = contacts_accounts_list_finalize;
	g_signal_new ("account_selected", CONTACTS_TYPE_ACCOUNTS_LIST, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
}


static void contacts_accounts_list_instance_init (ContactsAccountsList * self) {
	self->priv = CONTACTS_ACCOUNTS_LIST_GET_PRIVATE (self);
}


static void contacts_accounts_list_finalize (GObject* obj) {
	ContactsAccountsList * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, CONTACTS_TYPE_ACCOUNTS_LIST, ContactsAccountsList);
	_g_object_unref0 (self->priv->accounts_view);
	_g_object_unref0 (self->priv->last_selected_row);
	_g_object_unref0 (self->priv->add_account_button);
	_g_object_unref0 (self->selected_store);
	G_OBJECT_CLASS (contacts_accounts_list_parent_class)->finalize (obj);
}


GType contacts_accounts_list_get_type (void) {
	static volatile gsize contacts_accounts_list_type_id__volatile = 0;
	if (g_once_init_enter (&contacts_accounts_list_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ContactsAccountsListClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) contacts_accounts_list_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ContactsAccountsList), 0, (GInstanceInitFunc) contacts_accounts_list_instance_init, NULL };
		GType contacts_accounts_list_type_id;
		contacts_accounts_list_type_id = g_type_register_static (gtk_grid_get_type (), "ContactsAccountsList", &g_define_type_info, 0);
		g_once_init_leave (&contacts_accounts_list_type_id__volatile, contacts_accounts_list_type_id);
	}
	return contacts_accounts_list_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



