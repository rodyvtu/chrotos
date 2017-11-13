#ifndef PHOTOSMODEL_H
#define PHOTOSMODEL_H

#include <QAbstractListModel>

#include "photo.h"

class PhotosModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit PhotosModel(QObject *parent = 0);

    int columnCount(const QModelIndex &parent) const;
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    Photo photo(const QModelIndex &index) const;
    void addPhoto(const QString &fname);
    void addDir(const QString &dir);

private:
    QList<Photo> _data;
    QList<QString> _folders;

signals:
    // void orderChanged();
public slots:


};

#endif // PHOTOSMODEL_H
