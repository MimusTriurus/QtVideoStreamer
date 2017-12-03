#include "MainWindow.h"
#include <QApplication>
#include <QDebug>

int main( int argc, char *argv[ ] )
{
    QApplication a( argc, argv );
    QString host{ "localhost" };
    if ( argc > 1 ) {
        qDebug( ) << argv[ 1 ];
        host = argv[ 1 ];
    }

    MainWindow w{ host };
    w.show( );

    return a.exec( );
}
