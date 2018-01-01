#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <ImageSerialization.h>

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    ui->setupUi( this );
    initInterface( );

    connect( &_transmitter, SIGNAL( onError( QString ) ),
             this, SLOT( onCrash( QString ) ) );
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
    if ( _showFrameWin.isChecked( ) ) {
        connect( &_qCapture, SIGNAL( grabed( QImage ) ),
                 &_frameWnd, SLOT( drawBackgroundImg( QImage ) ) );
        _frameWnd.show( );
    }
    _transmitter.host( _host.text( ) );
    _transmitter.port( _port.text( ).toInt( ) );

    connect( &_qCapture, SIGNAL( grabed( QImage ) ),
             this, SLOT( onGrabImg( QImage ) ) );
    _qCapture.start( );
}

void MainWindow::onGrabImg( const QImage &img ) {
    _transmitter.sendFrameData( ImageSerialization::serializeImg( img ) );
}

void MainWindow::onCrash( const QString &crashMessage ) {
    _log.append( "<font color = red>CRASH:" + crashMessage + "<\\font>" );
}
