/**
 * @author wuxw
 * @date 10/8/23
 * @desc ...
 */
//
// Created by 朱小争 on 10/8/23.
//

#include <QObject>
#include <QDebug>
#include <QVariantMap>

#ifndef QTCXX_MYOBSERVER_H
#define QTCXX_MYOBSERVER_H

class MyObserver : public QObject
{
    Q_OBJECT

public slots:
        void handleNotification(const QString& name, const QVariantMap& userInfo)
    {
        qDebug() << "Received notification:" << name;
        qDebug() << "User Info:" << userInfo;
    }
};

#endif  // QTCXX_MYOBSERVER_H
