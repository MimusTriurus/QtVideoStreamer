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
    connect( &_tmrFrameUpdate, SIGNAL( timeout( ) ), this, SLOT( onNewCvFrame( ) ) );
    _tmrFrameUpdate.setInterval( UPDATE_FRAME_INTERVAL );
    initInterface( );
}

void MainWindow::initInterface( ) {
    auto l = new QVBoxLayout( this->centralWidget( ) );
    this->centralWidget( )->setLayout( l );
    connect( &_btnStart, &QPushButton::clicked, this, &MainWindow::onBtnStartStop );
    l->addWidget( new QLabel( "Camera index", this->centralWidget( ) ) );
    l->addWidget( &_camIndex );
    l->addWidget( &_showCameraWin );
    l->addWidget( &_btnStart );
}

MainWindow::~MainWindow( ) {
    _capture.close( );
    delete ui;
}

void MainWindow::onNewCvFrame( ) {
    cv::Mat frame{ _capture.read( ) };
    if ( !frame.empty( ) && _showCameraWin.isChecked( ) ) {
        //cv::resize( frame, frame, cv::Size( 640, 360 ), 0, 0, cv::INTER_CUBIC );
        imshow( "win", frame );
    }
}

void MainWindow::onBtnStartStop( ) {
    _start = !_start;
    int num = _camIndex.text( ).toInt( );
    if ( _start ) {
        _btnStart.setText( "Stop" );
        _capture.open( num );
        _tmrFrameUpdate.start( );
    }
    else {
        _btnStart.setText( "Start" );
        _capture.close( );
        _tmrFrameUpdate.stop( );
    }
}
