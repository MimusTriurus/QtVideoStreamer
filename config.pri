#глобальные переменные для линковки библиотек opencv на Windows

equals(QT_ARCH, i386) {
    #message("32-bit")
    OPENCV_LIBS_PATH   = -L$$PWD/dependencies/lib/x86/
}

equals(QT_ARCH, "x86_64") {
    #message("64-bit")
    OPENCV_LIBS_PATH   = -L$$PWD/dependencies/lib/x64/
}


OPENCV_LIB_CORE    = -lopencv_core2413
OPENCV_LIB_IMGPROC = -lopencv_imgproc2413
OPENCV_LIB_HIGHGUI = -lopencv_highgui2413

OPENCV_INCLUDEPATH = $$PWD/dependencies/include
OPENCV_DEPENDPATH  = $$PWD/dependencies/include
