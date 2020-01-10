%global folks_version 0.11.4
%global gtk3_version 3.22.0
%global geocode_glib_version 3.15.3

Name:           gnome-contacts
Version:        3.28.2
Release:        1%{?dist}
Summary:        Contacts manager for GNOME

License:        GPLv2+
URL:            https://wiki.gnome.org/Apps/Contacts
Source0:        https://download.gnome.org/sources/%{name}/3.28/%{name}-%{version}.tar.xz
Patch0:         no-python3.patch

BuildRequires:  desktop-file-utils
BuildRequires:  docbook-dtds
BuildRequires:  docbook-style-xsl
BuildRequires:  gettext
BuildRequires:  meson
BuildRequires:  vala
BuildRequires:  /usr/bin/appstream-util
BuildRequires:  /usr/bin/xsltproc
BuildRequires:  pkgconfig(champlain-0.12)
BuildRequires:  pkgconfig(cheese-gtk)
BuildRequires:  pkgconfig(clutter-gtk-1.0)
BuildRequires:  pkgconfig(folks) >= %{folks_version}
BuildRequires:  pkgconfig(folks-eds)
BuildRequires:  pkgconfig(folks-telepathy)
BuildRequires:  pkgconfig(gee-0.8)
BuildRequires:  pkgconfig(geocode-glib-1.0) >= %{geocode_glib_version}
BuildRequires:  pkgconfig(gnome-desktop-3.0)
BuildRequires:  pkgconfig(goa-1.0)
BuildRequires:  pkgconfig(gobject-introspection-1.0)
BuildRequires:  pkgconfig(gtk+-3.0) >= %{gtk3_version}

Requires:       folks%{?_isa} >= 1:%{folks_version}
Requires:       geocode-glib%{?_isa} >= %{geocode_glib_version}
Requires:       gtk3%{?_isa} >= %{gtk3_version}
Requires:       hicolor-icon-theme

%description
%{name} is a standalone contacts manager for GNOME desktop.

%prep
%setup -q
%patch0 -p1 -b .no-py3

%build
%meson
%meson_build

%install
%meson_install
%find_lang %{name}

%check
appstream-util validate-relax --nonet %{buildroot}/%{_datadir}/metainfo/org.gnome.Contacts.appdata.xml
desktop-file-validate %{buildroot}/%{_datadir}/applications/org.gnome.Contacts.desktop

%postun
if [ $1 -eq 0 ]; then
  glib-compile-schemas %{_datadir}/glib-2.0/schemas &>/dev/null || :
fi

%posttrans
glib-compile-schemas %{_datadir}/glib-2.0/schemas &>/dev/null || :

