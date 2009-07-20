TARGET = QDetroBro
QT += core \
    gui \
    webkit \
    network
HEADERS += FlickCharm.h \
    QDetroBro.h
SOURCES += FlickCharm.cpp \
    main.cpp \
    QDetroBro.cpp
FORMS += QDetroBro.ui
RESOURCES += 
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
