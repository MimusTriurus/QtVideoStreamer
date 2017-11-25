#include "VideoTransmitter.h"

VideoTransmitter::VideoTransmitter( QString host, quint16 port, QObject *parent ) :
    HOST{ host },
    PORT{ port },
    PACKET_SIZE{ 4096 },
    QObject( parent )
{
    connect( &_socket, SIGNAL( error( QAbstractSocket::SocketError ) ),
             this, SLOT( onError( QAbstractSocket::SocketError ) ) );

    //_socket.connectToHost( HOST, PORT, QIODevice::OpenModeFlag::WriteOnly );
}

void VideoTransmitter::sendNewFrame( QByteArray imgData ) {
    int totalPack = 1 + ( imgData.size( ) - 1 ) / PACKET_SIZE;
    sendPacketsCount( totalPack );
    while ( !imgData.isEmpty( ) ) {
        _socket.writeDatagram( imgData.mid( 0, PACKET_SIZE ), HOST, PORT );
        imgData.remove( 0, PACKET_SIZE );
    }
}

void VideoTransmitter::sendPacketsCount( int count ) {
    QByteArray array;
    QDataStream streamIn( &array, QIODevice::WriteOnly );
    streamIn << count;
    //qDebug( ) << "send packet count:" << count << " raw:" << array;
    _socket.writeDatagram( array, HOST, PORT );
}

void VideoTransmitter::onError( QAbstractSocket::SocketError errorMessage ) {
    qDebug( ) << "VideoTransmitter error:" << errorMessage;
}
