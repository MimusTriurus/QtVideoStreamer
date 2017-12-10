#ifndef VIDEORECIEVER_H
#define VIDEORECIEVER_H

#include <QtCore>
#include <QUdpSocket>
#include <QImage>
#include "opencv2/opencv.hpp"

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
    void matReceived( cv::Mat mat );
private:
    QUdpSocket _server;
    int _packetCount;
    QByteArray _imgBytes;
private slots:
    void onReceiveMatData( );
};

#endif // VIDEORECIEVER_H
