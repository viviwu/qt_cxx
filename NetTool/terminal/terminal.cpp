
// Terminal.cpp
#include "Terminal.h"
#include <QUuid>

#define Server_IP QHostAddress::LocalHost
#define Server_PORT 1234
#define LISTEN_PORT 5678
Terminal::Terminal( QObject *parent)
    : QObject(parent),  m_ServerAddress(Server_IP), m_ServerPort(Server_PORT), m_listenPort(LISTEN_PORT), m_socket(nullptr), m_server(nullptr)
{
    m_udid=QUuid::createUuid().toString(QUuid::StringFormat::WithoutBraces);
}

void Terminal::start()
{
    // Start listening for incoming connections
    m_server = new QTcpServer(this);
    connect(m_server, &QTcpServer::newConnection, this, &Terminal::handleNewConnection);
    m_server->listen(QHostAddress::Any, m_listenPort);

    // Connect to Server
    m_socket = new QTcpSocket(this);
    connect(m_socket, &QTcpSocket::connected, this, &Terminal::handleConnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &Terminal::handleDataReceived);
    connect(m_socket, &QTcpSocket::disconnected, this, &Terminal::handleDisconnected);
    m_socket->connectToHost(m_ServerAddress, m_ServerPort);
}

void Terminal::handleConnected()
{
    emit connectedToServer();

    // Send command menu to Server
    sendRequestToServer("GET_TERMINAL_LIST");
}

void Terminal::handleDisconnected()
{
    emit terminalDisconnected();
}

void Terminal::handleDataReceived()
{
    QByteArray data = m_socket->readAll();
    QString response = QString::fromUtf8(data);

    // Process the response received from the Server
    if (response.startsWith("TERMINAL_LIST:")) {
        response.remove("TERMINAL_LIST:");
        QStringList terminals = response.split(",", Qt::SkipEmptyParts);
        emit terminalListReceived(terminals);
    } else {
        // Handle other responses from Server or other Terminals
        // ...
    }
}

void Terminal::handleNewConnection()
{
    // Accept the new connection
    QTcpSocket *clientSocket = m_server->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::disconnected, clientSocket, &QTcpSocket::deleteLater);

    emit terminalConnected();
}

void Terminal::registTerminalInfo()
{
    if (m_socket->state() == QAbstractSocket::ConnectedState) {
        QString term_info=QString("%1").arg(m_listenPort);
        m_socket->write(term_info.toUtf8());
        m_socket->flush();
    }
}

void Terminal::sendRequestToServer(const QString& request)
{
    if (m_socket->state() == QAbstractSocket::ConnectedState) {
        m_socket->write(request.toUtf8());
        m_socket->flush();
    }
}

