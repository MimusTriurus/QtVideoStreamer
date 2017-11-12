#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    capture = new Capture( this );

    capture->open( );

    connect( &_tmrFrameUpdate, SIGNAL( timeout( ) ), capture, SLOT( read( ) ) );
    connect( capture, SIGNAL( newFrame( QImage ) ),
             this, SLOT( updateOriginalFrame( QImage ) ) );
    _tmrFrameUpdate.start( 5 );

    connect( capture, SIGNAL( newFrame( cv::Mat& ) ),
             &_frameTransmitter, SLOT( sendNewFrame( cv::Mat& ) ) );

    _frameTransmitter.connectToHost( );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateOriginalFrame( const QImage &qOriginalFrame )
{
    ui->label->setPixmap( QPixmap::fromImage( qOriginalFrame ) );
}
