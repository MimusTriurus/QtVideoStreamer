#ifndef VIDEORECIEVER_H
#define VIDEORECIEVER_H

#include <QtCore>
#include <QUdpSocket>
#include <QThread>

/**
 * @brief Приемник видеопотока
 */
class VideoReciever : public QThread {
    Q_OBJECT
public:
    explicit VideoReciever( QObject *parent = nullptr );
    ~VideoReciever( );

    void listen( const quint16 port, const double interval = 0.33 );
    void stopListen( );
signals:
    void imgDataReceived( QByteArray );
protected:
    void run( ) override;
private:
    int         _imgSize;
    QByteArray  _imgBytes;
    quint16     _port;
    double      _interval;
    bool        _workInProgress{ false };
};

#endif // VIDEORECIEVER_H
