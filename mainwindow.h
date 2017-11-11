#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCoreApplication>
#include <QMainWindow>
#include <QDesktopWidget>
#include <QDebug>
#include <QSize>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QToolButton>
#include <QStatusBar>
#include <QSplitter>
#include <QScrollArea>
#include <QLabel>
#include <QTableView>

#include "photosmodel.h"
#include "photoviewer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    PhotosModel* _model;
    PhotoViewer* photoViewer;
    QTableView* tableView;

    void initializeMenu();
    void initializeToolBar();
    void initializeMainWindow();
    void initializeStatusBar();


public slots:
    void exit() const;
};

#endif // MAINWINDOW_H
