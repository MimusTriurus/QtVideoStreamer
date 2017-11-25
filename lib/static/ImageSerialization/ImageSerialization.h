#ifndef IMAGESERIALIZATION_H
#define IMAGESERIALIZATION_H

#include <QtCore>
/**
 * @brief Сериализация и десериализация QImage
 */
class ImageSerialization
{
public:
    ImageSerialization( ) = delete;
    static QByteArray serialize( QImage img );
    static QImage deserialize( QByteArray imgData );
};

#endif // IMAGESERIALIZATION_H
