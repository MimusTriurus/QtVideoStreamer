#-------------------------------------------------
#
# Project created by QtCreator 2017-11-11T13:04:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VideoCaptureTest
TEMPLATE = app

CONFIG += c++11

DESTDIR = ../../bin

MOC_DIR = moc

OBJECTS_DIR = obj

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

include(../../config.pri)

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/CvVideoCapture/release/ -lCvVideoCapture
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/CvVideoCapture/debug/ -lCvVideoCapture
else:unix:!macx: LIBS += -L$$OUT_PWD/../../lib/static/CvVideoCapture/ -lCvVideoCapture

INCLUDEPATH += $$PWD/../../lib/static/CvVideoCapture
DEPENDPATH += $$PWD/../../lib/static/CvVideoCapture

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/CvVideoCapture/release/libCvVideoCapture.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/CvVideoCapture/debug/libCvVideoCapture.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/CvVideoCapture/release/CvVideoCapture.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/CvVideoCapture/debug/CvVideoCapture.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/CvVideoCapture/libCvVideoCapture.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/FpsChecker/release/ -lFpsChecker
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/FpsChecker/debug/ -lFpsChecker
else:unix:!macx: LIBS += -L$$OUT_PWD/../../lib/static/FpsChecker/ -lFpsChecker

INCLUDEPATH += $$PWD/../../lib/static/FpsChecker
DEPENDPATH += $$PWD/../../lib/static/FpsChecker

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/FpsChecker/release/libFpsChecker.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/FpsChecker/debug/libFpsChecker.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/FpsChecker/release/FpsChecker.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/FpsChecker/debug/FpsChecker.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/FpsChecker/libFpsChecker.a
