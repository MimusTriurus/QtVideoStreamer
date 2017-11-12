#include "Capture.h"

#include <QtCore>
#include <QImage>

#include <QDebug>

Capture::Capture( QObject *parent ) :
    QObject( parent )
{

}

bool Capture::open( int deviceId ) {
    _cap.open( deviceId );
    if( _cap.isOpened( ) == false ) {
        qDebug() << "Camera not successfully connected.";
        return false;
    }
    return true;
}

bool Capture::open( const QString &source ) {

    _cap.open( source.toUtf8().data() );
    if( _cap.isOpened( ) == false ) {
        qDebug() << "Source " << source << "not available";
        return false;
    }
    return true;
}

bool Capture::read( ) {
    cv::Mat grabbedFrame;
    cv::Mat grabbedFrameForDisplay;
    _cap.read( grabbedFrame );

    if( grabbedFrame.empty( ) == true ) {
        qDebug("Frame is empty!");
        return false;
    }

    cv::resize( grabbedFrame, grabbedFrame, cv::Size( ), 0.5, 0.5 );
    cv::cvtColor( grabbedFrame, grabbedFrameForDisplay, CV_BGR2RGB );

    QImage grabbedQImage( ( uchar* )grabbedFrameForDisplay.data,
                           grabbedFrameForDisplay.cols,
                           grabbedFrameForDisplay.rows,
                           grabbedFrameForDisplay.step,
                           QImage::Format_RGB888) ;

    emit newFrame( grabbedFrame );
    emit newFrame( grabbedQImage );

    return true;
}
