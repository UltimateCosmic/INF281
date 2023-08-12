/* 
 * Proyecto:    Lab09_Deudas2022-1
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 21 de junio de 2023, 11:05 PM
 */

#include <iostream>
using namespace std;

#include "Procesa.h"

int main(int argc, char** argv) {
    Procesa pro;
    pro.carga();
    // pro.actualiza();
    pro.muestra();
    return 0;
}

