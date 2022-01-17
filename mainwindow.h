#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class DuGraphicsScene;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionSalir_triggered();

    void on_actionAcerca_de_Qt_triggered();

    void on_actionPintar_triggered();

    void on_actionPintar_Linea_Recta_triggered();

private:
    Ui::MainWindow *ui;
    DuGraphicsScene *mGraphicsScene;
};
#endif // MAINWINDOW_H
