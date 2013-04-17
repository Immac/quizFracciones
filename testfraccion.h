#ifndef TESTFRACCION_H
#define TESTFRACCION_H
#include "operacion.h"
class TestFraccion
{
private:
    int cuantas_operaciones;
    int time_en_minutos;
    int vmenor_numerador;
    int vmayor_numerador;
    int vmenor_denominador;
    int vmayor_denominador;

    Operacion* *operaciones;

public:
    TestFraccion();
};

#endif // TESTFRACCION_H
