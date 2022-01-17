#include "dugraphicsscene.h"
#include "DuLineaRectaObject.h"
#include "DuCurvaBezierObject.h"

#include <QGraphicsSceneMouseEvent>

DuGraphicsScene::DuGraphicsScene(QObject *parent)
    :QGraphicsScene(parent)
{
    mPresionadoPrimerPunto = false;
    mPresionadoSegundoPunto = false;
    mPintandoLineaRecta = true;
    mPintandoCurvaBezier = false;
}

void DuGraphicsScene::setPintandoCurvaBezierOn()
{
    mPintandoCurvaBezier = true;
    mPintandoLineaRecta = false;
}

void DuGraphicsScene::setPintandoLineaRectaOn()
{
    mPintandoCurvaBezier = false;
    mPintandoLineaRecta = true;
}

void DuGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(!mPresionadoPrimerPunto){
        mPunto1 = event->scenePos();
        mPresionadoPrimerPunto = true;
        mPresionadoSegundoPunto = false;
    }else{
        mPunto2 = event->scenePos();
        mPresionadoSegundoPunto = true;
        mPresionadoPrimerPunto = false;
    }


    event->accept();
}

void DuGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(mPintandoCurvaBezier){

        for(auto &curva : mCurvas){
            if(curva->isUnderMouse()){
                curva->setPuntoControl(event->scenePos());
                break;
            }
        }
        update();
    }
    event->accept();
}

void DuGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(mPintandoLineaRecta){
        if(mPresionadoSegundoPunto){
            addItem(new DuLineaRectaObject(mPunto1,mPunto2));
            mPresionadoPrimerPunto = false;
            mPresionadoSegundoPunto = false;
        }
    }else{
        if(mPresionadoSegundoPunto){
            auto curva = new DuCurvaBezierObject(mPunto1,event->scenePos(),mPunto2);
            mCurvas.append(curva);
            addItem(curva);
            mPresionadoPrimerPunto = false;
            mPresionadoSegundoPunto = false;
        }
    }

    update();
    event->accept();
}
