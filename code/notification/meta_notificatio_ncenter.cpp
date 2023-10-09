// xnotificationcenter.cpp
#include "meta_notificatio_ncenter.h"

MetaNotificationCenter *MetaNotificationCenter::m_instance = nullptr;

MetaNotificationCenter *MetaNotificationCenter::instance() {
  if (!m_instance) {
    m_instance = new MetaNotificationCenter();
  }
  return m_instance;
}

void MetaNotificationCenter::addObserver(QObject *observer, const char *selector, const QString &name) {
  const QMutexLocker locker(&m_mutex);
  m_observers.insert(name, qMakePair(observer, selector));
}

void MetaNotificationCenter::removeObserver(QObject *observer, const QString &name) {
  QMutexLocker locker(&m_mutex);
  if (name.isEmpty()) {
    for (auto it = m_observers.begin(); it != m_observers.end();) {
      if (it.value().first == observer) {
        it = m_observers.erase(it);
      } else {
        ++it;
      }
    }
  } else {
    m_observers.remove(name, qMakePair(observer, ""));
  }
}

QJsonObject MetaNotificationCenter::postNotification(const QString &name, const QJsonObject &data) {
  qDebug() << __FUNCTION__ << name << data;
  QJsonObject info;
  QMutexLocker locker(&m_mutex);
  auto range = m_observers.equal_range(name);
  for (auto it = range.first; it != range.second; ++it) {
    QObject *observer = it.value().first;
    const char *selector = it.value().second;
    qDebug() << observer << selector;
    QJsonObject result;
    QMetaObject::invokeMethod(observer, selector, Q_RETURN_ARG(QJsonObject, result), Q_ARG(QJsonObject, data));
    //    qDebug() << "result: " << result;
    const QMetaObject *meta = observer->metaObject();
    info.insert(meta->className(), result);
  }
  return info;
}

MetaNotificationCenter::MetaNotificationCenter() : QObject() {
}

MetaNotificationCenter::~MetaNotificationCenter() {
  delete m_instance;
}
