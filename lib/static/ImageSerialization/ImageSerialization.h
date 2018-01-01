#ifndef IMAGESERIALIZATION_H
#define IMAGESERIALIZATION_H

#include <QtCore>
/**
 * @brief Сериализация и десериализация QImage
 */
class ImageSerialization {
public:
    ImageSerialization( ) = delete;
    static QByteArray serializeImg( const QImage &img );
    static QImage deserializeImg( QByteArray &imgData );
};

#endif // IMAGESERIALIZATION_H
