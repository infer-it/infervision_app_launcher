#include <QCoreApplication>
#include <iostream>
#include <QProcess>
#include <QDebug>

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QProcess *pkill = new QProcess();
    pkill->start("taskkill /f /im SlicerApp-real.exe");
    pkill->waitForFinished();
    QProcess *pstart = new QProcess();
    QStringList l;
    for (int i = 1; i < argc; i++) {
        l << argv[i];
    }
    pstart->start("Slicer.exe", l);
    pstart->waitForStarted();
    a.quit();
}