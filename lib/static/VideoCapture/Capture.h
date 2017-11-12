#ifndef CAPTURE_H
#define CAPTURE_H

#include <QtCore>
#include <QObject>
#include <QDebug>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#define DEFAULT_CAMERA_ID 0

/**
 * @brief Предназначен для получения кадров в формате QImage, cv::Mat
 * из различных исчников видео информации
 */
class Capture : public QObject
{
    Q_OBJECT
public:
    explicit Capture( QObject *parent = nullptr );
public slots:
    /**
     * @brief чтение очередного кадра
     * @return успешное\не успешное чтение
     */
    bool read( );
    /**
     * @brief получение доступа к камере
     * @param deviceId идентификатор камеры
     * @return успешное\не успешное получение доступа к камере
     */
    bool open( int deviceId = DEFAULT_CAMERA_ID );
    /**
     * @brief получение доступа к иному источнику видео
     * @param source источник видео (файл, url, udp, rtsp )
     * @return успешное\не успешное получение доступа к источнику
     */
    bool open( const QString &source );
signals:
    /**
     * @brief новый кадр получен из источника
     */
    void newFrame( const QImage & );
    /**
     * @brief новый кадр получен из источника
     */
    void newFrame( cv::Mat & );
private:
    cv::VideoCapture _cap;
};

#endif // CAPTURE_H
