// main.cpp
#include <QCoreApplication>
#include <QDebug>


#include "Tracker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"sizeof(quint64):"<<sizeof(quint64);
    // Create Tracker
    Tracker tracker;

    // Start Tracker
    tracker.start(1234);

    return a.exec();
}
