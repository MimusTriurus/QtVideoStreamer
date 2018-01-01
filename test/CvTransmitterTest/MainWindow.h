#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QTimer>

#include <Capture.h>
#include <VideoTransmitter.h>

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
    Ui::MainWindow      *ui;

    Capture             _capture;
    QTimer              _tmrFrameUpdate;
    VideoTransmitter    _transmitter;

    QLineEdit           _cameraId{ "0" };
    QLineEdit           _host{ "127.0.0.1" };
    QLineEdit           _port{ "10000" };
    QTextEdit           _log;
    QCheckBox           _showFrameWin{ "Show frame window" };

    void initInterface( );
private slots:
    void onBtnStart( );
    void onCrash( const QString &crashMessage );
    void onUpdateFrame( const cv::Mat &frame );
};

#endif // MAINWINDOW_H
