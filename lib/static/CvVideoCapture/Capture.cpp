#include "Capture.h"
#include <QDebug>

Capture::Capture( QObject *parent ) :
    QObject( parent ) {
}

Capture::~Capture( ) {
    if ( _capture.isOpened( ) )
        _capture.release( );
}

bool Capture::isOpened( ) {
    return _capture.isOpened( );
}

int Capture::getIntervalByMaxFps( const int fps ) {
    return cvRound( 1000 / fps );
}

bool Capture::open( const int deviceId ) {
    bool success{ _capture.open( deviceId ) };
    if ( !success )
        emit this->onError( "error on open camera " + QString::number( deviceId ) );
    return _capture.isOpened( );
}

void Capture::close( ) {
    _capture.release( );
}

void Capture::read( cv::Mat &mat ) {
    _capture >> mat;
}
