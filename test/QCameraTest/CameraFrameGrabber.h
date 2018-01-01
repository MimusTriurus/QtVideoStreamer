#ifndef CAMERAFRAMEGRABBER_H
#define CAMERAFRAMEGRABBER_H

#include <QWidget>
#include <QAbstractVideoSurface>
#include <QVideoSurfaceFormat>

class CameraFrameGrabber : public QAbstractVideoSurface {
    Q_OBJECT
public:
    explicit CameraFrameGrabber( QObject *parent = nullptr );
    bool present( const QVideoFrame &frame );
    QList<QVideoFrame::PixelFormat> supportedPixelFormats( QAbstractVideoBuffer::HandleType handleType ) const;
signals:
    void grabImg( const QImage & );
public slots:

private:
    QVideoFrame         _grabedFrame;
    QImage::Format      _imgFormat;
    QVideoSurfaceFormat _videoFormat;

};

#endif // CAMERAFRAMEGRABBER_H
