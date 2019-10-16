TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        banco.cpp \
        main.cpp \
        usuario.cpp

DISTFILES += \
    datos \
    sudo

HEADERS += \
    banco.h \
    usuario.h
