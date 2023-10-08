/**
 * @author wuxw
 * @date 10/8/23
 * @desc ...
 */
//
// Created by 朱小争 on 10/8/23.
//

#ifndef QTCXX_QTNOTIFICATIONCENTER_H
#define QTCXX_QTNOTIFICATIONCENTER_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QVariant>
#include <functional>

// 定义函数指针类型
typedef void (*NotificationHandler)(const QString& name, const QVariantMap& userInfo);

class QTNotificationCenter : public QObject
{
Q_OBJECT

public:
    static QTNotificationCenter* defaultCenter()
    {
        static QTNotificationCenter notificationCenter;
        return &notificationCenter;
    }

    void postNotification(const QString& name, const QVariantMap& userInfo = QVariantMap())
    {
        emit notificationPosted(name, userInfo);
    }

    void addObserver(QObject* observer, const QString& name, NotificationHandler handler)
    {
        QString key = QString("%1:%2").arg(name, QString::number(reinterpret_cast<qint64>(handler)));
        m_observers[key] = observer;
        connect(this, SIGNAL(notificationPosted(QString,QVariantMap)), observer, SLOT(handleNotification(QString,QVariantMap)));
        m_handlers[handler] = observer;
    }

    void removeObserver(QObject* observer, const QString& name, NotificationHandler handler)
    {
        QString key = QString("%1:%2").arg(name, QString::number(reinterpret_cast<qint64>(handler)));
        m_observers.remove(key);
        disconnect(this, SIGNAL(notificationPosted(QString,QVariantMap)), observer, SLOT(handleNotification(QString,QVariantMap)));
        m_handlers.remove(handler);
    }

    void addObserver(QObject* observer, const QString& name, const QString& selector)
    {
        QString key = QString("%1:%2").arg(name, selector);
        m_observers[key] = observer;
//        connect(this, SIGNAL(notificationPosted(QString,QVariantMap)), observer, selector.toUtf8().constData());
        connect(this, SIGNAL(notificationPosted(QString,QVariantMap)), observer, SLOT(handleNotification(QString,QVariantMap)));
    }

    void removeObserver(QObject* observer, const QString& name, const QString& selector)
    {
        QString key = QString("%1:%2").arg(name, selector);
        m_observers.remove(key);
//        disconnect(this, SIGNAL(notificationPosted(QString,QVariantMap)), observer, selector.toUtf8().constData());
        disconnect(this, SIGNAL(notificationPosted(QString,QVariantMap)), observer, SLOT(handleNotification(QString,QVariantMap)));
    }

signals:
    void notificationPosted(const QString& name, const QVariantMap& userInfo);

private:
    QTNotificationCenter() {}

    QMap<QString, QObject*> m_observers;

    QMap<NotificationHandler, QObject*> m_handlers;
};

#endif  // QTCXX_QTNOTIFICATIONCENTER_H
