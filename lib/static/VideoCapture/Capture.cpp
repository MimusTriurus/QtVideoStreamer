#include "Capture.h"

#include <QtCore>
#include <QImage>
#include <QDebug>

Capture::Capture( QObject *parent ) :
    QObject( parent ) {

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
    _cap.open( source.toUtf8( ).data( ) );
    if( _cap.isOpened( ) == false ) {
        qDebug() << "Source " << source << "not available";
        return false;
    }
    return true;
}

bool Capture::read( ) {
    cv::Mat cvFrame;
    _cap.read( cvFrame );
    if( cvFrame.empty( ) == true ) {
        qDebug("Frame is empty!");
        return false;
    }
    //cv::resize( cvFrame, cvFrame, cv::Size( ), 0.5, 0.5 );
    cv::cvtColor( cvFrame, cvFrame, CV_BGR2RGB );
    QImage qFrame( ( uchar* )cvFrame.data,
                           cvFrame.cols,
                           cvFrame.rows,
                           cvFrame.step,
                           QImage::Format_RGB888 ) ;
    emit newCvFrame( cvFrame );
    emit newQFrame( qFrame );
    return true;
}
