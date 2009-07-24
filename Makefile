# ==============================================================================
# Generated by qmake (2.01a) (Qt 4.5.2-tower) on: Fri 24. Jul 16:50:44 2009
# This file is generated by qmake and should not be modified by the
# user.
#  Name        : Makefile
#  Description : Wrapper Makefile for calling Symbian build tools
#
# ==============================================================================


QMAKE             = c:\Qt\4.5.2-tower\bin\qmake
DEL_FILE          = rm
DEL_DIR           = rmdir
XCOPY             = xcopy /d /f /h /r /y /i
ABLD              = ABLD.BAT
DEBUG_PLATFORMS   = winscw gcce armv5 armv6
RELEASE_PLATFORMS = gcce armv5 armv6
MAKE              = make

ifeq (WINS,$(findstring WINS, $(PLATFORM)))
ZDIR=$(EPOCROOT)epoc32\release\$(PLATFORM)\$(CFG)\Z
else
ZDIR=$(EPOCROOT)epoc32\data\z
endif

DEFINES	 = -DSYMBIAN -DUNICODE -DQT_KEYPAD_NAVIGATION -D_WCHAR_T_DECLARED -DQT_WEBKIT_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB
INCPATH	 =  -I"C:/Qt/4.5.2-tower/include/QtCore" -I"C:/Qt/4.5.2-tower/include/QtCore/tmp" -I"C:/Qt/4.5.2-tower/include/QtNetwork" -I"C:/Qt/4.5.2-tower/include/QtNetwork/tmp" -I"C:/Qt/4.5.2-tower/include/QtGui" -I"C:/Qt/4.5.2-tower/include/QtGui/tmp" -I"C:/Qt/4.5.2-tower/include/QtWebKit" -I"C:/Qt/4.5.2-tower/include/QtWebKit/tmp" -I"C:/Qt/4.5.2-tower/include" -I"C:/Qt/4.5.2-tower/include/tmp" -I"C:/Qt/4.5.2-tower/mkspecs/common/symbian" -I"C:/Qt/4.5.2-tower/mkspecs/common/symbian/tmp" -I"C:/S60/devices/S60_5th_Edition_SDK_v1.0/epoc32/include" -I"C:/Symbian/Carbide/workspace/QDetroBro" -I"C:/Symbian/Carbide/workspace/QDetroBro/tmp" -I"C:/S60/devices/S60_5th_Edition_SDK_v1.0/epoc32/include/stdapis" -I"C:/S60/devices/S60_5th_Edition_SDK_v1.0/epoc32/include/stdapis/sys" -I"C:/S60/devices/S60_5th_Edition_SDK_v1.0/epoc32/include/stdapis/stlport"
first: default
default: debug-winscw
all: debug release

qmake:
	$(QMAKE) -spec symbian-abld -o "bld.inf" "C:/Symbian/Carbide/workspace/QDetroBro/QDetroBro.pro"

bld.inf:
	$(QMAKE)

$(ABLD): bld.inf
	bldmake bldfiles

debug: $(ABLD)
	$(ABLD) build winscw udeb
	$(ABLD) build gcce udeb
	$(ABLD) build armv5 udeb
	$(ABLD) build armv6 udeb

release: $(ABLD)
	$(ABLD) build gcce urel
	$(ABLD) build armv5 urel
	$(ABLD) build armv6 urel

debug-winscw: $(ABLD)
	$(ABLD) build winscw udeb
debug-gcce: $(ABLD)
	$(ABLD) build gcce udeb
debug-armv5: $(ABLD)
	$(ABLD) build armv5 udeb
debug-armv6: $(ABLD)
	$(ABLD) build armv6 udeb
release-gcce: $(ABLD)
	$(ABLD) build gcce urel
release-armv5: $(ABLD)
	$(ABLD) build armv5 urel
release-armv6: $(ABLD)
	$(ABLD) build armv6 urel

export: $(ABLD)
	$(ABLD) export

cleanexport: $(ABLD)
	$(ABLD) cleanexport

C:\Qt\4.5.2-tower\bin\moc.exe:
	(cd $(QTDIR)/src/tools/moc && $(MAKE))

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_NavigationBarWidget.cpp moc_ChaseWidget.cpp moc_AddressBarWidget.cpp moc_FlickCharm.cpp moc_QDetroBro.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_NavigationBarWidget.cpp moc_ChaseWidget.cpp moc_AddressBarWidget.cpp moc_FlickCharm.cpp moc_QDetroBro.cpp 2> NUL
moc_NavigationBarWidget.cpp: ui_NavigationBarWidget.h \
		NavigationBarWidget.h \
		..\..\..\..\Qt\4.5.2-tower\bin\moc.exe
	C:\Qt\4.5.2-tower\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN NavigationBarWidget.h -o moc_NavigationBarWidget.cpp

