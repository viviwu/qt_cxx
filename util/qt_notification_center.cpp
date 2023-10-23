/**
 * @author wuxw
 * @date 10/8/23
 * @desc ...
 */


#include "qt_notification_center.h"

QTNotificationCenter* QTNotificationCenter::defaultCenter() {
  static QTNotificationCenter notificationCenter;
  return &notificationCenter;
}

QTNotificationCenter::~QTNotificationCenter(){
    qDebug()<<__FUNCTION__ ;
}

void QTNotificationCenter::postNotification(const QString& name, const QVariantMap& userInfo) {
  emit notificationPosted(name, userInfo);
}

void QTNotificationCenter::addObserver(QObject* observer,
                                       const char* selector,
                                       const QString& name) {
  QString key = QString("%1:%2").arg(name, selector);
  m_observers[key] = observer;
  connect(this, SIGNAL(notificationPosted(const QString&, const QVariantMap&)), observer, selector);
}

void QTNotificationCenter::removeObserver(QObject* observer,
                                          const char* selector,
                                          const QString& name) {
  QString key = QString("%1:%2").arg(name, selector);
  m_observers.remove(key);
  disconnect(this, SIGNAL(notificationPosted(const QString&, const QVariantMap&)), observer,
             selector);
}
