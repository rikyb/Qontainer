QT       += core gui widgets
TEMPLATE = app
TARGET = Qontainer
CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    Source/alcolico.cpp \
    Source/birra.cpp \
    Source/distillato.cpp \
    Source/fermentato.cpp \
    Source/gin.cpp \
    Source/rum.cpp \
    Source/tequila.cpp \
    Source/vino.cpp \
    GUI/basewindow.cpp \
    main.cpp \
    GUI/popup.cpp\
    GUI/searchw.cpp\

HEADERS += \
    Source/alcolico.h \
    Source/birra.h \
    Source/distillato.h \
    Source/fermentato.h \
    Source/gin.h \
    Source/rum.h \
    Source/tequila.h \
    Source/vino.h \
    Source/container.h\
    Source/deepptr.h\
    GUI/basewindow.h \
    GUI/popup.h\
    GUI/searchw.h\

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
