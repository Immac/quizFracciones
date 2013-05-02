#include "fraccion.h"

Fraccion::Fraccion(){
        this->numerador=1;
        this->denominador=1;
    }
Fraccion::Fraccion(int num, int den){
    this->setFraccion(num,den);
}
Fraccion::Fraccion(Fraccion *fraccion){
    this->setFraccion(fraccion);
}


int     Fraccion::getNumerador(){
        return this->numerador;
    }

int     Fraccion::getDenominador(){

    return this->denominador;
    }

void    Fraccion::setNumerador(int nuevoNum){

    numerador = nuevoNum;
}

void    Fraccion::setDenominador(int nuevoDenom){
    if (nuevoDenom == 0) return;
    denominador = nuevoDenom;
}

void    Fraccion::setFraccion(int num,int denom){
    setNumerador(num);
    setDenominador(denom);
}

void    Fraccion::setFraccion(Fraccion F){
    this->setFraccion(F.getNumerador(),F.getDenominador());
}

void    Fraccion::setFraccion(Fraccion* F){
    this->setFraccion(F->getNumerador(),F->getDenominador());
}

void        Fraccion::sumar(Fraccion f){
    int newDenom    =   this->getDenominador()  * f.getDenominador();
    int newNum      =   this->getNumerador()    * f.getDenominador()+
                        this->getDenominador()  * f.getNumerador();

    this->setDenominador(newDenom);
    this->setNumerador(newNum);
}

void        Fraccion::sumar(Fraccion f1, Fraccion f2){
  f1.sumar(f2);
 this->setFraccion(f1);
}

Fraccion    Fraccion::Sumar(Fraccion f1,Fraccion f2){
    Fraccion fraccion;
    fraccion.sumar(f1,f2);
    return fraccion;
}

QString Fraccion::toString(){
    QString temp;
    temp.setNum(this->numerador)   ;
    temp = temp + "/";
    temp = temp  + QString::number(this->getDenominador());

    return temp;

}

Fraccion    Fraccion::simplificar(){
    int num = this->getNumerador();
    int den = this->getDenominador();
    Fraccion returnThis;
    returnThis.setFraccion(returnThis.simplificar(num,den,2));
    return returnThis;
   }

Fraccion    Fraccion::simplificar(Fraccion f){
   f.simplificarEsto();
   return f;
}

Fraccion    Fraccion::simplificar(int num, int den, int i){

    Fraccion returnThis(num,den);

    if ( i > num || i > den){

        return returnThis;

    }
    if ( num%i == 0 && den%i == 0){
        int newNum = num/i;
        int newDen = den/i;

        return simplificar( newNum , newDen, i );

    } else {
        return simplificar( num , den , i+1);

    }
}

void        Fraccion::simplificarEsto(){
    Fraccion f;
    int den = simplificar().getDenominador();
    int num = simplificar().getNumerador();
    f.setFraccion(num,den);

    setFraccion(f);
}

bool        Fraccion::esIgual(Fraccion f){
    Fraccion yo = this->simplificar();
    Fraccion comparado = f.simplificar();
    if( yo.getDenominador()==comparado.getDenominador() &&
        yo.getNumerador() == comparado.getNumerador()    ){

            return true;
    }

    return false;

}

bool        Fraccion::esMayor(Fraccion f){
    Fraccion yo;
    yo.setFraccion(this->getNumerador(),this->getDenominador());
    Fraccion comparado = f;
    int yo_new_num, com_new_num;

    yo_new_num = yo.getNumerador() * comparado.getDenominador();
    com_new_num = comparado.getNumerador() * yo.getDenominador();

    if(yo_new_num > com_new_num){
        return true;
    }
    return false;
}


bool        Fraccion::esMenor(Fraccion f){

    bool mayor = this->esMayor(f);
    bool igual = this->esIgual(f);

    if(!mayor && !igual){
        return true;
    }
    return false;
}

void        Fraccion::restar(Fraccion f){
    int newDenom    =   this->getDenominador()  * f.getDenominador();
    int newNum      =   this->getNumerador()    * f.getDenominador()-
                        this->getDenominador()  * f.getNumerador();

    this->setDenominador(newDenom);
    this->setNumerador(newNum);
}

void        Fraccion::restar(Fraccion f1, Fraccion f2){
    f1.restar(f2);
    this->setFraccion(f1);
}

Fraccion    Fraccion::Restar(Fraccion f1, Fraccion f2){
    Fraccion fraccion;
    fraccion.restar(f1,f2);
    return fraccion;
}

void        Fraccion::multiplicar(Fraccion f){
    int newDenom    =   this->getDenominador()  * f.getDenominador();
    int newNum      =   this->getNumerador()    * f.getNumerador();

    this->setFraccion(newNum,newDenom);
}

void        Fraccion::multiplicar(Fraccion f1, Fraccion f2){
    f1.multiplicar(f2);
    this->setFraccion(f1);
}

Fraccion    Fraccion::Multiplicar(Fraccion f1, Fraccion f2){
    Fraccion fraccion;
    fraccion.multiplicar(f1,f2);
    return fraccion;
}

void        Fraccion::dividir(Fraccion f){
    int newDenom    =   this->getDenominador()  * f.getNumerador();
    int newNum      =   this->getNumerador()    * f.getDenominador();

    this->setFraccion(newNum,newDenom);
}

void        Fraccion::dividir(Fraccion f1, Fraccion f2){
    f1.dividir(f2);
    this->setFraccion(f1);
}

Fraccion    Fraccion::Dividir(Fraccion f1, Fraccion f2){
    Fraccion fraccion;
    fraccion.dividir(f1,f2);
    return fraccion;
}

//Hola mundo :D
