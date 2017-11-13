#ifndef PHOTO_H
#define PHOTO_H

#include <QSize>
#include <QString>
#include <QDate>
#include <QTime>
#include <QDateTime>

class Photo {

public:
    explicit Photo();
    explicit Photo(const QString fname);

    QString file() const;
    QString dir() const;
    QDateTime dateTime() const;

    QString setFile() const;
    QString setDir() const;
    QDateTime setDateTime() const;

protected:
    void _loadFileData(const QString & fname);

private:
    QString _file;
    QString _dir;

    // Exif data
    int _width;
    int _height;
    double _latitude;
    double _longitude;
    QString _camera;
    double _rotation;
    QDateTime _datetime;
};

#endif // PHOTO_H
