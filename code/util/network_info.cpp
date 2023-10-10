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

// ��ȡIP��ַ �������һ����
QString getHostIpAddress()
{
  QString strIpAddress;
  QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
  // ��ȡ��һ����������IPv4��ַ
  int nListSize = ipAddressesList.size();
  for (int i = 0; i < nListSize; ++i) {
    if (ipAddressesList.at(i) != QHostAddress::LocalHost && ipAddressesList.at(i).toIPv4Address()) {
      strIpAddress = ipAddressesList.at(i).toString();
      break;
    }
  }
  // ���û���ҵ������Ա���IP��ַΪIP
  if (strIpAddress.isEmpty()) {
    strIpAddress = QHostAddress(QHostAddress::LocalHost).toString();
  }
  return strIpAddress;
}

// ��ȡMac��ַ
QString getHostMacAddress()
{
  QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces(); // ��ȡ��������ӿ��б�
  int nCnt = nets.count();
  QString strMacAddr = "";
  for (int i = 0; i < nCnt; i++) {
    // ���������ӿڱ�������������в��Ҳ��ǻػ���ַ(��������ӿ�)������ܾ���������Ҫ�ҵ�Mac��ַ
    if (nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning)
        && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack)
        && nets[i].type() != QNetworkInterface::Virtual) {
      strMacAddr = nets[i].hardwareAddress(); // ���ｨ�鷵�ض�����ܵ�MAC
      break;
    }
  }
  return strMacAddr;
}

//�����Ļ�ȡ������ͨ������ҳ����ȡ����IP ����ip
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