/**
 * @author wuxw
 * @date 10/8/23
 * @desc ...
 */


#ifndef QTCXX_QTNOTIFICATIONCENTER_H
#define QTCXX_QTNOTIFICATIONCENTER_H

#include <QMap>
#include <QMetaMethod>
#include <QObject>
#include <QString>
#include <QVariant>
#include <QVariantMap>


// typedef void (*NotificationHandler)(const QString& name, const QVariantMap& userInfo);

class QTNotificationCenter : public QObject {
  Q_OBJECT

  public:
  static QTNotificationCenter* defaultCenter();
  ~QTNotificationCenter();

  void postNotification(const QString& name, const QVariantMap& userInfo = QVariantMap());

  void addObserver(QObject* observer, const char* selector, const QString& name);

  void removeObserver(QObject* observer, const char* selector, const QString& name);

  signals:
  void notificationPosted(const QString& name, const QVariantMap& userInfo);

  private:
  QTNotificationCenter() {}

  QMap<QString, QObject*> m_observers;
};

#endif  // QTCXX_QTNOTIFICATIONCENTER_H
