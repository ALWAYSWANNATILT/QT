#include "qpaintwidget.h"
#include "windows.h"
#include <QPainter>
#include <QTimer>
#include <cmath>

QPaintWidget::QPaintWidget(QWidget * parent) : QWidget(parent)

{

QTimer *timer = new QTimer(this);
connect(timer, SIGNAL(timeout()), this, SLOT(UpdatePixmap()));
timer->start(10);
}


void QPaintWidget::paintEvent(QPaintEvent *) {

QPainter p(this); // Создаём новый объект рисовальщика
QTransform transform;
transform.rotate(90,Qt::ZAxis);
transform.translate(60,-20);
 p.setTransform(transform);
p.setFont(QFont("Yu Gothic", 10, QFont::Bold));
p.drawText(rect(), "Лабораторная работа №1");
transform.rotate(-90,Qt::ZAxis);
 p.setTransform(transform);


p.setPen(QPen(Qt::red,1,Qt::SolidLine)); // Настройки рисования
p.drawLine(center.x() - 30  , center.y() + 10, center.x() + 50,center.y() + 10);
p.drawLine(center.x() - 30  , center.y() + 10, center.x() - 30 ,center.y() + 40);
p.drawLine(center.x() - 30  , center.y() + 40, center.x() + 50 ,center.y() + 40);
p.drawLine(center.x() + 50  , center.y() + 40, center.x() + 50 ,center.y() + 10);

p.drawLine(center.x() -10  , center.y() + 40, center.x() + -10 ,center.y() + 60);
p.drawLine(center.x() -10 ,center.y() + 60, center.x() - 50 ,center.y() + 60);
p.drawLine(center.x() - 50 ,center.y() + 60, center.x() - 50 ,center.y() + 100);
p.drawLine(center.x() - 50 ,center.y() + 100, center.x() + 70 ,center.y() + 100);
p.drawLine(center.x() + 70 ,center.y() + 100, center.x() + 70 ,center.y() + 60);
p.drawLine(center.x() + 70 ,center.y() + 60, center.x()  + 30  , center.y() + 60);
p.drawLine(center.x()  + 30  , center.y() + 60, center.x() +30  , center.y() + 40);


center.setX(start.x() + r * cos(t));
center.setY(start.y() + r * sin(t));

r -= 0.5;
t +=0.1;

}

void QPaintWidget::UpdatePixmap()
{
update();
}
