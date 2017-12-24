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

DESTDIR = ../../bin

MOC_DIR = moc

OBJECTS_DIR = obj

CONFIG += c++11

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}

win32 {
    include(../../config.pri)
    LIBS += $$OPENCV_LIBS_PATH $$OPENCV_LIB_CORE \
    $$OPENCV_LIB_IMGPROC \
    $$OPENCV_LIB_HIGHGUI

    INCLUDEPATH += $$OPENCV_INCLUDEPATH
    DEPENDPATH += $$OPENCV_DEPENDPATH
}

############################# VideoCapture ################################
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
############################# VideoTransmitter #################################
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
