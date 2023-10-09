#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QJsonObject>
#include <QMainWindow>

#include "consumer.h"
#include "producer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    Q_INVOKABLE QJsonObject onDataReceived(const QJsonObject &data);

private slots:
    void onRecievedNotify(const QString &name, const QVariantMap &userInfo);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    Consumer consumer_;
    Producer producer_;
};
#endif  // MAINWINDOW_H
