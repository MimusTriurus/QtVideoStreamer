#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <MatSerialization.h>
#include <iostream>

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow     { parent },
    ui              { new Ui::MainWindow },
    _cameraIsOpen   { false },
    _showFrameWindow{ false },
    _grayScale      { false },
    _link           { false },
    _resizeFrame    { false },
    _qual           { 50 },
    _cameraId       { "0" },
    _host           { "127.0.0.1" },
    _port           { "10000" },
    _showFrameWin   { "Show frame window" },
    _toGrayscale    { "Convert BGR2RGB" },
    _resize         { "Resize to 320x240" },
    _quality        { "50" },
    _width          { "640" },
    _height         { "480" },
    _fps            { "30" },
    _btnStart       { "Start" }
{
    ui->setupUi( this );
    initInterface( );

    connect( &_tmrFrameUpdate, SIGNAL( timeout( ) ),
             this, SLOT( onUpdateFrame( ) ) );
    connect( &_capture, SIGNAL( onError( QString ) ),
             this, SLOT( onCrash( QString ) ) );
}

MainWindow::~MainWindow( ) {
    delete ui;
}

void MainWindow::initInterface( ) {
    auto mainLayout = new QVBoxLayout( this->centralWidget( ) );
    this->centralWidget( )->setLayout( mainLayout );
    _showFrameWin.setChecked( false );
    mainLayout->addWidget( &_showFrameWin );
    mainLayout->addWidget( &_toGrayscale );
    mainLayout->addWidget( &_resize );

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

    lbl = new QLabel( "Set camera resolution( width x height ):", this );
    mainLayout->addWidget( lbl );
    mainLayout->addWidget( &_width );
    mainLayout->addWidget( &_height );

    lbl = new QLabel( "Set camera FPS:", this );
    mainLayout->addWidget( lbl );
    mainLayout->addWidget( &_fps );

    connect( &_btnStart, SIGNAL( clicked( ) ), this, SLOT( onBtnStart( ) ) );
    mainLayout->addWidget( &_btnStart );

    mainLayout->addWidget( &_log );
}

void MainWindow::onBtnStart( ) {
    if ( !_capture.isOpened( ) ) {
        bool opened = _capture.open( _cameraId.text( ).toInt( ) );
        if ( opened ) {
            _capture.resolution( _width.text( ).toInt( ), _height.text( ).toInt( ) );
            _capture.fps( _fps.text( ).toInt( ) );
            _transmitter.host( _host.text( ) );
            _transmitter.port( _port.text( ).toInt( ) );
            _tmrFrameUpdate.start( Capture::getIntervalByMaxFps( _capture.fps( ) ) );
            _btnStart.setText( "Stop" );

            _showFrameWindow = _showFrameWin.isChecked( );
            _grayScale       = _toGrayscale.isChecked( );
            _resizeFrame     = _resize.isChecked( );
            _qual            = _quality.text( ).toInt( );
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
    _fpsChecker.stop( );
    _fpsChecker.start( );

    cv::Mat frame;
    _capture.read( frame );
    if ( frame.empty( ) ) {
        onCrash( "frame is empty" );
        return;
    }

    if ( _grayScale )
        cv::cvtColor( frame, frame, cv::COLOR_BGR2GRAY );

    if ( _resizeFrame ) {
        cv::resize( frame, frame, cv::Size( 320, 240 ) );
    }

    if ( frame.data ) {
        if ( _showFrameWindow ) {
            cv::namedWindow( "Transmitter", cv::WINDOW_AUTOSIZE );

            cv::putText( frame,
                         cv::format( "FPS=%d",
                         _fpsChecker.fps( ) ),
                         cv::Point( 30, 30 ),
                         cv::FONT_HERSHEY_SIMPLEX,
                         0.8,
                         cv::Scalar( 255, 0, 0 ) );

            cv::imshow( "Transmitter", frame );
        }

        int quality = _qual;
        std::vector<uchar> outputBytesNew( frame.rows * frame.cols);
        MatSerialization::serializeMat( frame, outputBytesNew, quality );
        _transmitter.sendFrameData( outputBytesNew );
    }
}

void MainWindow::onCrash( const QString &crashMessage ) {
    _log.append( "<font color = red>CRASH:" + crashMessage + "<\\font>" );
}
