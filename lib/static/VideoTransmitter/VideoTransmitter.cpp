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

void VideoTransmitter::sendFrameData( QByteArray &imgData ) {
    int totalPack = 1 + ( imgData.size( ) - 1 ) / PACKET_SIZE;
    sendPacketsCount( totalPack );

    while ( !imgData.isEmpty( ) ) {
        _socket.writeDatagram( imgData.mid( 0, PACKET_SIZE ), _host, _port );
        imgData.remove( 0, PACKET_SIZE );
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
