#include <QCoreApplication>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValueRef>
#include <QJsonValue>
#include <QDebug>
#include <QList>
#include <QMap>

void modifyGivenPairInJsonArray(QJsonArray &json_array) {
  for (int i = 0; i < json_array.size(); ++i) {
    // 获取当前元素的引用
    const QJsonValue json_element = json_array.at(i);
    if (json_element.isObject()) {
      QJsonObject json_object = json_element.toObject();
      if (json_object.contains("xkey")) {
        json_object["xkey"] = 43;
      }
      json_array.replace(i, json_object);
    }
  }
}

void json_array_tester() {
  QJsonArray json_array = {
      QJsonObject{{"xkey", 10}},
      QJsonObject{{"xkey", 20}},
      QJsonObject{{"xkey", 30}}
  };

  modifyGivenPairInJsonArray(json_array);

  for (const QJsonValue &value: json_array) {
    qDebug() << value.toObject();
  }
}

int main() {
  //    QCoreApplication a(argc, argv);
//    qDebug() << "Hello World";
//    return QCoreApplication::exec();
  return 0;
}