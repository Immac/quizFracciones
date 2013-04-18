#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include "fraccion.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mitest();
    
private slots:
    void on_pb_sumar_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
