#-------------------------------------------------
#
# Project created by QtCreator 2017-11-11T14:48:37
#
#-------------------------------------------------

QT       += core network widgets

QT       -= gui

TARGET = VideoReceiver
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

SOURCES += VideoReceiver.cpp

HEADERS += VideoReceiver.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}

win32 { LIBS += -L$$PWD/../../dependencies/lib/ -lopencv_core2413 \
    -lopencv_highgui2413 \
    -lopencv_imgproc2413

    INCLUDEPATH += $$PWD/../../../dependencies/include
    DEPENDPATH += $$PWD/../../../dependencies/include
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
