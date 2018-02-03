#-------------------------------------------------
#
# Project created by QtCreator 2018-02-03T22:49:39
#
#-------------------------------------------------

QT       -= gui

TARGET = FpsChecker
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

SOURCES += FpsChecker.cpp

HEADERS += FpsChecker.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

include(../../config.pri)
