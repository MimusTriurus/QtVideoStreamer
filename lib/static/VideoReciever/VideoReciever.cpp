#include "VideoReciever.h"

#define PACK_SIZE 4096

VideoReciever::VideoReciever( QObject *parent ) : QObject( parent ) {
    _frameBuffer.resize( BUF_LEN );
    _server.bind( QHostAddress::Any, 8080 );
    connect( &_server, SIGNAL( readyRead( ) ), this, SLOT( onRecieveData( ) ) );
}

void VideoReciever::onRecieveData( ) {
    QByteArray datagram;
    datagram.resize( _server.pendingDatagramSize( ) );
    QHostAddress *address = new QHostAddress( );
    _server.readDatagram( datagram.data( ), datagram.size( ), address );
    int msgSize{ datagram.size( ) };

    if ( msgSize == PACK_SIZE ) {
        _currentPacket++;
        qDebug( ) << "part " + QString::number( _currentPacket ) + " of frame recieved";
        _frameBuffer.append( datagram );
        if ( _currentPacket == _packetCount ) {
            qDebug( ) << "full frame recieved";
            _packetCount = 0;
            _currentPacket = 0;
        }
    }

    if ( msgSize == sizeof( int ) ) {
        _packetCount = Converter::convertFromByteArray<int>( datagram );
        _currentPacket = 0;
        _frameBuffer.resize( _packetCount * PACK_SIZE);
        qDebug( ) << "recieve packetCount" << _packetCount;
    }
}
