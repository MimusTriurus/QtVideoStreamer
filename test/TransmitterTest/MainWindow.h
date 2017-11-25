#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Capture.h>
#include <VideoTransmitter.h>
#include <QUdpSocket>
#include <QPainter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = nullptr );
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Capture *capture;
    QImage _background;
    QTimer _tmrFrameUpdate;
    VideoTransmitter _frameTransmitter{ "127.0.0.1", 10000 };
private slots:
    void updateOriginalFrame( const QImage &qOriginalFrame );

    // QWidget interface
protected:
    void paintEvent( QPaintEvent *event );
};

#endif // MAINWINDOW_H
