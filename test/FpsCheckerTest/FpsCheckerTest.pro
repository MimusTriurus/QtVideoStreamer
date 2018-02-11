QT += core
QT -= gui

TARGET = FpsCheckerTest
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

DESTDIR = ../../bin

include(../../config.pri)

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
