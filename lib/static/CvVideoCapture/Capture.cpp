#include "Capture.h"
#include <QDebug>

Capture::Capture( QObject *parent ) :
    QThread( parent ) {
}

Capture::~Capture( ) {
    if ( _work )
        this->close( );
    // для корректного завершения потока
    while ( this->isRunning( ) ) {

    }
}

void Capture::frameHeight( int value ) {
    _frameHeight = value;
}

void Capture::frameWidth( int value ) {
    _frameWidth = value;
}

void Capture::fps( int value ) {
    _fps = value;
}

bool Capture::open( const int deviceId ) {
    _deviceId = deviceId;
    _work = true;
    if ( !this->isRunning( ) )
        this->start( );
    return true;
}

void Capture::close( ) {
    _work = false;
}

void Capture::run( ) {
    auto cap = new cv::VideoCapture( );
    cap->set( CV_CAP_PROP_FRAME_WIDTH, _frameWidth );
    cap->set( CV_CAP_PROP_FRAME_HEIGHT, _frameHeight );
    cap->set( CV_CAP_PROP_FPS, _fps );
    cap->open( _deviceId );
    if( cap->isOpened( ) == false ) {
        qDebug( ) << "Camera " << _deviceId << "is not available";
        emit onError( "Camera " + QString::number( _deviceId ) + "is not available" );
        _work = false;
    }
    //qDebug( ) << "start thread";
    while ( _work ) {
        cap->read( _frame );
    }
    cap->release( );
    if ( cap ) {
        delete cap;
    }
    //qDebug( ) << "stop thread";
}

cv::Mat Capture::read( ) {
    return _frame;
}
