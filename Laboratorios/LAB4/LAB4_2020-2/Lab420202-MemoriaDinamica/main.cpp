/* 
 * Proyecto:    Lab420202-MemoriaDinamica
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 4 de mayo de 2023, 03:19 PM
 */

#include <iostream>
using namespace std;

#include "Laboratorio04_Funciones.h"

int main(int argc, char** argv) {
    char **codigoMed,**medicos;
    double *tarifas;
    cargarMedicos(codigoMed, medicos, tarifas);
    reporteMedicos(codigoMed, medicos, tarifas);
    reporteDeIngresos(codigoMed, medicos, tarifas);
    return 0;
}

