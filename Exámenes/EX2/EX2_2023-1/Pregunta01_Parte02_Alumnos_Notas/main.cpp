/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Alumno: Johan Carlo Amador Egoavil
 * Código: 20203350
 *
 * Created on 11 de julio de 2023, 08:03 AM
 */

#include <iostream>
using namespace std;

#include "Facultad.h"

int main(int argc, char** argv) {
    class Facultad facultad;
    
    facultad.leerAlumnosNotas("Notas-Preg01.csv", "Alumnos-Preg01.csv");
    facultad.imprimeAlumnosNotas("PruebaAlumnosNotas.txt");
    facultad.actualizaNotas();
    facultad.imprimeAlumnosNotas("PruebaNotasActualizadas.txt");
    
    return 0;
}

