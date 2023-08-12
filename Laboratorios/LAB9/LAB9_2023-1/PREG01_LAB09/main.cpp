/* 
 * File:   main.cpp
 * Alumno: Johan Carlo Amador Egoavil
 * Código: 20203350
 *
 * Created on 23 de junio de 2023, 07:57 AM
 */

#include <iostream>
using namespace std;

#include "Tesoreria.h"

int main(int argc, char** argv) {    
    Tesoreria OTeso;
    
    OTeso.cargaescalas();
    OTeso.cargaalumnos();
    // OTeso.actualizaboleta();
    OTeso.imprimeboleta();
    
    return 0;
}

