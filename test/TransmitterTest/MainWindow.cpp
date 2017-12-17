#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QTimer>
#include <QImageWriter>
#include <ImageSerialization.h>

#include <opencv2/core/core.hpp>

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    ui->setupUi( this );
    initInterface( );

    connect( &_tmrFrameUpdate, SIGNAL( timeout( ) ),
             &_capture, SLOT( read( ) ) );

    connect( &_capture, SIGNAL( onError( QString ) ),
             this, SLOT( onCrash( QString ) ) );
    connect( &_transmitter, SIGNAL( onError( QString ) ),
             this, SLOT( onCrash( QString ) ) );

    connect( &_capture, SIGNAL( newCvFrame( cv::Mat ) ),
             &_transmitter, SLOT( sendNewFrame( cv::Mat ) ) );
}

MainWindow::~MainWindow( ) {
    delete ui;
}

void MainWindow::initInterface( ) {
    auto mainLayout = new QVBoxLayout( this->centralWidget( ) );
    this->centralWidget( )->setLayout( mainLayout );
    _showFrameWin.setChecked( true );
    mainLayout->addWidget( &_showFrameWin );

    auto lbl = new QLabel( "Set camera:", this );
    mainLayout->addWidget( lbl );
    mainLayout->addWidget( &_cameraId );

    lbl = new QLabel( "Set host:", this );
    mainLayout->addWidget( lbl );
    mainLayout->addWidget( &_host );

    lbl = new QLabel( "Set port:", this );
    mainLayout->addWidget( lbl );
    mainLayout->addWidget( &_port );

    auto btn = new QPushButton( "Start", this );
    connect( btn, SIGNAL( clicked( ) ), this, SLOT( onBtnStart( ) ) );
    mainLayout->addWidget( btn );

    mainLayout->addWidget( &_log );
}

void MainWindow::onBtnStart( ) {
    if ( _showFrameWin.isChecked( ) )
        connect( &_capture, SIGNAL( newCvFrame( cv::Mat ) ),
             this, SLOT( onUpdateFrame( cv::Mat ) ) );
    bool camOpened = _capture.open( _cameraId.text( ).toInt( ) );
    _transmitter.host( _host.text( ) );
    _transmitter.port( _port.text( ).toInt( ) );
    if ( camOpened )
        _tmrFrameUpdate.start( 30 );
}

void MainWindow::onUpdateFrame( const cv::Mat &frame ) {
    if ( frame.data ) {
        cv::namedWindow( "Transmitter", cv::WINDOW_AUTOSIZE );
        cv::imshow( "Transmitter", frame );
    }
}

void MainWindow::onCrash( const QString &crashMessage ) {
    _log.append( "<font color = red>CRASH:" + crashMessage + "<\\font>" );
}
