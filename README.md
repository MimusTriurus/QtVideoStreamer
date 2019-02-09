# QtVideoStreamer
Simple Qt video streamer
____________________________________________________________________________________________________________
MatSerialization    - static library of serialization/deserialization cv::Mat

CvVideoCapture      - static library of image capture from camera by means of OpenCV

VideoTransmitter    - static library of image transmitting from camera to application-receiver over network 

VideoReceiver       - static library of image receiving over network from application-transmitter 

FpsChecker			- static library of check fps

CvTransmitterTest   - test application – image transmitter from camera by means of OpenCV

CvReceiverTest      - test application – image receiver from camera by means of OpenCV

VideoCaptureTest	- test CvVideoCapture
_____________________________________________________________________________________________________________

System requirements:
----------------------------------------------
1. ОС: Windows, Linux;
2. Qt 5.5.1 or higher;
3. OpenCV 3 or higher;
4. Compiler with support for c++ 11;
5. Web-camera.

Setup for Windows:
----------------------------------------------
1. Clone the repository;
2. If required, specify in file config.pri the path to directory of opencv libraries, the name of the libraries and the path to header files (by default  config.pri has the link to “dependencies” of the project with  binary files of opencv3 VC12 x64);
3. Build the project.

Setup for Linux:
----------------------------------------------
1. Clone the repository;
2. Launch the console and run command “sudo apt-get install libopencv-dev”;
3. Build the project.

Compiled applications are located in folder “bin”

Remarks:
----------------------------------------------
OpenCV relies on the V4L2 (Video for Linux) module, so try adding the following line at the bottom of the file /etc/modules and rebooting your Raspberry Pi.
bcm2835-v4l2
This ensures that the Broadcom Video For Linux 2 (v4l2) driver is loaded at all subsequent reboots.

Binary files Win x64 - https://cloud.mail.ru/public/LtSM/XU1EyMhwK
