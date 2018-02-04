#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QLabel>
#include <QLayout>
#include <QTimer>

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    ui->setupUi( this );
    _showCameraWin.setChecked( true );
    _capture.frameHeight( 1080 );
    _capture.frameWidth( 1920 );
    connect( &_tmrFrameUpdate, SIGNAL( timeout( ) ), this, SLOT( onNewCvFrame( ) ) );
    initInterface( );
}

void MainWindow::initInterface( ) {
    auto l = new QVBoxLayout( this->centralWidget( ) );
    this->centralWidget( )->setLayout( l );
    connect( &_btnStart, &QPushButton::clicked, this, &MainWindow::onBtnStartStop );
    l->addWidget( new QLabel( "Camera index", this->centralWidget( ) ) );
    l->addWidget( &_camIndex );
    l->addWidget( new QLabel( "Camera max fps", this->centralWidget( ) ) );
    l->addWidget( &_camFps );
    l->addWidget( &_showCameraWin );
    l->addWidget( &_btnStart );
}

MainWindow::~MainWindow( ) {
    _capture.close( );
    delete ui;
}

void MainWindow::onNewCvFrame( ) {
    _fpsChecker.stop( );
    _fpsChecker.start( );
    cv::Mat frame;
    _capture.read( frame );
    if ( !frame.empty( ) && _showCameraWin.isChecked( ) ) {
        //cv::resize( frame, frame, cv::Size( 640, 360 ), 0, 0, cv::INTER_CUBIC );

        cv::putText( frame,
                     cv::format( "FPS=%d",
                     _fpsChecker.fps( ) ),
                     cv::Point( 30, 30 ),
                     cv::FONT_HERSHEY_SIMPLEX,
                     0.8,
                     cv::Scalar( 255, 0, 0 ) );

        imshow( "win", frame );
    }
}

void MainWindow::onBtnStartStop( ) {
    _start = !_start;
    if ( _start ) {
        int num = _camIndex.text( ).toInt( );
        int interval = Capture::getIntervalByMaxFps( _camFps.text( ).toInt( ) );
        _tmrFrameUpdate.setInterval( interval );
        _btnStart.setText( "Stop" );
        _capture.open( num );
        _tmrFrameUpdate.start( );
    }
    else {
        _btnStart.setText( "Start" );
        _capture.close( );
        _tmrFrameUpdate.stop( );
        _fpsChecker.reset( );
    }
}
