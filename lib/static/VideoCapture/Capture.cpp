#include "Capture.h"
#include <QDebug>

Capture::Capture( QObject *parent ) :
    QObject( parent ) {

}

bool Capture::open( const int deviceId ) {
    _cap.open( deviceId );
    if( _cap.isOpened( ) == false ) {
        qDebug( ) << "Camera " << deviceId << "is not available";
        emit onError( "Camera " + QString::number( deviceId )  + " is not available" );
        return false;
    }
    return true;
}

bool Capture::open( const QString &source ) {
    _cap.open( source.toUtf8( ).data( ) );
    if ( _cap.isOpened( ) == false ) {
        qDebug( ) << "Source " << source << " is not available";
        emit onError( "Source " + source + " is not available" );
        return false;
    }
    return true;
}

bool Capture::read( ) {
    cv::Mat cvFrame;
    _cap.read( cvFrame );
    if ( cvFrame.empty( ) == true ) {
        qDebug( "Frame is empty!" );
        emit onError( "Frame is empty!" );
        return false;
    }
    emit newCvFrame( cvFrame );
    return true;
}
