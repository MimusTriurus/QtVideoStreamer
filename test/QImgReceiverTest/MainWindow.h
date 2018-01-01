#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <VideoReceiver.h>

#include "FrameWindow.h"

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
    FrameWindow _frameWin;
    QLineEdit _port{ "10000" };
    VideoReciever _receiver;
    void initInterface( );
private slots:
    void onReceiveData( const QByteArray &data );
};

#endif // MAINWINDOW_H
