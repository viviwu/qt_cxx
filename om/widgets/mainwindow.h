#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

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

    void showEvent(QShowEvent * ev) override;

public slots:
    void onRecievedNotify(const QString &name, const QVariantMap &userInfo) ;
    void onMenuButtonClicked();
    void onSettingButtonClicked();

private:
    Ui::MainWindow *ui;
    QSqlRelationalTableModel model;
};
#endif  // MAINWINDOW_H
