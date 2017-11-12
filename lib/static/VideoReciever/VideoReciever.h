#ifndef VIDEORECIEVER_H
#define VIDEORECIEVER_H

#include <QtCore>
#include <QUdpSocket>

#include <Converter.h>

#define BUF_LEN 65540

class VideoReciever : public QObject
{
    Q_OBJECT
public:
    VideoReciever( QObject *parent = nullptr );
private:
    QUdpSocket _server;
    QByteArray _frameBuffer;
    int _packetCount{ 0 };
    int _currentPacket{ 0 };
private slots:
    void onRecieveData( );
};

#endif // VIDEORECIEVER_H
