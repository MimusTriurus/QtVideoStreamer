#ifndef VIDEORECIEVER_H
#define VIDEORECIEVER_H

#include <QtCore>
#include <QUdpSocket>
#include <QImage>
#include "opencv2/opencv.hpp"

/**
 * @brief Приемник видеопотока
 */
class VideoReciever : public QObject {
    Q_OBJECT
public:
    explicit VideoReciever( QObject *parent = nullptr );
    void listen( const quint16 port );
signals:
    void matReceived( cv::Mat mat );
private:
    QUdpSocket _server;
    int _packetCount;
    QByteArray _imgBytes;
private slots:
    void onReceiveMatData( );
};

#endif // VIDEORECIEVER_H
