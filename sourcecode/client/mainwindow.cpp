#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "multicast.h"
#include <QtWidgets>

using std::string;
using std::vector;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //set up the GUI
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setupConnections()
{
    //add the connect button function push
    QAction *connectButton = ui->menuBar->addAction("Connect");
    connect(connectButton, SIGNAL(triggered()), this, SLOT(initialConnect()));


    //make now playing fields read only
    ui->artistName->setFocusPolicy(Qt::NoFocus);
    ui->artistName->setReadOnly(true);

    ui->songName->setFocusPolicy(Qt::NoFocus);
    ui->songName->setReadOnly(true);
}


bool MainWindow::initialConnect()
{
    //do later, i assume will call a socket connect function
    // to get stuff out of the GUI land.
    //Please don't write socket stuff in the GUI!!!


    return true;
}


void MainWindow::clearListeners()
{
    ui->listeners->clear();
}

void MainWindow::updateListeners(string listener)
{
    ui->listeners->addItem(QString::fromStdString(listener));
}

void MainWindow::updateNowPlaying(vector<string> songInfo)
{
    ui->songName->append(QString::fromStdString(songInfo[0]));
    ui->artistName->append(QString::fromStdString(songInfo[1]));
}
