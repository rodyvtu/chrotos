#include "photo.h"

Photo::Photo()
{
    _width = 0;
    _height = 0;
}

Photo::Photo(const QString fname)
{
    _file = fname;

    _loadFileData(fname);
}

void Photo::_loadFileData(const QString & fname)
{

    // Some demo data
    double latitude = 41.390205, longitude = 2.154007; // Barcelona, Spain
    QDate date(2017, 01, 01);
    QTime time(10,00,00);

    // Dimensions of the photo
    _width = 100;
    _height = 100;

    // Store exif data
    _datetime.setDate(date);
    _datetime.setTime(time);
    _camera = "Nikon D5600";
    _rotation = 0.0;
    _latitude = latitude;
    _longitude = longitude;
}
