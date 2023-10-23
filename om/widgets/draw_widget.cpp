#include "draw_widget.h"
#include <QPainter>

DrawWidget::DrawWidget(QWidget *parent)
    : QWidget{parent}
{

}

DrawWidget::~DrawWidget(){
  qDebug()<<__FUNCTION__;
}

void DrawWidget::paintEvent(QPaintEvent *event)
{
  qDebug()<<__FUNCTION__;
  QPainter painter(this);
  int W = 50;
  for (int i = 0; i <=9; ++i) {
    painter.drawLine(10+W*i, 10, 10+W*i, 10+W*9);
    painter.drawLine(10, 10+W*i, 10+W*9, 10+W*i);
  }
  painter.drawLine(10, 10, W, W);
  painter.drawRect(50, 50, W, W);
  painter.drawText(150, 150, "Hello Qt!");
}

void DrawWidget::showEvent(QShowEvent *evt) {
  qDebug()<<__FUNCTION__;
}
