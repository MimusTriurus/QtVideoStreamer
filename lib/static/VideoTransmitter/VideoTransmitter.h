#ifndef VIDEOTRANSMITTER_H
#define VIDEOTRANSMITTER_H

#include <QtCore>
#include <QUdpSocket>
#include <Converter.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class VideoTransmitter : public QObject
{
    Q_OBJECT
public:
    VideoTransmitter( QObject *parent = nullptr );
public slots:
    void sendNewFrame( cv::Mat &frame );
    void connectToHost( QString host = "localhost", int port = 8080 );
private:
    QUdpSocket _socket;
    std::vector < uchar > _encoded;
private slots:
    void onConnected( );
    void onDisconnected( );
    void onError( QAbstractSocket::SocketError errorMessage );
};

#endif // VIDEOTRANSMITTER_H
