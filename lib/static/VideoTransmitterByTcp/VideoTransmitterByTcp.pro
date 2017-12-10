#-------------------------------------------------
#
# Project created by QtCreator 2017-12-10T09:52:15
#
#-------------------------------------------------

QT       += widgets network

QT       -= gui

TARGET = VideoTransmitterByTcp
TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++11

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
        VideoTransmitterByTcp.cpp

HEADERS += \
        VideoTransmitterByTcp.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}

win32 {
    LIBS += -LC:/opencv2/opencv/build/x64/vc14/lib/*
    INCLUDEPATH += C:/opencv2/opencv/build/include
    DEPENDPATH += C:/opencv2/opencv/build/include
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ImageSerialization/release/ -lImageSerialization
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ImageSerialization/debug/ -lImageSerialization
else:unix:!macx: LIBS += -L$$OUT_PWD/../ImageSerialization/ -lImageSerialization

INCLUDEPATH += $$PWD/../ImageSerialization
DEPENDPATH += $$PWD/../ImageSerialization

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageSerialization/release/libImageSerialization.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageSerialization/debug/libImageSerialization.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageSerialization/release/ImageSerialization.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageSerialization/debug/ImageSerialization.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../ImageSerialization/libImageSerialization.a
