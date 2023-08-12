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
#include <cstring>
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

void AlumnoNotas::actualizarDato() {
    actualizar();
    totalizar();
}

void AlumnoNotas::actualizar() {
    char cad[10];
    for (int i=0; i<notas.size(); i++) {
        notas[i].GetCodigo_curso(cad);
        borrarNotaRepetida(cad, i);
    }
}

void AlumnoNotas::borrarNotaRepetida(const char *cad, int j) {
    int postIni, cantCur=0, flag;
    char cad2[10];
    for (i=j+1; i<notas.size(); i++) {
        notas[i].GetCodigo_curso(cad2);
        if (strcmp(cad, cad2)==0) {
            if (flag==0) postIni = i;
            flag = 1;
            cantCur++;
        }
        notas.erase(notas.begin()+postIni, notas.begin()+postIni+cantCur);
    }
}

void AlumnoNotas::totalizar() {
    int prom;
    for (int i=0; notas.size(); i++)
        prom += notas[i].GetCalificacion();
    prom /= notas.size();
    alumno.SetPromedio(prom);
}


