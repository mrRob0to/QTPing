#include "ping.h"

Ping::Ping(QObject *parent) : QObject(parent)
{
    connect(&m_process, &QProcess::errorOccurred, this, &Ping::errorOccurred);
    connect(&m_process, &QProcess::readyReadStandardError, this, &Ping::readyReadStdErr);
    connect(&m_process, &QProcess::readyReadStandardOutput, this, &Ping::readyReadStdOut);
    connect(&m_process, &QProcess::started, this, &Ping::started);
    connect(&m_process, &QProcess::stateChanged, this, &Ping::stateChanged);
    connect(&m_process, &QProcess::readyRead, this, &Ping::readyRead);


    //Overload finished
    connect(&m_process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, &Ping::finished);

    m_listening = false;
    m_address ="";

}

//Public
QString Ping::operatingSystem(){

    return QSysInfo::prettyProductName();

}

QString Ping::getAddress() const{
    return m_address;
}

void Ping::setAddress(const QString &address){

    m_address = address;

}


//Private
QString Ping::getProcess(){

    qInfo() << Q_FUNC_INFO;
    if(QSysInfo::productType() == "windows") return "cmd";
    if(QSysInfo::productType() == "osx") return "/bin/zsh";

    return "bash";

}

void Ping::startPing(){

    QByteArray command;
    command.append("ping " + m_address);
    //if(QSysInfo::productType() == "windows") command.append("\r");
    command.append("\n");
    m_process.write(command);

}


//Public Slots
void Ping::start(){

    qInfo() << Q_FUNC_INFO;
    m_listening = true;
    m_process.start(getProcess());

}

void Ping::stop(){

    qInfo() <<Q_FUNC_INFO;
    m_listening = false;
    m_process.close();

}


//Private Slots
void Ping::readyReadStdErr(){

    if(!m_listening) return;
    qInfo() << Q_FUNC_INFO;
    //Do I need this?
    //QByteArray data = m_process.readAllStandardError();
    QString message = "Standard Error: ";
    message.append(m_process.readAllStandardError());
    emit output(message);

}

void Ping::readyReadStdOut(){

}

void Ping::started(){

    qInfo() << Q_FUNC_INFO;

}

void Ping::readyRead(){

    if(!m_listening) return;
    qInfo() << Q_FUNC_INFO;
    QByteArray data = m_process.readAll().trimmed();
    qInfo() << data;
    emit output(data);

}

void Ping::errorOccurred(QProcess::ProcessError error){

    if(!m_listening) return;
    qInfo() << Q_FUNC_INFO << error;
    emit output("Error");

}

void Ping::finished(int exitCode, QProcess::ExitStatus exitStatus){

    if(!m_listening) return;
    qInfo() << Q_FUNC_INFO;
    Q_UNUSED(exitCode);
    Q_UNUSED(exitStatus);
    emit output("Complete");

}

void Ping::stateChanged(QProcess::ProcessState newState){

    qInfo() << Q_FUNC_INFO;
    switch(newState){

        case QProcess::NotRunning:
            emit output("Not running");
            break;
        case QProcess::Starting:
            emit output("Starting...");
            break;
        case QProcess::Running:
            emit output("Running");
            startPing();
            break;

        }
}
