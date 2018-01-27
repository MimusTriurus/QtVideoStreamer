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
class Capture : public QThread {
    Q_OBJECT
public:
    explicit Capture( QObject *parent = nullptr );
    ~Capture( );

    void frameHeight( int value );
    void frameWidth( int value );
    void fps( int value );
public slots:
    /**
     * @brief чтение очередного кадра
     * @return кадр
     */
    cv::Mat read( );
    /**
     * @brief получение доступа к камере
     * @param deviceId идентификатор камеры
     * @return успешное\не успешное получение доступа к камере
     */
    bool open( const int deviceId = DEFAULT_CAMERA_ID );

    void close( );
protected:
    void run( );
signals:
    /**
     * @brief сообщение об ошибке
     */
    void onError( const QString & );
private:
    int _deviceId{ DEFAULT_CAMERA_ID };
    bool _work{ false };
    cv::Mat _frame;
    int _frameHeight{ 240 };
    int _frameWidth{ 320 };
    int _fps{ 30 };
};

#endif // CAPTURE_H
