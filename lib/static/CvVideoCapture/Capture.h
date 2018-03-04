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
    bool isOpened( ) const;
    /**
     * @brief сеттер разрешения камеры
     * @param width
     * @param height
     */
    void resolution( double width, double height );
    /**
     * @brief геттер ширины кадра
     * @return ширина кадра
     */
    double width( ) const;
    /**
     * @brief геттер высоты кадра
     * @return высота кадра
     */
    double height( ) const ;
    /**
     * @brief сеттер fps для камеры
     * @param fps камеры
     */
    void fps( double value );
    /**
     * @brief геттер fps для камеры
     * @return fps камеры
     */
    double fps( ) const;
    /**
     * @brief получаем интервал опроса камеры
     * на получение нового кадра исходя из требуемого максимального fps
     * @param fps масксимальный fps камер( не факт что камера его выдаст )
     * @return интервал таймера опроса камеры на чтение кадра
     */
    static int getIntervalByMaxFps( const int fps );

    static void printOpenCvBuildInfo( );
public slots:
    void read( cv::Mat &mat );
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
    cv::VideoCapture _capture;
};

#endif // CAPTURE_H
