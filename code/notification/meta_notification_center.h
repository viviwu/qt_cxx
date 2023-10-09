// xnotificationcenter.h
#ifndef META_NOTIFICATIO_NCENTER_H
#define META_NOTIFICATIO_NCENTER_H

#include <QJsonObject>
#include <QMap>
#include <QMultiMap>
#include <QMutex>
#include <QObject>

/**
 * QMetaObject::invokeMethod
 *
 */
class MetaNotificationCenter : public QObject {
  Q_OBJECT

 public:
  static MetaNotificationCenter *instance();

  void addObserver(QObject *observer, const char *selector,
                   const QString &name);

  void removeObserver(QObject *observer, const QString &name = QString());

  QJsonObject postNotification(const QString &name, const QJsonObject &data);

 private:
  MetaNotificationCenter();
  ~MetaNotificationCenter();

  static MetaNotificationCenter *m_instance;
  QMultiMap<QString, QPair<QObject *, const char *>> m_observers;
  QMutex m_mutex;
};

#endif  // META_NOTIFICATIO_NCENTER_H
