#ifndef VIDEORECIEVER_H
#define VIDEORECIEVER_H

#include <QtCore>
#include <QUdpSocket>
#include <QImage>

/**
 * @brief Приемник видеопотока
 */
class VideoReciever : public QObject
{
    Q_OBJECT
public:
    explicit VideoReciever( quint16 port = 10000, QObject *parent = nullptr );
signals:
    void imageReceived( QImage img );
private:
    QUdpSocket _server;
    int _packetCount;
    QByteArray _imgBytes;
    QBuffer _buffer;
private slots:
    void onRecieveData( );
};

#endif // VIDEORECIEVER_H
