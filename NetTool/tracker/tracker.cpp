
// Tracker.cpp
#include "tracker.h"
#include <QUuid>
#include "connection.h"

/*******************************Tracker*******************************/

Tracker::Tracker(QObject *parent) : QObject(parent), m_tcpServer(nullptr)
{

}

QList<TerminalInfo>& Tracker::activeTerminals() {
    return m_activeTerminals;
}

void Tracker::start(int port)
{
    m_tcpServer = new QTcpServer(this);
    connect(m_tcpServer, &QTcpServer::newConnection, this, &Tracker::handleNewConnection);

    if (!m_tcpServer->listen(QHostAddress::Any, port)) {
        qDebug() << "Failed to start tracker:" << m_tcpServer->errorString();
        return;
    }

    qDebug() << "Tracker started on port" << m_tcpServer->serverPort();
}

void Tracker::stop()
{
    if (m_tcpServer) {
        m_tcpServer->close();
        m_tcpServer->deleteLater();
        m_tcpServer = nullptr;
    }

    qDebug() << "Tracker stopped";
}

void Tracker::handleNewConnection()
{
    TerminalInfo term={0};
    QTcpSocket *socket = m_tcpServer->nextPendingConnection();
    term.udid = QUuid::createUuid().toString(QUuid::StringFormat::WithoutBraces);
    term.ip = socket->peerAddress().toString();
    term.port = socket->peerPort();
    m_activeTerminals.append(term);

    Connection *connection = new Connection(socket, this);

    connect(connection, &Connection::disconnected, this, &Tracker::handleDisconnected);

    qDebug() << "New connection from:" <<socket->peerName() << socket->peerAddress().toString() << socket->peerPort();
}

void Tracker::handleDisconnected(const QTcpSocket *socket)
{
    m_activeTerminals.erase(std::remove_if(m_activeTerminals.begin(), m_activeTerminals.end(), [&](const auto& t) {
        return t.ip == socket->peerAddress().toString() && t.port == socket->peerPort();
    }), m_activeTerminals.end());

    // socket->deleteLater();
    qDebug() << "Terminal disconnected:" << socket->peerAddress().toString();
}

