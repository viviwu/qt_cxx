#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Tracker;

class Connection : public QObject
{
    Q_OBJECT

public:
    explicit Connection(QTcpSocket *socket, Tracker *parent = nullptr);

    ~Connection();

signals:
    void disconnected(const QTcpSocket *socket);

private slots:
    void handleReadyRead();
    void handleDisconnected();

    void registerTerminal(const QString &terminalId, quint16 port);
    void unregisterTerminal(const QString &terminalId);

private:
    QTcpSocket *m_socket;
    Tracker *tracker;
};

#endif // CONNECTION_H
