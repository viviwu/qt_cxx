#include "producer.h"

#include <QDebug>
#include <QJsonObject>

#include "notification/meta_notification_center.h"

Producer::Producer(QObject *parent)
    : QObject{parent}
{

}

void Producer::sendData() {
  qDebug() << __FUNCTION__;
  QJsonObject data;
  data["title"] = "This is title";
  data["message"] = "Hello, observers!";

  lock_.lock();
  qDebug() << data;
  QJsonObject result = MetaNotificationCenter::instance()->postNotification("dataReceived", data);
  qDebug() << __FUNCTION__ << "result: " << result;
  lock_.unlock();
}

/*
 Qt/c++在子线程中 调用主线程的方法并同步获取返回值，怎么操作实现并保证线程安全？
 Qt 的线程同步机制，如 QMutex 或 QWaitCondition，来保证线程安全。
另外，也可以使用 QtConcurrent 框架来实现并发执行带有返回值的函数，避免在信号与槽机制中使用带有返回值的函数。

#include <QtConcurrent>

// 定义一个函数，用于对一个数组进行平方操作
void square(int &value)
{
  value = value * value;
}

int main()
{
  // 定义一个数组，用于存储待处理的数据
  QList<int> data;
  for (int i = 0; i < 10000; i++) {
    data.append(i);
  }

          // 使用 QtConcurrent::blockingMapped 函数并行执行平方操作
  QList<int> result = QtConcurrent::blockingMapped(data, square);

          // 输出结果
  for (int i = 0; i < result.size(); i++) {
    qDebug() << result.at(i);
  }

  return 0;
}
 */
