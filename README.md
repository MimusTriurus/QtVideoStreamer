# QtVideoStreamer
Simple Qt video streamer
____________________________________________________________________________________________________________
ImageSerialization  - static library of serialization/deserialization QImage

MatSerialization    - static library of serialization/deserialization cv::Mat

CvVideoCapture      - static library of image capture from camera by means of OpenCV

QVideoCapture       - static library of image capture from camera by means of Qt (QCamera)

VideoTransmitter    - static library of image transmitting from camera to application-receiver over network 

VideoReceiver       - static library of image receiving over network from application-transmitter 

CvTransmitterTest   - test application – image transmitter from camera by means of OpenCV

CvReceiverTest      - test application – image receiver from camera by means of OpenCV

QImgTransmitterTest - test application – image transmitter from camera by means of Qt (QCamera)
QImgReceiverTest    - test application – image receiver from camera by means of Qt (QCamera)
_____________________________________________________________________________________________________________

System requirements:
----------------------------------------------
1. ОС: Windows, Linux;
2. Qt 5.5.1 or higher;
3. OpenCV 2.4;
4. Compiler with support for c++ 11;
5. Web-camera.

Setup for Windows:
----------------------------------------------
1. Clone the repository;
2. If required, specify in file config.pri the path to directory of opencv libraries, the name of the libraries and the path to header files (by default  config.pri has the link to “dependencies” of the project with  binary files of opencv2 VC14);
3. Assemble the project.

Setup for Linux:
----------------------------------------------
1. Clone the repository;
2. Launch the console and run command “sudo apt-get install libopencv-dev” and “ sudo apt-get install qtmultimedia5-dev”;
3. Assemble the project.

Compiled applications are located in folder “bin”
