/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlumnoNotas.cpp
 * Author: alulab14
 * 
 * Created on 11 de julio de 2023, 08:27 AM
 */

#include <iostream>
#include <vector>
#include <fstream>
#include "AlumnoNotas.h"

AlumnoNotas::AlumnoNotas() {
}

AlumnoNotas::AlumnoNotas(const AlumnoNotas& orig) {
}

AlumnoNotas::~AlumnoNotas() {
}

void AlumnoNotas::leerDato(ifstream &arch) {
    arch>>alumno;
}

int AlumnoNotas::obtenerCodigo() {
    return alumno.GetCodigo_alumno();
}

void AlumnoNotas::insertarNota(class Nota &notaAlumno) {
    notas.push_back(notaAlumno);
    //notas.shrink_to_fit();
}

void AlumnoNotas::imprimirAlumno(ofstream &arch) {
    alumno.imprimeAlumno(arch);
    for (int i=0; i<notas.size(); i++) {
        notas[i].imprimeNota(arch); 
    }
}

