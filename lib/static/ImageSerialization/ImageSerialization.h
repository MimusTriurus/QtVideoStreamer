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
    static QByteArray serializeImg( QImage img );
    static QImage deserializeImg( QByteArray imgData );

    static QByteArray serializeMat( cv::Mat mat );
    static cv::Mat deserializeMat( QByteArray matData );
};

#endif // IMAGESERIALIZATION_H
