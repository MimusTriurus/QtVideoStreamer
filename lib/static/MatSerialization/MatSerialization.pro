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

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}

win32 {
    include(../../../config.pri)
    LIBS += $$OPENCV_LIBS_PATH $$OPENCV_LIB_CORE \
    $$OPENCV_LIB_IMGPROC \
    $$OPENCV_LIB_HIGHGUI

    INCLUDEPATH += $$OPENCV_INCLUDEPATH
    DEPENDPATH += $$OPENCV_DEPENDPATH
}
