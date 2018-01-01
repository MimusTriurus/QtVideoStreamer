#-------------------------------------------------
#
# Project created by QtCreator 2017-11-11T15:22:25
#
#-------------------------------------------------

QT       += core gui network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CvTransmitterTest
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
############################# MatSerialization #################################
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
############################# VideoCapture ################################
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
