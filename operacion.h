#ifndef OPERACION_H
#define OPERACION_H
#include "fraccion.h"
class Operacion
{
private:
    Fraccion operando1;
    Fraccion opernado2;
    Fraccion resulrado;
    char operador; // + , - , * , /

public:
    Operacion();
    Operacion( Fraccion op1, Fraccion op2, char operador );

    Fraccion    getOperando1();
    Fraccion    getOperando2();
    char        getOperador();

    void        setOperando1(Fraccion f);
    void        setOperando2(Fraccion f);
    void        setOperador(char operador);
    void        setOperacion(Fraccion op1, Fraccion op2);


    void        calcularResultado();
};

#endif // OPERACION_H
