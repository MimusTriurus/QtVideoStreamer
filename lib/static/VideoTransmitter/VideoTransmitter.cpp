#include "VideoTransmitter.h"

VideoTransmitter::VideoTransmitter( QString host, quint16 port, QObject *parent ) :
    QObject     { parent },
    _packetSize { 8192 },
    _quality    { 55 },
    _host       { host },
    _port       { port }
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

void VideoTransmitter::packetSize( int size ) {
    _packetSize = size;
}

void VideoTransmitter::sendFrameData( const std::vector<uchar> &imgData ) {
    int imgDataSize{ static_cast<int>( imgData.size( ) ) };
    int totalPack = 1 + ( imgDataSize - 1 ) / _packetSize;
    sendImgSize( imgDataSize );
    for ( int i = 0; i < totalPack; i++ ) {
        int size{ _packetSize };
        if ( i == totalPack - 1 )
            size = imgDataSize - ( i * _packetSize );
        _socket.writeDatagram( reinterpret_cast<const char*>( &imgData[ i * _packetSize ] ),
                                   static_cast<int>( size ),
                                   _host,
                                   _port );
    }
}

void VideoTransmitter::sendImgSize( const int count ) {
    QByteArray array;
    QDataStream streamIn( &array, QIODevice::WriteOnly );
    streamIn << count;
    _socket.writeDatagram( array, _host, _port );
}
