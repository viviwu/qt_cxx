/**
 * @author wuxw
 * @date 10/8/23
 * @desc ...
 */
//
// Created by 朱小争 on 10/8/23.
//

#include <QMetaObject>

#include "qt_notification_center.h"

QTNotificationCenter* QTNotificationCenter::defaultCenter()
{
    static QTNotificationCenter notificationCenter;
    return &notificationCenter;
}

void QTNotificationCenter::postNotification(const QString& name, const QVariantMap& userInfo)
{
    emit notificationPosted(name, userInfo);
}

void QTNotificationCenter::addObserver(QObject* observer, const QString& name, const QMetaMethod &selector){
    QString key = QString("%1:%2").arg(name,  selector.name());
    m_observers[key] = observer;
    connect(this, SIGNAL(notificationPosted(QString,QVariantMap)), observer, SLOT(selector));
}

void QTNotificationCenter::removeObserver(QObject* observer, const QString& name, const QMetaMethod &selector){
    QString key = QString("%1:%2").arg(name, selector.name());
    m_observers[key] = observer;
    disconnect(this, SIGNAL(notificationPosted(QString,QVariantMap)), observer, SLOT(selector));
}

/*
void QTNotificationCenter::addObserver(QObject* observer, const QString& name, const QString& selector)
{
    QString key = QString("%1:%2").arg(name, selector);
    m_observers[key] = observer;
//        connect(this, SIGNAL(notificationPosted(QString,QVariantMap)), observer, selector.toUtf8().constData());
    connect(this, SIGNAL(notificationPosted(QString,QVariantMap)), observer, SLOT(handleNotification(QString,QVariantMap)));
}

void QTNotificationCenter::removeObserver(QObject* observer, const QString& name, const QString& selector)
{
    QString key = QString("%1:%2").arg(name, selector);
    m_observers.remove(key);
//        disconnect(this, SIGNAL(notificationPosted(QString,QVariantMap)), observer, selector.toUtf8().constData());
    disconnect(this, SIGNAL(notificationPosted(QString,QVariantMap)), observer, SLOT(handleNotification(QString,QVariantMap)));
}
*/
