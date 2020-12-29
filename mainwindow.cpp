#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lblOS->setText("OS Detected: " + m_OperatingSystem.getOS());
    m_Ping.setAddress(ui->txtIP->text());
    connect(ui->btnStart, &QPushButton::clicked, &m_Ping, &Ping::start);
    connect(ui->btnStop, &QPushButton::clicked, &m_Ping, &Ping::stop);
    connect(&m_Ping, &Ping::output, this, &MainWindow::output);
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
    m_Ping.setAddress(ui->txtIP->text());
}
