#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    ui->setupUi( this );
    init( );
}

MainWindow::~MainWindow( ) {
    delete ui;
}

void MainWindow::init( ) {
    _camera.setViewfinder( &_frameGrabber );
    connect( &_frameGrabber, SIGNAL( grabImg( QImage ) ),
             this, SLOT( onGrabImg( QImage ) ) );
    _camera.start( );
}

void MainWindow::paintEvent( QPaintEvent * ) {
    QPainter painter( this );
    painter.drawImage( 0,0, _capturedFrame );
}

void MainWindow::readyForCapture( bool ready ) {
    qDebug( ) << "ready for capture:" + ready;
}

void MainWindow::onGrabImg( const QImage &img ) {
    _capturedFrame = img;
    this->repaint( );
}
