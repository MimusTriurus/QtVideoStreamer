#-------------------------------------------------
#
# Project created by QtCreator 2017-12-31T16:10:11
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = QCameraTest
TEMPLATE = app

DESTDIR = ../../bin

SOURCES += main.cpp\
        MainWindow.cpp

HEADERS  += MainWindow.h

FORMS    += MainWindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/QVideoCapture/release/ -lQVideoCapture
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/QVideoCapture/debug/ -lQVideoCapture
else:unix:!macx: LIBS += -L$$OUT_PWD/../../lib/static/QVideoCapture/ -lQVideoCapture

INCLUDEPATH += $$PWD/../../lib/static/QVideoCapture
DEPENDPATH += $$PWD/../../lib/static/QVideoCapture

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/QVideoCapture/release/libQVideoCapture.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/QVideoCapture/debug/libQVideoCapture.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/QVideoCapture/release/QVideoCapture.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/QVideoCapture/debug/QVideoCapture.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/QVideoCapture/libQVideoCapture.a
