#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ping.h"
#include "operatingsystem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void output(QString data);
    void on_txtIP_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Ping m_Ping;
    OperatingSystem m_OperatingSystem;
};
#endif // MAINWINDOW_H
