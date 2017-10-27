#ifndef PHOTOVIEWER_H
#define PHOTOVIEWER_H

#include <QDebug>
#include <QWidget>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPalette>
#include <QMessageBox>
#include <QImage>
#include <QImageReader>

class PhotoViewer : public QWidget
{
    Q_OBJECT

private:
    QImage image;
    QScrollArea* imageScrollArea;
    QLabel* imageLabel;
    double scalefactor;

    void createActions();

public:
    explicit PhotoViewer(QWidget *parent = 0);
    ~PhotoViewer();

    bool PhotoViewer::loadFile(const QString &fileName);
};

#endif // PHOTOVIEWER_H
