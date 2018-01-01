#-------------------------------------------------
#
# Project created by QtCreator 2017-11-11T14:48:04
#
#-------------------------------------------------

QT       += core gui network

TARGET = VideoTransmitter
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

SOURCES += VideoTransmitter.cpp

HEADERS += VideoTransmitter.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
