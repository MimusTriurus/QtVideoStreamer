#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _capture.open( CAMERA_ID );

    connect( &_tmrFrameUpdate, SIGNAL( timeout( ) ), &_capture, SLOT( read( ) ) );
    connect( &_capture, SIGNAL( newQFrame( QImage ) ),
             this, SLOT( onNewQFrame( QImage ) ) );

    connect( &_capture, SIGNAL( newCvFrame( cv::Mat ) ),
             this, SLOT( onNewCvFrame( cv::Mat ) ) );

    _tmrFrameUpdate.setInterval( UPDATE_FRAME_INTERVAL );
    _tmrFrameUpdate.start( );

    cv::namedWindow( CV_WIN_NAME, 1 );
}

MainWindow::~MainWindow( ) {
    delete ui;
}

void MainWindow::onNewQFrame( QImage frame ) {
    _background = frame;
    this->repaint( );
}

void MainWindow::onNewCvFrame( cv::Mat frame ) {
    imshow( CV_WIN_NAME, frame );
}

void MainWindow::paintEvent( QPaintEvent *event ) {
    Q_UNUSED( event )
    QPainter painter( this );
    painter.drawImage( 0, 0, _background.scaled( this->size( ) ) );
}
