#include "VideoTransmitter.h"

#define FRAME_HEIGHT 720
#define FRAME_WIDTH 1280
#define FRAME_INTERVAL ( 1000 / 30 )
#define PACK_SIZE 4096
#define ENCODE_QUALITY 80

VideoTransmitter::VideoTransmitter( QObject *parent ) :
    QObject( parent )
{
    connect( &_socket, SIGNAL( connected( ) ), this, SLOT( onConnected( ) ) );
    connect( &_socket, SIGNAL( disconnected( ) ), this, SLOT( onDisconnected( ) ) );
    connect( &_socket, SIGNAL( error( QAbstractSocket::SocketError ) ),
             this, SLOT( onError( QAbstractSocket::SocketError ) ) );
}

void VideoTransmitter::sendNewFrame( cv::Mat & frame ) {
    //qDebug( ) << "-------------------------------";
    if( frame.size( ).width == 0 ) return;
    cv::Mat send;
    cv::resize( frame, send, cv::Size( FRAME_WIDTH, FRAME_HEIGHT ),
                0, 0, cv::INTER_LINEAR );
    std::vector < int > compressionParams;
    compressionParams.push_back( CV_IMWRITE_JPEG_QUALITY );
    compressionParams.push_back( ENCODE_QUALITY );
    cv::imencode( ".jpg", send, _encoded, compressionParams );
    int totalPack = 1 + ( _encoded.size( ) - 1 ) / PACK_SIZE;
    //qDebug( ) << totalPack;
    _socket.write( Converter::convertToByteArray<int>( totalPack ), sizeof( int ) );
    //qDebug() << _encoded.size();
    const uchar *carr = &_encoded[0];
    QByteArray b( (char*)carr );
    for ( int i = 0; i < totalPack; ++i ) {
        QByteArray bOut = b.mid( i * PACK_SIZE, PACK_SIZE );
        _socket.write( bOut, PACK_SIZE );
    }
        //_socket.write( Converter::convertToByteArray<uchar>( _encoded[ i * PACK_SIZE ] ), PACK_SIZE );
}

void VideoTransmitter::connectToHost( QString host, int port ) {
    _socket.connectToHost( host, port, QIODevice::OpenModeFlag::WriteOnly );
}

void VideoTransmitter::onConnected( ) {
    qDebug( ) << "connected";
}

void VideoTransmitter::onDisconnected( ) {
    qDebug( ) << "disconnected";
}

void VideoTransmitter::onError( QAbstractSocket::SocketError errorMessage ) {
    qDebug( ) << "VideoTransmitter error:" << errorMessage;
}
/*
QByteArray VideoTransmitter::intToArray( int value ) {
    QByteArray array;
    QDataStream stream( &array, QIODevice::ReadWrite );
    stream << value;
    return array;
}
*/

