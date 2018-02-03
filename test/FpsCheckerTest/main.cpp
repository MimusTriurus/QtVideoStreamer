#include <QCoreApplication>

#include <iostream>
#include <ctime>

#include <opencv2/opencv.hpp>

#include <FpsChecker.h>

int main( int argc, char *argv[ ] ) {
    QCoreApplication a( argc, argv );

    cv::VideoCapture capture;

    capture.open( 0 );

    if ( !capture.isOpened( ) ) {
        std::cout << "Problem connecting to cam " << std::endl;
        return -1;
    }

    cv::Mat frame;
    FpsChecker _fpsChecker;

    while ( 1 ) {
        _fpsChecker.stop( );
        _fpsChecker.start( );

        capture.read( frame );

        if( frame.empty( ) ) {
            break;
        }

        cv::putText( frame,
                     cv::format( "FPS=%d",
                     _fpsChecker.fps( ) ),
                     cv::Point( 30, 60 ),
                     cv::FONT_HERSHEY_SIMPLEX,
                     0.8,
                     cv::Scalar( 255, 0, 0 ) );

        cv::imshow( "FPS test", frame );
        cv::waitKey( 1 );
    }

    return a.exec( );
}

