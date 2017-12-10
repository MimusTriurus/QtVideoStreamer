#ifndef VIDEORECEIVERBYTCP_H
#define VIDEORECEIVERBYTCP_H

#include <QtCore>
#include <QImage>
#include <QTcpServer>
#include "opencv2/opencv.hpp"

class VideoReceiverByTcp : public QObject {
    Q_OBJECT
public:
    VideoReceiverByTcp( quint16 listeningPort = 65000, QObject *parent = nullptr );
signals:
    void matReceived( cv::Mat mat );
private:
    QTcpServer _server;
    QByteArray _imgBytes;
private slots:
    void onReadyRead( );
    void onClientConnected( );
};

#endif // VIDEORECEIVERBYTCP_H
