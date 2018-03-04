#include "Capture.h"
#include <QDebug>

Capture::Capture( QObject *parent ) :
    QObject( parent ) {

}

Capture::~Capture( ) {
    if ( _capture.isOpened( ) )
        _capture.release( );
}

bool Capture::isOpened( ) const {
    return _capture.isOpened( );
}

void Capture::resolution( double width, double height ) {
    if ( _capture.isOpened( ) ) {
        _capture.set( cv::CAP_PROP_FRAME_HEIGHT, height );
        _capture.set( cv::CAP_PROP_FRAME_WIDTH, width );
    }
}

double Capture::width( ) const {
    return _capture.get( cv::CAP_PROP_FRAME_WIDTH );
}

double Capture::height( ) const {
    return _capture.get( cv::CAP_PROP_FRAME_HEIGHT );
}

void Capture::fps( double value ) {
    _capture.set( CV_CAP_PROP_FPS, value );
}

double Capture::fps( ) const {
    return _capture.get( CV_CAP_PROP_FPS );
}

int Capture::getIntervalByMaxFps( const int fps ) {
    return cvRound( 1000 / fps );
}

void Capture::printOpenCvBuildInfo( ) {
    std::cout << cv::getBuildInformation( ) << std::endl;
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
