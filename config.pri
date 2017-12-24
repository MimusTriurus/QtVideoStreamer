#глобальные переменные для линковки библиотек opencv на Windows

OPENCV_LIBS_PATH   = -L$$PWD/dependencies/lib/
OPENCV_LIB_CORE    = -lopencv_core2413
OPENCV_LIB_IMGPROC = -lopencv_imgproc2413
OPENCV_LIB_HIGHGUI = -lopencv_highgui2413

OPENCV_INCLUDEPATH = $$PWD/dependencies/include
OPENCV_DEPENDPATH  = $$PWD/dependencies/include
