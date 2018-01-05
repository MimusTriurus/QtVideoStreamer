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
    cv::namedWindow( "Receiver", cv::WINDOW_AUTOSIZE );
    cv::Mat img{ MatSerialization::deserializeMat( data ) };
    if ( !img.empty( ) )
        cv::imshow( "Receiver", img );
}

void MainWindow::initInterface( ) {
    this->centralWidget( )->setLayout( new QVBoxLayout( this->centralWidget( ) ) );
    this->centralWidget( )->layout( )->addWidget( new QLabel( "Set listening port" ) );
    this->centralWidget( )->layout( )->addWidget( &_port );
    auto btnListen = new QPushButton( "Start to listen", this );
    connect( btnListen, &QPushButton::clicked, [ this ]( ) {
        this->_receiver.listen( this->_port.text( ).toInt( ) );
    } );
    this->centralWidget( )->layout( )->addWidget( btnListen );
    this->centralWidget( )->layout( )->setAlignment( Qt::AlignTop );
}
