/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 21 de abril de 2023, 08:06 AM
 */

#include <iostream>
using namespace std;

#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    crearBinarios("AlumnosXCursos.txt", "Cursos.bin", "Alumnos.bin", 
            "ListaDeClases.bin", "Escalas.bin");        
    imprimirReporteDeVerificacion("ReporteDeVerificacion.txt", "Cursos.bin", 
            "Alumnos.bin", "ListaDeClases.bin", "Escalas.bin");
    return 0;
}

