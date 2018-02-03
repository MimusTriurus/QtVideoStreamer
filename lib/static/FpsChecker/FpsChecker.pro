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

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}

win32 {
    include(../../config.pri)
    LIBS += $$OPENCV_LIBS_PATH $$OPENCV_LIB_CORE \
    $$OPENCV_LIB_IMGPROC \
    $$OPENCV_LIB_HIGHGUI

    INCLUDEPATH += $$OPENCV_INCLUDEPATH
    DEPENDPATH += $$OPENCV_DEPENDPATH
}
