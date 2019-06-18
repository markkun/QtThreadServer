#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tcpServer = new TcpServerEcho(QHostAddress::AnyIPv4, 1234, this);
}

MainWindow::~MainWindow()
{
    tcpServer->close();
    delete ui;
}
