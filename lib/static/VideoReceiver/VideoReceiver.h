#ifndef VIDEORECIEVER_H
#define VIDEORECIEVER_H

#include <QtCore>
#include <QUdpSocket>
#include <QImage>

/**
 * @brief Приемник видеопотока
 */
class VideoReciever : public QObject {
    Q_OBJECT
public:
    explicit VideoReciever( QObject *parent = nullptr );
    void listen( const quint16 port );
signals:
    void imgDataReceived( const QByteArray & );
private:
    QUdpSocket _server;
    int _packetCount;
    QByteArray _imgBytes;
private slots:
    void onReceiveData( );
};

#endif // VIDEORECIEVER_H
