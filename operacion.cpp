#include "operacion.h"

Operacion::Operacion()
{   setOperador('+');
    calcularResultado();
}

Fraccion Operacion::getOperando1(){
    return this->operando1;
}
Fraccion Operacion::getOperando2(){
    return this->operando2;
}

Fraccion Operacion::getOperador(){
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
