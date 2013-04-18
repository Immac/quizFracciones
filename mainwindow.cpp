#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "operacion.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mitest();
}


void MainWindow::mitest(){
    /*
    //=== Test 1 ===//
    qDebug()<<"Testing";
    Fraccion primera(2,3);
    qDebug()<<"Denominador es:"<< primera.getDenominador();
    qDebug()<<"Numerador es:"<< primera.getNumerador();
    primera.setDenominador(0);
    qDebug()<<"Denominador es: "<<primera.getDenominador();
    primera.setDenominador(5);
    qDebug()<<"Denominador es:" << primera.getDenominador();
    */
    /*
    //=== Test 2; Suma ===//
    Fraccion fraccion1(1,2);
    Fraccion fraccion2(1,3);
    fraccion1.sumar(fraccion2);
    qDebug()<< fraccion1.getNumerador()<<"/"
            << fraccion1.getDenominador();
    */
    /*
    //=== Test 3; Suma, estilo Java ==/
    Fraccion *Frac;
    Frac = new Fraccion(5,6);
    Frac->setDenominador(2);

    delete Frac;
    */
    //===Test 4; suma, estatica y normal ==/
    /*
    Fraccion f1(1,2);
    Fraccion f2(1,3);
    qDebug()<< f1.getNumerador() <<"/" << f1.getDenominador();
    qDebug()<< f2.getNumerador() <<"/" << f2.getDenominador();
    Fraccion f3,f4;
    f3.sumar(f1,f2);
    f4 = Fraccion::Sumar(f1,f2);
    qDebug()<< f3.toString();
    qDebug()<< f4.toString();
    */
/*
    //=== Test 5; otras operaciones ==/
    Fraccion f9;
    f9.setFraccion(5,10);
    f9.simplificarEsto();
    qDebug() << f9.toString();
*/

/*
    //=== Test 6, comparadores ==//

    Fraccion f10;
    Fraccion f11;
    Fraccion f12;
    f10.setFraccion(8,10);
    f11.setFraccion(4,5);
    f12.setFraccion(9,9) ;

    qDebug() << f10.toString() << " Es igual a: " << f11.toString() <<
                " ?";
    qDebug() << f10.esIgual(f11);

    qDebug() << f12.toString() << " Es igual a: " << f11.toString() <<
                " ?";
    qDebug() << f12.esIgual(f11);

    qDebug() << f12.toString() << " Es mayor a: " << f11.toString() <<
                " ?";
    qDebug() << f12.esMayor(f11);

    qDebug() << f12.toString() << " Es menor a: " << f11.toString() <<
                " ?";
    qDebug() << f12.esMenor(f11);

    qDebug() << f10.toString() << " Es menor a: " << f11.toString() <<
                " ?";
    qDebug() << f10.esMenor(f11);
*/

    //=== Test 7, operacion ==/
    Fraccion f1(1,2);
    Fraccion f2(3,4);

    Operacion operacion2;
    Operacion operacion1(f1,f2,'/');

    qDebug() << operacion1.getResultado().toString();
    qDebug() << operacion2.toString();
    qDebug() << operacion1.toString();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_sumar_clicked()
{
  Fraccion f1,f2,f3;

    f1.setNumerador(ui->le_num1->text().toInt());
    f1.setDenominador(ui->le_den1->text().toInt());
    f2.setNumerador(ui->le_num2->text().toInt());
    f2.setDenominador(ui->le_den2->text().toInt());
    f3.sumar(f1,f2);
    f3.simplificarEsto();
    QString numerador,denominador;
    numerador.setNum(f3.getNumerador());
    denominador.setNum(f3.getDenominador());

    ui->le_res_num->setText(numerador);
    ui->le_res_den->setText(denominador);
}
