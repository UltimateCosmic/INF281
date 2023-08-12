/* 
 * File:   main.cpp
 * Alumno: Johan Carlo Amador Egoavil
 * Código: 20203350
 *
 * Created on 30 de junio de 2023, 09:17 AM
 */

#include <iostream>
using namespace std;

#include "Tesoreria.h"

int main(int argc, char** argv) {
    Tesoreria ABoleta;
    
    ABoleta.cargaalumnos();
    ABoleta.actualizaboleta();
    ABoleta.imprimeboleta();
        
    return 0;
}

