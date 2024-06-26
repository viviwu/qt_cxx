#include <QCoreApplication>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonValueRef>
#include <QHash>
#include <QMap>


void http_params(){
    QJsonObject filter;
    filter.insert("name", "solomon");
    filter.insert("age", 35);
    filter.insert("sex", true);
    filter.insert("height", 174.5);

    QString url_str("http://www.api.com");
    for (const QString &key : filter.keys()) {
        const QJsonValue value = filter.value(key);
        QString text;
        if (value.isBool())
            text = QString::number(value.toBool());
        else if (value.isDouble())
            text = QString::number(value.toDouble());
        else
            text = value.toString();

        if (url_str.contains("?"))
            url_str = QString("%1&%2=%3").arg(url_str, key).arg(text);
        else
            url_str = QString("%1?%2=%3").arg(url_str, key).arg(text);
    }
    qDebug() << url_str;
}

void unordered_dict(){
    QHash<int, QString> dict={{101,"A"},{103,"C"},{102,"B"},{104,"D"}};
    dict.insert(3, "type");
    dict.insert(1, "name");
    dict.insert(0, "id");
    dict.insert(2, "key");

    QHash<int, QString>::const_iterator i = dict.constBegin(); // 用于只读遍历
    while (i != dict.constEnd()) {
        qDebug() << i.key() << ":" << i.value();
        ++i;
    }

    int size = dict.size();
    qDebug()<<"dict size="<<size;

    bool containsKey = dict.contains(3);
    if(containsKey){
        QString value = dict.value(2);
        qDebug()<<"dict['2']"<<value;
        dict.remove(2);
    }
    dict.clear();
}

void ordered_dict(){
    QMap<int, QString> dict={{101,"A"},{103,"C"},{102,"B"},{104,"D"}};
    dict.insert(3, "type");
    dict.insert(1, "name");
    dict.insert(0, "id");
    dict.insert(2, "key");

    QMap<int, QString>::const_iterator i = dict.constBegin();
    while (i != dict.constEnd()) {
        qDebug() << i.key() << ":" << i.value();
        ++i;
    }

    int size = dict.size();
    qDebug()<<"dict size="<<size;

    bool containsKey = dict.contains(3);
    if(containsKey){
        QString value = dict.value(2);
        qDebug()<<"dict['2']"<<value;
        dict.remove(2);
    }
    dict.clear();
}

#define USE_QT_APP 0

int main(int argc, char *argv[])
{
#if  USE_QT_APP
    QCoreApplication a(argc, argv);

    return a.exec();
#else
    //    http_params();

    unordered_dict();

    qDebug()<<"++++++++++++++++++++";

    ordered_dict();


#endif

    return 0;
}

