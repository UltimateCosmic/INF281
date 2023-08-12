/* 
 * Proyecto:    LAB2_2021-1
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 17 de abril de 2023, 08:52 PM
 */

#include <iostream>
using namespace std;

#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    // Primer punto:
    crearPrimerosBinarios("Infracciones-Conductores.txt", "Conductores.bin",
            "FaltasCometidas.bin");
    crearReporteDeVerificacion("ReporteDeVerificacion.txt", "Conductores.bin", 
            "FaltasCometidas.bin");    
    // Segundo punto:
    crearArchInfracciones("Infracciones.txt", "ListadoDeInfracciones.bin");
    crearReporteDeInfracciones("ReporteDeInfracciones.txt", 
            "ListadoDeInfracciones.bin");
    // Tercer punto:    
    completarBinarios("Conductores.bin", "FaltasCometidas.bin", 
            "ListadoDeInfracciones.bin");
    crearReporteDeVerificacion("ReporteDeVerificacion2.txt", "Conductores.bin", 
            "FaltasCometidas.bin");    
    return 0;
}

