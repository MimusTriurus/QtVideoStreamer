#include "Capture.h"
#include <QDebug>

Capture::Capture( QObject *parent ) :
    QObject( parent ) {

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

bool Capture::open( const int deviceId ) {
    return _capture.open( deviceId );
}

void Capture::close( ) {
    _capture.release( );
}

cv::Mat Capture::read( ) {
    _capture >> _frame;
    return _frame;
}
