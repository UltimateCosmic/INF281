/* 
 * Proyecto:    LAB05_PuntMultiples
 * Archivo:     main.cpp
 * Autor:       Cosmo
 * Codigo:      20203350
 *
 * Creado el 9 de mayo de 2023, 11:57 PM
 */

#include <iostream>
using namespace std;

#include "BibManejoDinamicoDeMemoria.h"

int main(int argc, char** argv) {
    char **conductor, ***placa;
    int *licencia, **falta;
    double **multa;    
    cargarConductores(licencia, conductor);
    reporteConductores(licencia, conductor);   
    cargarFaltas(licencia, placa, falta);
    reporteFaltas(licencia, conductor, placa, falta);
    resumenMultas(licencia, falta, multa);
    reporteMultas(licencia, conductor, multa);
    return 0;
}

