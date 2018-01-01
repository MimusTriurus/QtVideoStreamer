#include "CameraFrameGrabber.h"
#include <QDebug>

CameraFrameGrabber::CameraFrameGrabber( QObject *parent ) :
    QAbstractVideoSurface( parent )
{
    _imgFormat = QImage::Format_ARGB32;
}

bool CameraFrameGrabber::present( const QVideoFrame &frame ) {
    _grabedFrame = frame;
    if ( this->surfaceFormat( ).pixelFormat( ) != _grabedFrame.pixelFormat( ) ||
         this->surfaceFormat( ).frameSize( ) != _grabedFrame.size( ) ) {
        this->stop( );
        qDebug( ) << "invalid format";
        return false;
    }
    else {
        if ( _grabedFrame.map( QAbstractVideoBuffer::ReadOnly ) ) {
            QImage img( _grabedFrame.bits( ),
                        _grabedFrame.width( ),
                        _grabedFrame.height( ),
                        _grabedFrame.bytesPerLine( ),
                        _imgFormat );
            emit grabImg( img );
            _grabedFrame.unmap( );
            return true;
        }
        else {
            qDebug( ) << "error on convert to image";
            return false;
        }
    }

    return true;
}

QList<QVideoFrame::PixelFormat> CameraFrameGrabber::supportedPixelFormats( QAbstractVideoBuffer::HandleType handleType ) const {
    if ( handleType == QAbstractVideoBuffer::NoHandle ) {
        QList<QVideoFrame::PixelFormat> pixelFormat{ QVideoFrame::Format_ARGB32,
                                                   QVideoFrame::Format_RGB32,
                                                   QVideoFrame::Format_RGB555,
                                                   QVideoFrame::Format_RGB565
                                                   };
        return pixelFormat;
    }
    else
        return QList<QVideoFrame::PixelFormat>( );
}

