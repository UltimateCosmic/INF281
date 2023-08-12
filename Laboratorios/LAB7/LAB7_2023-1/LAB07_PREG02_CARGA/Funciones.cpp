#include <iostream>
#include <fstream>
using namespace std;

#include "Funciones.h"
#include "alumno.h"
#include "alumnonota.h"

void cargaralumnos(class alumno *lalumnos) {
    ifstream archAlumnos("Alumnos.csv", ios::in);
    if (not archAlumnos.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo Alumnos.csv"<<endl;
        exit(1);
    }
    int numAlumnos=0;
    while (true) {
        archAlumnos>>lalumnos[numAlumnos];
        if (archAlumnos.eof()) break;
        numAlumnos++;
    }    
    lalumnos[numAlumnos].SetCodigo(0);
}

void cargarnotas(class alumnonota *lnotas) {
    ifstream archNotas("Notas.csv", ios::in);
    if (not archNotas.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo Notas.csv"<<endl;
        exit(1);
    }    
    int numAlumnota=0;
    while (true) {
        archNotas>>lnotas[numAlumnota];
        if (archNotas.eof()) break;
        numAlumnota++;
    }
    lnotas[numAlumnota].SetCodigo(0);
}

void actualizarnotas(class alumno *lalumnos, class alumnonota *lnotas) {
    class Nota nota;
    int pos, numDat=0, cantVeces;
    char curso[7];
    while (lalumnos[numDat].GetCodigo()) numDat++;
    for (int i=0; i<numDat; i++) {
        pos = buscarPos(lnotas[i].GetCodigo(), lalumnos);
        lnotas[i]&nota;
        if (pos!=-1) {
            lalumnos[i] += nota;
            nota.GetCodcurso(curso);
            cantVeces = calcularCantVeces(curso, lalumnos[i]);     
            if (cantVeces==0)
                lalumnos[i].SetNumprimera(cantVeces+1);
            if (cantVeces==1)
                lalumnos[i].SetNumsegunda(cantVeces+1);
            if (cantVeces==2)
                lalumnos[i].SetNumtercera(cantVeces+1);
        }
    }
}

int buscarPos(int codigo, class alumno *lalumnos) {    
    for (int i=0; lalumnos[i].GetCodigo()!=0; i++)
        if (lalumnos[i].GetCodigo()==codigo)
            return i;
    return -1;
}

int calcularCantVeces(char *curso, class alumno lalumnos) {
    int cantVeces=0;    
    /*for (int i=0; i<lalumnos.GetNumcursos(); i++) {
        //lalumnos.GetNota(i);
    }   */ 
    return cantVeces;
}

void imprimealumnos(class alumno *lalumnos) {
    ofstream archReporte("ReporteDeAlumnos.txt", ios::out);
    if (not archReporte.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo ReporteDeAlumnos.txt"<<endl;
        exit(1);
    }
    for (int i=0; lalumnos[i].GetCodigo()!=0; i++) 
        archReporte<<lalumnos[i];
}