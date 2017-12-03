#include "VideoReceiver.h"
#include <QImageReader>
#include <ImageSerialization.h>
#include <QBuffer>

VideoReciever::VideoReciever( quint16 port, QObject *parent ) : QObject( parent ) {
    _server.bind( QHostAddress::Any, port );
    connect( &_server, &QUdpSocket::readyRead, this, &VideoReciever::onReceiveMatData );
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
