//
// Created by viviwu on 2023/10/10.
//

#include <QHostAddress>
#include <QHostInfo>
#include <QNetworkAccessManager>
#include <QNetworkInterface>
#include <QNetworkReply>
#include <QEventLoop>

#include "network_info.h"

// 获取IP地址 这个方法一般是
QString getHostIpAddress()
{
  QString strIpAddress;
  QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
  // 获取第一个本主机的IPv4地址
  int nListSize = ipAddressesList.size();
  for (int i = 0; i < nListSize; ++i) {
    if (ipAddressesList.at(i) != QHostAddress::LocalHost && ipAddressesList.at(i).toIPv4Address()) {
      strIpAddress = ipAddressesList.at(i).toString();
      break;
    }
  }
  // 如果没有找到，则以本地IP地址为IP
  if (strIpAddress.isEmpty()) {
    strIpAddress = QHostAddress(QHostAddress::LocalHost).toString();
  }
  return strIpAddress;
}

// 获取Mac地址
QString getHostMacAddress()
{
  QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces(); // 获取所有网络接口列表
  int nCnt = nets.count();
  QString strMacAddr = "";
  for (int i = 0; i < nCnt; i++) {
    // 如果此网络接口被激活并且正在运行并且不是回环地址(本地虚拟接口)，则可能就是我们需要找的Mac地址
    if (nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning)
        && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack)
        && nets[i].type() != QNetworkInterface::Virtual) {
      strMacAddr = nets[i].hardwareAddress(); // 这里建议返回多个可能的MAC
      break;
    }
  }
  return strMacAddr;
}

//外网的获取方法，通过爬网页来获取外网IP 公网ip
QString GetInternetIP()
{
  QUrl url("http://whois.pconline.com.cn/");
  QNetworkAccessManager *manager = new QNetworkAccessManager();
  QNetworkReply *reply = manager->get(QNetworkRequest(url));

  QEventLoop eventLoop;
  QObject::connect(manager, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));
  eventLoop.exec();

  QByteArray responseData = reply->readAll();

  QString html = responseData.replace(" ", "");
  html = html.replace("\r", "");
  html = html.replace("\n", "");
  QStringList list = html.split("<br/>");
  if (list.size() < 4) {
    return "0.0.0.0";
  }
  QString tar = list[3];
//  qDebug() << "tar:" << tar;
  QStringList ip = tar.split("=");
  if (ip.count()>0)
    return ip[1];
  else
    return "0:0:0:0";
}
