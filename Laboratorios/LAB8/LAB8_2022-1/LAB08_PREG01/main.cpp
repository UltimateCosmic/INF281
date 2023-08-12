/* 
 * Proyecto:    LAB08_PREG01
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 16 de junio de 2023, 02:30 AM
 */

#include <iostream>
using namespace std;

#include "Tienda.h"

int main(int argc, char** argv) {

    Tienda tien;
    tien.carga();
    // tien.actualiza(20);
    tien.muestra();
            
    return 0;
}

