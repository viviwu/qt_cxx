//#include <QApplication>
//#include <QPushButton>

#include <QMetaObject>
#include <QCoreApplication>
#include <QMetaObject>
#include <QMetaProperty>

#include "QTNotificationCenter.h"
#include "MyObserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyObserver observer1;
    MyObserver observer2;

    QTNotificationCenter::defaultCenter()->addObserver(&observer1, "NotificationName", "handleNotification(QString,QVariantMap)");
    QTNotificationCenter::defaultCenter()->addObserver(&observer2, "NotificationName", "handleNotification(QString,QVariantMap)");

    QVariantMap userInfo;
    userInfo["Key"] = "Value";

    QTNotificationCenter::defaultCenter()->postNotification("NotificationName", userInfo);

    QTNotificationCenter::defaultCenter()->removeObserver(&observer1, "NotificationName", "handleNotification(QString,QVariantMap)");

    int ret = 0;
    ret = a.exec();
    return ret;
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