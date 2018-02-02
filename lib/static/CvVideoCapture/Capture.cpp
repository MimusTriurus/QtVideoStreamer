#include "Capture.h"
#include <QDebug>

Capture::Capture( QObject *parent ) :
    QObject( parent ) {
    _capture.set( CV_CAP_PROP_FRAME_HEIGHT, 480 );
    _capture.set( CV_CAP_PROP_FRAME_WIDTH, 640 );
}

Capture::~Capture( ) {
    if ( _capture.isOpened( ) )
        _capture.release( );
}

void Capture::frameHeight( int value ) {
    _capture.set( CV_CAP_PROP_FRAME_HEIGHT, value );
}

void Capture::frameWidth( int value ) {
    _capture.set( CV_CAP_PROP_FRAME_WIDTH, value );
}

void Capture::fps( int value ) {
    _capture.set( CV_CAP_PROP_FPS, value );
}

bool Capture::isOpened( ) {
    return _capture.isOpened( );
}

bool Capture::open( const int deviceId ) {
    _capture.open( deviceId );
    qDebug( ) << _capture.get( CV_CAP_PROP_FRAME_HEIGHT );
    qDebug( ) << _capture.get( CV_CAP_PROP_FRAME_WIDTH );
    return _capture.isOpened( );
}

void Capture::close( ) {
    _capture.release( );
}

void Capture::read( cv::Mat &mat ) {
    _capture >> mat;
}
