#-------------------------------------------------
#
# Project created by QtCreator 2017-12-31T16:10:11
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = QCameraTest
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    CameraFrameGrabber.cpp

HEADERS  += MainWindow.h \
    CameraFrameGrabber.h

FORMS    += MainWindow.ui
