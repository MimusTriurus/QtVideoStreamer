#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect( &_frameReceiver, SIGNAL( matReceived( cv::Mat ) ), this, SLOT( onReceiveImg( cv::Mat ) ) );
    connect( &_frameReceiver, SIGNAL( imageReceived( QImage ) ), this, SLOT( onReceiveImg( QImage ) ) );
    connect( &_frameReceiverByTcp, SIGNAL( matReceived( cv::Mat ) ), this, SLOT( onReceiveImgByTcp( cv::Mat ) ) );
}

MainWindow::~MainWindow( ) {
    delete ui;
}

void MainWindow::paintEvent( QPaintEvent *event ) {
    Q_UNUSED( event )
//  Segmentation fault on Ubuntu and Raspbian
    if ( _background.isNull( ) ) return;
    QPainter painter( this );
    painter.drawImage( 0, 0, _background.scaled( this->size( ) ) );
}

void MainWindow::onReceiveImg( QImage frame ) {
    _background = frame;
    this->repaint( );
}

void MainWindow::onReceiveImg( cv::Mat img ) {
    if ( img.data ) {
        cv::namedWindow( "Udp", cv::WINDOW_AUTOSIZE );
        cv::imshow( "Udp", img );
        /*
        cv::resize( cvFrame, cvFrame, cv::Size( ), 0.5, 0.5 );
        cv::cvtColor( img, img, CV_BGR2RGB );
        QImage qFrame( ( uchar* )img.data,
                               img.cols,
                               img.rows,
                               img.step,
                               QImage::Format_RGB888 ) ;
        onReceiveImg( qFrame );
        */
    }
}

void MainWindow::onReceiveImgByTcp( cv::Mat img ) {
    if ( img.data ) {
      cv::namedWindow( "Tcp", cv::WINDOW_AUTOSIZE );
      cv::imshow( "Tcp", img );
      /*
      cv::resize( cvFrame, cvFrame, cv::Size( ), 0.5, 0.5 );
      cv::cvtColor( img, img, CV_BGR2RGB );
      QImage qFrame( ( uchar* )img.data,
                             img.cols,
                             img.rows,
                             img.step,
                             QImage::Format_RGB888 ) ;
      onReceiveImg( qFrame );
      */
    }
    else
        qDebug( ) << "error onReceiveImgByTcp";
}
