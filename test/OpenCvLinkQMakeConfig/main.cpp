#include <QCoreApplication>
#include <QDebug>
#include <opencv2/opencv.hpp>

int main( int argc, char *argv[ ] ) {
    QCoreApplication a (argc, argv );

    cv::VideoCapture cap;

    if ( cap.open( 0 ) ) {
        cv::namedWindow( "frame", cv::WINDOW_AUTOSIZE );
        while ( true ) {
            cv::Mat frame;
            cap.read( frame );
            if( frame.empty( ) )
                qDebug( ) << "empty";
            cv::imshow( "frame", frame );
        }
    }
    else {
        qDebug( ) << "error on open cam";
    }

    return a.exec();
}

