/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 2 de mayo de 2023, 04:19 PM
 */

#include <iostream>
using namespace std;

#include "BibliotecaMemoriaDinamica.h"

int main(int argc, char** argv) {
    char **conductor,*gravedad;
    int *licencia, *infraccion;
    double *multa;
    cargarConductores(licencia, conductor);
    reporteConductores(licencia, conductor);
    cargarInfracciones(infraccion, gravedad, multa);
    reporteInfracciones(infraccion, gravedad, multa);
    reporteDeFaltas(licencia, conductor, infraccion, gravedad, multa);
    return 0;
}

