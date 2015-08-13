#include "cpuinfo.h"

CPUInfo::CPUInfo(QObject *parent) : QObject(parent),
    m_process(new QProcess(this))
{
}

// args => strprogram(QString) - command to be executed
QString CPUInfo::launchProgram(const QString &strprogram)
{
    m_process->start("sh");
    m_process->write(strprogram.toLatin1());
    m_process->closeWriteChannel();
    m_process->waitForFinished(-1);
    QByteArray output = m_process->readAll();
    m_process->close();
    return output;
}

QString CPUInfo::GetCPUInfo()
{
    // 'cat' is a lunux command, here its used for extracting details from '/proc/cpuinfo'
    return launchProgram("cat /proc/cpuinfo");
}
