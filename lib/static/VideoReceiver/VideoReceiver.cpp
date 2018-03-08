#include "VideoReceiver.h"
#include <QDebug>

VideoReciever::VideoReciever( QObject *parent ) :
    QObject( parent ),
    _imgSize{ -1 }
{
    connect( &_server, &QUdpSocket::readyRead, this, &VideoReciever::onReceiveData );
}

void VideoReciever::listen( const quint16 port ) {
    _server.bind( QHostAddress::Any, port );
}

void VideoReciever::stopListen( ) {
    _server.close( );
}

void VideoReciever::onReceiveData( ) {
    while ( _server.hasPendingDatagrams( ) ) {
        QByteArray datagram;
        datagram.resize( _server.pendingDatagramSize( ) );
        QHostAddress address;
        _server.readDatagram( datagram.data( ), datagram.size( ), &address );
        int msgSize{ datagram.size( ) };
        if ( msgSize == sizeof( int ) ) {
            if ( _imgBytes.count( ) == _imgSize ) {
                emit imgDataReceived( _imgBytes );
            }
            else
                qDebug( ) << "crash on receive img data" << _imgBytes.count( ) << "!=" << _imgSize;
            _imgBytes.clear( );
            QDataStream stream( datagram );
            stream >> _imgSize;
            return;
        }
        _imgBytes.append( datagram );
    }
}