moc_ChaseWidget.cpp: ChaseWidget.h \
		..\..\..\..\Qt\4.5.2-tower\bin\moc.exe
	C:\Qt\4.5.2-tower\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN ChaseWidget.h -o moc_ChaseWidget.cpp

moc_AddressBarWidget.cpp: ui_AddressBarWidget.h \
		chasewidget.h \
		AddressBarWidget.h \
		..\..\..\..\Qt\4.5.2-tower\bin\moc.exe
	C:\Qt\4.5.2-tower\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN AddressBarWidget.h -o moc_AddressBarWidget.cpp

moc_FlickCharm.cpp: FlickCharm.h \
		..\..\..\..\Qt\4.5.2-tower\bin\moc.exe
	C:\Qt\4.5.2-tower\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN FlickCharm.h -o moc_FlickCharm.cpp

moc_QDetroBro.cpp: AddressBarWidget.h \
		ui_AddressBarWidget.h \
		chasewidget.h \
		NavigationBarWidget.h \
		ui_NavigationBarWidget.h \
		QDetroBro.h \
		..\..\..\..\Qt\4.5.2-tower\bin\moc.exe
	C:\Qt\4.5.2-tower\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN QDetroBro.h -o moc_QDetroBro.cpp

compiler_rcc_make_all: qrc_images.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_images.cpp 2> NUL
qrc_images.cpp: images.qrc
	c:\Qt\4.5.2-tower\bin\rcc -name images images.qrc -o qrc_images.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp 2> NUL
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_NavigationBarWidget.h ui_AddressBarWidget.h
compiler_uic_clean:
	-$(DEL_FILE) ui_NavigationBarWidget.h ui_AddressBarWidget.h 2> NUL
ui_NavigationBarWidget.h: NavigationBarWidget.ui
	c:\Qt\4.5.2-tower\bin\uic.exe NavigationBarWidget.ui -o ui_NavigationBarWidget.h

ui_AddressBarWidget.h: AddressBarWidget.ui \
		chasewidget.h
	c:\Qt\4.5.2-tower\bin\uic.exe AddressBarWidget.ui -o ui_AddressBarWidget.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

create_temps:
	-@ if NOT EXIST "C:\Qt\4.5.2-tower\include\QtCore\tmp" mkdir "C:\Qt\4.5.2-tower\include\QtCore\tmp"
	-@ if NOT EXIST "C:\Qt\4.5.2-tower\include\QtCore\tmp\tmp" mkdir "C:\Qt\4.5.2-tower\include\QtCore\tmp\tmp"
	-@ if NOT EXIST "C:\Qt\4.5.2-tower\include\QtNetwork\tmp" mkdir "C:\Qt\4.5.2-tower\include\QtNetwork\tmp"
	-@ if NOT EXIST "C:\Qt\4.5.2-tower\include\QtNetwork\tmp\tmp" mkdir "C:\Qt\4.5.2-tower\include\QtNetwork\tmp\tmp"
	-@ if NOT EXIST "C:\Qt\4.5.2-tower\include\QtGui\tmp" mkdir "C:\Qt\4.5.2-tower\include\QtGui\tmp"
	-@ if NOT EXIST "C:\Qt\4.5.2-tower\include\QtGui\tmp\tmp" mkdir "C:\Qt\4.5.2-tower\include\QtGui\tmp\tmp"
	-@ if NOT EXIST "C:\Qt\4.5.2-tower\include\QtWebKit\tmp" mkdir "C:\Qt\4.5.2-tower\include\QtWebKit\tmp"
	-@ if NOT EXIST "C:\Qt\4.5.2-tower\include\QtWebKit\tmp\tmp" mkdir "C:\Qt\4.5.2-tower\include\QtWebKit\tmp\tmp"
	-@ if NOT EXIST "C:\Qt\4.5.2-tower\include\tmp" mkdir "C:\Qt\4.5.2-tower\include\tmp"
	-@ if NOT EXIST "C:\Qt\4.5.2-tower\include\tmp\tmp" mkdir "C:\Qt\4.5.2-tower\include\tmp\tmp"
	-@ if NOT EXIST "C:\Qt\4.5.2-tower\mkspecs\common\symbian\tmp" mkdir "C:\Qt\4.5.2-tower\mkspecs\common\symbian\tmp"
	-@ if NOT EXIST "C:\Qt\4.5.2-tower\mkspecs\common\symbian\tmp\tmp" mkdir "C:\Qt\4.5.2-tower\mkspecs\common\symbian\tmp\tmp"
	-@ if NOT EXIST "C:\S60\devices\S60_5th_Edition_SDK_v1.0\epoc32\include\tmp" mkdir "C:\S60\devices\S60_5th_Edition_SDK_v1.0\epoc32\include\tmp"
	-@ if NOT EXIST "C:\Symbian\Carbide\workspace\QDetroBro\tmp" mkdir "C:\Symbian\Carbide\workspace\QDetroBro\tmp"
	-@ if NOT EXIST "C:\Symbian\Carbide\workspace\QDetroBro\tmp\tmp" mkdir "C:\Symbian\Carbide\workspace\QDetroBro\tmp\tmp"
	-@ if NOT EXIST "C:\S60\devices\S60_5th_Edition_SDK_v1.0\epoc32\include\stdapis\tmp" mkdir "C:\S60\devices\S60_5th_Edition_SDK_v1.0\epoc32\include\stdapis\tmp"
	-@ if NOT EXIST "C:\S60\devices\S60_5th_Edition_SDK_v1.0\epoc32\include\stdapis\sys\tmp" mkdir "C:\S60\devices\S60_5th_Edition_SDK_v1.0\epoc32\include\stdapis\sys\tmp"
	-@ if NOT EXIST "C:\S60\devices\S60_5th_Edition_SDK_v1.0\epoc32\include\stdapis\stlport\tmp" mkdir "C:\S60\devices\S60_5th_Edition_SDK_v1.0\epoc32\include\stdapis\stlport\tmp"

