#include <iostream>
#include <fstream>
using namespace std;

#include "FuncionesAuxiliares.h"

void completarCampos(const char *nombArchClases, const char *nombArchCursos,
        const char *nombArchAlumnos, const char *nombArchEscalas) {  
    ifstream archCursos(nombArchCursos, ios::in|ios::binary);
    if (not archCursos.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchCursos<<endl;
        exit(1);
    }
    ifstream archAlumnos(nombArchAlumnos, ios::in|ios::binary);
    if (not archAlumnos.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchAlumnos<<endl;
        exit(1);
    }
    ofstream archClases(nombArchClases, ios::out|ios::binary);
    if (not archClases.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchClases<<endl;
        exit(1);
    }
    ifstream archEscalas(nombArchEscalas, ios::in|ios::binary);
    if (not archEscalas.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchEscalas<<endl;
        exit(1);
    }
    determinarCostoDelCilo(archCursos, archAlumnos, archClases, archEscalas);
}

void determinarCostoDelCilo(ifstream &archCursos, ifstream &archAlumnos, 
        fstream &archClases, ifstream &archEscalas) {
    
    
    
    
}