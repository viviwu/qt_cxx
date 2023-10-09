#ifndef CONSUMER_H
#define CONSUMER_H

#include <QJsonObject>
#include <QObject>
class Consumer : public QObject
{
  Q_OBJECT
 public:
  explicit Consumer(QObject *parent = nullptr);
  ~Consumer();
 public slots:
  Q_INVOKABLE QJsonObject onDataReceived(const QJsonObject &data);

 signals:
};

#endif // CONSUMER_H
