#include "testfraccion.h"

TestFraccion::TestFraccion(){

    this->cuantas_operaciones = 10;
    this->time_en_minutos=1;
    this->set_dificultad(1);
    this->operaciones = new Operacion[10];
    this->respuestas = new Fraccion*[10];

    for(int i = 0 ; i < 10;i++){
        this->respuestas[i] = 0;
    }
    srand(time(0));
    this->generarRandoms();
}

void TestFraccion::set_dificultad(int nivel){
    switch(nivel){
    case 1:
        this->vmayor_denominador=5;
        this->vmenor_denominador=1;
        this->vmayor_numerador=5;
        this->vmenor_numerador=1;
        qDebug() << "1";
        break;
    case 2:
        this->vmayor_denominador=20;
        this->vmenor_denominador=1;
        this->vmayor_numerador=20;
        this->vmenor_numerador=1;
        qDebug() << "2";
        break;
    case 3:
        this->vmayor_denominador=10;
        this->vmenor_denominador=3;
        this->vmayor_numerador=10;
        this->vmenor_numerador=3;
        qDebug() << "3";
        break;
    case 4:
        this->vmayor_denominador=20;
        this->vmenor_denominador=3;
        this->vmayor_numerador=20;
        this->vmenor_numerador=3;
        qDebug() << "4";
        break;
    default:

        this->vmayor_denominador=10;
        this->vmenor_denominador=1;
        this->vmayor_numerador=10;
        this->vmenor_numerador=1;


    }

}

TestFraccion::TestFraccion(int cuantas_operaciones,
                           int time_en_minutos,
                           int dificultad){
    //dificultad -> los rangos;
    this->cuantas_operaciones =cuantas_operaciones;
    this->time_en_minutos = time_en_minutos;
    this->set_dificultad(dificultad);
    this->operaciones = new Operacion[cuantas_operaciones];
    this->respuestas = new Fraccion*[cuantas_operaciones];

    for(int i = 0 ; i < cuantas_operaciones;i++){
        this->respuestas[i] = 0;
    }
    srand(time(0));
    this->generarRandoms();
}

void TestFraccion::generarRandoms(){
    int numerador2, numerador1, denominador2, denominador1,oper;
    Fraccion op1,op2;
    char operador;
    Operacion temp;

    for (int i = 0; i < cuantas_operaciones; i++)
    {


        denominador1 = rand() % (vmayor_denominador - vmenor_denominador)
                       + vmenor_denominador;

        numerador1 = rand() % (vmayor_numerador - vmenor_numerador)
                     + vmenor_numerador;

        denominador2 = rand() % (vmayor_denominador - vmenor_denominador)
                       + vmenor_denominador;

        numerador2 = rand() % (vmayor_numerador - vmenor_numerador)
                     + vmenor_numerador;

        op1.setFraccion(numerador1, denominador1);
        op2.setFraccion(numerador2, denominador2);
        oper = rand()%4;
        switch (oper) {
            case 0:
                operador = '+';
                break;
            case 1:
                operador = '-';
                break;
            case 2:
                operador = '*';
                break;
            default:
                operador = '/';

        }

        temp.setOperacion(op1,op2,operador);
        operaciones[i] = temp;

    }

}

TestFraccion::~TestFraccion(){
    delete[] this->operaciones;
    qDebug() << "Corriendo Destructor";
    for(int i = 0; i < this->cuantas_operaciones; i++){
        if(this->respuestas[i] != 0){
            delete respuestas[i];
        }
    }

    delete[] this->respuestas;
}

Operacion TestFraccion::getOperacion(int index){
    // validar el indice
    return this->operaciones[index];
}

void TestFraccion::setRespuesta(Fraccion respuesta,int index){
    //validar el indice
    if(respuestas[index]!=0){
        this->respuestas[index]->setFraccion(respuesta);
    }else{
        this->respuestas[index]= new Fraccion(respuesta);
    }

}

double TestFraccion::getPuntaje(){
    int correctas = 0;
    double puntaje;
    for( int i = 0; i < this->getCantidadDeOperaciones(); i++ ){

        if ( !(this->getRespuesta(i)->esIgual(0))
            && this->getRespuesta(i)->esIgual( this->getOperacion(i).getResultado() ) ){
               correctas++;
        }

    }
    puntaje = correctas/this->getCantidadDeOperaciones();
    return puntaje;
}

QString TestFraccion::getPuntajeString(){
    double puntaje;
    QString puntajeString;
    puntaje = this->getPuntaje();
    puntajeString.setNum(puntaje);


    return puntajeString;
}


Fraccion *TestFraccion::getRespuesta(int index){

    return this->respuestas[index];
}

void TestFraccion::shuffle(){

    for (int i = 0; i < this->getCantidadDeOperaciones(); i++){
        int random = rand()%getCantidadDeOperaciones();

        exchange(i,random);
    }
}
void TestFraccion::nullifyRespuesta(int index){
    this->respuestas[index] = 0;
}

void TestFraccion::exchange(int posInicial, int posFinal){

    Operacion   *tempOperacion = new Operacion;
    Fraccion    *tempFraccion = new Fraccion;


    //=== Colocar los valores de posIni en Temp;
    tempOperacion->setOperacion(this->getOperacion(posInicial));

    if(this->getRespuesta(posInicial) != 0){
    tempFraccion->setFraccion(this->getRespuesta(posInicial));
    }else{
    tempFraccion = 0;
    }

    //== Colocar los valores desde posFin en posIni ==//

    // this->getOperacion(posInicial).setOperacion(this->getOperacion(posFinal));
    this->operaciones[posInicial].setOperacion(this->getOperacion(posFinal));

    if (this->getRespuesta(posFinal) != 0){
    this->setRespuesta(this->getRespuesta(posFinal),posInicial);
    }else{
        this->nullifyRespuesta(posInicial);
    }
     //== Colocar los valores desde temp a posFinal  ==//

    if (tempFraccion != 0){
    this->setRespuesta(tempFraccion,posFinal);
    }else{
        this->nullifyRespuesta(posFinal);
    }

    //this->getOperacion(posFinal).setOperacion(tempOperacion);
    this->operaciones[posFinal].setOperacion(tempOperacion);

/*
    delete tempFraccion;
    delete tempOperacion;
*/
}

int TestFraccion::respuestasCorrectas(){
    int returnThis = 0;

    for (int i = 0; i < this->getCantidadDeOperaciones(); i++){
        if (respuestaCorrecta(i)){
           returnThis++;
        }
    }

    return returnThis;
}

bool TestFraccion::respuestaCorrecta(int index){
    Fraccion f1,f2;
    bool returnThis;

    if(this->getRespuesta(index) == 0){
        return false;
    }

    f1.setFraccion(this->getRespuesta(index));
    f2.setFraccion(this->getOperacion(index).getResultado());

    returnThis = f1.esIgual(f2);

    return returnThis;
}

int TestFraccion::respuestasIncorrectas(){
   int returnThis;

   returnThis = this->getCantidadDeOperaciones()
           - this->respuestasCorrectas();
   return returnThis;
}

double TestFraccion::getScore(){
    double score;

    score = (double)this->respuestasCorrectas()
            /(double)this->getCantidadDeOperaciones()
            *100;
    QString temp;
    temp.setNum(score);
    qDebug() << temp;

    temp.setNum(this->respuestasCorrectas());
    qDebug() << temp;

    temp.setNum(this->getCantidadDeOperaciones());
    qDebug() << temp;
    return score;
}
