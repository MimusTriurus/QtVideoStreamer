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
    connect( &_camera, SIGNAL( grabed( QImage ) ),
             this, SLOT( onGrabImg( QImage ) ) );
    _camera.start( );
}

void MainWindow::paintEvent( QPaintEvent * ) {
    QPainter painter( this );
    painter.drawImage( 0,0, _capturedFrame );
}

void MainWindow::onGrabImg( const QImage &img ) {
    _capturedFrame = img;
    this->repaint( );
}
