#include "mainwindow.h"

#include <QMessageBox>

#include "qt_notification_center.h"
#include "uic/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  QTNotificationCenter::defaultCenter()->addObserver(this, SLOT(onRecievedNotify(const QString&, const QVariantMap &)), "NotificationName");
}

MainWindow::~MainWindow() {
  QTNotificationCenter::defaultCenter()->removeObserver(this, SLOT(onRecievedNotify(const QString&, const QVariantMap &)), "NotificationName");
  delete ui;
  qDebug() << __FUNCTION__;
}


void MainWindow::onRecievedNotify(const QString &name, const QVariantMap &userInfo) {
  qDebug() << __FUNCTION__ << name ;
  QMap<QString, QVariant>::const_iterator iter;   //! QVariantMap::iterator iter;
  for (iter = userInfo.begin();  iter!= userInfo.end(); iter++) {
    qInfo()<<iter.key()<<iter.value();
  }
}

void MainWindow::on_pushButton_clicked() {

  qDebug()<<__FUNCTION__ ;
  QVariantMap userInfo;
  userInfo["Key"] = "Value";
  userInfo["volume"] = 1200;
  userInfo["price"] = 12.34;
  QTNotificationCenter::defaultCenter()->postNotification("NotificationName", userInfo);
}
