#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <VideoReceiver.h>
#include <VideoReceiverByTcp.h>
#include "opencv2/opencv.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = nullptr );
    ~MainWindow( );
protected:
    void paintEvent( QPaintEvent *event );
private:
    QImage _background;
    Ui::MainWindow *ui;
    VideoReciever _frameReceiver;
    VideoReceiverByTcp _frameReceiverByTcp;
private slots:
    void onReceiveImg( QImage img );
    void onReceiveImg( cv::Mat img );
    void onReceiveImgByTcp( cv::Mat img );
};

#endif // MAINWINDOW_H
