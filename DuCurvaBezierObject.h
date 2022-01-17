#ifndef DUCURVABEZIEROBJECT_H
#define DUCURVABEZIEROBJECT_H

#include <QGraphicsObject>

class DuCurvaBezierObject : public QGraphicsObject
{
public:
    DuCurvaBezierObject(const QPointF &puntoInicio, const QPointF puntoControl, const QPointF puntoFinal,QGraphicsItem *parent=nullptr);
    void setPuntoControl(const QPointF &puntoControl){
        mPuntoControl = puntoControl;
    }
protected:
    QRectF boundingRect()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget = nullptr) override;
private:
    QPointF mPuntoInicio;
    QPointF mPuntoControl;
    QPointF mPuntoFinal;

    QPainterPath getPath()const;
};

#endif // DUCURVABEZIEROBJECT_H
