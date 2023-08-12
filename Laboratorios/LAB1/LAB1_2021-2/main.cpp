/* 
 * Proyecto:    LAB1_2021-2
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 1 de abril de 2023, 11:32 PM
 */

#include <iostream>
using namespace std;

#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {

    int fechaDocentes, fechaEstudiantes, fechaPersonal;
    imprimirCabeceraPrincipal(fechaDocentes, fechaEstudiantes, fechaPersonal);
    imprimirReporte(fechaDocentes, fechaEstudiantes, fechaPersonal);
    
    return 0;
}

