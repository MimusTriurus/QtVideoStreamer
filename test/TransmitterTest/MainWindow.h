#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

#include <Capture.h>
#include <VideoTransmitter.h>
#include <VideoTransmitterByTcp.h>

#include "opencv2/opencv.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QString host, QWidget *parent = nullptr );
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Capture *capture;
    QImage _background;
    QTimer _tmrFrameUpdate;
    VideoTransmitter      _frameTransmitterByUdp{ "127.0.0.1", 10000 };
    VideoTransmitterByTcp _frameTransmitterByTcp;
private slots:
    void updateOriginalFrame( const QImage &qOriginalFrame );
    void updateOriginalFrame( cv::Mat mat );
    // QWidget interface
protected:
    void paintEvent( QPaintEvent *event );
};

#endif // MAINWINDOW_H
