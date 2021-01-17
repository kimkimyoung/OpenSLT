#ifndef EVENTLABEL_H
#define EVENTLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <QList>
#include "opencv2/opencv.hpp"

class EventLabel : public QLabel
{
    Q_OBJECT
public:
    explicit EventLabel(QWidget *parent = nullptr);

private:

public:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

    QList<QRect> rectlist;
    QRect currRect;
    bool isClearLastBox = false;

signals:
    void mouseReleaseSignal();
    void rectLocationSet(QList<int>);\
public slots:
    void deleteRectlist();
    void deleteLastRect();

};

#endif // EVENTLABEL_H
