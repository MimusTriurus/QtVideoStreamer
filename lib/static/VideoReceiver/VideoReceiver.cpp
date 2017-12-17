#include "VideoReceiver.h"
#include <ImageSerialization.h>
#include <QDebug>

VideoReciever::VideoReciever( QObject *parent ) : QObject( parent ) {
    connect( &_server, &QUdpSocket::readyRead, this, &VideoReciever::onReceiveMatData );
}

void VideoReciever::listen( const quint16 port ) {
    _server.bind( QHostAddress::Any, port );
}

void VideoReciever::onReceiveMatData( ) {
    while ( _server.hasPendingDatagrams( ) ) {
        QByteArray datagram;
        datagram.resize( _server.pendingDatagramSize( ) );
        QHostAddress *address = new QHostAddress( );
        _server.readDatagram( datagram.data( ), datagram.size( ), address );
        int msgSize{ datagram.size( ) };
        if ( msgSize == sizeof( int ) ) {
            QDataStream stream( datagram );
            stream >> _packetCount;
            if ( _imgBytes.count( ) != 0 ) {
                emit matReceived( ImageSerialization::deserializeMat( _imgBytes ) );
            }
            _imgBytes.clear( );
            return;
        }
        _imgBytes.append( datagram );
    }
}
