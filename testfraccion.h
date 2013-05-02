#ifndef TESTFRACCION_H
#define TESTFRACCION_H
#include "operacion.h"
#include <cmath>
#include <ctime> //o time.h
#include <QDebug>
#include <QString>

class TestFraccion
{
private:
    int cuantas_operaciones;
    int time_en_minutos;
    int vmenor_numerador;
    int vmayor_numerador;
    int vmenor_denominador;
    int vmayor_denominador;
    void generarRandoms();
    void set_dificultad(int nivel);
    Operacion *operaciones; // arreglo dinamico de operaciones
    Fraccion* *respuestas;  //areglo dinamico de apuntadores a fraccion
    void nullifyRespuesta(int index);

    void exchange(int posInicial,int posFinal);
    bool respuestaCorrecta(int index);
public:
      void shuffle();
    TestFraccion();
    TestFraccion(int cuantas_operaciones,
                 int time_en_minutos,
                 int dificultad);


    ~TestFraccion();

    int getCantidadDeOperaciones(){
        return this-> cuantas_operaciones;
    }

    QString getPuntajeString();
    double getPuntaje();
    Operacion getOperacion(int index);
    Fraccion* getRespuesta(int index);
    void setRespuesta(Fraccion respuesta, int index);
    int respuestasCorrectas();
    int respuestasIncorrectas();
    double getScore();
};

#endif // TESTFRACCION_H
