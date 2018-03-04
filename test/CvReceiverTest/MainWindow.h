#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <FpsChecker.h>
#include <VideoReceiver.h>

#include <opencv2/opencv.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow( QWidget *parent = nullptr );
    ~MainWindow( );
private:
    Ui::MainWindow  *ui;
    QLineEdit       _port{ "10000" };
    VideoReciever   _receiver;
    bool            _isListen{ false };
    QPushButton     _btnListen{ "Start" };
    FpsChecker      _fpsChecker;
    void initInterface( );
private slots:
    void onReceiveData( const QByteArray &data );
    void onListenClick( );
};

#endif // MAINWINDOW_H
