#ifndef CPUINFO_H
#define CPUINFO_H

#include <QObject>
#include <QProcess>

// Class to get CPUInfo
class CPUInfo : public QObject
{
    Q_OBJECT
public:
    CPUInfo(QObject *parent = 0);
    QString GetCPUInfo();

private:
    QProcess *m_process;

    //internal method that execute terminal command & collects output
    QString launchProgram(const QString &strprogram);
};

#endif // CPUINFO_H
