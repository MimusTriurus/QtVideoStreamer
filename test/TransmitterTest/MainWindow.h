#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Capture.h>
#include <VideoTransmitter.h>
#include <VideoReciever.h>
#include <QUdpSocket>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = nullptr );
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Capture *capture;
    QTimer _tmrFrameUpdate;
    VideoReciever _frameReciever;
    VideoTransmitter _frameTransmitter;
private slots:
    void updateOriginalFrame(const QImage &qOriginalFrame);
};

#endif // MAINWINDOW_H
