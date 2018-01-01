#include "QVideoCapture.h"

QVideoCapture::QVideoCapture( const QCameraInfo &cam, QObject *parent ) :
    QObject( parent ),
    _camera{ cam }
{
    _camera.setViewfinder( &_grabber );
    connect( &_grabber, SIGNAL( grabImg( QImage ) ), this, SIGNAL( grabed( QImage ) ) );
}

void QVideoCapture::start( ) {
    _camera.start( );
}

void QVideoCapture::stop( ) {
    _camera.stop( );
}
