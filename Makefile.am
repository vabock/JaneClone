# 依存関係にあるソース群
SUBDIRS = 

if BUILDING_SQLITE3
   SUBDIRS += sqlite3
endif

if BUILDING_WXSQLITE3
   SUBDIRS += wxsqlite3
endif

if BUILDING_CURLPP
   SUBDIRS += curlpp
endif

SUBDIRS += cmdline_twitter src test

# パッケージ作成用サブディレクトリも設定する
DIST_SUBDIRS = $(SUBDIRS)

# janeclone.wrapper向けルール
bin_SCRIPTS = janeclone
CLEANFILES  = $(bin_SCRIPTS)
EXTRA_DIST  = misc/janeclone.wrapper  \
	      misc/janeclone.menu     \
	      misc/janeclone.desktop  \
	      test                    \
	      $(wildcard babel/*.dat) \
	      $(wildcard bebel/*.csv) \
	      man/janeclone.man

# 書き換えスクリプト
janecloneexecdir 	= $(datarootdir)/@PACKAGE@
janecloneexecrcdir	= $(prefix)/share/pixmaps/@PACKAGE@

do_subst_wrapper =  sed -e 's,%%%appdir%%%,$(datarootdir)/@PACKAGE@,g' \
			-e 's,%%%pkglibdir%%%,$(pkglibdir),g'
do_subst_menu 	 =  sed -e 's,%%%bindir%%%,$(bindir)/,g' \
			-e 's,%%%janecloneexecrcdir%%%,$(janecloneexecrcdir),g'

# Doxygen
docs: src/*.cpp src/*.hpp Doxyfile
	doxygen && cd docs/ && git add . && git commit -m 'updated docs' && git push origin gh-pages

# manページ
man1_MANS = man/janeclone.man

# janecloneスクリプトを作成する
janeclone:
if USE_LINUX
	if [ -d debian ]; then \
		$(do_subst_menu) misc/janeclone.menu > debian/menu; \
	fi
endif

# インストール時のファイルコピー(パッケージビルド時は行わない)
install-data-local:
	@if test ! -d debian; then										      \
	   cp -r $(top_builddir)/src/rc $(datarootdir)/@PACKAGE@;						      \
	   if test "x`uname -s`" = "xFreeBSD"; then                   						      \
	      $(do_subst_menu) $(top_builddir)/misc/janeclone.desktop > /usr/local/share/applications/janeclone.desktop; \
	   else                                                                                          		 \
	      $(do_subst_menu) $(top_builddir)/misc/janeclone.desktop > /usr/share/applications/janeclone.desktop;       \
	   fi;														 \
	fi

# ChangeLogと連動させる
dist-hook: ChangeLog

# configure.acが更新された時動く
ChangeLog: configure.ac
	@echo "Non-maintainer upload" > ChangeLog
	@echo "" >> ChangeLog
	git log --stat --name-only --date=short --abbrev-commit >> ChangeLog

# NSISの設定ファイル
MAKENSIS    = makensis
NSIS_NSI_IN = $(top_builddir)/misc/janeclone.nsi.in
NSIS_NSI    = $(top_builddir)/extras/janeclone.nsi
NLIST	    = $(shell for x in {1..$(words $(WIN32_DEP))}; do echo $$x; done)
WIN32_DEP   = libstdc++ libgcc libxml2 zlib libcurl libjpeg libpng libtiff ssleay32 libeay32

# RPM用設定ファイル
RPM_MACRO   = $(top_builddir)/extras/package/.rpmmacros
# <パッケージ名>-<バージョン番号>.<リリース番号>.spec
SPECFILE	= $(PACKAGE_NAME)-$(VERSION).spec
SPECFILE_PATH	= $(top_builddir)//$(SPECFILE)
# <パッケージ名>-<バージョン番号>.<リリース番号>.<アーキテクチャ>.rpm
RPMNAME		= $(PACKAGE_NAME)-$(VERSION).`uname -m`.rpm

# Debian用COPYRIGHTの場所
COPYRIGHT=$(distdir)/debian/copyright
PACKAGER="Hiroyuki Nagata"
AUTHOR="Hiroyuki Nagata"

# OSX application bundle用の設定
ICONFILE		= janeclone.icns
ICONPATH		= $(wildcard $(top_builddir)/src/rc/* )
RCPATH			= $(top_builddir)/src/rc
SCRIPTPATH		= $(top_builddir)/src/script
PROGVER			= $(VERSION)
BUNDLE			= $(top_builddir)/$(PACKAGE_NAME).app
MACICON			= $(BUNDLE)/Contents/$(ICONFILE)
MACPKGINFO		= $(BUNDLE)/Contents/PkgInfo
MACINFOPLIST		= $(BUNDLE)/Contents/Info.plist
# OSX Info.plist用の設定
COMPANY			= ????
BUNDLEPACKAGE		= APPL
BUNDLESIGNATURE		= ????

#
# Windows(x86)向けのインストーラ作成(クロスコンパイラ向け)
#
package-win32-msi: prepare-package check-nsis
	touch $(NSIS_NSI)
	cp -p $(top_builddir)/INSTALL $(top_builddir)/extras/package
	cp -p $(top_builddir)/README $(top_builddir)/extras/package
	cp -rp $(top_builddir)/src/rc $(top_builddir)/extras/package
	cp -rp $(top_builddir)/src/script $(top_builddir)/extras/package
# find dlls and copy to package directory
	for f in `find $(top_builddir) -name \*.dll`; do                                                    \
	   cp -p $${f} $(top_builddir)/extras/package;                                                      \
	done
	for f in `find $(top_builddir)/src/.libs/ -name $(PACKAGE).exe`; do                             \
	   cp -p $${f} $(top_builddir)/extras/package;                                                      \
	done
	for f in `find $(bindir) $(libdir) -name wx*@WX_VERSION_MAJOR@@WX_VERSION_MINOR@*.dll`; do          \
	   cp -p $${f} $(top_builddir)/extras/package;         	                                            \
	done
	@$(foreach x,$(WIN32_DEP),                                 \
	   for f in `find $(bindir) $(libdir) -name $(x)*.dll`; do \
	      cp -p $${f} $(top_builddir)/extras/package;          \
	   done;                                                   \
	)
# add line to NSIS script
	cp -p $(NSIS_NSI_IN) $(NSIS_NSI)
	sed -i 's/%%%VERSION%%%/$(PACKAGE_VERSION)/g' $(NSIS_NSI)
	sed -i 's/%%%ARCH%%%/win32/g' $(NSIS_NSI)
	sed -i 's/%%%DEFAULT_PROGRAMFILES%%%/$$PROGRAMFILES32/g' $(NSIS_NSI)
	@echo 'makensis start...'
	$(MAKENSIS) $(NSIS_NSI)

# Windows(x86)向けのzip作成
package-win32-zip: prepare-package
	cp -p $(top_builddir)/INSTALL $(top_builddir)/extras/package
	cp -p $(top_builddir)/README $(top_builddir)/extras/package
	cp -rp $(top_builddir)/src/rc $(top_builddir)/extras/package
	cp -rp $(top_builddir)/src/script $(top_builddir)/extras/package
	for f in `find $(top_builddir) -name \*.dll`; do                                                    \
	   cp -p $${f} $(top_builddir)/extras/package;                                                      \
	done
	for f in `find $(top_builddir)/src/.libs/ -name $(PACKAGE).exe`; do                             \
	   cp -p $${f} $(top_builddir)/extras/package;                                                      \
	done
	for f in `find $(bindir) $(libdir) -name wx*@WX_VERSION_MAJOR@@WX_VERSION_MINOR@*.dll`; do          \
	   cp -p $${f} $(top_builddir)/extras/package;         	                                            \
	done
	@$(foreach x,$(WIN32_DEP),                                 \
	   for f in `find $(bindir) $(libdir) -name $(x)*.dll`; do \
	      cp -p $${f} $(top_builddir)/extras/package;          \
	   done;                                                   \
	)
	( cd $(top_builddir)/extras && zip -r $(PACKAGE)-win32-$(VERSION).zip package/ && mv $(PACKAGE)-win32-$(VERSION).zip ../ )

#
# Windows(x64)向けのインストーラ作成(クロスコンパイラ向け)
#
package-win64-msi: prepare-package check-nsis
	cp -p $(top_builddir)/INSTALL $(top_builddir)/extras/package
	cp -p $(top_builddir)/README $(top_builddir)/extras/package
	cp -rp $(top_builddir)/src/rc $(top_builddir)/extras/package
	cp -rp $(top_builddir)/src/script $(top_builddir)/extras/package
# find dlls and copy to package directory
	for f in `find $(top_builddir) -name \*.dll`; do                                                    \
	   cp -p $${f} $(top_builddir)/extras/package;                                                      \
	done
	for f in `find $(top_builddir)/src/.libs/ -name $(PACKAGE).exe`; do                             \
	   cp -p $${f} $(top_builddir)/extras/package;                                                      \
	done
	for f in `find $(bindir) $(libdir) -name wx*@WX_VERSION_MAJOR@@WX_VERSION_MINOR@*.dll`; do          \
	   cp -p $${f} $(top_builddir)/extras/package;         	                                            \
	done
	@$(foreach x,$(WIN32_DEP),                                 \
	   for f in `find $(bindir) $(libdir) -name $(x)*.dll`; do \
	      cp -p $${f} $(top_builddir)/extras/package;          \
	   done;                                                   \
	)
# add line to NSIS script
	cp -p $(NSIS_NSI_IN) $(NSIS_NSI)
	sed -i 's/%%%VERSION%%%/$(PACKAGE_VERSION)/g' $(NSIS_NSI)
	sed -i 's/%%%ARCH%%%/win64/g' $(NSIS_NSI)
	sed -i 's/%%%DEFAULT_PROGRAMFILES%%%/$$PROGRAMFILES64/g' $(NSIS_NSI)
	@echo 'makensis start...'
	$(MAKENSIS) $(NSIS_NSI)

# Windows(x64)向けのzip作成
package-win64-zip: prepare-package
	cp -p $(top_builddir)/INSTALL $(top_builddir)/extras/package
	cp -p $(top_builddir)/README $(top_builddir)/extras/package
	cp -rp $(top_builddir)/src/rc $(top_builddir)/extras/package
	cp -rp $(top_builddir)/src/script $(top_builddir)/extras/package
	for f in `find $(top_builddir) -name \*.dll`; do                                                    \
	   cp -p $${f} $(top_builddir)/extras/package;                                                      \
	done
	for f in `find $(top_builddir)/src/.libs/ -name $(PACKAGE).exe`; do                             \
	   cp -p $${f} $(top_builddir)/extras/package;                                                      \
	done
	for f in `find $(bindir) $(libdir) -name wx*@WX_VERSION_MAJOR@@WX_VERSION_MINOR@*.dll`; do          \
	   cp -p $${f} $(top_builddir)/extras/package;         	                                            \
	done
	@$(foreach x,$(WIN32_DEP),                                 \
	   for f in `find $(bindir) $(libdir) -name $(x)*.dll`; do \
	      cp -p $${f} $(top_builddir)/extras/package;          \
	   done;                                                   \
	)
	( cd $(top_builddir)/extras && zip -r $(PACKAGE)-win64-$(VERSION).zip package/ && mv $(PACKAGE)-win64-$(VERSION).zip ../ )

# specファイルの生成
generate-spec:
	@echo "Create SPEC file..."
# SPECファイルを作成する
	touch $(SPECFILE_PATH)
	@echo "%define	       name    janeclone					 "	> $(SPECFILE_PATH)
	@echo "%define	       version 1.1.4						 "	>> $(SPECFILE_PATH)
	@echo "%define	       release 0						 "	>> $(SPECFILE_PATH)
	@echo "%define	       prefix  /usr						 "	>> $(SPECFILE_PATH)
	@echo "%define	       _rpmfilename %%{NAME}-%%{VERSION}-%%{RELEASE}.%%{ARCH}.rpm"	>> $(SPECFILE_PATH)
	@echo "										 "	>> $(SPECFILE_PATH)
	@echo "Name:	%{name}								 "	>> $(SPECFILE_PATH)
	@echo "Version: %{version}							 "	>> $(SPECFILE_PATH)
	@echo "Release: %{release}							 "	>> $(SPECFILE_PATH)
	@echo "Source: %{name}_%{version}.tar.gz					 "	>> $(SPECFILE_PATH)
	@echo "Packager: Hiroyuki Nagata <newserver002@gmail.com>			 "	>> $(SPECFILE_PATH)
	@echo "BuildRoot: /var/tmp/%{name}-%{version}-root				 "	>> $(SPECFILE_PATH)
	@echo "Summary: Cross Platform 2ch browser					 "	>> $(SPECFILE_PATH)
	@echo "License: see /usr/share/doc/janeclone/copyright				 "	>> $(SPECFILE_PATH)
	@echo "Group: Applications/Internet						 "	>> $(SPECFILE_PATH)
	@echo "Url: http://hiroyuki-nagata.github.io/					 "	>> $(SPECFILE_PATH)
	@echo "										 "	>> $(SPECFILE_PATH)
	@echo "Requires: filesystem							 "	>> $(SPECFILE_PATH)
	@echo "										 "	>> $(SPECFILE_PATH)
	@echo "BuildRequires: gcc-c++							 "      >> $(SPECFILE_PATH) 
	@echo "BuildRequires: zlib-devel						 "      >> $(SPECFILE_PATH) 
	@echo "BuildRequires: wxGTK-devel						 "      >> $(SPECFILE_PATH) 
	@echo "BuildRequires: libxml2-devel						 "      >> $(SPECFILE_PATH) 
	@echo "										 "	>> $(SPECFILE_PATH)
	@echo "%description" >> $(SPECFILE_PATH)
	@echo "JaneClone is a plain browser dedicated to read 2ch thread. Using a library called wxWidgets." >> $(SPECFILE_PATH)
	@echo "It will work on Windows, Linux, Mac. It will keep the platform-specific user interface." >> $(SPECFILE_PATH)
	@echo "" >> $(SPECFILE_PATH)
	@echo "%prep" >> $(SPECFILE_PATH)
	@echo "%setup -q" >> $(SPECFILE_PATH)
	@echo "" >> $(SPECFILE_PATH)
	@echo "%build" >> $(SPECFILE_PATH)
	@echo "rm -rf $RPM_BUILD_ROOT" >> $(SPECFILE_PATH)
	@echo "./bootstrap" >> $(SPECFILE_PATH)
	@echo "CXXFLAGS=$RPM_OPT_FLAGS ./configure --prefix=%{prefix}" >> $(SPECFILE_PATH)
	@echo "make" >> $(SPECFILE_PATH)
	@echo "" >> $(SPECFILE_PATH)
	@echo "%install" >> $(SPECFILE_PATH)
	@echo "[ -d $RPM_BUILD_ROOT ] && rm -rf $RPM_BUILD_ROOT;" >> $(SPECFILE_PATH)
	@echo "make -e prefix=$RPM_BUILD_ROOT%{prefix} install" >> $(SPECFILE_PATH)
	@echo "" >> $(SPECFILE_PATH)
	@echo "%clean" >> $(SPECFILE_PATH)
	@echo "[ -d $RPM_BUILD_ROOT ] && rm -rf $RPM_BUILD_ROOT;" >> $(SPECFILE_PATH)
	@echo "" >> $(SPECFILE_PATH)
	@cat $(SPECFILE_PATH)

# RH系ディストリビューション向けのインストーラ作成
package-rpm: package-clean generate-spec
	@echo 'RPM package create start...'
#mkdir -p $(top_builddir)/extras/package/{BUILD,RPMS,SOURCES,SPECS,SRPMS}
#	touch $(RPM_MACRO)
# 	echo "%_topdir $(top_builddir)/extras/package" > $(RPM_MACRO)
# 	echo "%packager Hiroyuki Nagata <$(PACKAGE_BUGREPORT)>" >> $(RPM_MACRO)
# 	echo "%_sysconfdir /etc" >> $(RPM_MACRO)
# 	$(MAKE) dist
# 	mv $(distdir).tar.gz $(top_builddir)/extras/package/SOURCES
# rpmbuildを実行する
#	cd $(top_builddir)/extras/package/SPECS && rpmbuild --macros=$(RPM_MACRO) -ba $(SPECFILE)
	@echo 'RPM package create end...'

#
# Debian系ディストリビューション向けのインストーラ作成
#
if USE_LINUX
   # debian version
   DEBIAN_VERSION=`cat /etc/debian_version`
endif

# target for debian with GPG key
package-deb-with-gpg: package-deb
	@if gpg --version >/dev/null 2>&1; then                                      \
	   echo "sign by GPG key...";                                                \
	   (cd $(distdir) && debuild --preserve-env --preserve-envvar PATH);         \
	else                                                                         \
	   echo "not use GPG key...if you want to sign, make by terminal.";          \
	   (cd $(distdir) && debuild --preserve-env --preserve-envvar PATH -uc -us); \
	fi

# target for debian without GPG key
package-deb-local: package-deb
	@echo "not use GPG key...if you want to sign, make by terminal."
	(cd $(distdir) && debuild --preserve-env --preserve-envvar PATH -uc -us)

# update license info
package-deb-license:

# target for debian
package-deb: package-deb-license local-distdir-remove dist
	(tar xvf $(distdir).tar.gz && cd $(distdir) && yes | dh_make -n -s -e $(PACKAGE_BUGREPORT) -f ../$(distdir).tar.gz)
	@echo "This env is Travis ? -> $(TRAVIS_CI)"
	@if test "$(TRAVIS_CI)" = "true"; then                                 \
	   echo "This is Travis CI, use Debian ubuntu control file...";        \
	   cp $(top_builddir)/debian/control.ubuntu $(distdir)/debian/control; \
	elif test "$(WX_VERSION_MAJOR)" = "2"; then                            \
	   echo "use Debian wheezy control file...";                           \
	   cp $(top_builddir)/debian/control.wheezy $(distdir)/debian/control; \
	else                                                                   \
	   echo "use Debian jessie control file...";                           \
	   cp $(top_builddir)/debian/control.jessie $(distdir)/debian/control; \
	fi
	sed -i 's/%%%STANDARDS-VERSION%%%/@DEB_STANDARDS_VERSION@/g' $(distdir)/debian/control #  debian policy version
	sed -i 's/%%%VERSION%%%/$(PACKAGE_VERSION)+nmuX/g' $(distdir)/debian/control           #  upstream version 
	sed -i 's/%%%PACKAGE_BUGREPORT%%%/$(PACKAGE_BUGREPORT)/g' $(distdir)/debian/control    #  bugreport address
	sed -i 's/%%%VERSION%%%/$(VERSION)/g' $(distdir)/man/janeclone.man             	       #  upstream version
	sed -i "s/%%%DATE%%%/`date +\"%B %d, %Y\"`/g" $(distdir)/man/janeclone.man
	@echo "-----------------------------------------------------------------------------"
	@cat $(distdir)/man/janeclone.man
	@echo "-----------------------------------------------------------------------------"
	cp $(top_builddir)/debian/rules   $(distdir)/debian/rules                              #  rule file
	rm -f $(distdir)/debian/*.ex                                                           #  delete example files
	rm -f $(distdir)/debian/*.EX                                                           #  delete example files
	rm -f $(distdir)/src/rc/COPYING							       #  license files are all 
	rm -f $(distdir)/src/rc/gpl-2.0.txt						       #  in the "copyright"
	ls $(distdir)/
	sed -i 's/<possible notes regarding this package - if none, delete this file>//g' $(distdir)/debian/README.Debian
	sed -i '4r README' $(distdir)/debian/README.Debian
	sed -i 's/\r//'    $(distdir)/debian/README.Debian
	@echo "-----------------------------------------------------------------------------"
	echo "This package was debianized by $(PACKAGER) <$(PACKAGE_BUGREPORT)> on" > $(COPYRIGHT)
	echo `date -R`                                                             >> $(COPYRIGHT)
	echo ""                                                                    >> $(COPYRIGHT)
	echo "It was downloaded from $(UPSTREAM_URL)"                              >> $(COPYRIGHT)
	echo ""                                                                    >> $(COPYRIGHT)
	echo "Upstream Author: $(AUTHOR) <$(PACKAGE_BUGREPORT)>"                   >> $(COPYRIGHT)
	echo ""                                                                    >> $(COPYRIGHT)
	echo "Copyright:  © 2011-" `date +"%Y"` "$(AUTHOR)"                        >> $(COPYRIGHT)
	echo ""                                                                    >> $(COPYRIGHT)
	echo "License:                                         "                   >> $(COPYRIGHT)
	echo ""                                                                    >> $(COPYRIGHT)
	cat $(top_builddir)/COPYING |                                              >> $(COPYRIGHT)
	echo ""
	echo "-----------------------------------------------------------------------------" >> $(COPYRIGHT)
	@echo "-----------------------------------------------------------------------------"
	@cat $(distdir)/debian/copyright
	@echo "-----------------------------------------------------------------------------"
	@cat $(distdir)/debian/control
	@echo "-----------------------------------------------------------------------------"
	@cat $(distdir)/debian/rules
	@echo "-----------------------------------------------------------------------------"

# local dist remove
local-distdir-remove:
	rm -rf $(BUNDLE)
	$(am__post_remove_distdir)

# OSX向けのバイナリ(テスト用)
osx-make-bin : local-distdir-remove $(BUNDLE) $(BUNDLE)/Contents/MacOS/$(PACKAGE_NAME) $(MACICON) $(MACPKGINFO) $(MACINFOPLIST) wxmac-dist-shared-lib

# OSX向けのバイナリ作成
osx-make-hook : local-distdir-remove $(BUNDLE) $(BUNDLE)/Contents/MacOS/$(PACKAGE_NAME) $(MACICON) $(MACPKGINFO) $(MACINFOPLIST) check-dylibbundler wxmac-dist-shared-lib package-osx-intel64-dmg

# Bundleその他の生成方法を書く
#  This builds the bundle's directory structure.
$(BUNDLE) :
	@echo "==== Building bundle directory structure ===="
	mkdir -p $(BUNDLE)/Contents
	mkdir -p $(BUNDLE)/Contents/MacOS
	mkdir -p $(BUNDLE)/Contents/Resources

#  This builds the executable right inside the bundle.
$(BUNDLE)/Contents/MacOS/$(PACKAGE_NAME):
	@echo "==== Copying executable ===="
	cp -f $(JANEEXE) $(BUNDLE)/Contents/MacOS/$(PACKAGE_NAME)
	cp -rf $(SCRIPTPATH) $(BUNDLE)/Contents/MacOS

#  This copies the icon file into the bundle.
$(MACICON):
	@echo "==== Copying icon file into bundle ===="
	cp -f $(ICONPATH) $(BUNDLE)/Contents/Resources/

#  This creates the Contents/PkgInfo file.
$(MACPKGINFO):
	@echo "==== Creating PkgInfo ===="
	touch $(MACPKGINFO)
	@/bin/echo -n "$(BUNDLEPACKAGE)$(BUNDLESIGNATURE)" > $(MACPKGINFO)

#  This creates the Contents/Info.plist file.
$(MACINFOPLIST):
	@echo "==== Creating Info.plist ===="
	touch $(MACINFOPLIST)
	@echo "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" >> $(MACINFOPLIST)
	@echo "<!DOCTYPE plist PUBLIC " >> $(MACINFOPLIST)
	@echo "\"-//Apple Computer//DTD PLIST 1.0//EN\" " >> $(MACINFOPLIST)
	@echo "\"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">" >> $(MACINFOPLIST)
	@echo "<plist version=\"1.0\">" >> $(MACINFOPLIST)
	@echo "<dict>" >> $(MACINFOPLIST)
	@echo "   <key>NSPrincipalClass</key>" >> $(MACINFOPLIST)
	@echo "   <string>NSApplication</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleDevelopmentRegion</key>" >> $(MACINFOPLIST)
	@echo "   <string>Japanese</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleExecutable</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(PACKAGE_NAME)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleIconFile</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(ICONFILE)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleName</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(PACKAGE_NAME)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleIdentifier</key>" >> $(MACINFOPLIST)
	@echo "   <string>com.$(COMPANY).$(PACKAGE_NAME)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleInfoDictionaryVersion</key>" >> $(MACINFOPLIST)
	@echo "   <string>6.0</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundlePackageType</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(BUNDLEPACKAGE)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleSignature</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(BUNDLESIGNATURE)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleVersion</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(PROGVER)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleShortVersionString</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(PROGVER)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleGetInfoString</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(PACKAGE_NAME), Version $(PROGVER), $(COMPANY)</string>" >> $(MACINFOPLIST)
	@echo "</dict>" >> $(MACINFOPLIST)
	@echo "</plist>" >> $(MACINFOPLIST)

# OSX向けにライブラリをBUNDLEに設定する
WXLIBPOSTFIX = *wx*@WX_VERSION_MAJOR@.@WX_VERSION_MINOR@.@WX_VERSION_MICRO@.dylib
WXLIBDIR     = `@WX_CONFIG_PATH@ --prefix`/lib
BINDIR	     = $(BUNDLE)/Contents/MacOS
LIBDEFDIR    = /usr/local/lib
JANEEXE      = $(top_builddir)/src/$(PACKAGE_NAME)
MACJANEEXE   = $(BUNDLE)/Contents/MacOS/$(PACKAGE_NAME)
DYLIBBUNDLER = dylibbundler

wxmac-dist-shared-lib:
	@echo "Copying and Patching JaneClone subdirectory libraries to " $(BINDIR)/lib " ..."
	mkdir $(BINDIR)/lib
	@for dylibs in `otool -L $(MACJANEEXE) | grep -o /.\*.dylib | sort -u `; do \
	   if [[ $$dylibs != /usr/lib/* ]]; then                                    \
	      echo "Copying " $$dylibs " to " $(BINDIR)/lib;                        \
	      cp -p $$dylibs $(BINDIR)/lib;                                         \
	      echo "Patching " $$dylibs " to " $(BINDIR)/lib;                       \
	      install_name_tool -change $$dylibs                                    \
	                        @executable_path/lib/`basename $$dylibs`            \
	                        $(MACJANEEXE);                                      \
	   fi                                                                       \
	done
	@echo "=====================================================================";
	@echo "End of JaneClone's dependency patching...                            ";
	@echo "=====================================================================";
	@for deplibs in `otool -L $(BINDIR)/lib/*.dylib | grep -o /.\*dylib | sort -u`; do   \
	   if [[ $$deplibs = /usr/local/lib/* ]] || [[ $$deplibs = /opt/local/lib/* ]]; then \
	      if [[ ! -e $(BINDIR)/lib/`basename $$deplibs` ]]; then \
	         echo "Copying " $$deplibs " to " $(BINDIR)/lib;     \
	         cp -p $$deplibs $(BINDIR)/lib;                      \
	      fi;                 \
	   fi;                    \
	done
	@echo "=====================================================================";
	@echo "End of JaneClone's dependency libraries copying...                   ";
	@echo "=====================================================================";
	@chmod +w $(BINDIR)/lib/*.dylib;
	@for file in `ls $(BINDIR)/lib/*.dylib` ; do \
	   otool -L $$file | egrep -v /\(usr/lib\|System\) | awk {'print $$1'} | while read line; \
	   do                 \
	      if [[ $$line != *: ]]; then \
		 echo "--> For " $$file; \
	         echo "Patching " $$line " to @executable_path/lib/" `basename $$line | sed -E 's/(^lib.*-)([0-9]\.[0-9]\.[0-9]).*/\1\2\.dylib/g'` ; \
	         install_name_tool -change $${line} @executable_path/lib/`basename $$line | sed -E 's/(^lib.*-)([0-9]\.[0-9]\.[0-9]).*/\1\2\.dylib/g'` $${file};  \
	      fi                          \
	   done                           \
	done

# OSX向けのインストーラ作成
package-osx-intel64-dmg:
	@echo "!!! Start make disk image file !!!";
	hdiutil create -ov -srcfolder $(BUNDLE) -fs HFS+ -format UDZO \
               -imagekey zlib-level=9 -volname "JaneClone.app" $(PACKAGE)-osx64-$(VERSION).dmg;
	@echo "!!! Finish make disk image file !!!";

# インストーラ作成のための準備
prepare-package: package-clean
	@echo 'create working directory...'
	mkdir $(top_builddir)/extras
	mkdir $(top_builddir)/extras/package
# check NSIS
check-nsis:
	@echo 'check NSIS...'
	@if makensis -VERSION >/dev/null 2>&1; then \
	    MAKENSIS="makensis"; \
	elif [ -x "/cygdrive/c/Program Files/NSIS/makensis" ]; then \
	    MAKENSIS="/cygdrive/c/Program\ Files/NSIS/makensis"; \
	elif [ -x "$(PROGRAMFILES)/NSIS/makensis" ]; then \
	    MAKENSIS="$(PROGRAMFILES)/NSIS/makensis"; \
	elif wine --version >/dev/null 2>&1; then \
	    MAKENSIS="wine C:/Program\ Files/NSIS/makensis.exe"; \
	else \
	    echo 'Error: cannot locate makensis tool'; exit 1; \
	fi; \
	echo 'NSIS is exist'

# check dylibbundler
check-dylibbundler:
	@echo 'check dylibbundler...'
	@if dylibbundler -VERSION >/dev/null 2>&1; then \
	    DYLIBBUNDLER="dylibbundler"; \
	elif [ -x "/usr/local/bin/dylibbundler" ]; then \
	    DYLIBBUNDLER="/usr/local/bin/dylibbundler"; \
	else \
	    echo 'Error: cannot locate dylibbundler'; exit 1; \
	fi; \
	echo 'dylibbundler is exist'


# 独自設定のクリーン用ターゲット
clean-local: package-clean local-distdir-remove
# パッケージディレクトリを削除するだけ
package-clean:
# rm packagedir and crate packagedir
	@echo 'delete working directory...'
	rm -rf $(top_builddir)/extras/package/
	rm -rf $(top_builddir)/extras/
