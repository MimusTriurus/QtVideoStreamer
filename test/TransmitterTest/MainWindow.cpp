#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QTimer>
#include <QImageWriter>
#include <ImageSerialization.h>

#include <opencv2/core/core.hpp>

MainWindow::MainWindow( QString host, QWidget *parent ) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    capture = new Capture( this );

    capture->open( 0 );

    _frameTransmitterByUdp.host( host );
    _frameTransmitterByUdp.setQuality( 20 );

    _frameTransmitterByTcp.connectToHost( host, 65000 );

    connect( &_tmrFrameUpdate, SIGNAL( timeout( ) ), capture, SLOT( read( ) ) );

    //connect( capture, SIGNAL( newCvFrame( cv::Mat ) ),
             //this, SLOT( updateOriginalFrame( cv::Mat ) ) );
    connect( capture, SIGNAL( newQImage( QImage ) ),
             this, SLOT( updateOriginalFrame( QImage ) ) );

    _tmrFrameUpdate.start( 5 );
}

MainWindow::~MainWindow( ) {
    delete ui;
}

void MainWindow::updateOriginalFrame( const QImage &qOriginalFrame ) {
    //_background = qOriginalFrame;
    //this->repaint( );
    _frameTransmitterByUdp.sendQImage( qOriginalFrame );
}

void MainWindow::updateOriginalFrame( cv::Mat mat ) {
    _frameTransmitterByUdp.sendNewFrame( mat );
    _frameTransmitterByTcp.sendNewFrame( mat );
}

void MainWindow::paintEvent( QPaintEvent *event ) {
    Q_UNUSED( event )
/*
    if ( _background.isNull( ) ) return;
    QPainter painter( this );
    painter.drawImage( 0, 0, _background.scaled( this->size( ) ) );
*/
}
