#include "FrameWindow.h"

FrameWindow::FrameWindow( QWidget *parent ) : QMainWindow( parent ) {

}

void FrameWindow::drawBackgroundImg( const QImage &img ) {
    _backgroundImg = img;
    if ( this->width( ) != img.width( ) )
        this->setMinimumWidth( img.width( ) );
    if ( this->height( ) != img.height( ) )
        this->setMinimumHeight( img.height( ) );
    this->repaint( );
}

void FrameWindow::paintEvent( QPaintEvent * ) {
    QPainter painter{ this };
    painter.drawImage( 0, 0, _backgroundImg );
}