extension_clean: compiler_clean
	-@ if EXIST "C:\Qt\4.5.2-tower\include\QtCore\tmp" rmdir  /S /Q  "C:\Qt\4.5.2-tower\include\QtCore\tmp"
	-@ if EXIST "C:\Qt\4.5.2-tower\include\QtCore\tmp\tmp" rmdir  /S /Q  "C:\Qt\4.5.2-tower\include\QtCore\tmp\tmp"
	-@ if EXIST "C:\Qt\4.5.2-tower\include\QtNetwork\tmp" rmdir  /S /Q  "C:\Qt\4.5.2-tower\include\QtNetwork\tmp"
	-@ if EXIST "C:\Qt\4.5.2-tower\include\QtNetwork\tmp\tmp" rmdir  /S /Q  "C:\Qt\4.5.2-tower\include\QtNetwork\tmp\tmp"
	-@ if EXIST "C:\Qt\4.5.2-tower\include\QtGui\tmp" rmdir  /S /Q  "C:\Qt\4.5.2-tower\include\QtGui\tmp"
	-@ if EXIST "C:\Qt\4.5.2-tower\include\QtGui\tmp\tmp" rmdir  /S /Q  "C:\Qt\4.5.2-tower\include\QtGui\tmp\tmp"
	-@ if EXIST "C:\Qt\4.5.2-tower\include\QtWebKit\tmp" rmdir  /S /Q  "C:\Qt\4.5.2-tower\include\QtWebKit\tmp"
	-@ if EXIST "C:\Qt\4.5.2-tower\include\QtWebKit\tmp\tmp" rmdir  /S /Q  "C:\Qt\4.5.2-tower\include\QtWebKit\tmp\tmp"
	-@ if EXIST "C:\Qt\4.5.2-tower\include\tmp" rmdir  /S /Q  "C:\Qt\4.5.2-tower\include\tmp"
	-@ if EXIST "C:\Qt\4.5.2-tower\include\tmp\tmp" rmdir  /S /Q  "C:\Qt\4.5.2-tower\include\tmp\tmp"
	-@ if EXIST "C:\Qt\4.5.2-tower\mkspecs\common\symbian\tmp" rmdir  /S /Q  "C:\Qt\4.5.2-tower\mkspecs\common\symbian\tmp"
	-@ if EXIST "C:\Qt\4.5.2-tower\mkspecs\common\symbian\tmp\tmp" rmdir  /S /Q  "C:\Qt\4.5.2-tower\mkspecs\common\symbian\tmp\tmp"
	-@ if EXIST "C:\S60\devices\S60_5th_Edition_SDK_v1.0\epoc32\include\tmp" rmdir  /S /Q  "C:\S60\devices\S60_5th_Edition_SDK_v1.0\epoc32\include\tmp"
	-@ if EXIST "C:\Symbian\Carbide\workspace\QDetroBro\tmp" rmdir  /S /Q  "C:\Symbian\Carbide\workspace\QDetroBro\tmp"
	-@ if EXIST "C:\Symbian\Carbide\workspace\QDetroBro\tmp\tmp" rmdir  /S /Q  "C:\Symbian\Carbide\workspace\QDetroBro\tmp\tmp"
	-@ if EXIST "C:\S60\devices\S60_5th_Edition_SDK_v1.0\epoc32\include\stdapis\tmp" rmdir  /S /Q  "C:\S60\devices\S60_5th_Edition_SDK_v1.0\epoc32\include\stdapis\tmp"
	-@ if EXIST "C:\S60\devices\S60_5th_Edition_SDK_v1.0\epoc32\include\stdapis\sys\tmp" rmdir  /S /Q  "C:\S60\devices\S60_5th_Edition_SDK_v1.0\epoc32\include\stdapis\sys\tmp"
	-@ if EXIST "C:\S60\devices\S60_5th_Edition_SDK_v1.0\epoc32\include\stdapis\stlport\tmp" rmdir  /S /Q  "C:\S60\devices\S60_5th_Edition_SDK_v1.0\epoc32\include\stdapis\stlport\tmp"

