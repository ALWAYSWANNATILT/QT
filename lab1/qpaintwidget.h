#ifndef QPAINTWIDGET_H
#define QPAINTWIDGET_H
#include <QtWidgets/QWidget>

class QPaintEvent;
class QPaintWidget : public QWidget
{
Q_OBJECT
QPoint center = QPoint(800, 400);
QPoint start = center;
double t = 0, r = 900;
public:
QPaintWidget(QWidget * parent = 0);
protected:


void paintEvent(QPaintEvent *);

private slots:
void UpdatePixmap();
};

#endif // QPAINTWIDGET_H
