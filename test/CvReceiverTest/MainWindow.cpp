#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <MatSerialization.h>

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    ui->setupUi(this);

    connect( &_receiver, SIGNAL( imgDataReceived( QByteArray ) ),
             this, SLOT( onReceiveData( QByteArray ) ) );

    initInterface( );
}

MainWindow::~MainWindow( ) {
    delete ui;
}

void MainWindow::onReceiveData( const QByteArray &data ) {
    _fpsChecker.stop( );
    _fpsChecker.start( );
    cv::namedWindow( "Receiver", cv::WINDOW_AUTOSIZE );
    cv::Mat img{ MatSerialization::deserializeMat( data ) };
    if ( !img.empty( ) ) {
        cv::putText( img,
                     cv::format( "FPS=%d",
                     _fpsChecker.fps( ) ),
                     cv::Point( 30, 30 ),
                     cv::FONT_HERSHEY_SIMPLEX,
                     0.8,
                     cv::Scalar( 255, 0, 0 ) );
        cv::imshow( "Receiver", img );
    }

}

void MainWindow::onListenClick( ) {
    if ( !_isListen ) {
        this->_receiver.listen( this->_port.text( ).toInt( ) );
        _btnListen.setText( "Stop" );
    }
    else {
        _btnListen.setText( "Start" );
        this->_receiver.stopListen( );
    }
    _isListen = !_isListen;
}

void MainWindow::initInterface( ) {
    this->centralWidget( )->setLayout( new QVBoxLayout( this->centralWidget( ) ) );
    this->centralWidget( )->layout( )->addWidget( new QLabel( "Set listening port" ) );
    this->centralWidget( )->layout( )->addWidget( &_port );
    connect( &_btnListen, &QPushButton::clicked, this, &MainWindow::onListenClick );
    this->centralWidget( )->layout( )->addWidget( &_btnListen );
    this->centralWidget( )->layout( )->setAlignment( Qt::AlignTop );
}
