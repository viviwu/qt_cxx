/**
 * @author wuxw
 * @date 10/8/23
 * @desc ...
 */
//
// Created by 朱小争 on 10/8/23.
//

#include "qt_notification_center.h"

#include <QMetaObject>
#include <QDebug>

QTNotificationCenter* QTNotificationCenter::defaultCenter() {
  static QTNotificationCenter notificationCenter;
  return &notificationCenter;
}

void QTNotificationCenter::postNotification(const QString& name, const QVariantMap& userInfo) {
  emit notificationPosted(name, userInfo);
}

void QTNotificationCenter::addObserver(QObject* observer,
                                       const char* selector,
                                       const QString& name) {
  qDebug()<<__FUNCTION__ <<" "<<selector;
  QString key = QString("%1:%2").arg(name, selector);
  m_observers[key] = observer;
  connect(this, SIGNAL(notificationPosted(const QString&, const QVariantMap&)), observer, selector);
}

void QTNotificationCenter::removeObserver(QObject* observer,
                                          const char* selector,
                                          const QString& name) {
  QString key = QString("%1:%2").arg(name, selector);
  disconnect(this, SIGNAL(notificationPosted(const QString&, const QVariantMap&)), observer,
             selector);
}
