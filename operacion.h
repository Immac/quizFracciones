#ifndef OPERACION_H
#define OPERACION_H
#include "fraccion.h"
#include <QString>
class Operacion
{
private:
    Fraccion operando1;
    Fraccion operando2;
    Fraccion resultado;
    char operador; // + , - , * , /

public:
    Operacion();

    Operacion( Fraccion op1, Fraccion op2, char operador );

    Fraccion    getOperando1();
    Fraccion    getOperando2();
    char        getOperador();
    Fraccion    getResultado();
    QString     toString();
    void        setOperando1(Fraccion f);
    void        setOperando2(Fraccion f);
    void        setOperador(char operador);
    void        setOperacion(Fraccion op1, Fraccion op2, char operador);
    void        setOperacion(Operacion operacion);
     void        setOperacion(Operacion* operacion);
    void        calcularResultado();

};

#endif // OPERACION_H
