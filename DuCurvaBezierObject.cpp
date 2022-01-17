#include "DuCurvaBezierObject.h"

#include <QPainter>

DuCurvaBezierObject::DuCurvaBezierObject(const QPointF &puntoInicio, const QPointF puntoControl, const QPointF puntoFinal, QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
    mPuntoInicio = puntoInicio;
    mPuntoControl = puntoControl;
    mPuntoFinal = puntoFinal;
}

QRectF DuCurvaBezierObject::boundingRect() const
{
    return getPath().boundingRect();
}

void DuCurvaBezierObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPen pen;
    pen.setWidth(5);
    painter->setPen(pen);
    painter->drawPath(getPath());
}

QPainterPath DuCurvaBezierObject::getPath() const
{
    QPainterPath path(mPuntoInicio);
    path.quadTo(mPuntoControl,mPuntoFinal);
    return path;
}
