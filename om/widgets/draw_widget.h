#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>

class DrawWidget : public QWidget
{
  Q_OBJECT
      public:
 explicit DrawWidget(QWidget *parent = nullptr);

          ~DrawWidget();

 void paintEvent(QPaintEvent *event) override ;

 void showEvent(QShowEvent *evt) override;

 signals:

};

#endif // DRAWWIDGET_H
