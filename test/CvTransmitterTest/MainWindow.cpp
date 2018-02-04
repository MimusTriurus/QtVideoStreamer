#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <MatSerialization.h>

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
    mainLayout->addWidget( &_toGrayscale );
    mainLayout->addWidget( &_resize );
    mainLayout->addWidget( &_byLink );

    auto lbl = new QLabel( "Set camera:", this );
    mainLayout->addWidget( lbl );
    mainLayout->addWidget( &_cameraId );

    lbl = new QLabel( "Set host:", this );
    mainLayout->addWidget( lbl );
    mainLayout->addWidget( &_host );

    lbl = new QLabel( "Set port:", this );
    mainLayout->addWidget( lbl );
    mainLayout->addWidget( &_port );

    lbl = new QLabel( "Set quality( 20 - 90 ):", this );
    mainLayout->addWidget( lbl );
    mainLayout->addWidget( &_quality );

    connect( &_btnStart, SIGNAL( clicked( ) ), this, SLOT( onBtnStart( ) ) );
    mainLayout->addWidget( &_btnStart );

    mainLayout->addWidget( &_log );
}

void MainWindow::onBtnStart( ) {
    if ( !_capture.isOpened( ) ) {
        bool opened = _capture.open( _cameraId.text( ).toInt( ) );
        if ( opened ) {
            _transmitter.host( _host.text( ) );
            _transmitter.port( _port.text( ).toInt( ) );
            _tmrFrameUpdate.start( Capture::getIntervalByMaxFps( 30 ) );
            _btnStart.setText( "Stop" );
        }
        else
            onCrash( "camera:" + _cameraId.text( ) + " is not opened" );
    }
    else {
        _btnStart.setText( "Start" );
        _capture.close( );
        _tmrFrameUpdate.stop( );
    }
}

void MainWindow::onUpdateFrame( ) {
    cv::Mat frame;
    _capture.read( frame );
    if ( frame.empty( ) ) {
        onCrash( "frame is empty" );
        return;
    }

    if ( _toGrayscale.isChecked( ) )
        cv::cvtColor( frame, frame, cv::COLOR_BGR2GRAY );
    if ( _resize.isChecked( ) ) {
        cv::resize( frame, frame, cv::Size( 320, 240 ) );
    }

    if ( frame.data ) {
        if ( _showFrameWin.isChecked( ) ) {
            cv::namedWindow( "Transmitter", cv::WINDOW_AUTOSIZE );
            cv::imshow( "Transmitter", frame );
        }
        int quality{ _quality.text( ).toInt( ) };

        if ( _byLink.isChecked( ) ) {
            std::vector<uchar> outputBytesNew;
            MatSerialization::serializeMat( frame, outputBytesNew, quality );
            _transmitter.sendFrameData( outputBytesNew );
        }
        else {
            QByteArray outputBytes;
            outputBytes = MatSerialization::serializeMat( frame, quality );
            _transmitter.sendFrameData( outputBytes );
        }
    }
}

void MainWindow::onCrash( const QString &crashMessage ) {
    _log.append( "<font color = red>CRASH:" + crashMessage + "<\\font>" );
}
