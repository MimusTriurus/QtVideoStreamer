#-------------------------------------------------
#
# Project created by QtCreator 2018-01-01T14:02:18
#
#-------------------------------------------------

QT       -= gui

TARGET = MatSerialization
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

SOURCES += MatSerialization.cpp

HEADERS += MatSerialization.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

include(../../../config.pri)
