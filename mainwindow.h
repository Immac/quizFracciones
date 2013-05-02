#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "testfraccion.h"
#include <qstring.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createTest();



private slots:
    void on_pb_Start_clicked();




    void on_pb_Inicio_clicked();

    void on_pb_Enviar_clicked();

    void on_pb_Cancelar_clicked();

    void on_pb_next_clicked();

    void on_pb_prev_clicked();

    void on_pb_ok_clicked();

    void on_pb_Shuffling_clicked();

private:
    Ui::MainWindow *ui;
    TestFraccion *miTest;
    void renderOperacion(int cual);
    int currentOperacion;
    void init();
    void destroyTest();
};

#endif // MAINWINDOW_H
