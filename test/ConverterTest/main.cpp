#include <QCoreApplication>
#include <QDebug>
#include <Converter.h>

int main( int argc, char *argv[ ] )
{
    QCoreApplication a( argc, argv );
    QByteArray array = Converter::convertToByteArray<uchar>( 5 );

    qDebug( ) << array;
    qDebug( ) << Converter::convertFromByteArray<uchar>( array );

    return a.exec();
}

