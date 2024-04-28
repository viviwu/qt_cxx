
// Server.cpp
#include "connection.h"
#include "server.h"
#include <QUuid>

/*******************************Server*******************************/

Server::Server(QObject *parent) : QObject(parent), m_tcpServer(nullptr)
{

}

QList<TerminalInfo>& Server::activeTerminals() {
    return m_activeTerminals;
}

void Server::start(int port)
{
    m_tcpServer = new QTcpServer(this);
    connect(m_tcpServer, &QTcpServer::newConnection, this, &Server::handleNewConnection);

    if (!m_tcpServer->listen(QHostAddress::Any, port)) {
        qDebug() << "Failed to start Server:" << m_tcpServer->errorString();
        return;
    }

    qDebug() << "Server started on port" << m_tcpServer->serverPort();
}

void Server::stop()
{
    if (m_tcpServer) {
        m_tcpServer->close();
        m_tcpServer->deleteLater();
        m_tcpServer = nullptr;
    }

    qDebug() << "Server stopped";
}

void Server::handleNewConnection()
{
    TerminalInfo term={0};
    QTcpSocket *socket = m_tcpServer->nextPendingConnection();
    term.udid = QUuid::createUuid().toString(QUuid::StringFormat::WithoutBraces);
    term.ip = socket->peerAddress().toString();
    term.port = socket->peerPort();
    m_activeTerminals.append(term);

    Connection *connection = new Connection(socket, this);

    connect(connection, &Connection::disconnected, this, &Server::handleDisconnected);

    qDebug() << "New connection from:" <<socket->peerName() << socket->peerAddress().toString() << socket->peerPort();
}

void Server::handleDisconnected(const QTcpSocket *socket)
{
    m_activeTerminals.erase(std::remove_if(m_activeTerminals.begin(), m_activeTerminals.end(), [&](const auto& t) {
        return t.ip == socket->peerAddress().toString() && t.port == socket->peerPort();
    }), m_activeTerminals.end());

    // socket->deleteLater();
    qDebug() << "Terminal disconnected:" << socket->peerAddress().toString();
}

