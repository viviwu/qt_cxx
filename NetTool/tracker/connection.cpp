#include "connection.h"
#include "server.h"
#include <QList>

Connection::Connection(QTcpSocket *socket, Server *parent)
    : QObject(parent)
    , m_socket(socket)
{
    Server = parent;
    //Already Connected
    connect(m_socket, &QTcpSocket::readyRead, this, &Connection::handleReadyRead);
    connect(m_socket, &QTcpSocket::disconnected, this, &Connection::handleDisconnected);
}

Connection::~Connection()
{
    m_socket->close();
    m_socket->deleteLater();
    qDebug() << __FUNCTION__;
}

void Connection::handleReadyRead()
{
    qDebug() << __FUNCTION__ << m_socket->peerName();
    QString request = m_socket->readAll();
    qDebug() << "Received request:" << request;

    QList<TerminalInfo> &m_activeTerminals = Server->activeTerminals();
    if (request.startsWith("REGISTER_TERMINAL:")) {
        request.remove("REGISTER_TERMINAL:");
        QStringList terminals = request.split(";", Qt::SkipEmptyParts);
        qDebug() << terminals;
    } else if (request == "GET_ACTIVE_TERMINALS") {
        QStringList terminals;
        for (const auto &terminal : m_activeTerminals) {
            terminals << terminal.udid;
        }
        QString msg("ACTIVE_TERMINALS:");
        msg += terminals.join(",");
        m_socket->write(msg.toUtf8());
        m_socket->flush();
        qDebug() << "terminals: " << terminals;
    }
}

void Connection::handleDisconnected()
{
    emit disconnected(m_socket);
}

void Connection::registerTerminal(const QString &terminalId, quint16 port)
{
    qDebug() << __FUNCTION__ << terminalId << port;
}

void Connection::unregisterTerminal(const QString &terminalId)
{
    qDebug() << __FUNCTION__ << terminalId;
}
