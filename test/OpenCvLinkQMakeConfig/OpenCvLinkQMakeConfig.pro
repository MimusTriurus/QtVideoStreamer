QT += core
QT -= gui

TARGET = OpenCvLinkQMakeConfig
CONFIG += console
CONFIG -= app_bundle

DESTDIR = ../../bin

TEMPLATE = app

SOURCES += main.cpp

win32 {
    include( ../../config/opencv_conf.pri )
    LIBS += $$OPENCV_LIBS_PATH
    $$OPENCV_LIB_CORE

    INCLUDEPATH += $$OPENCV_INCLUDEPATH
    DEPENDPATH += $$OPENCV_DEPENDPATH
}

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}
