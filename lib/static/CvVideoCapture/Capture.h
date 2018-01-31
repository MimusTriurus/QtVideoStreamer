#ifndef CAPTURE_H
#define CAPTURE_H

#include <QtCore>
#include <QObject>
#include <QThread>
#include <opencv2/opencv.hpp>

#define DEFAULT_CAMERA_ID 0
/**
 * @brief Предназначен для получения кадров в формате cv::Mat
 * из различных источников видео информации средствами cv::VideoCapture
 */
class Capture : public QObject {
    Q_OBJECT
public:
    explicit Capture( QObject *parent = nullptr );
    ~Capture( );

    void frameHeight( int value );
    void frameWidth( int value );
    void fps( int value );

    bool isOpened( );
public slots:
    /**
     * @brief чтение очередного кадра
     * @return кадр
     */
    cv::Mat read( );

    bool retrieve( cv::Mat &mat );
    /**
     * @brief получение доступа к камере
     * @param deviceId идентификатор камеры
     * @return успешное\не успешное получение доступа к камере
     */
    bool open( const int deviceId = DEFAULT_CAMERA_ID );

    void close( );
signals:
    /**
     * @brief сообщение об ошибке
     */
    void onError( const QString & );
private:
    cv::Mat _frame;
    cv::VideoCapture _capture;
};

#endif // CAPTURE_H
