/* 
 * Proyecto:    MetodoPorIncrementos-2022-2
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 * Codigo:      20203350
 *
 * Creado el 11 de mayo de 2023, 08:57 PM
 */

#include <iostream>
using namespace std;

#include "MetodoPorIncrementos.h"

int main(int argc, char** argv) {
    char ***medicoDatos, ****citaPaciente;
    int **citaCantidad;
    double *medicoTarifaHora, ***citaTiempoYPago;
    cargarCitas("Citas.csv", medicoDatos, medicoTarifaHora, citaPaciente, 
            citaCantidad, citaTiempoYPago);
    return 0;
}

