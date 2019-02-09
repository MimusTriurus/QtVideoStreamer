#ifndef VIDEOTRANSMITTER_H
#define VIDEOTRANSMITTER_H

#include <QtCore>
#include <QUdpSocket>
/**
 * @brief Передатчик видео стрима
 */
class VideoTransmitter : public QObject {
    Q_OBJECT
public:
    VideoTransmitter( QString host = "localhost", quint16 port = 10000, QObject *parent = nullptr );
    VideoTransmitter( ) = delete;
    void setQuality( const int quality );
    void host( const QString &host );
    void port( const quint16 port );
    void packetSize( int size );
signals:
    void onError( const QString & );
public slots:
    void sendFrameData( const std::vector<uchar> &imgData );
private:
    int             _packetSize;
    int             _quality;
    QUdpSocket      _socket;
    QHostAddress    _host;
    quint16         _port;
    void sendImgSize( const int count );
};

#endif // VIDEOTRANSMITTER_H
