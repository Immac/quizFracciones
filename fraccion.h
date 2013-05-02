#ifndef FRACCION_H
#define FRACCION_H

#include <string>
#include <QString>
using namespace std;


class Fraccion
{
private:
        int numerador;
        int denominador;
        Fraccion simplificar(int num, int den, int i);

public:
    Fraccion();
    Fraccion(int num,int den);
    Fraccion(Fraccion* fraccion);

        QString toString();
        int getDenominador();
        int getNumerador();

        void        setNumerador(int nuevoNum);
        void        setDenominador(int nuevoDenom);
        void        setFraccion(int num,int denom);
        void        setFraccion(Fraccion F);
        void        setFraccion(Fraccion* F);
        void sumar(Fraccion f);
        void sumar(Fraccion f1,Fraccion f2);
        static Fraccion Sumar(Fraccion f1, Fraccion f2);


        void        simplificarEsto();
        Fraccion    simplificar(Fraccion f);
        Fraccion    simplificar();



        // TODO


        bool esIgual(Fraccion f);
        bool esMenor(Fraccion f);
        bool esMayor(Fraccion f);



        void            restar(Fraccion f);
        void            restar(Fraccion f1,Fraccion f2);
        static Fraccion Restar(Fraccion f1, Fraccion f2);

        void            multiplicar(Fraccion f);
        void            multiplicar(Fraccion f1,Fraccion f2);
        static Fraccion Multiplicar(Fraccion f1, Fraccion f2);

        void        dividir(Fraccion f);
        void        dividir(Fraccion f1,Fraccion f2);
        static Fraccion Dividir(Fraccion f1,Fraccion f2);

};

#endif // FRACCION_H
