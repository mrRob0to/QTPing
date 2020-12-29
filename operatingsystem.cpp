#include "operatingsystem.h"

OperatingSystem::OperatingSystem(QObject *parent) : QObject(parent)
{


}

QString OperatingSystem::getOS(){

    return QSysInfo::prettyProductName();

}
