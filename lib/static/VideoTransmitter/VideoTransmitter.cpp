#include "VideoTransmitter.h"
#include <ImageSerialization.h>

VideoTransmitter::VideoTransmitter( QString host, quint16 port, QObject *parent ) :
    HOST{ host },
    PORT{ port },
    PACKET_SIZE{ 4096 },
    QObject{ parent }
{
    connect( &_socket, SIGNAL( error( QAbstractSocket::SocketError ) ),
             this, SLOT( onError( QAbstractSocket::SocketError ) ) );
}

void VideoTransmitter::sendNewFrame( QByteArray imgData ) {
    //_socket.writeDatagram( imgData, HOST, PORT );
    int totalPack = 1 + ( imgData.size( ) - 1 ) / PACKET_SIZE;
    sendPacketsCount( totalPack );
    while ( !imgData.isEmpty( ) ) {
        _socket.writeDatagram( imgData.mid( 0, PACKET_SIZE ), HOST, PORT );
        imgData.remove( 0, PACKET_SIZE );
    }
}

void VideoTransmitter::sendNewFrame( cv::Mat mat ) {
    sendNewFrame( ImageSerialization::serializeMat( mat ) );
}

void VideoTransmitter::onError( QAbstractSocket::SocketError errorMessage ) {
    qDebug( ) << "VideoTransmitter error:" << errorMessage;
}

void VideoTransmitter::sendPacketsCount( int count ) {
    QByteArray array;
    QDataStream streamIn( &array, QIODevice::WriteOnly );
    streamIn << count;
    _socket.writeDatagram( array, HOST, PORT );
}
