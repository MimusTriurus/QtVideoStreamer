#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect( &_frameReciever, &VideoReciever::imageReceived, this, &MainWindow::onReceiveImg );
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
