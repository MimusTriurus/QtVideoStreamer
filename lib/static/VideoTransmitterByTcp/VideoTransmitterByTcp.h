#ifndef VIDEOTRANSMITTERBYTCP_H
#define VIDEOTRANSMITTERBYTCP_H

#include <QtCore>
#include <QTcpSocket>
#include <opencv2/core/core.hpp>

class VideoTransmitterByTcp : public QObject {
    Q_OBJECT
public:
    VideoTransmitterByTcp( QObject *parent = nullptr );
    void setQuality( const int quality );
    void connectToHost( const QString &host, quint16 port );
public slots:
    void sendNewFrame( const cv::Mat &mat );
private:
    QTcpSocket _socket;
    int _quality{ 90 };
    QString _host;
    quint16 _port;
    void sendFrameData( const QByteArray &&imgData );
private slots:
    void onSocketError( QAbstractSocket::SocketError err );
    void onSocketConnected( );
};

#endif // VIDEOTRANSMITTERBYTCP_H
