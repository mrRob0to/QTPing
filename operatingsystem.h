#ifndef OPERATINGSYSTEM_H
#define OPERATINGSYSTEM_H

#include <QObject>

class OperatingSystem : public QObject
{
    Q_OBJECT
public:
    explicit OperatingSystem(QObject *parent = nullptr);
    QString getOS();

signals:

};

#endif // OPERATINGSYSTEM_H
