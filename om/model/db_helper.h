//
// Created by viviwu on 2023/10/11.
//

#include <QtSql>

#ifndef QTCXX_DB_HELPER_H
#define QTCXX_DB_HELPER_H

class DbHelper {

  public:
  /*
     This file defines a helper function to open a connection to an
     in-memory SQLITE database and to create a test table.

     If you want to use another database, simply modify the om
     below. All the examples in this directory use this function to
     connect to a database.
 */
//! [0]
  static bool createConnection() ;

  static void initializeModel(QSqlRelationalTableModel *model);

  //! [0]
};




#endif  // QTCXX_DB_HELPER_H
