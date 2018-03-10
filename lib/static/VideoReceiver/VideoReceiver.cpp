#include "VideoReceiver.h"
#include <QDebug>

VideoReciever::VideoReciever( QObject *parent ) :
    QThread( parent ),
    _imgSize    { -1 },
    _port       { 10000 },
    _interval   { 0.33 }
{

}

VideoReciever::~VideoReciever( ) {
    qDebug( ) << "destroy";
    _workInProgress = false;
    this->terminate( );
}

void VideoReciever::listen( const quint16 port , const double interval ) {
    _port       = port;
    _interval   = interval;
    if ( !this->isRunning( ) ) {
        _workInProgress = true;
        this->start( );
    }
}

void VideoReciever::stopListen( ) {
    this->_workInProgress = false;
}

void VideoReciever::run( ) {
    auto server = new QUdpSocket( );
    server->bind( _port );
    while ( _workInProgress ) {

        while ( server->hasPendingDatagrams( ) ) {
            QByteArray datagram;
            datagram.resize( server->pendingDatagramSize( ) );
            QHostAddress address;
            server->readDatagram( datagram.data( ), datagram.size( ), &address );
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
            }
            else
                _imgBytes.append( datagram );
        }

        QThread::msleep( _interval );
    }
    server->close( );
    delete server;
}
