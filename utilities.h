#ifndef UTILITIES_H
#define UTILITIES_H

#include <QObject>

class Utilities : public QObject
{
    Q_OBJECT
public:
    explicit Utilities(QObject *parent = nullptr);

public slots:
    void start();
    void stop();

signals:

};

#endif // UTILITIES_H
