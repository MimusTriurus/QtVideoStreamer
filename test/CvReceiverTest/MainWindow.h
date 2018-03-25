#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <FpsChecker.h>
#include <VideoReceiver.h>
#include <QTimer>

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
    VideoReciever   _receiver;
    bool            _isListen   { false };
    QPushButton     _btnListen  { "Start" };
    QLineEdit       _port       { "10000" };
    FpsChecker      _fpsChecker;

    QTimer          _tmrUpdate;

    void initInterface( );
private slots:
    void onReceiveData( QByteArray data );
    void onListenClick( );

    void update( );
};

#endif // MAINWINDOW_H
