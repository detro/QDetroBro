TARGET = QDetroBro
TEMPLATE = app
VERSION = 0.2.1 
QT += network \
    webkit
HEADERS += NavigationBarWidget.h \
    ChaseWidget.h \
    AddressBarWidget.h \
    FlickCharm.h \
    QDetroBro.h
SOURCES += NavigationBarWidget.cpp \
    ChaseWidget.cpp \
    AddressBarWidget.cpp \
    FlickCharm.cpp \
    main.cpp \
    QDetroBro.cpp
FORMS += NavigationBarWidget.ui \
    AddressBarWidget.ui
RESOURCES += images.qrc
symbian { 
    HEADERS += sym_iap_util.h
    SOURCES += QDetroBro_reg.rss
    LIBS += -lesock \
        -lconnmon
    TARGET.CAPABILITY = NetworkServices
    TARGET.EPOCHEAPSIZE = 0x20000 \
        0x2000000
    TARGET.UID3 = 0xE55B478A
}
