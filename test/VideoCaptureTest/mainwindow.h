#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <Capture.h>
#include <FpsChecker.h>

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

    Capture     _capture;
    FpsChecker  _fpsChecker;
    QTimer      _tmrFrameUpdate;
    bool        _start;

    QLineEdit   _camIndex;
    QLineEdit   _camFps;
    QCheckBox   _showCameraWin;
    QPushButton _btnStart;
    void initInterface( );
private slots:
    void onNewCvFrame( );
    void onBtnStartStop( );
};

#endif // MAINWINDOW_H
