/* 
 * Proyecto:    AplicacionConBibEstatica
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 28 de abril de 2023, 12:25 AM
 */

#include <iostream>
using namespace std;

#include "FuncionesAuxiliares.h"
#include "Estructuras.h"

int main(int argc, char** argv) {

    int numMedicos=0, numPacientes=0;
    struct StMedico medico[100];
    struct StPaciente paciente[100];
    /* a) */ leerMedicos(medico, numMedicos, "MedicosLab3.txt");
    /* b) */ leerPacientes(paciente, numPacientes, "PacientesLab3.txt");
    /* c) */ leerCitas(medico, numMedicos, paciente, numPacientes, "ConsultasLab3.txt");
    /* d) */ emitirReporte(paciente, numPacientes, "ReporteDePacientes.txt");
    
    return 0;
}

