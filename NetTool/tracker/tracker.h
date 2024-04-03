// Tracker.h
#ifndef TRACKER_H
#define TRACKER_H

#include <QList>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "fwd_def.h"

class Tracker : public QObject
{
    Q_OBJECT

public:
    explicit Tracker(QObject *parent = nullptr);

    QList<TerminalInfo>& activeTerminals() ;

public slots:
    void start(int port);
    void stop();

private slots:
    void handleNewConnection();
    void handleDisconnected(const QTcpSocket *socket);

private:
    QTcpServer *m_tcpServer;
    QList<TerminalInfo> m_activeTerminals;
};

#endif // TRACKER_H

