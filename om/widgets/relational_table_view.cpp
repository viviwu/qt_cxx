//
// Created by vivi wu on 2023/10/16.
//

// You may need to build the project (run Qt uic code generator) to get
// "ui_relational_table_view.h" resolved

#include "relational_table_view.h"

#include "db_helper.h"
#include "ui_relational_table_view.h"

RelationalTableView::RelationalTableView(QWidget *parent)
    : QWidget(parent), ui(new Ui::RelationalTableView) {
  setWindowTitle(QObject::tr("Relational Table Model"));
  ui->setupUi(this);

  DbHelper::initializeModel(&model);

  ui->tableView->setModel(&model);
  ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
  qDebug() << __FUNCTION__;
}

RelationalTableView::~RelationalTableView() {
  delete ui;
  qDebug() << __FUNCTION__;
}
