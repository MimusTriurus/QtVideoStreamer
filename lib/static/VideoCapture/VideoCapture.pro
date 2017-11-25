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

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}

win32 { LIBS += -L$$PWD/../../dependencies/lib/ -lopencv_core2413 \
    -lopencv_highgui2413 \
    -lopencv_imgproc2413

    INCLUDEPATH += $$PWD/../../../dependencies/include
    DEPENDPATH += $$PWD/../../../dependencies/include
}
