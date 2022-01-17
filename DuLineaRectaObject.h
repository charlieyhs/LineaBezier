#ifndef DULINEARECTA_H
#define DULINEARECTA_H

#include <QGraphicsObject>

class DuLineaRectaObject : public QGraphicsObject
{
public:
    DuLineaRectaObject(const QPointF &punto1,const QPointF &punto2, QGraphicsItem *parent = nullptr);
protected:

    QRectF boundingRect()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget = nullptr) override;
private:
    QPointF mPunto1;
    QPointF mPunto2;
};

#endif // DULINEARECTA_H
