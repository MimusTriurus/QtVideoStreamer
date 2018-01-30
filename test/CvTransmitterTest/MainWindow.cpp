#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <MatSerialization.h>

#include <opencv2/core/core.hpp>

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    ui->setupUi( this );
    initInterface( );

    connect( &_tmrFrameUpdate, SIGNAL( timeout( ) ),
             this, SLOT( onUpdateFrame( ) ) );
    connect( &_capture, SIGNAL( onError( QString ) ),
             this, SLOT( onCrash( QString ) ) );
    //connect( &_transmitter, SIGNAL( onError( QString ) ),
             //this, SLOT( onCrash( QString ) ) );
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
    bool camOpened = _capture.open( _cameraId.text( ).toInt( ) );

    _transmitter.host( _host.text( ) );
    _transmitter.port( _port.text( ).toInt( ) );

    if ( camOpened )
        _tmrFrameUpdate.start( 5 );
}

void MainWindow::onUpdateFrame( ) {
    cv::Mat frame = _capture.read( );
    if ( frame.data ) {
        if ( _showFrameWin.isChecked( ) ) {
            cv::namedWindow( "Transmitter", cv::WINDOW_AUTOSIZE );
            cv::imshow( "Transmitter", frame );
        }
        _transmitter.sendFrameData( MatSerialization::serializeMat( frame ) );
    }
}

void MainWindow::onCrash( const QString &crashMessage ) {
    _log.append( "<font color = red>CRASH:" + crashMessage + "<\\font>" );
}
