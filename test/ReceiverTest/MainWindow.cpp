#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect( &_frameReciever, &VideoReciever::imageReceived, this, &MainWindow::onReceiveImg );
    connect( &_frameReceiver, SIGNAL( matReceived( cv::Mat ) ), this, SLOT( onReceiveImg( cv::Mat ) ) );
}

MainWindow::~MainWindow( ) {
    delete ui;
}

void MainWindow::paintEvent( QPaintEvent *event ) {
    Q_UNUSED( event )
    if ( _background.isNull( ) ) return;
    QPainter painter( this );
    painter.drawImage( 0, 0, _background.scaled( this->size( ) ) );
}

void MainWindow::onReceiveImg( QImage frame ) {
    _background = frame;
    this->repaint( );
}

void MainWindow::onReceiveImg( cv::Mat img ) {
    //qDebug( ) << "receive img";
    if ( img.data ) {
        qDebug( ) << img.rows << img.cols;
        //cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
        //cv::imshow( "Display window", img );
    }
}
