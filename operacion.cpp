#include "operacion.h"

Operacion::Operacion()
{   setOperador('+');
    calcularResultado();
}

Operacion::Operacion(Fraccion op1, Fraccion op2, char operador){
    this->setOperacion(op1,op2,operador);
}

QString Operacion::toString(){
    QString temp;
    temp = operando1.toString() + " ";
    temp += this->getOperador();
    temp += " " + operando2.toString() + " ";
    temp += " = " + resultado.toString();
    return temp;
}

Fraccion Operacion::getOperando1(){
    return this->operando1;
}
Fraccion Operacion::getOperando2(){
    return this->operando2;
}

char Operacion::getOperador(){
    return this->operador;
}

void    Operacion::setOperando1(Fraccion f){
    this->operando1.setFraccion(f);
    calcularResultado();
}

void    Operacion::setOperando2(Fraccion f){
    this->operando2.setFraccion(f);
    calcularResultado();
}
void    Operacion::setOperador(char operador){
    this->operador = operador;
    calcularResultado();
}


void    Operacion::setOperacion(Fraccion op1, Fraccion op2,
                                char operador){

    this->setOperando1(op1);
    this->setOperando2(op2);
    this->setOperador(operador);


    calcularResultado();
}
void    Operacion::setOperacion(Operacion *operacion){
    Fraccion op1,op2;
    char operador;
    op1.setFraccion(operacion->getOperando1());
    op2.setFraccion(operacion->getOperando2());
    operador = operacion->getOperador();

    this->setOperacion(op1,op2,operador);


}
void    Operacion::setOperacion(Operacion operacion){
    Fraccion op1,op2;
    char operador;
    op1.setFraccion(operacion.getOperando1());
    op2.setFraccion(operacion.getOperando2());
    operador = operacion.getOperador();

    this->setOperacion(op1,op2,operador);
}

Fraccion Operacion::getResultado(){
    calcularResultado();
    return this->resultado;
}

void Operacion::calcularResultado(){

    Fraccion op1 = this->getOperando1();
    Fraccion op2 = this->getOperando2();

    switch (this->operador){
    case '+': this->resultado.sumar(op1,op2);
        break;
    case '-': this->resultado.restar(op1,op2);
        break;
    case '*': this->resultado.multiplicar(op1,op2);
        break;
    case '/': this->resultado.dividir(op1,op2);
        break;
    default : this->resultado.sumar(op1,op2);
        this->operador = '+';
        break;


    }
}
