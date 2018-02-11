#include "VideoReceiver.h"
#include <QDebug>

VideoReciever::VideoReciever( QObject *parent ) : QObject( parent ) {
    connect( &_server, &QUdpSocket::readyRead, this, &VideoReciever::onReceiveData );
}

void VideoReciever::listen( const quint16 port ) {
    _server.bind( QHostAddress::Any, port );
}

void VideoReciever::stopListen( ) {
    _server.close( );
}

void VideoReciever::onReceiveData( ) {
    qDebug( ) << "receive";
    while ( _server.hasPendingDatagrams( ) ) {
        QByteArray datagram;
        datagram.resize( _server.pendingDatagramSize( ) );
        QHostAddress address;
        _server.readDatagram( datagram.data( ), datagram.size( ), &address );
        int msgSize{ datagram.size( ) };
        if ( msgSize == sizeof( int ) ) {
            QDataStream stream( datagram );
            stream >> _packetCount;
            qDebug( ) << _packetCount;
            if ( _imgBytes.count( ) != 0 ) {
                emit imgDataReceived( _imgBytes );
            }
            _imgBytes.clear( );
            return;
        }
        _imgBytes.append( datagram );
    }
}
