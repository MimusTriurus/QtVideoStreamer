#-------------------------------------------------
#
# Project created by QtCreator 2017-11-19T18:25:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenCvTest
TEMPLATE = app

DESTDIR = ../../bin

MOC_DIR = moc

OBJECTS_DIR = obj

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        MainWindow.cpp

HEADERS += \
        MainWindow.h

FORMS += \
        MainWindow.ui

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}

win32 { LIBS += -L$$PWD/../../dependencies/lib/ -lopencv_core2413 \
    -lopencv_imgproc2413 \
    -lopencv_highgui2413

    INCLUDEPATH += $$PWD/../../dependencies/include
    DEPENDPATH += $$PWD/../../dependencies/include
}
