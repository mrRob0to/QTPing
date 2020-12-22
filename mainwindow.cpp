#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lblOS->setText("OS Detected: " + m_ping.operatingSystem());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::output(QString data)
{

}


void MainWindow::on_txtIP_textChanged(const QString &arg1)
{

}
