#ifndef MATSERIALIZATION_H
#define MATSERIALIZATION_H

#include <QtCore>
#include "opencv2/opencv.hpp"

/**
 * @brief Сериализация и десереализаци cv::Mat
 */
class MatSerialization {
public:
    MatSerialization( ) = delete;

    static QByteArray serializeMat( const cv::Mat &mat, int quality = 80 );
    static void serializeMat( const cv::Mat &mat, QByteArray &matData, int quality = 80 );
    static cv::Mat deserializeMat( const QByteArray &matData );
};

#endif // MATSERIALIZATION_H
