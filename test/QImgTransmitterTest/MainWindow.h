#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QCheckBox>

#include <QVideoCapture.h>
#include <VideoTransmitter.h>

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
    Ui::MainWindow      *ui;

    FrameWindow         _frameWnd;
    QVideoCapture       _qCapture;
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
    void onGrabImg( const QImage &img );
};

#endif // MAINWINDOW_H
