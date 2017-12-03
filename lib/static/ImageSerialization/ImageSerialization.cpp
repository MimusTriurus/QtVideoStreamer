#include "ImageSerialization.h"

#include <QImageWriter>
#include <QImageReader>
#include <QDataStream>

#define IMG_EXT "JPG"

QByteArray ImageSerialization::serializeImg( const QImage &img ) {
    QBuffer buffer;
    QImageWriter writer( &buffer, IMG_EXT );
    writer.write( img );
    QByteArray data;
    data.append( buffer.data( ) );
    return data;
}

QImage ImageSerialization::deserializeImg( QByteArray imgData ) {
    QBuffer buffer( &imgData );
    QImageReader reader( &buffer, IMG_EXT );
    QImage img( reader.read( ) );
    return img;
}

QByteArray ImageSerialization::serializeMat( const cv::Mat &mat , int quality ) {
    std::vector<uchar> buffer;
    std::vector<int> compressionParams = std::vector<int>( 2 );
    compressionParams[ 0 ] = 1;
    compressionParams[ 1 ] = quality;
    cv::imencode( ".jpg", mat, buffer, compressionParams );
    QByteArray result = QByteArray::fromRawData( reinterpret_cast<const char*>( buffer.data( ) ), buffer.size( ) );
    return result;
}

cv::Mat ImageSerialization::deserializeMat( const QByteArray &matData ) {
    std::vector<uchar> buffer( matData.cbegin( ), matData.cend( ) );
    cv::Mat result = cv::imdecode( cv::Mat( buffer ), 1 );
    return result;
}
