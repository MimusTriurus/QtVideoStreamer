#-------------------------------------------------
#
# Project created by QtCreator 2017-11-11T12:54:37
#
#-------------------------------------------------
QT       += core widgets
QT       -= gui

TARGET = VideoCapture
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

SOURCES += \
    Capture.cpp

HEADERS += \
    Capture.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

CONFIG += link_pkgconfig
PKGCONFIG += opencv
