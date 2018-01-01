#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QCamera>
#include <QTimer>
#include <QCameraInfo>
#include <QCameraImageCapture>

#include "CameraFrameGrabber.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = nullptr );
    ~MainWindow( );

private:
    Ui::MainWindow *ui;
    QCamera             _camera{ QCameraInfo::defaultCamera( ) };
    QImage              _capturedFrame;
    CameraFrameGrabber  _frameGrabber;
    void init( );
    // QWidget interface
protected:
    void paintEvent( QPaintEvent * );
private slots:
    void readyForCapture( bool ready );
    void onGrabImg( const QImage &img );
};

#endif // MAINWINDOW_H
