/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Facultad.cpp
 * Author: alulab14
 * 
 * Created on 11 de julio de 2023, 08:28 AM
 */

#include <fstream>

#include "Facultad.h"
#include "AperturaDeArchivos.h"

void Facultad::leerAlumnosNotas (const char *nombArchNotas, const char *nombArchAlumnos) {    
    ifstream archAlumnos;
    AperturaDeUnArchivoDeTextosParaLeer(archAlumnos, nombArchAlumnos);
    ifstream archNotas;
    AperturaDeUnArchivoDeTextosParaLeer(archNotas, nombArchNotas);
    leerAlumnos(archAlumnos);
    leerNotas(archNotas);
}

void Facultad::leerAlumnos (ifstream &arch) {    
    while (true) {
        alumnosxNotas.insertarNodo(arch);        
        if (arch.eof()) break;
    }
}

void Facultad::leerNotas (ifstream &arch) {    
    int semestre, codigo;            
    class Nota notaAlumno;
    char c;
    while (true) {
        arch>>semestre;
        if (arch.eof()) return;
        arch.get();    
        arch>>codigo;
        arch.get();
        class Nota notaAlumno;
        while (true) {          
            arch>>notaAlumno;
            notaAlumno.SetCiclo(semestre);        
            alumnosxNotas.insertarNota(notaAlumno, codigo);        
            arch>>c;
            if (c!=',') break;
            if (arch.eof()) break;
        }
    }
}

void Facultad::imprimeAlumnosNotas (const char *nombArchReporte) {    
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte, nombArchReporte);
    alumnosxNotas.imprimeLista(archReporte);
}

void Facultad::actualizaNotas() {    
    alumnosxNotas.actualizarNotasAlumnos();
}
