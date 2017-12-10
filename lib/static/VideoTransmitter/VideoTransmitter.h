#ifndef VIDEOTRANSMITTER_H
#define VIDEOTRANSMITTER_H

#include <QtCore>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QImage>
#include <opencv2/core/core.hpp>
/**
 * @brief Передатчик видео стрима
 */
class VideoTransmitter : public QObject {
    Q_OBJECT
public:
    VideoTransmitter( QString host = "localhost", quint16 port = 10000, QObject *parent = nullptr );
    void setQuality( const int quality );
    void host( const QString &host );
    void port( const quint16 port );
public slots:
    void sendNewFrame( const cv::Mat &mat );
    void sendQImage( QImage img );
private:
    QUdpSocket _socket;
    int _quality{ 90 };
    const int PACKET_SIZE;
    QHostAddress _host;
    quint16 _port;
    void sendPacketsCount( const int count );
    void sendFrameData( const QByteArray &&imgData );
private slots:
    void onError( QAbstractSocket::SocketError errorMessage );
};

#endif // VIDEOTRANSMITTER_H
