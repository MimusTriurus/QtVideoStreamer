#-------------------------------------------------
#
# Project created by QtCreator 2017-11-11T15:22:25
#
#-------------------------------------------------

QT       += core gui network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QImgTransmitterTest
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    FrameWindow.cpp

HEADERS  += MainWindow.h \
    FrameWindow.h

FORMS    += MainWindow.ui

DESTDIR = ../../bin

MOC_DIR = moc

OBJECTS_DIR = obj

CONFIG += c++11

############################ ImageSerialization ################################
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/ImageSerialization/release/ -lImageSerialization
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/ImageSerialization/debug/ -lImageSerialization
else:unix:!macx: LIBS += -L$$OUT_PWD/../../lib/static/ImageSerialization/ -lImageSerialization

INCLUDEPATH += $$PWD/../../lib/static/ImageSerialization
DEPENDPATH += $$PWD/../../lib/static/ImageSerialization

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/ImageSerialization/release/libImageSerialization.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/ImageSerialization/debug/libImageSerialization.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/ImageSerialization/release/ImageSerialization.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/ImageSerialization/debug/ImageSerialization.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/ImageSerialization/libImageSerialization.a
############################ QVideoCapture #####################################
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
############################ VideoTransmitter ##################################
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
