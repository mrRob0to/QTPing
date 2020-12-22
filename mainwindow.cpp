#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lblOS->setText("OS Detected: " + m_ping.operatingSystem());
    m_ping.setAddress(ui->txtIP->text());
    connect(ui->btnStart, &QPushButton::clicked, &m_ping, &Ping::start);
    connect(ui->btnStop, &QPushButton::clicked, &m_ping, &Ping::stop);
    connect(&m_ping, &Ping::output, this, &MainWindow::output);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::output(QString data)
{

    ui->plainTextEdit->appendPlainText(data);

}


void MainWindow::on_txtIP_textChanged(const QString &arg1)
{

    Q_UNUSED(arg1);
    m_ping.setAddress(ui->txtIP->text());

}
