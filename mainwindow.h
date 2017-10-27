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

#include "photoviewer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    PhotoViewer* photoViewer;

    void initializeMenu();
    void initializeToolBar();
    void initializeMainWindow();
    void initializeStatusBar();

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void exit() const;
};

#endif // MAINWINDOW_H
