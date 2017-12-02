#include "ImageSerialization.h"

#include <QImageWriter>
#include <QImageReader>
#include <QDataStream>

#define IMG_EXT "JPG"

QByteArray ImageSerialization::serializeImg( QImage img ) {
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

QByteArray ImageSerialization::serializeMat( cv::Mat mat ) {
    if ( !mat.data ) {
        qDebug( ) <<  "Could not open or find the image";
        return nullptr;
    }
    cv::cvtColor( mat, mat, CV_BGR2BGRA );
    QByteArray outBytes;
    QDataStream outStream{ &outBytes, QIODevice::WriteOnly };
    outStream << mat.rows;
    outStream << mat.cols;
    outStream << mat.type( );
    QByteArray imgBytes{ ( char* )( mat.data ) };
    outStream << imgBytes;
    //qDebug( ) << "receive" << mat.rows << mat.cols << imgBytes.count( );
    return outBytes;
}

cv::Mat ImageSerialization::deserializeMat( QByteArray matData ) {
    int rows{ 0 };
    int cols{ 0 };
    int type{ CV_8UC4 };
    QByteArray imgBytes;
    QByteArray inBytes{ matData };
    QDataStream inStream{ &inBytes, QIODevice::ReadOnly };
    inStream >> rows;
    inStream >> cols;
    inStream >> type;
    inStream >> imgBytes;
    cv::Mat img = cv::Mat{ rows, cols, type, imgBytes.data( ) };
    if ( imgBytes.count( ) >= ( imgBytes.count( ) * 4096 ) )
        cv::imshow( "Display window", img );
    else
        qDebug( ) << "receive" << rows << cols << type << imgBytes.count( );
    return img;
}
