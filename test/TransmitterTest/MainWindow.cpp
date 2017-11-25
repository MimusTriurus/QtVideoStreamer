#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QTimer>
#include <QImageWriter>
#include <ImageSerialization.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    capture = new Capture( this );

    capture->open( 1 );

    connect( &_tmrFrameUpdate, SIGNAL( timeout( ) ), capture, SLOT( read( ) ) );

    connect( capture, SIGNAL( newQFrame( QImage ) ),
             this, SLOT( updateOriginalFrame( QImage ) ) );

    _tmrFrameUpdate.start( 5 );
}

MainWindow::~MainWindow( ) {
    delete ui;
}

void MainWindow::updateOriginalFrame( const QImage &qOriginalFrame ) {
    _frameTransmitter.sendNewFrame( ImageSerialization::serialize( qOriginalFrame ) );
    _background = qOriginalFrame;
    this->repaint( );
}

void MainWindow::paintEvent( QPaintEvent *event ) {
    Q_UNUSED( event )
    if ( _background.isNull( ) ) return;
    QPainter painter( this );
    painter.drawImage( 0, 0, _background.scaled( this->size( ) ) );
}
