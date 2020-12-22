#include "ping.h"

Ping::Ping(QObject *parent) : QObject(parent)
{

}

//Public
QString Ping::operatingSystem(){

}

QString Ping::getAddress() const{

}

void Ping::setAddress(const QString &address){

}


//Private
QString Ping::getProcess(){

}

void Ping::startPing(){

}


//Public Slots
void Ping::start(){

}

void Ping::stop(){

}


//Private Slots
void Ping::readyReadStdErr(){

}

void Ping::readyReadStdOut(){

}

void Ping::started(){

}

void Ping::readyRead(){

}

void Ping::errorOccurred(QProcess::ProcessError error){

}

void Ping::finished(int exitCode, QProcess::ExitStatus exitStatus){

}

void Ping::stateChanged(QProcess::ProcessState newState){

}


//Signals
void Ping::output(QString data){

}
