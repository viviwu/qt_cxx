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
#include <QMetaMethod>

// 定义函数指针类型
//typedef void (*NotificationHandler)(const QString& name, const QVariantMap& userInfo);

class QTNotificationCenter : public QObject
{
Q_OBJECT

public:
    static QTNotificationCenter* defaultCenter();

    void postNotification(const QString& name, const QVariantMap& userInfo = QVariantMap());

    void addObserver(QObject* observer, const QString& name, const QMetaMethod &selector);

    void removeObserver(QObject* observer, const QString& name, const QMetaMethod& selector);

//    void addObserver(QObject* observer, const QString& name, const QString& selector);
//
//    void removeObserver(QObject* observer, const QString& name, const QString& selector);

signals:
    void notificationPosted(const QString& name, const QVariantMap& userInfo);

private:
    QTNotificationCenter() {}

    QMap<QString, QObject*> m_observers;

//    QMap<NotificationHandler, QObject*> m_handlers;
};

#endif  // QTCXX_QTNOTIFICATIONCENTER_H
