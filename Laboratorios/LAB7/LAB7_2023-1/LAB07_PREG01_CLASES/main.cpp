/* 
 * File:   main.cpp
 * Alumno: Johan Carlo Amador Egoavil
 * Código: 20203350
 *
 * Created on 9 de junio de 2023, 08:00 AM
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "alumno.h"
#include "alumnonota.h"
#include "Nota.h"

int main(int argc, char** argv) {
    
    // Lectura e impresión de alumnos
    ifstream archAlumnos("Alumnos.csv", ios::in);
    if (not archAlumnos.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo Alumnos.csv"<<endl;
        exit(1);
    }    
    ofstream archRep("ReporteDeAlumnos.txt", ios::out);
    if (not archRep.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo ReporteDeAlumnos.txt"<<endl;
        exit(1);
    }    
    class alumno alum;
    while (true) {
        archAlumnos>>alum;
        if (archAlumnos.eof()) break;
        archRep<<alum;
    }
    
    // Lectura e impresión de notas
    ifstream archNotas("Notas.csv", ios::in);
    if (not archNotas.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo Notas.csv"<<endl;
        exit(1);
    }    
    ofstream archRepNotas("ReporteDeNotas.txt", ios::out);
    if (not archRep.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo ReporteDeNotas.txt"<<endl;
        exit(1);
    }    
    ofstream archRepTotalizacion("ReporteDearchRepTotalizacion.txt", ios::out);
    if (not archRepTotalizacion.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo ReporteDearchRepTotalizacion.txt"<<endl;
        exit(1);
    }    
    class alumnonota alumNota;
    class Nota notaAlumno;
    char codcur[7];
    while (true) {
        archNotas>>alumNota;
        if (archNotas.eof()) break;
        alumNota.GetCodcurso(codcur);
        archRepNotas<<alumNota.GetCodigo()<<" - "<<codcur<<" - "
                <<alumNota.GetCiclo()<<" - "<<alumNota.GetNota()<<endl;
        alumNota & notaAlumno;
        archRepTotalizacion<<notaAlumno.GetNota()<<endl;
    }    
    
    // Dato de prueba de totalización
    alum+=notaAlumno;
    archRepTotalizacion<<alum;
    
    return 0;
}

