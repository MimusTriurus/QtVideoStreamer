#include "MatSerialization.h"

#define MAT_EXT ".jpg"

QByteArray MatSerialization::serializeMat( const cv::Mat &mat , int quality ) {
    std::vector<uchar> buffer;
    std::vector<int> compressionParams = std::vector<int>( 2 );
    compressionParams[ 0 ] = 1;
    compressionParams[ 1 ] = quality;
    cv::imencode( MAT_EXT, mat, buffer, compressionParams );
    QByteArray result = QByteArray::fromRawData( reinterpret_cast<const char*>( buffer.data( ) ),
                                                 static_cast<int>( buffer.size( ) ) );
    return result;
}

cv::Mat MatSerialization::deserializeMat( const QByteArray &matData ) {
    std::vector<uchar> buffer( matData.cbegin( ), matData.cend( ) );
    cv::Mat result = cv::imdecode( cv::Mat( buffer ), 1 );
    return result;
}
