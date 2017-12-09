#include "VideoTransmitter.h"
#include <ImageSerialization.h>

VideoTransmitter::VideoTransmitter( QString host, quint16 port, QObject *parent ) :
    _host{ host },
    _port{ port },
    PACKET_SIZE{ 4096 },
    QObject{ parent }
{
    connect( &_socket, SIGNAL( error( QAbstractSocket::SocketError ) ),
             this, SLOT( onError( QAbstractSocket::SocketError ) ) );
}

void VideoTransmitter::setQuality( int quality ) {
    _quality = quality;
}

void VideoTransmitter::host( const QString &host ) {
    _host = host;
}

void VideoTransmitter::port( quint16 port ) {
    _port = port;
}

void VideoTransmitter::sendFrameData( QByteArray &&imgData ) {
    int totalPack = 1 + ( imgData.size( ) - 1 ) / PACKET_SIZE;
    sendPacketsCount( totalPack );
    //qDebug( ) << "packet count:" << totalPack;
    _socket.writeDatagram( imgData , _host, _port );
    int i{ 0 };
    while ( i < totalPack ) {
        QByteArray bytes{ imgData.mid( i*PACKET_SIZE, PACKET_SIZE ) };
        _socket.writeDatagram( bytes , _host, _port );
        i++;
        //qDebug( ) << "send packet" << i << "from" << totalPack;
    }
}

void VideoTransmitter::sendNewFrame( cv::Mat mat ) {
    sendFrameData( ImageSerialization::serializeMat( mat, _quality ) );
}

void VideoTransmitter::onError( QAbstractSocket::SocketError errorMessage ) {
    qDebug( ) << "VideoTransmitter error:" << errorMessage;
}

void VideoTransmitter::sendPacketsCount( int count ) {
    QByteArray array;
    QDataStream streamIn( &array, QIODevice::WriteOnly );
    streamIn << count;
    _socket.writeDatagram( array, _host, _port );
}
