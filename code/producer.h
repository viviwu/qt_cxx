#ifndef PRODUCER_H
#define PRODUCER_H

#include <QMutex>
#include <QObject>

class Producer : public QObject
{
  Q_OBJECT
 public:
  explicit Producer(QObject *parent = nullptr);

  void sendData();

 signals:

 private:
  QMutex lock_;
};

#endif // PRODUCER_H
