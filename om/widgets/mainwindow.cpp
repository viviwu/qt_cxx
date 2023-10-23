#include "mainwindow.h"

#include <QMessageBox>
#include <QSpacerItem>

#include "draw_widget.h"
#include "qt_notification_center.h"
#include "relational_table_view.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  QTNotificationCenter::defaultCenter()->addObserver(
      this, SLOT(onRecievedNotify(const QString &, const QVariantMap &)),
      "NotificationName");

  menus = QString("关系表,绘图,设置").split(",");
  for (int i = 0; i < menus.count(); ++i) {
    const QString name = menus[i];
    QPushButton *button = new QPushButton(name);
    button->setObjectName(QString::number(i));
    button->setMinimumSize(QSize(60, 30));
    button->setMaximumSize(QSize(60, 30));
    ui->verticalLayout->addWidget(button);

    connect(button, SIGNAL(clicked(bool)), this, SLOT(onMenuButtonClicked()));

    QWidget *widget = widgetByName(name);
    ui->stackedWidget->insertWidget(i, widget);
  }
//  QSpacerItem *verticalSpacer =
//      new QSpacerItem(20, 434, QSizePolicy::Minimum, QSizePolicy::Expanding);
//  ui->verticalLayout->addItem(verticalSpacer);
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

QWidget *MainWindow::widgetByName(const QString &name) {
  QWidget *widget = nullptr;
  if ("关系表" == name) {
    widget = new RelationalTableView(this);
  } else if ("绘图" == name) {
    widget = new DrawWidget(this);
  } else {
    widget = new QWidget(this);
  }
  return widget;
}

void MainWindow::onRecievedNotify(const QString &name, const QVariantMap &userInfo) {
  qDebug() << __FUNCTION__ << name ;
  QMap<QString, QVariant>::const_iterator iter;   //! QVariantMap::iterator iter;
  for (iter = userInfo.begin();  iter!= userInfo.end(); iter++) {
    qInfo()<<iter.key()<<iter.value();
  }
}

void MainWindow::onMenuButtonClicked() {
  QPushButton *button = (QPushButton *)sender();
  int index = button->objectName().toInt();
  qDebug()<<__func__<<index<<ui->stackedWidget->count();
  ui->stackedWidget->setCurrentIndex(index);
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
