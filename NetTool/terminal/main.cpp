
// main.cpp
#include <QCoreApplication>
#include <QDebug>

#include "Terminal.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create and start Terminal
    Terminal terminal;
    terminal.start();

    // Connect Terminal signals to slots
    QObject::connect(&terminal, &Terminal::connectedToTracker, [&]() {
        qDebug() << "Connected to Tracker";
    });

    QObject::connect(&terminal, &Terminal::terminalListReceived, [&](const QStringList& terminals) {
        qDebug() << "Terminal List:";
        for (const auto& terminal : terminals)
            qDebug() << terminal;
    });

    QObject::connect(&terminal, &Terminal::terminalConnected, [&]() {
        qDebug() << "Terminal connected to another Terminal";
    });

    QObject::connect(&terminal, &Terminal::terminalDisconnected, [&]() {
        qDebug() << "Terminal disconnected from another Terminal";
    });

    return a.exec();
}

