/* 
 * Proyecto:    LAB1_2022-1
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 13 de abril de 2023, 08:41 PM
 */

#include <iostream>
using namespace std;

#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {    
    double descA, descB, descC;
    char producto[7];
    leerDescuentos(descA, descB, descC, producto);
    imprimirReporteDeGastos(descA, descB, descC, producto);
    return 0;
}

