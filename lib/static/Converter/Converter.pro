#-------------------------------------------------
#
# Project created by QtCreator 2017-11-11T20:02:54
#
#-------------------------------------------------

QT       -= gui

TARGET = Converter
TEMPLATE = lib
CONFIG += staticlib

SOURCES += Converter.cpp

HEADERS += Converter.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
