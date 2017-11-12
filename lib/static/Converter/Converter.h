#ifndef CONVERTER_H
#define CONVERTER_H

#include <QtCore>
#include <QByteArray>

namespace Converter {
    template <typename T>
    QByteArray convertToByteArray( T value ) {
        QByteArray array;
        QDataStream stream( &array, QIODevice::ReadWrite );
        stream << value;
        return array;
    }

    template <typename T>
    T convertFromByteArray( const QByteArray &bytes ) {
        T result;
        QDataStream stream( bytes );
        stream >> result;
        return result;
    }
}



#endif // CONVERTER_H
