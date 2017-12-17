#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Capture.h"

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
    const std::string CV_WIN_NAME{ "win" };
    const int CAMERA_ID{ 0 };
    const int UPDATE_FRAME_INTERVAL{ 5 };
private slots:
    void onNewCvFrame( const cv::Mat &frame );
};

#endif // MAINWINDOW_H
