#include "VideoReceiver.h"
#include <QCoreApplication>
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

const QByteArray &VideoReciever::imgData( ) const {
    QMutexLocker locker ( &_mutex );
    return _imgData;
}

void VideoReciever::run( ) {
    auto server = new QUdpSocket( );
    server->bind( _port );
    while ( _workInProgress ) {
        QCoreApplication::processEvents( );
        while ( server->hasPendingDatagrams( ) ) {
            QByteArray datagram;
            datagram.resize( server->pendingDatagramSize( ) );
            QHostAddress address;
            server->readDatagram( datagram.data( ), datagram.size( ), &address );
            int msgSize{ datagram.size( ) };
            if ( msgSize == sizeof( int ) ) {
                if ( _imgBuffer.count( ) == _imgSize ) {
                    _imgData = _imgBuffer;
                    emit imgDataReceived( _imgBuffer );
                }
                else
                    qDebug( ) << "crash on receive img data" << _imgBuffer.count( ) << "!=" << _imgSize;
                _imgBuffer.clear( );
                QDataStream stream( datagram );
                stream >> _imgSize;
            }
            else
                _imgBuffer.append( datagram );
        }
    }
    server->close( );
    delete server;
}
