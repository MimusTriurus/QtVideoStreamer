#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <VideoReceiver.h>
#include "opencv2/opencv.hpp"

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
    QLineEdit _port{ "10000" };
    VideoReciever _receiver;
    void initInterface( );
private slots:
    void onReceiveImg( const cv::Mat &img );
};

#endif // MAINWINDOW_H