%files -f %{name}.lang
%doc AUTHORS NEWS
%license COPYING
%{_bindir}/%{name}
%{_libexecdir}/gnome-contacts-search-provider
%{_datadir}/applications/org.gnome.Contacts.desktop
%{_datadir}/dbus-1/services/org.gnome.Contacts.service
%{_datadir}/dbus-1/services/org.gnome.Contacts.SearchProvider.service
%{_datadir}/glib-2.0/schemas/org.gnome.Contacts.gschema.xml
%dir %{_datadir}/gnome-shell
%dir %{_datadir}/gnome-shell/search-providers
%{_datadir}/gnome-shell/search-providers/org.gnome.Contacts.search-provider.ini
%{_datadir}/icons/hicolor/*/apps/gnome-contacts.png
%{_datadir}/icons/hicolor/symbolic/apps/gnome-contacts-symbolic.svg
%{_datadir}/metainfo/org.gnome.Contacts.appdata.xml
%{_mandir}/man1/%{name}.1*


%changelog
* Wed Jun 06 2018 Richard Hughes <rhughes@redhat.com> - 3.28.2-1
- Update to 3.28.2
- Resolves: #1567478

* Wed Sep 21 2016 Kalev Lember <klember@redhat.com> - 3.22.1-1
- Update to 3.22.1
- Resolves: #1386886

* Wed Jun 29 2016 Matthias Clasen <mclasen@redhat.com> - 3.14.2-4
- Update translations
- Resolves: #1049777

* Wed Jun 17 2015 Alexander Larsson <alexl@redhat.com> - 3.14.2-3
- Fix home email address
- Resolves: #1053667
- Related: #1174711

* Thu May 21 2015 Matthias Clasen <mclasen@redhat.com> - 3.14.2-2
- Rebuild against new gnome-desktop3
Related: #1174711

* Mon Mar 23 2015 Richard Hughes <rhughes@redhat.com> - 3.14.2-1
- Update to 3.14.2
- Resolves: #1174711

* Wed Dec 17 2014 David King <dking@redhat.com> - 3.8.2-6
- Fix display of address fields when adding the first contact (#1053654)

* Fri Jan 24 2014 Daniel Mach <dmach@redhat.com> - 3.8.2-5
- Mass rebuild 2014-01-24

* Fri Dec 27 2013 Daniel Mach <dmach@redhat.com> - 3.8.2-4
- Mass rebuild 2013-12-27

* Wed Jul 10 2013 Matthias Clasen <mclasen@redhat.com> - 3.8.2-3
- Add a man page

* Fri Jun 21 2013 Matthias Clasen <mclasen@redhat.com> - 3.8.2-2
- Don't install ChangeLog

* Tue May 28 2013 Matthias Clasen <mclasen@redhat.com> - 3.8.2-1
- Update to 3.8.2

* Mon Apr 15 2013 Richard Hughes <rhughes@redhat.com> - 3.8.1-1
- Update to 3.8.1

* Tue Mar 26 2013 Kalev Lember <kalevlember@gmail.com> - 3.8.0-1
- Update to 3.8.0

* Fri Mar  8 2013 Matthias Clasen <mclasen@redhat.com> - 3.7.91-1
- Update to 3.7.91

* Thu Feb 21 2013 Kalev Lember <kalevlember@gmail.com> - 3.7.90-1
- Update to 3.7.90

* Wed Feb 20 2013 Kalev Lember <kalevlember@gmail.com> - 3.7.3-3
- Rebuilt for libgnome-desktop soname bump

* Fri Jan 25 2013 Peter Robinson <pbrobinson@fedoraproject.org> 3.7.3-2
- Rebuild for new cogl

* Fri Dec 21 2012 Kalev Lember <kalevlember@gmail.com> - 3.7.3-1
- Update to 3.7.3

* Tue Nov 20 2012 Milan Crha <mcrha@redhat.com> - 3.6.2-2
- Rebuild against newer evolution-data-server

* Tue Nov 13 2012 Kalev Lember <kalevlember@gmail.com> - 3.6.2-1
- Update to 3.6.2

* Thu Oct 25 2012 Milan Crha <mcrha@redhat.com> - 3.6.1-2
- Rebuild against newer evolution-data-server

* Tue Oct 16 2012 Kalev Lember <kalevlember@gmail.com> - 3.6.1-1
- Update to 3.6.1

* Tue Oct  2 2012 Peter Robinson <pbrobinson@fedoraproject.org> - 3.6.0-2
- Obsolete contacts. RHBZ # 861373
- Cleanup spec, update URL and Source locations

* Tue Sep 25 2012 Richard Hughes <hughsient@gmail.com> - 3.6.0-1
- Update to 3.6.0

* Wed Sep 19 2012 Kalev Lember <kalevlember@gmail.com> - 3.5.92-2
- Rebuilt for new libcheese

* Wed Sep 19 2012 Richard Hughes <hughsient@gmail.com> - 3.5.92-1
- Update to 3.5.92

* Tue Sep 04 2012 Richard Hughes <hughsient@gmail.com> - 3.5.91-1
- Update to 3.5.91

* Tue Aug 28 2012 Matthias Clasen <mclasen@redhat.com> - 3.5.90-2
- Rebuild against new cogl/clutter

* Tue Aug 21 2012 Elad Alfassa <elad@fedoraproject.org> - 3.5.90-1
- New upstream release

* Tue Jul 31 2012 Richard Hughes <hughsient@gmail.com> - 3.5.4.1-1
- Update to 3.5.4.1

* Fri Jul 27 2012 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 3.5.3-3
- Rebuilt for https://fedoraproject.org/wiki/Fedora_18_Mass_Rebuild

* Wed Jul 18 2012 Matthias Clasen <mclasen@redhat.com> - 3.5.3-2
- Rebuild

* Tue Jul 17 2012 Richard Hughes <hughsient@gmail.com> - 3.5.3-1
- Update to 3.5.3

* Mon Jun 25 2012 Richard Hughes <hughsient@gmail.com> - 3.5.2-1
- Update to 3.5.2

* Thu Jun 07 2012 Richard Hughes <hughsient@gmail.com> - 3.5.1-1
- Update to 3.5.1

* Fri May 18 2012 Richard Hughes <hughsient@gmail.com> - 3.4.1-1
- Update to 3.4.1

* Tue Apr 24 2012 Kalev Lember <kalevlember@gmail.com> - 3.4.0-2
- Silence rpm scriptlet output

* Tue Mar 27 2012 Richard Hughes <hughsient@gmail.com> - 3.4.0-1
- Update to 3.4.0

* Wed Mar 21 2012 Kalev Lember <kalevlember@gmail.com> - 3.3.92-1
- Update to 3.3.92

* Tue Mar  6 2012 Matthias Clasen <mclasen@redhat.com> - 3.3.91-1
- Update to 3.3.91

* Sun Feb 26 2012 Matthias Clasen <mclasen@redhat.com> - 3.3.90-1
- Update to 3.3.90

* Tue Feb  7 2012 Matthias Clasen <mclasen@redhat.com> - 3.3.4-1
- Update to 3.3.4

* Tue Jan 17 2012 Matthias Clasen <mclasen@redhat.com> - 3.3.3-1
- Update to 3.3.3

* Fri Jan 13 2012 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 3.3.1-2
- Rebuilt for https://fedoraproject.org/wiki/Fedora_17_Mass_Rebuild

* Tue Dec 20 2011 Matthias Clasen <mclasen@redhat.com> - 3.3.1-1
- Update to 3.3.1

* Thu Nov 24 2011 Tomas Bzatek <tbzatek@redhat.com> - 3.2.2-3
- Rebuilt for new eds

* Wed Oct 26 2011 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 3.2.2-2
- Rebuilt for glibc bug#747377

* Thu Oct 20 2011 Elad Alfassa <elad@fedoraproject.org> - 3.2.2-1
- Upstream bugfix release 3.2.2
- Fixes RHBZ #743827, #743989

* Tue Oct 18 2011 Elad Alfassa <elad@fedoraproject.org> - 3.2.1-1
- Update to 3.2.1 (Translation updates)

* Tue Sep 27 2011 Elad Alfassa <elad@fedoraproject.org> - 3.2.0.1-1
- New upstream release

* Tue Sep 20 2011 Elad Alfassa <elad@fedoraproject.org> - 0.1.5.2-1
- New upstream release (mainly contact linking support)

* Wed Sep 07 2011 Elad Alfassa <elad@fedoraproject.org> - 0.1.4.1-1
- New upstream release (fix a crash).

* Wed Sep 07 2011 Elad Alfassa <elad@fedoraproject.org> - 0.1.4-1
- New upstream release:
- *Unique application instance support
- *Support browsing for avatar file
- *Support deleting (some) contacts
- *Support linking contacts
- *Support for new fields:
-  * nickname
-  * birthday (readonly)
-  * company/title/etc (readonly)
- * Lots of small UI tweaks

* Tue Aug 30 2011 Elad Alfassa <elad@fedoraproject.org> - 0.1.3-1
- New upstream version

* Mon Aug 22 2011 Brian Pepple <bpepple@fedoraproject.org> - 0.1.2-2
- Rebuld for eds.

* Tue Aug 16 2011 Elad Alfassa <elad@fedoraproject.org> - 0.1.2-0
- New upstream release

* Sun Aug 14 2011 Elad Alfassa <elad@fedoraproject.org> - 0.1.1-2
- Rebuilt to fix broken libfolks dependencies

* Tue Jul 05 2011 Elad Alfassa <elad@fedoraproject.org> - 0.1.1-1
- Update to 0.1.1

* Sun Jun 19 2011 Elad Alfassa <elad@fedoraproject.org> - 0.1.0-3
- Fix unowned directory

* Sun Jun 19 2011 Elad Alfassa <elad@fedoraproject.org> - 0.1.0-2
- Add missing doc files.
- Use package names instead of pkgconfig() in BuildRequires

* Mon Jun 13 2011 Elad Alfassa <elad@fedoraproject.org> - 0.1.0-1
- Initial packaging


