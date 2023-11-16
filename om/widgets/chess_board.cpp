#include "chess_board.h"

#include <QPainter>

ChessBoard::ChessBoard(QWidget *parent) : QWidget{parent} {}

ChessBoard::~ChessBoard() { qDebug() << __FUNCTION__; }

void ChessBoard::paintEvent(QPaintEvent *event) {
  qDebug()<<__FUNCTION__;
  QPainter painter(this);

  const float grid_w = 70.0f, radius = 40.0f;  // Radius
  float x = 0.0f, y = 0.0f, x0 = 50.0f, y0 = 30.0f;

  for (int i = 0; i < 9; ++i) {
    y = y0 + grid_w * i;
    painter.drawLine(x0, y, x0 + grid_w * 4, y);
    x = x0 + grid_w * 5;
    painter.drawLine(x, y, x + grid_w * 4, y);
  }

  for (int i = 0; i <= 9; ++i) {
    painter.drawLine(x0 + grid_w * i, y0, x0 + grid_w * i, y0 + grid_w * 8);
  }

  painter.save();
  painter.setBrush(Qt::lightGray);
  painter.drawRect(x0 + grid_w * 4, y, grid_w, grid_w * 9);
  for (int i = 0; i < 9; ++i) {
    painter.drawEllipse(x0 - radius / 2, y0 + grid_w * i - radius / 2, radius,
                        radius);
    painter.drawEllipse(x0 + grid_w * 9 - radius / 2,
                        y0 + grid_w * i - radius / 2, radius, radius);
  }
  painter.restore();

  painter.save();
  painter.translate(350, 150);
  painter.rotate(90);
  painter.setFont(QFont("Arial", 36));
  painter.drawText(0, 0, "river  boundary");
  painter.restore();
}

void ChessBoard::showEvent(QShowEvent *evt) { qDebug() << __FUNCTION__; }
