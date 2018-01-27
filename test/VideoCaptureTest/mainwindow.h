#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <Capture.h>

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
    Capture _capture;
    QTimer _tmrFrameUpdate;
    bool _start{ false };
    const int CAMERA_ID{ 1 };
    const int UPDATE_FRAME_INTERVAL{ 5 };

    QLineEdit _camIndex{ "1" };
    QCheckBox _showCameraWin{ "Show Camera Win" };
    QPushButton _btnStart{ "Start" };
    void initInterface( );
private slots:
    void onNewCvFrame( );
    void onBtnStartStop( );
};

#endif // MAINWINDOW_H
