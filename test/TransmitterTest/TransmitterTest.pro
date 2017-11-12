#-------------------------------------------------
#
# Project created by QtCreator 2017-11-11T15:22:25
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TransmitterTest
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp

HEADERS  += MainWindow.h

FORMS    += MainWindow.ui

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/VideoTransmitter/release/ -lVideoTransmitter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/VideoTransmitter/debug/ -lVideoTransmitter
else:unix:!macx: LIBS += -L$$OUT_PWD/../../lib/static/VideoTransmitter/ -lVideoTransmitter

INCLUDEPATH += $$PWD/../../lib/static/VideoTransmitter
DEPENDPATH += $$PWD/../../lib/static/VideoTransmitter

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoTransmitter/release/libVideoTransmitter.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoTransmitter/debug/libVideoTransmitter.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoTransmitter/release/VideoTransmitter.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoTransmitter/debug/VideoTransmitter.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoTransmitter/libVideoTransmitter.a

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/VideoReciever/release/ -lVideoReciever
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/VideoReciever/debug/ -lVideoReciever
else:unix: LIBS += -L$$OUT_PWD/../../lib/static/VideoReciever/ -lVideoReciever

INCLUDEPATH += $$PWD/../../lib/static/VideoReciever
DEPENDPATH += $$PWD/../../lib/static/VideoReciever

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoReciever/release/libVideoReciever.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoReciever/debug/libVideoReciever.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoReciever/release/VideoReciever.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoReciever/debug/VideoReciever.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/VideoReciever/libVideoReciever.a
