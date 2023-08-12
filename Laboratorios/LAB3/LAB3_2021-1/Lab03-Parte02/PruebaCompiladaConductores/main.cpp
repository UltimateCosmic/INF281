/* 
 * Proyecto:    PruebaCompiladaConductores
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 27 de abril de 2023, 09:29 PM
 */

#include <iostream>
using namespace std;

#include "FuncionesAuxiliares.h"
#include "StructConductor.h"

int main(int argc, char** argv) {

    int numConductores=0;
    struct ConductorSt conductor[200];    
    /* a) */ leerConductores("Conductores.txt", conductor, numConductores);
    /* b) */ leerFaltas("RegistroDeFallas.txt", conductor, numConductores);
    /* c) */ completarMulta("Infracciones.txt", conductor, numConductores);
    /* d) */ calculaMonto(conductor, numConductores);
    /* e) */ emitirReporte("Reporte.txt", conductor, numConductores);    
    /* f) */ aplicarAmnistia(conductor, numConductores);
    /* g) */ emitirReporte("Reporte2.txt", conductor, numConductores);
    
    return 0;
}

