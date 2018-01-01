#ifndef QVIDEOCAPTURE_H
#define QVIDEOCAPTURE_H

#include <QtCore>
#include <QCamera>
#include <QCameraInfo>
#include "CameraFrameGrabber.h"

/**
 * @brief Предназначен для получения кадров в формате QImage
 * из различных источников видео информации средствами QCamera
 */
class QVideoCapture : public QObject {
    Q_OBJECT
public:
    QVideoCapture( const QCameraInfo &cam = QCameraInfo::defaultCamera( ),
                   QObject *parent = nullptr );
signals:
    void grabed( const QImage & );
public slots:
    void start( );
    void stop( );
private:
    QCamera             _camera;
    CameraFrameGrabber  _grabber;
};

#endif // QVIDEOCAPTURE_H
