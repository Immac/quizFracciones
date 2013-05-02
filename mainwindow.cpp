#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "operacion.h"
#include <cstring>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{   ui->setupUi(this);
    //== Pantalla de inicio, indice 0 ==//
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::init(){

    this->miTest = 0;
    this->currentOperacion = 0;
    //this->renderOperacion(currentOperacion);

}

void MainWindow::createTest(){
    //=== inicios ===//
    int cuantas_operaciones =
            this->ui->spin_NumeroDeOperaciones->value();
    int time_en_minutos =
            this->ui->spin_TiempoEnMinutos->value();
    int dificultad =
            this->ui->cbDificultad->currentIndex() + 1;


    //=== Inicializar el Test ===//
    this->init();
    this->miTest = new TestFraccion(cuantas_operaciones,
                                    time_en_minutos,
                                    dificultad ); // puede tener () o no;
    this->renderOperacion(currentOperacion);
    //=== Imprimir en el debug el test completo ==//
    for( int i = 0; i < miTest->getCantidadDeOperaciones(); i++ ){
        qDebug() << miTest->getOperacion(i).toString();
    }




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::destroyTest(){
    delete this->miTest;
    this->miTest = 0;
}

void MainWindow::on_pb_Start_clicked()
{
    this->createTest();
    this->renderOperacion(0);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pb_Inicio_clicked()

{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pb_Enviar_clicked()
{
    double score;
    int totalOperaciones,opCorrectas,opIncorrectas;
    score = miTest->getScore();
    totalOperaciones = miTest->getCantidadDeOperaciones();
    opCorrectas = miTest->respuestasCorrectas();
    opIncorrectas = miTest->respuestasIncorrectas();

    QString temp1,temp2;

    //=== Total de operaciones ===//
    temp1 = "Total Operaciones: ";
    temp2.setNum(totalOperaciones);
    temp1 += temp2;
    this->ui->lb_totalOperaciones->setText(temp1);
    //===  Total de respuestas correctas ===//
    temp1 = "Respuestas Correctas: ";
    temp2.setNum(opCorrectas);
    temp1 += temp2;
    this->ui->lb_totalCorrectas->setText(temp1);
    //=== Total de respuestas incorrectas ===//
    temp1 = "Respuestas Incorrectas: ";
    temp2.setNum(opIncorrectas);
    temp1 += temp2;
    this->ui->lb_totalIncorrectas->setText(temp1);
    //=== Nota en % ===//
    temp1 = "Nota en (%): ";
    temp2.setNum(score);
    temp1 += temp2 + "%";
    this->ui->lb_nota->setText(temp1);


    // TODO: puntajes antes de destruir el test

    this->destroyTest();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pb_Cancelar_clicked()
{
    this->destroyTest();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::renderOperacion(int cual){
// TODO: todo lol;
    Operacion operacion;
    Fraccion f1,f2,r1;
    QString temp;
    char operador;
    if (cual == 0){
        this->ui->pb_prev->setDisabled(true);
    } else {
        this->ui->pb_prev->setDisabled(false);
    }
    int cant = miTest->getCantidadDeOperaciones();

    if (cual == cant - 1){
        this->ui->pb_next->setDisabled(true);
    } else {
        this->ui->pb_next->setDisabled(false);
    }

//== la operacion actual ==//
    operacion = miTest->getOperacion(cual);
    f1.setFraccion(operacion.getOperando1());
    f2.setFraccion(operacion.getOperando2());

//== Verificar si existe respuesta, y si existe se escribe ==//

    if(miTest->getRespuesta(currentOperacion) != 0){

        r1.setFraccion(miTest->getRespuesta(currentOperacion));

        temp.setNum(r1.getNumerador());
        ui->le_top->setText(temp);

        temp.setNum(r1.getDenominador());
        ui->le_bot->setText(temp);

        qDebug() << miTest->getRespuesta(currentOperacion)->toString();
    }else{
        ui->le_top->setText("");
        ui->le_bot->setText("");
    }

//== Escribir las dos primeras fracciones ==//
    temp.setNum(f1.getNumerador());
    this->ui->lbl_Numerador1->setText(temp);
    temp.setNum(f1.getDenominador());
    this->ui->lbl_Denominador1->setText(temp);
    temp.setNum(f2.getNumerador());
    this->ui->lbl_Numerador2->setText(temp);
    temp.setNum(f2.getDenominador());
    this->ui->lbl_Denominador2->setText(temp);
//== Escribir el simbolo ==//
    operador = operacion.getOperador();
    temp = operador;
    this->ui->lb_operador->setText(temp);
}

void MainWindow::on_pb_next_clicked(){
    this->currentOperacion++;
    this->renderOperacion(currentOperacion);
}

void MainWindow::on_pb_prev_clicked(){
    this->currentOperacion--;
    this->renderOperacion(currentOperacion);
}

void MainWindow::on_pb_ok_clicked(){
    QString top,bot;
    int inttop,intbot;
    Fraccion f1;

    top = ui->le_top->text();
    bot = ui->le_bot->text();

    inttop = top.toInt();
    intbot = bot.toInt();

    f1.setFraccion(inttop,intbot);

    qDebug() << f1.toString();
    // == Pick a shoe == //

    miTest->setRespuesta(f1,this->currentOperacion);

    //qDebug() <<miTest->getRespuesta(currentOperacion)->toString();


}

void MainWindow::on_pb_Shuffling_clicked()
{
    miTest->shuffle();
    this->renderOperacion(this->currentOperacion);
}
