#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QCamera>
#include <QTimer>
#include <QCameraInfo>
#include <QCameraImageCapture>

#include <QVideoCapture.h>

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
    QVideoCapture       _camera{ QCameraInfo::defaultCamera( ) };
    QImage              _capturedFrame;
    void init( );
    // QWidget interface
protected:
    void paintEvent( QPaintEvent * ) override;
private slots:
    void onGrabImg( const QImage &img );
};

#endif // MAINWINDOW_H
