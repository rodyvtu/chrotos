#include "photoviewer.h"

PhotoViewer::PhotoViewer(QWidget *parent) :
    QWidget(parent)
{
    // Set up the image
    _image = new QImage();

    // Set up image label
    _imageLabel = new QLabel(this);
    _imageLabel->setBackgroundRole(QPalette::Base);
    _imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    _imageLabel->setScaledContents(true);

    // Set up the button
    _button = new QPushButton();
    _button->setText(tr("Open an image"));

    // Set up the layout
    _layout = new QVBoxLayout(this);
    _layout->addWidget(_imageLabel);
    _layout->addWidget(_button);

    // Scale the picture with factor
    _scaleFactor = 1.0;

    // Create actions
    createActions();

    setLayout(_layout);
}

PhotoViewer::~PhotoViewer()
{
}


void PhotoViewer::createActions()
{
    // Bind the hotkeys etc.
    connect( _button, SIGNAL(clicked(bool)),
             this, SLOT(openFile()) );
}

bool PhotoViewer::loadFile(const QString &fileName)
{
    QImageReader imageReader;
    QString msg;
    QPixmap pixmap;
    QSize labelSize = _imageLabel->size();

    // Read image
    imageReader.setFileName(fileName);
    imageReader.setAutoTransform(true); // Take portrait mode in account for JPEG images

    // Check if succesful
    if(!imageReader.read(_image)){
        msg = tr("Cannot load \"%1\".<br /> %2");
        msg = msg.arg(fileName, imageReader.errorString());
        QMessageBox::information(this, "Chroto", msg);
    }

    // Show the image
    pixmap = QPixmap::fromImage(*_image);
    qDebug() << "Label size: " << labelSize << endl;
    _imageLabel->setPixmap(pixmap);
}


void PhotoViewer::openFile()
{
    // Get the file
    QString fileName = QFileDialog::getOpenFileName(
                          this,
                          tr("Open Image"),
                          QString(),
                          tr("Image Files (*.png *.jpg *.bmp)")
                        );
    // Load the file
    loadFile(fileName);
}
