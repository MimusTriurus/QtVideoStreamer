#include "VideoTransmitter.h"

VideoTransmitter::VideoTransmitter( QString host, quint16 port, QObject *parent ) :
    QObject{ parent },
    _host{ host },
    _port{ port }
{

}

void VideoTransmitter::setQuality( const int quality ) {
    _quality = quality;
}

void VideoTransmitter::host( const QString &host ) {
    _host = host;
}

void VideoTransmitter::port( const quint16 port ) {
    _port = port;
}

void VideoTransmitter::sendFrameData( const std::vector<uchar> &imgData ) {
    int imgDataSize{ static_cast<int>( imgData.size( ) ) };
    int totalPack = 1 + ( imgDataSize - 1 ) / PACKET_SIZE;
    sendPacketsCount( totalPack );
    for ( int i = 0; i < totalPack; i++ ) {
        _socket.writeDatagram( reinterpret_cast<const char*>( &imgData[ i * PACKET_SIZE ] ),
                                   static_cast<int>( PACKET_SIZE ),
                                   _host,
                                   _port );
    }
}

void VideoTransmitter::sendPacketsCount( const int count ) {
    QByteArray array;
    QDataStream streamIn( &array, QIODevice::WriteOnly );
    streamIn << count;
    _socket.writeDatagram( array, _host, _port );
}
