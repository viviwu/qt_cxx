// Terminal.h
#ifndef TERMINAL_H
#define TERMINAL_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QHostAddress>

class Terminal : public QObject
{
    Q_OBJECT

public:
    explicit Terminal(QObject *parent = nullptr);

    void start();

signals:
    void connectedToTracker();
    void terminalListReceived(const QStringList& terminals);
    void terminalConnected();
    void terminalDisconnected();

private slots:
    void handleConnected();
    void handleDisconnected();
    void handleDataReceived();
    void handleNewConnection();

private:
    void registTerminalInfo();
    void sendRequestToTracker(const QString& request);

    QString m_udid;
    QHostAddress m_trackerAddress;
    quint16 m_trackerPort;
    quint16 m_listenPort;
    QTcpSocket *m_socket;
    QTcpServer *m_server;
};

#endif // TERMINAL_H

