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

    bool                _cameraIsOpen   { false };
    bool                _showFrameWindow{ false };
    bool                _grayScale      { false };
    bool                _link           { false };
    bool                _resizeFrame    { false };
    int                 _qual           { 50 };

    Capture             _capture;
    QTimer              _tmrFrameUpdate;
    VideoTransmitter    _transmitter;

    QLineEdit           _cameraId    { "0" };
    QLineEdit           _host        { "192.168.1.41" };
    QLineEdit           _port        { "10000" };
    QTextEdit           _log;
    QCheckBox           _showFrameWin{ "Show frame window" };
    QCheckBox           _toGrayscale { "Convert BGR2RGB" };
    QCheckBox           _resize      { "Resize to 320x240" };
    QLineEdit           _quality     { "50" };

    QPushButton         _btnStart    { "Start" };

    FpsChecker          _fpsChecker;
    void initInterface( );
private slots:
    void onBtnStart( );
    void onCrash( const QString &crashMessage );
    void onUpdateFrame( );
};

#endif // MAINWINDOW_H
