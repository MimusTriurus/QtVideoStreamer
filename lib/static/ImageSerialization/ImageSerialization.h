#ifndef IMAGESERIALIZATION_H
#define IMAGESERIALIZATION_H

#include <QtCore>
#include "opencv2/opencv.hpp"
/**
 * @brief Сериализация и десериализация QImage
 */
class ImageSerialization
{
public:
    ImageSerialization( ) = delete;
    static QByteArray serializeImg( const QImage &img );
    static QImage deserializeImg( QByteArray imgData );

    static QByteArray serializeMat( const cv::Mat &mat, int quality = 80 );
    static cv::Mat deserializeMat( const QByteArray &matData );
};

#endif // IMAGESERIALIZATION_H
