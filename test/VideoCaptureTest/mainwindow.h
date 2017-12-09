#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "Capture.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = nullptr );
    ~MainWindow( );
private:
    Ui::MainWindow *ui;
    Capture _capture;
    QImage _background;
    QTimer _tmrFrameUpdate;
    const std::string CV_WIN_NAME{ "win" };
    const int CAMERA_ID{ 0 };
    const int UPDATE_FRAME_INTERVAL{ 5 };
private slots:
    void onNewQFrame( QImage frame );
    void onNewCvFrame( cv::Mat frame );

    // QWidget interface
protected:
    void paintEvent( QPaintEvent *event );
};

#endif // MAINWINDOW_H
