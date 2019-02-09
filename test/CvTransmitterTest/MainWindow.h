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
#include <FpsChecker.h>

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
    Ui::MainWindow      *ui;

    bool                _cameraIsOpen;
    bool                _showFrameWindow;
    bool                _grayScale;
    bool                _link;
    bool                _resizeFrame;
    int                 _qual;

    Capture             _capture;
    QTimer              _tmrFrameUpdate;
    VideoTransmitter    _transmitter;

    QLineEdit           _cameraId;
    QLineEdit           _host;
    QLineEdit           _port;
    QTextEdit           _log;
    QCheckBox           _showFrameWin;
    QCheckBox           _toGrayscale;
    QCheckBox           _resize;
    QLineEdit           _quality;

    QLineEdit           _width;
    QLineEdit           _height;

    QLineEdit           _fps;

    QPushButton         _btnStart;

    FpsChecker          _fpsChecker;
    void initInterface( );
private slots:
    void onBtnStart( );
    void onCrash( const QString &crashMessage );
    void onUpdateFrame( );
};

#endif // MAINWINDOW_H
