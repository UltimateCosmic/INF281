/* 
 * File:   main.cpp
 * Alumno: Johan Carlo Amador Egoavil
 * Codigo: 20203350
 *
 * Created on 16 de mayo de 2023, 08:02 AM
 */

#include <iostream>
using namespace std;

#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {

    char ***cursos, ***alumnos_nom_mod;
    double *cursos_cred, escalas[5];
    int *alumnos_cod, **alumnos;
    
    cargarCursosYEscalas(cursos, cursos_cred, escalas, "Cursos.csv", "Escalas.csv");  
    pruebaDeCargaDeCursos(cursos, cursos_cred, escalas, "PruebaCursos.txt");
    
    cargarAlumnos(alumnos_cod, alumnos, alumnos_nom_mod, "Alumnos.csv");
    pruebaDeCargaDeAlumnos(alumnos_cod, alumnos, alumnos_nom_mod, "PruebaAlumnos.txt");
    
    return 0;
}

