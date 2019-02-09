#ifndef FPSCHECKER_H
#define FPSCHECKER_H

#include <QObject>
#include <opencv2/opencv.hpp>

class FpsChecker {
public:
    FpsChecker( );

    void start( );
    void stop( );

    int fps( ) const;

    void reset( );
private:
    int64 _counter;
    int64 _sumTime;
    int64 _startTime;

    int64  getTimeTicks( ) const;
    double getTimeMicro( ) const;
    double getTimeMilli( ) const;
    double getTimeSec( )   const;
    int64  getCounter( )   const;
};

#endif // FPSCHECKER_H
