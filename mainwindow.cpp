#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QDesktopWidget desktop;
    QSize desktopDimension = desktop.availableGeometry(this).size();

    // Resize to 70% of the desktop size
    resize(desktopDimension*0.7);

    // Set up the widgets
    initializeMenu();
    initializeToolBar();
    initializeMainWindow();
    initializeStatusBar();

    // Up and running
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::initializeMenu()
{
    QMenuBar* menubar = new QMenuBar(this);

    // Compose File menu
    QMenu* fileMenu = new QMenu(tr("&File"), this);
    QAction* openAction = new QAction(tr("&Open"), this);
    fileMenu->addAction(openAction);
    QAction* saveAction = new QAction(tr("&Save"), this);
    fileMenu->addAction(saveAction);
    QAction* exitAction = new QAction(tr("E&xit"), this);
    fileMenu->addAction(exitAction);


    // Compose Help menu
    QMenu* helpMenu = new QMenu(tr("&Help"), this);
    QAction* helpAction = new QAction(tr("&Help"), this);
    helpMenu->addAction(helpAction);

    // Assemble the menubar
    menubar->addMenu(fileMenu);
    menubar->addMenu(helpMenu);
    setMenuBar(menubar);

    // Connect all actions
    connect(exitAction, SIGNAL(triggered(bool)), this, SLOT(exit()));
}

void MainWindow::initializeToolBar()
{
    QToolBar* toolbar = new QToolBar(this);

    // Compose Add button
    QMenu* addMenu = new QMenu(tr("&Add"), this);
    QAction* addFolderAction = new QAction(tr("&Folder"), this);
    addMenu->addAction(addFolderAction);
    QAction* addPhotoAction = new QAction(tr("&Photo"), this);
    addMenu->addAction(addPhotoAction);

    QToolButton* addToolButton = new QToolButton(this);
    addToolButton->setMenu(addMenu);
    addToolButton->setPopupMode(QToolButton::MenuButtonPopup);
    addToolButton->setDefaultAction(addFolderAction);
    toolbar->addWidget(addToolButton);

    // Assemble the toolbar
    addToolBar(toolbar);
}


void MainWindow::initializeMainWindow()
{
    // Some content
    QScrollArea* filesScrollArea = new QScrollArea(this);
    filesScrollArea->setMinimumWidth(200);
    photoViewer = new PhotoViewer(this);
    QScrollArea* thumbnailsScrollArea = new QScrollArea(this);
    thumbnailsScrollArea->setMinimumHeight(200);
    QScrollArea* infoScrollArea = new QScrollArea(this);
    infoScrollArea->setMinimumWidth(200);


    // Set the splitter between the photo viewer and the thumbnails
    QSplitter* photoThumbnailSplitter = new QSplitter(Qt::Vertical, this);
    photoThumbnailSplitter->addWidget(photoViewer);
    photoThumbnailSplitter->addWidget(thumbnailsScrollArea);
    photoThumbnailSplitter->setCollapsible(1, true);

    QList<int> vsizes;
    vsizes.push_back(width()*0.80);
    vsizes.push_back(width()*0.20);
    photoThumbnailSplitter->setSizes(vsizes);

    // Set up main splitter between files | photos
    QSplitter* filesPhotosSplitter = new QSplitter(Qt::Horizontal, this);
    filesPhotosSplitter->addWidget(filesScrollArea);
    filesPhotosSplitter->addWidget(photoThumbnailSplitter);
    filesPhotosSplitter->addWidget(infoScrollArea );
    filesPhotosSplitter->setCollapsible(0, true);
    filesPhotosSplitter->setCollapsible(2, true);

    QList<int> hsizes;
    hsizes.push_back(width()*0.20);
    hsizes.push_back(width()*0.60);
    hsizes.push_back(width()*0.20);
    filesPhotosSplitter->setSizes(hsizes);

    // Assemble the central widgets
    setCentralWidget(filesPhotosSplitter);
}

void MainWindow::initializeStatusBar()
{
    QStatusBar* statusbar = new QStatusBar(this);
    setStatusBar(statusbar);
}

void MainWindow::exit() const
{
    QCoreApplication::quit();
}

MainWindow::~MainWindow()
{

}
