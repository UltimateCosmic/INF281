/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 28 de abril de 2023, 09:26 AM
 */

#include <iostream>
using namespace std;

#include "FuncionesAuxiliares.h"
#include "Estructuras.h"

int main(int argc, char** argv) {

    struct StCurso cursos[20];
    struct StAlumno alumnos[100];
    /* a) */ leerCursos(cursos, "Cursos.txt");
    /* b) */ leerAlumnos(alumnos, "Alumnos.txt");
    /* c) */ leerMatricula(cursos, alumnos, "Matricula.txt");
    /* d) */ calcularTotales(alumnos, cursos, "Escalas.txt");
    
    return 0;
}

