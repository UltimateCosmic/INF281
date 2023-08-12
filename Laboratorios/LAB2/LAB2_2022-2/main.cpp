/* 
 * Proyecto:    LAB2_2022-2
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 20 de abril de 2023, 02:08 PM
 */

#include <iostream>
using namespace std;

#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    crearBinarios("Pacientes.bin", "Medicina.bin");    
    separarInformacion("Medico-Paciente-Medicinas.txt", "Medicos.txt", 
            "Pacientes.bin", "Consultas.txt", "Medicina.bin");       
    imprimirReporteDeVerificacion("Medicos.txt", "Pacientes.bin", 
            "Consultas.txt", "Medicina.bin", "ReporteDeVerificacion.txt");
    modificarPacientes("Consultas.txt", "Medicina.bin", "Pacientes.bin");
    imprimirReporteDeVerificacion("Medicos.txt", "Pacientes.bin", 
            "Consultas.txt", "Medicina.bin", "ReporteDeEmpresa.txt");
    return 0;
}
