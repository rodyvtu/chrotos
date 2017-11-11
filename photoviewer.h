#ifndef PHOTOVIEWER_H
#define PHOTOVIEWER_H

#include <QDebug>
#include <QDir>
#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPalette>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <QImageReader>

class PhotoViewer : public QWidget
{
    Q_OBJECT

public:
    explicit PhotoViewer(QWidget *parent = 0);
    ~PhotoViewer();

protected:
    bool loadFile(const QString &fileName);
    void createActions();

protected slots:
    void openFile();

private:
    QImage* _image;
    QVBoxLayout* _layout;
    QPushButton* _button;
    QLabel* _imageLabel;
    double _scaleFactor;

};

#endif // PHOTOVIEWER_H
