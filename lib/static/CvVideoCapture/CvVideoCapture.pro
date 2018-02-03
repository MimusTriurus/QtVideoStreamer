#-------------------------------------------------
#
# Project created by QtCreator 2017-11-11T12:54:37
#
#-------------------------------------------------
QT       += core widgets
QT       -= gui

TARGET = CvVideoCapture
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

include( ../../../config.pri )