pre_targetdeps: \
	generated_sources \
	all_source_deps \
	ui_NavigationBarWidget.h \
	ui_AddressBarWidget.h

generated_sources: \
	moc_NavigationBarWidget.cpp \
	moc_ChaseWidget.cpp \
	moc_AddressBarWidget.cpp \
	moc_FlickCharm.cpp \
	moc_QDetroBro.cpp \
	qrc_images.cpp

all_source_deps: \
	NavigationBarWidget.h \
	ui_NavigationBarWidget.h \
	ChaseWidget.h \
	addressbarwidget.h \
	ui_AddressBarWidget.h \
	chasewidget.h \
	flickcharm.h \
	QDetroBro.h \
	AddressBarWidget.h \
	sym_iap_util.h \
	FlickCharm.h

finalize:

winscw_deployment:

winscw_deployment_clean:

dodistclean:
	-@ if EXIST "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro_gcce_udeb.pkg" $(DEL_FILE)  "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro_gcce_udeb.pkg"
	-@ if EXIST "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro_gcce_urel.pkg" $(DEL_FILE)  "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro_gcce_urel.pkg"
	-@ if EXIST "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro_armv5_udeb.pkg" $(DEL_FILE)  "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro_armv5_udeb.pkg"
	-@ if EXIST "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro_armv5_urel.pkg" $(DEL_FILE)  "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro_armv5_urel.pkg"
	-@ if EXIST "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro_armv6_udeb.pkg" $(DEL_FILE)  "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro_armv6_udeb.pkg"
	-@ if EXIST "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro_armv6_urel.pkg" $(DEL_FILE)  "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro_armv6_urel.pkg"
	-@ if EXIST "c:\Symbian\Carbide\workspace\QDetroBro\Makefile" $(DEL_FILE)  "c:\Symbian\Carbide\workspace\QDetroBro\Makefile"
	-@ if EXIST "c:\Symbian\Carbide\workspace\QDetroBro\Makefile_0xE55B478A.mk" $(DEL_FILE)  "c:\Symbian\Carbide\workspace\QDetroBro\Makefile_0xE55B478A.mk"
	-@ if EXIST "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro_0xE55B478A.mmp" $(DEL_FILE)  "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro_0xE55B478A.mmp"
	-@ if EXIST "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro_reg.rss" $(DEL_FILE)  "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro_reg.rss"
	-@ if EXIST "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro.rss" $(DEL_FILE)  "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro.rss"
	-@ if EXIST "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro.loc" $(DEL_FILE)  "c:\Symbian\Carbide\workspace\QDetroBro\QDetroBro.loc"
	-@ if EXIST "c:\Symbian\Carbide\workspace\QDetroBro\bld.inf" $(DEL_FILE)  "c:\Symbian\Carbide\workspace\QDetroBro\bld.inf"

distclean: clean dodistclean

clean: $(ABLD)
	-$(ABLD) reallyclean
	-bldmake clean

run:
	-call /S60/devices/S60_5th_Edition_SDK_v1.0/epoc32\release\winscw\udeb\QDetroBro.exe

