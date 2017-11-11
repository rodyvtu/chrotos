#include "photosmodel.h"

PhotosModel::PhotosModel(QObject *parent) : QAbstractTableModel()
{

}

int PhotosModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

int PhotosModel::rowCount(const QModelIndex &parent) const
{
    return 50;
}

QVariant PhotosModel::data(const QModelIndex &index, int role) const
{
    QString txt;
    QVariant data;

    if(role == Qt::DisplayRole)
    {
        // Create some artificial data
        txt = tr("Item (%1,%2)").arg(index.row()+1).arg(index.column()+1);

        // Wrap in QVariant
        data.setValue(txt);
    }

    return data;
}

QVariant PhotosModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    QString txt;
    QString name;
    QVariant data;

    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal){
            name = "Col. ";
        } else {
            name = "Row ";
        }

        // Create some artificial data
        txt = tr("%1 %2").arg(name).arg(section+1);

        // Wrap in QVariant
        data.setValue(txt);
    }

    return data;
}
