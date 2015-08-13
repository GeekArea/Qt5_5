#include <QApplication>
#include <QQmlApplicationEngine>
#include <QStringListModel>
#include <QtQml>
#include "cpuinfo.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine qmlEngine;

    QStringListModel modelCPU;
    QStringList listCPULineDetails;

    CPUInfo *cpuInfo = new CPUInfo();
    //Here we will get data from terminal & split for newline
    QStringList listBeforeCleanup = cpuInfo->GetCPUInfo().split(QRegExp("\n"));
    foreach (QString str, listBeforeCleanup) {
        //replacing tab for space (count:4)
        str.replace("\t","    ");
        listCPULineDetails.append(str);
    }
    modelCPU.setStringList(listCPULineDetails);
    //Pass model from C++ to QML by setting it as a context property
    qmlEngine.rootContext()->setContextProperty("cpuInfoModel", &modelCPU);

    //load QML
    qmlEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
