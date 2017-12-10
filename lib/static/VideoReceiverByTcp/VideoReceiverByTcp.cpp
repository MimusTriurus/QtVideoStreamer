#include "VideoReceiverByTcp.h"
#include <QTcpSocket>
#include <QDebug>
#include <ImageSerialization.h>

VideoReceiverByTcp::VideoReceiverByTcp( quint16 listeningPort, QObject *parent ) : QObject( parent ) {
    connect( &_server, SIGNAL( newConnection( ) ), this, SLOT( onClientConnected( ) ) );
    _server.listen( QHostAddress::Any, listeningPort );
}

void VideoReceiverByTcp::onReadyRead( ) {
    QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>( sender( ) );
    QByteArray bytes{ clientSocket->readAll( ) };
    emit matReceived( ImageSerialization::deserializeMat( bytes ) );
    //qDebug( ) << "img data size:" << bytes.count( );
}

void VideoReceiverByTcp::onClientConnected( ) {
    qDebug( ) << "client connect";
    QTcpSocket* clientSocket = _server.nextPendingConnection( );
    connect( clientSocket, SIGNAL( readyRead( ) ), this, SLOT( onReadyRead( ) ) );
}
