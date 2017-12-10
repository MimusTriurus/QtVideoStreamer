#include "VideoTransmitterByTcp.h"
#include <QDataStream>
#include <ImageSerialization.h>

VideoTransmitterByTcp::VideoTransmitterByTcp( QObject *parent ) : QObject( parent ) {
    connect( &_socket, SIGNAL( connected( ) ), this, SLOT( onSocketConnected( ) ) );
    connect( &_socket, SIGNAL( error( QAbstractSocket::SocketError ) ), this, SLOT( onSocketError( QAbstractSocket::SocketError ) ) );
}

void VideoTransmitterByTcp::setQuality( const int quality ) {
    _quality = quality;
}

void VideoTransmitterByTcp::connectToHost( const QString &host, quint16 port ) {
    _host = host;
    _port = port;
    _socket.connectToHost( _host, _port );
}

void VideoTransmitterByTcp::sendNewFrame( const cv::Mat &mat ) {
    sendFrameData( ImageSerialization::serializeMat( mat, _quality ) );
}

void VideoTransmitterByTcp::sendFrameData( const QByteArray &&imgData ) {
    _socket.write( imgData );
    /*
    const int BUFFER_SIZE{ 4096 };
    int totalPack = 1 + ( imgData.size( ) - 1 ) / BUFFER_SIZE;
    QByteArray array;
    QDataStream streamIn( &array, QIODevice::WriteOnly );
    streamIn << totalPack;
    _socket.write( array );
    _socket.waitForBytesWritten( );

    int i{ 0 };
    while ( i < totalPack ) {
        QByteArray bytes{ imgData.mid( i*BUFFER_SIZE, BUFFER_SIZE ) };
        _socket.write( bytes );
        _socket.waitForBytesWritten( );
        i++;
    }
    */
}

void VideoTransmitterByTcp::onSocketError( QAbstractSocket::SocketError err ) {
    QString strError =
        "Error: " + ( err == QAbstractSocket::HostNotFoundError ?
                     "The host was not found." :
                     err == QAbstractSocket::RemoteHostClosedError ?
                     "The remote host is closed." :
                     err == QAbstractSocket::ConnectionRefusedError ?
                     "The connection was refused." :
                     QString( _socket.errorString( ) )
                    );
    qDebug( ) << "error:" << strError;
}

void VideoTransmitterByTcp::onSocketConnected( ) {
    qDebug( ) << "connected to host" << _host << " port" << _port;
}
