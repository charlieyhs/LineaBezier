#include "DuLineaRectaObject.h"

#include <QPainter>

DuLineaRectaObject::DuLineaRectaObject(const QPointF &punto1, const QPointF &punto2, QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
    mPunto1 = punto1;
    mPunto2 = punto2;
}

QRectF DuLineaRectaObject::boundingRect() const
{
    const float x2 = mPunto2.x();
    const float x1 = mPunto1.x();
    const float y2 = mPunto2.y();
    const float y1 = mPunto1.y();
    return QRectF(mPunto1, QSizeF(x2-x1,y2-y1));
}

void DuLineaRectaObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    (void)option;
    (void)widget;
    QPen pen;
    pen.setWidth(5);
    painter->setPen(pen);
    painter->drawLine(mPunto1,mPunto2);
}
