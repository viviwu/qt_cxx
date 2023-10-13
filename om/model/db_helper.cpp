//
// Created by viviwu on 2023/10/11.
//
#include "db_helper.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


bool DbHelper::createConnection()
{
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  // db.setDatabaseName(":memory:");
  db.setDatabaseName("app.db");
  if (!db.open()) {
    QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
                          QObject::tr("Unable to establish a database connection.\n"
                                      "This example needs SQLite support. Please read "
                                      "the Qt SQL driver documentation for information how "
                                      "to build it.\n\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    return false;
  }
  QSqlQuery query;
  query.exec("create table if not exists  employee(id int primary key, name varchar(20), city int, country int)");
  query.exec("insert into employee values(1, 'Espen', 5000, 47)");
  query.exec("insert into employee values(2, 'Harald', 80000, 49)");
  query.exec("insert into employee values(3, 'Sam', 100, 1)");

  query.exec("create table  if not exists  city(id int, name varchar(20))");
  query.exec("insert into city values(100, 'San Jose')");
  query.exec("insert into city values(5000, 'Oslo')");
  query.exec("insert into city values(80000, 'Munich')");

  query.exec("create table  if not exists  country(id int, name varchar(20))");
  query.exec("insert into country values(1, 'USA')");
  query.exec("insert into country values(47, 'Norway')");
  query.exec("insert into country values(49, 'Germany')");
  return true;
}

void DbHelper::initializeModel(QSqlRelationalTableModel *model) {
  //! [0]
  model->setTable("employee");
  //! [0]

  model->setEditStrategy(QSqlTableModel::OnManualSubmit);
  //! [1]
  model->setRelation(2, QSqlRelation("city", "id", "name"));
  //! [1] //! [2]
  model->setRelation(3, QSqlRelation("country", "id", "name"));
  //! [2]

  //! [3]
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("City"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Country"));
  //! [3]

  model->select();
}
