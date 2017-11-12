#-------------------------------------------------
#
# Project created by QtCreator 2017-11-11T13:04:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VideoCaptureTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += c++11

CONFIG += link_pkgconfig
PKGCONFIG += opencv

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/VideoCapture/release/ -lVideoCapture
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/VideoCapture/debug/ -lVideoCapture
else:unix:!macx: LIBS += -L$$OUT_PWD/../../lib/static/VideoCapture/ -lVideoCapture

INCLUDEPATH += $$PWD/../../lib/static/VideoCapture
DEPENDPATH += $$PWD/../../lib/static/VideoCapture

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoCapture/release/libVideoCapture.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoCapture/debug/libVideoCapture.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoCapture/release/VideoCapture.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoCapture/debug/VideoCapture.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoCapture/libVideoCapture.a
