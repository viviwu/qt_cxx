//
// Created by vivi wu on 2023/10/16.
//

#ifndef QTCXX_relational_table_view_H
#define QTCXX_relational_table_view_H

#include <QWidget>
#include <QSqlRelationalTableModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class RelationalTableView;
}
QT_END_NAMESPACE

class RelationalTableView : public QWidget {
  Q_OBJECT

  public:
  explicit RelationalTableView(QWidget *parent = nullptr);
  ~RelationalTableView();

 private:
  Ui::RelationalTableView *ui;
  QSqlRelationalTableModel model;
};

#endif  // QTCXX_relational_table_view_H
