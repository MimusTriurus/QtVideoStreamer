#include "MatSerialization.h"

#define MAT_EXT ".jpg"

void MatSerialization::serializeMat( const cv::Mat &mat, std::vector<uchar> &output, int quality ) {
    std::vector<int> compressionParams = std::vector<int>( 2 );
    compressionParams[ 0 ] = cv::IMWRITE_JPEG_QUALITY;
    compressionParams[ 1 ] = quality;
    cv::imencode( MAT_EXT, mat, output, compressionParams );
}

cv::Mat MatSerialization::deserializeMat( const QByteArray &matData ) {
    std::vector<uchar> buffer( matData.cbegin( ), matData.cend( ) );
    cv::Mat result = cv::imdecode( cv::Mat( buffer ), 1 );
    return result;
}
