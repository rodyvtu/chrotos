#include "photoviewer.h"

PhotoViewer::PhotoViewer(QWidget *parent) :
    QWidget(parent)
{


    // Set up image label
    imageLabel = new QLabel(this);
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    // Set up scroll area
    imageScrollArea = new QScrollArea(this);
    imageScrollArea->setBackgroundRole(QPalette::Dark);
    imageScrollArea->setVisible(false);
    imageScrollArea->setWidget(imageLabel);

    // Scale the picture with factor
    scalefactor = 1.0;


    // Create actions
    createActions();

    // Load Image
    QPixmap pixmap;
    QString fileName("/home/rody/Pictures/wallpapers/2017-04-28.jpg");

    // Set-up scroll area (prevents overflow)

    // Read an image
    QImageReader imageReader(fileName);
    imageReader.setAutoTransform(true); // Take portrait mode in account for JPEG images

    if(imageReader.read(image)){
        QString msg = tr("Cannot load %1: %2").arg(fileName, imageReader.errorString());
        QMessageBox::information(this, "Chroto", msg);
    }

    // Add to layout
    layout->addWidget(scrollArea);
    setLayout(layout);
}


PhotoViewer::createActions()
{
    qDebug() << "Create the actions" << endl;
}

bool PhotoViewer::loadFile(const QString &fileName)
{

    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return false;
    }

PhotoViewer::~PhotoViewer()
{
}
