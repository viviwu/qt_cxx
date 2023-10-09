#include "consumer.h"

#include <QDebug>
#include <QJsonObject>

#include "notification/meta_notificatio_ncenter.h"

Consumer::Consumer(QObject *parent) : QObject{parent} {
  qDebug() << __FUNCTION__;
  MetaNotificationCenter::instance()->addObserver(this, "onDataReceived", "dataReceived");
}

Consumer::~Consumer() {
  qDebug() << __FUNCTION__;
  MetaNotificationCenter::instance()->removeObserver(this, "dataReceived");
}

Q_INVOKABLE QJsonObject Consumer::onDataReceived(const QJsonObject &data) {
  qDebug() << "Data received:" << data["message"].toString();
  QJsonObject result;
  result["string"] = "I got it";
  return result;
}
