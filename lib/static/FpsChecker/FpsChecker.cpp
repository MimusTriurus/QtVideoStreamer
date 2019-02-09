#include "FpsChecker.h"

int64 FpsChecker::getTimeTicks( ) const {
    return _sumTime;
}

double FpsChecker::getTimeMicro( ) const {
    return  getTimeMilli( ) * 1e3;
}

double FpsChecker::getTimeMilli( ) const {
    return getTimeSec( ) * 1e3;
}

double FpsChecker::getTimeSec( ) const {
    return ( double )getTimeTicks( )/cv::getTickFrequency( );
}

int64 FpsChecker::getCounter( ) const {
    return _counter;
}

void FpsChecker::reset( ) {
    _startTime = 0;
    _sumTime = 0;
    _counter = 0;
}

FpsChecker::FpsChecker( ) :
    _counter{ 0 },
    _sumTime{ 0 },
    _startTime{ 0 }
{

}

void FpsChecker::start( ) {
    _startTime = cv::getTickCount( );
}

void FpsChecker::stop( ) {
    int64 time = cv::getTickCount( );
    if ( _startTime == 0 )
        return;
    ++_counter;
    _sumTime += ( time - _startTime );
    _startTime = 0;
}

int FpsChecker::fps( ) const {
    return cvRound( getCounter( ) / getTimeSec( ) );
}


