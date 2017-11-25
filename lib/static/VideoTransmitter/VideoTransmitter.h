#ifndef VIDEOTRANSMITTER_H
#define VIDEOTRANSMITTER_H

#include <QtCore>
#include <QUdpSocket>
#include <Converter.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

/**
 * @brief Передатчик видео стрима
 */
class VideoTransmitter : public QObject
{
    Q_OBJECT
public:
    VideoTransmitter( QString host = "localhost", quint16 port = 10000, QObject *parent = nullptr );
public slots:
    void sendNewFrame( QByteArray imgData );
private:
    QUdpSocket _socket;
    void sendPacketsCount( int count );
    const int PACKET_SIZE;
    const QHostAddress HOST;
    const quint16 PORT;
private slots:
    void onError( QAbstractSocket::SocketError errorMessage );
};

#endif // VIDEOTRANSMITTER_H
