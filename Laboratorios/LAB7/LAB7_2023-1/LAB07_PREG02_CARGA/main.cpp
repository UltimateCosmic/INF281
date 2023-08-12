/* 
 * File:   main.cpp
 * Alumno: Johan Carlo Amador Egoavil
 * Código: 20203350
 *
 * Created on 9 de junio de 2023, 09:15 AM
 */

#include <iostream>
using namespace std;

#include "Funciones.h"
#include "alumno.h"
#include "alumnonota.h"

int main(int argc, char** argv) {

    alumno lalumnos[100];
    alumnonota lnotas[200];
    
    cargaralumnos(lalumnos);
    cargarnotas(lnotas);
    actualizarnotas(lalumnos, lnotas);
    imprimealumnos(lalumnos);

    return 0;
}

