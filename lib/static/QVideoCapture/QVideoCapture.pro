s#-------------------------------------------------
#
# Project created by QtCreator 2018-01-01T13:05:00
#
#-------------------------------------------------

QT       += core widgets multimedia

QT       -= gui

TARGET = QVideoCapture
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

SOURCES += \
    CameraFrameGrabber.cpp \
    QVideoCapture.cpp

HEADERS += \
    CameraFrameGrabber.h \
    QVideoCapture.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
