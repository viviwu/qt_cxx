#include "mainwindow.h"

#include <QMessageBox>


#include "qt_notification_center.h"
#include "ui_mainwindow.h"
#include "relationa_ltable_view.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  QTNotificationCenter::defaultCenter()->addObserver(this, SLOT(onRecievedNotify(const QString &, const QVariantMap &)),
                                                     "NotificationName");

  RelationalTableView *rtv = new RelationalTableView;
  ui->stackedWidget->addWidget(rtv);
  connect(ui->Button, SIGNAL(clicked(bool)), this, SLOT(onMenuButtonClicked()));
}

MainWindow::~MainWindow() {
  QTNotificationCenter::defaultCenter()->removeObserver(this, SLOT(onRecievedNotify(const QString&, const QVariantMap &)), "NotificationName");
  delete ui;
  qDebug() << __FUNCTION__;
}

void MainWindow::showEvent(QShowEvent * ev)
{
  qDebug() << __FUNCTION__;
  Q_UNUSED(ev)
}

void MainWindow::onRecievedNotify(const QString &name, const QVariantMap &userInfo) {
  qDebug() << __FUNCTION__ << name ;
  QMap<QString, QVariant>::const_iterator iter;   //! QVariantMap::iterator iter;
  for (iter = userInfo.begin();  iter!= userInfo.end(); iter++) {
    qInfo()<<iter.key()<<iter.value();
  }
}

void MainWindow::onMenuButtonClicked() {
  ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::onSettingButtonClicked()
{
  qDebug()<<__FUNCTION__ ;
  qDebug()<<__FUNCTION__ ;
  QVariantMap userInfo;
  userInfo["Key"] = "Value";
  userInfo["volume"] = 1200;
  userInfo["price"] = 12.34;
  QTNotificationCenter::defaultCenter()->postNotification("NotificationName", userInfo);
}