#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dugraphicsscene.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mGraphicsScene = new DuGraphicsScene(this);
    ui->graphicsView->setScene(mGraphicsScene);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionSalir_triggered()
{
    close();
}

void MainWindow::on_actionAcerca_de_Qt_triggered()
{
    QMessageBox::aboutQt(this,"Qt");
}

void MainWindow::on_actionPintar_triggered()
{
    mGraphicsScene->setPintandoCurvaBezierOn();
    mGraphicsScene->setPintandoLineaRectaOn();
}

void MainWindow::on_actionPintar_Linea_Recta_triggered()
{
    mGraphicsScene->setPintandoCurvaBezierOn();
    mGraphicsScene->setPintandoLineaRectaOn();
}
