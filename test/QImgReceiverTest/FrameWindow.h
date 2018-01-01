#ifndef FRAMEWINDOW_H
#define FRAMEWINDOW_H

#include <QMainWindow>
#include <QPainter>

class FrameWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit FrameWindow( QWidget *parent = nullptr );

signals:

public slots:
    void drawBackgroundImg( const QImage &img );
protected:
    void paintEvent( QPaintEvent * ) override;
private:
    QImage _backgroundImg;
};

#endif // FRAMEWINDOW_H
