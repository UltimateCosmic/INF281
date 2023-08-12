/* 
 * File:   main.cpp
 * Alumno: Johan Carlo Amador Egoavil
 * Código: 20203350
 *
 * Created on 16 de junio de 2023, 09:27 AM
 */

#include <iostream>
using namespace std;

#include "Tesoreria.h"

int main(int argc, char** argv) {
    Tesoreria caja;
    caja.cargaescalas();
    caja.cargaalumnos();
    caja.actualiza(20);
    caja.imprime();
    return 0;
}

