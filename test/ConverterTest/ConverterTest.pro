QT += core
QT -= gui

TARGET = ConverterTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/Converter/release/ -lConverter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/Converter/debug/ -lConverter
else:unix:!macx: LIBS += -L$$OUT_PWD/../../lib/static/Converter/ -lConverter

INCLUDEPATH += $$PWD/../../lib/static/Converter
DEPENDPATH += $$PWD/../../lib/static/Converter

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/Converter/release/libConverter.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/Converter/debug/libConverter.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/Converter/release/Converter.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/Converter/debug/Converter.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/Converter/libConverter.a
