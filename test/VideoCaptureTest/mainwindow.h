#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Capture.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Capture *capture;
    QTimer _tmrFrameUpdate;
private slots:
    void updateOriginalFrame(const QImage &qOriginalFrame);
};

#endif // MAINWINDOW_H
