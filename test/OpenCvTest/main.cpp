#include "MainWindow.h"
#include <QApplication>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main( int argc, char *argv[ ] )
{
    QApplication a( argc, argv );
    /*
    MainWindow w;
    w.show();
*/
    VideoCapture cap( 1 ); // open the default camera
    if( !cap.isOpened( ) )  // check if we succeeded
        return -1;

    Mat edges;
    namedWindow("edges",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        cvtColor(frame, edges, COLOR_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);
        if(waitKey(30) >= 0) break;
    }

    return a.exec();
}
