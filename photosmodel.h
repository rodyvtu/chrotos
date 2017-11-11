#ifndef PHOTOSMODEL_H
#define PHOTOSMODEL_H

#include <QAbstractListModel>

class PhotosModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit PhotosModel(QObject *parent = 0);

    int columnCount(const QModelIndex &parent) const;
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

signals:

public slots:
};

#endif // PHOTOSMODEL_H
