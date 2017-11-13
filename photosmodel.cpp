#include "photosmodel.h"

PhotosModel::PhotosModel(QObject *parent) : QAbstractTableModel()
{
    Photo photo;
    _data.append(photo);
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
    QString name;
    QVariant data;

    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal){
            switch(section)
            {
                case 0:
                    name = "photo";
                    break;
                case 1:
                    name = "folder";
                    break;
                case 2:
                    name = "width";
                    break;
                case 3:
                    name = "height";
                    break;
                default:
                    name = QString("Col. %1").arg(section);
                    break;
            }
        } else {
            // Create some artificial data
            name = tr("%1").arg(section+1);
        }

        // Wrap in QVariant
        data.setValue(name);
    }

    return data;
}


