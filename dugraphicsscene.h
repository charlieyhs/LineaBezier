#ifndef DUGRAPHICSSCENE_H
#define DUGRAPHICSSCENE_H

#include <QGraphicsScene>

class DuCurvaBezierObject;

class DuGraphicsScene : public QGraphicsScene
{
public:
    DuGraphicsScene(QObject *parent = nullptr);
    void setPintandoCurvaBezierOn();
    void setPintandoLineaRectaOn();
    bool getPintandoCurvaBezier() const{
        return mPintandoCurvaBezier;
    }
    bool getPintandoLineaRecta()const{
        return mPintandoLineaRecta;
    }
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QPointF mPunto1;
    QPointF mPunto2;
    bool mPresionadoPrimerPunto;
    bool mPresionadoSegundoPunto;
    bool mPintandoCurvaBezier;
    bool mPintandoLineaRecta;
    QList <DuCurvaBezierObject *> mCurvas;
};

#endif // DUGRAPHICSSCENE_H
