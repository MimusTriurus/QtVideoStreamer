#-------------------------------------------------
#
# Project created by QtCreator 2017-11-25T21:28:23
#
#-------------------------------------------------

QT       += core gui network

DESTDIR = ../../bin

MOC_DIR = moc

OBJECTS_DIR = obj

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CvReceiverTest
TEMPLATE = app

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

include(../../config.pri)

#################################### VideoReceiver #############################
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/VideoReceiver/release/ -lVideoReceiver
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/VideoReceiver/debug/ -lVideoReceiver
else:unix:!macx: LIBS += -L$$OUT_PWD/../../lib/static/VideoReceiver/ -lVideoReceiver

INCLUDEPATH += $$PWD/../../lib/static/VideoReceiver
DEPENDPATH += $$PWD/../../lib/static/VideoReceiver

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoReceiver/release/libVideoReceiver.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoReceiver/debug/libVideoReceiver.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoReceiver/release/VideoReceiver.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoReceiver/debug/VideoReceiver.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoReceiver/libVideoReceiver.a
#################################### MatSerialization ##########################
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/MatSerialization/release/ -lMatSerialization
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/MatSerialization/debug/ -lMatSerialization
else:unix:!macx: LIBS += -L$$OUT_PWD/../../lib/static/MatSerialization/ -lMatSerialization

INCLUDEPATH += $$PWD/../../lib/static/MatSerialization
DEPENDPATH += $$PWD/../../lib/static/MatSerialization

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/MatSerialization/release/libMatSerialization.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/MatSerialization/debug/libMatSerialization.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/MatSerialization/release/MatSerialization.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/MatSerialization/debug/MatSerialization.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/MatSerialization/libMatSerialization.a
################################### Fps checker ################################
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
