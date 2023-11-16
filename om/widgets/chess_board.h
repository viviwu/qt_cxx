#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>

class ChessBoard : public QWidget {
  Q_OBJECT
      public:
       explicit ChessBoard(QWidget *parent = nullptr);

       ~ChessBoard();

       void paintEvent(QPaintEvent *event) override;

       void showEvent(QShowEvent *evt) override;

      signals:
};

#endif // DRAWWIDGET_H
