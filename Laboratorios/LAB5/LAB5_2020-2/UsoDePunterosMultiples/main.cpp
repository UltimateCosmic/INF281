/* 
 * Proyecto:    UsoDePunterosMultiples
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 * Codigo:      20203350
 *
 * Creado el 11 de mayo de 2023, 11:35 AM
 */

#include <iostream>
using namespace std;

#include "Laboratorio04_Funciones.h"

int main(int argc, char** argv) {
    char **codMed, **nombMed, ***nombPac;
    int **codPac, **veces;
    double *tarifas, **porcPac;
    leerMedicos(codMed, nombMed, tarifas);
    repMedicos(codMed, nombMed, tarifas);
    leerAtenciones(codMed, codPac, nombPac, porcPac, veces);    
    repDeIngresos(codMed, nombMed, tarifas, codPac, nombPac, porcPac, veces);
    return 0;
}

