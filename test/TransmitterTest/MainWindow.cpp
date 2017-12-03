#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QTimer>
#include <QImageWriter>
#include <ImageSerialization.h>

MainWindow::MainWindow( QString host, QWidget *parent ) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    capture = new Capture( this );

    capture->open( 0 );

    _frameTransmitter.host( host );

    connect( &_tmrFrameUpdate, SIGNAL( timeout( ) ), capture, SLOT( read( ) ) );

    connect( capture, SIGNAL( newCvFrame( cv::Mat ) ),
             this, SLOT( updateOriginalFrame( cv::Mat ) ) );

    _tmrFrameUpdate.start( 1 );
}

MainWindow::~MainWindow( ) {
    delete ui;
}

void MainWindow::updateOriginalFrame( const QImage &qOriginalFrame ) {
    _background = qOriginalFrame;
    this->repaint( );
}

void MainWindow::updateOriginalFrame( cv::Mat mat ) {
    //_frameTransmitter.sendNewFrame( mat );
    //cv::imshow( "test", mat );
    _frameTransmitter.sendNewFrame( mat );
}

void MainWindow::paintEvent( QPaintEvent *event ) {
    Q_UNUSED( event )
    /*
    if ( _background.isNull( ) ) return;
    QPainter painter( this );
    painter.drawImage( 0, 0, _background.scaled( this->size( ) ) );
    */
}
