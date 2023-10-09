#include "mainwindow.h"

#include <QMessageBox>

#include "meta_notificatio_ncenter.h"
#include "uic/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  MetaNotificationCenter::instance()->addObserver(this, "onDataReceived", "dataReceived");
}

MainWindow::~MainWindow()
{
  MetaNotificationCenter::instance()->removeObserver(this, "dataReceived");

  delete ui;
  qDebug()<<__FUNCTION__;
}

Q_INVOKABLE QJsonObject MainWindow::onDataReceived(const QJsonObject &data) {
  qDebug() << __FUNCTION__;
  QJsonObject json;

  qDebug() << "Data received:" << data["message"].toString();

  QMessageBox::StandardButton reply;
  reply = QMessageBox::question(qApp->activeWindow(), data["title"].toString(), data["message"].toString(),
                                QMessageBox::Yes | QMessageBox::No);
  if (reply == QMessageBox::No) {
    json.insert("bool", false);
  } else {
    json.insert("bool", true);
  }
  return json;
}

void MainWindow::on_pushButton_clicked() {
  producer_.sendData();

  //  QThread *thread = new QThread();
  //  producer.moveToThread(thread);
  //  Consumer::connect(thread, &QThread::started, &producer, &Producer::sendData);
  //  thread->start();
}
