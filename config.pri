#глобальные переменные для линковки библиотек opencv на Windows

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}

win32 {
    OPENCV_INCLUDEPATH = $$PWD/dependencies/include
    OPENCV_DEPENDPATH  = $$PWD/dependencies/include

    equals(QT_ARCH, i386) {
        message("Win 32-bit unsupported yet")
        OPENCV_LIBS_PATH   = -L$$PWD/dependencies/lib/x86/
    }

    equals(QT_ARCH, "x86_64") {
        #message("64-bit")
        OPENCV_LIBS_PATH   = -L$$PWD/dependencies/lib/x64/
    }
    # версия opencv
    LIBS += $$OPENCV_LIBS_PATH -lopencv_world310

    INCLUDEPATH += $$OPENCV_INCLUDEPATH
    DEPENDPATH += $$OPENCV_DEPENDPATH
}
