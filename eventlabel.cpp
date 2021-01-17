#include "eventlabel.h"
#include <QMouseEvent>
#include <QMessageBox>
#include <QApplication>
#include "mainwindow.h"

EventLabel::EventLabel(QWidget *parent) : QLabel(parent)
{
    this->setMouseTracking(true);
}

void EventLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 2));

    currRect = QRect(x1, y1, x2-x1, y2-y1);

    if (isClearLastBox)
    {
        x1 = 0;
        x2 = 0;
        y1 = 0;
        y2 = 0;
        isClearLastBox = false;
    }
    painter.drawRect(currRect);

    for (int i=0; i < rectlist.size(); i++)
    {
        painter.drawRect(rectlist[i]);
    }
}

void EventLabel::deleteLastRect()
{
    rectlist.pop_back();
//    isClearLastBox = true;
}

void EventLabel::mousePressEvent(QMouseEvent *event)
{
    x1 = event->x();
    y1 = event->y();
    QCursor cursor;
    cursor.setShape(Qt::ClosedHandCursor);
    QApplication::setOverrideCursor(cursor);
}

void EventLabel::mouseReleaseEvent(QMouseEvent *event)
{
    x2 = event->x();
    y2 = event->y();
    update();
    rectlist.append(currRect);
    QApplication::restoreOverrideCursor();
    QList<int> rectLocation;
    rectLocation << x1 << x2 << y1 << y2;
    emit mouseReleaseSignal();
    emit rectLocationSet(rectLocation);
}

void EventLabel::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        x2 = event->x();
        y2 = event->y();
        update();
    }
}

void EventLabel::deleteRectlist()
{
    rectlist.clear();
    isClearLastBox = true;
}
