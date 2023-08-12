/* 
 * Proyecto:    LAB1_2022-1
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 8 de abril de 2023, 06:47 PM
 */

#include <iostream>
using namespace std;

#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {

    char especialidadA[20], especialidadB[20];
    int fechaDelProceso;
    leerEspecialidadesYFecha(especialidadA, especialidadB, fechaDelProceso);
    imprimirReporteDeEmpresa(especialidadA, especialidadB, fechaDelProceso);
    
    return 0;
}

