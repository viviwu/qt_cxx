#include <QApplication>
#include <QHostInfo>

#include "db_helper.h"
#include "mainwindow.h"
#include "network_info.h"

void localMachineNetworkInfo(){
  qDebug() << getHostIpAddress();
  qDebug() << getHostMacAddress();

  QString hostname = QHostInfo::localHostName();
  qDebug() << hostname;

  QString netIp = GetInternetIP(); //公网ip
  qDebug() << netIp;
}

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  if (!DbHelper::createConnection())
    return EXIT_FAILURE;

  MainWindow w;
  w.show();

  localMachineNetworkInfo();

  return a.exec();
}

/**

#include "my_class.h"

int main(int argc, char *argv[]) {
    int ret = 0;

#if 0
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    ret = QApplication::exec();
#else
    QCoreApplication app(argc, argv);

    MyObject obj;
    const QMetaObject *metaObj = obj.metaObject();
    int propertyCount = metaObj->propertyCount();
    qDebug()<<"propertyCount ="<<propertyCount;

    for (int i = 0; i < propertyCount; ++i) {
        QMetaProperty metaProperty = metaObj->property(i);
        const char *propertyName = metaProperty.name();
        const char *typeName = metaProperty.typeName();
        qDebug() << "Property Name:" << propertyName<<" typeName:"<<typeName;
    }


#endif

    return ret;
}

 *
 */
