// main.cpp
#include <QCoreApplication>
#include <QDebug>


#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"sizeof(quint64):"<<sizeof(quint64);
    // Create Server
    Server Server;

    // Start Server
    Server.start(1234);

    return a.exec();
}
