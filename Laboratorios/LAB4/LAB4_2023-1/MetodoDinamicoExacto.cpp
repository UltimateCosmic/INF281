#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "MetodoDinamicoExacto.h"
#define MAX_LINEA 100

void lecturaAlumnos(const char *nombArch, int *&alumno_Codigo, 
        char **&alumno_Nombre, char *&alumno_Modalidad, int *&alumno_Porcentaje, 
        int *&alumno_Escala) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    leerAlumnos(arch, alumno_Codigo, alumno_Nombre, alumno_Modalidad, 
            alumno_Porcentaje, alumno_Escala);
}

void leerAlumnos(ifstream &arch, int *&alumno_Codigo, char **&alumno_Nombre, 
        char *&alumno_Modalidad, int *&alumno_Porcentaje, int *&alumno_Escala) {
    int buffCodigo[100], buffPorcentaje[100], buffEscala[100], numDat=0;
    char buffModalidad[100], *buffNombre[100];   
    while (true) {
        arch>>buffCodigo[numDat];
        if (arch.eof()) break;
        arch.get(); // coma
        buffNombre[numDat] = leerCadena(arch, ',');
        buffModalidad[numDat] = arch.get();
        if (buffModalidad[numDat]!='V' && buffModalidad[numDat]!='S') {
            buffModalidad[numDat]='S';
            buffPorcentaje[numDat]=0;
            arch.unget();
        } else if (buffModalidad[numDat]=='V') {
            arch.get();
            buffPorcentaje[numDat]=0;
        } else{
            arch.get();
            arch>>buffPorcentaje[numDat];
            arch.get();
        }
        arch>>buffEscala[numDat];
        numDat++;
    }
    leerAlumnosExactos(alumno_Codigo, alumno_Nombre, alumno_Modalidad, 
            alumno_Porcentaje, alumno_Escala, buffCodigo, buffNombre, 
            buffModalidad, buffPorcentaje, buffEscala, numDat);
}

char *leerCadena(ifstream &arch) {
    char cadena[60], *cad;
    arch.getline(cadena, 60);
    cad = new char[strlen(cadena)+1];
    strcpy(cad, cadena);
    return cad;
}

char *leerCadena(ifstream &arch, char delim) {
    char cadena[60], *cad;
    arch.getline(cadena, 60, delim);
    cad = new char[strlen(cadena)+1];
    strcpy(cad, cadena);
    return cad;
}

void leerAlumnosExactos(int *&alumno_Codigo, char **&alumno_Nombre, 
        char *&alumno_Modalidad, int *&alumno_Porcentaje, int *&alumno_Escala, 
        int *buffCodigo, char **buffNombre, char *buffModalidad, 
        int *buffPorcentaje, int *buffEscala, int numDat) {
    alumno_Codigo = new int[numDat+1];
    alumno_Nombre = new char*[numDat+1];
    alumno_Porcentaje = new int[numDat+1];
    alumno_Escala = new int[numDat+1];
    alumno_Modalidad = new char[numDat+1];
    for (int i=0; i<numDat; i++) {
        alumno_Codigo[i]=buffCodigo[i];
        alumno_Nombre[i]=buffNombre[i];
        alumno_Porcentaje[i]=buffPorcentaje[i];
        alumno_Escala[i]=buffPorcentaje[i];
        alumno_Modalidad[i]=buffModalidad[i];
    }    
    alumno_Codigo[numDat]=0;
    alumno_Nombre[numDat]=nullptr;
    alumno_Porcentaje[numDat]=0;
    alumno_Escala[numDat]=0;
    alumno_Modalidad[numDat]=0;
}

void pruebaLecturaAlumnos(const char *nombArch, int *alumno_Codigo, 
        char **alumno_Nombre, char *alumno_Modalidad, int *alumno_Porcentaje, 
        int *alumno_Escala) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    imprimirReporteDeAlumnos(arch, alumno_Codigo, alumno_Nombre, 
            alumno_Modalidad, alumno_Porcentaje, alumno_Escala);
}

void imprimirReporteDeAlumnos(ofstream &arch, int *alumno_Codigo, 
        char **alumno_Nombre, char *alumno_Modalidad, int *alumno_Porcentaje, 
        int *alumno_Escala) {
    arch<<"Codigo"<<setw(10)<<"Modalidad"<<setw(10)<<"Porcentaje"<<setw(10)
            <<"Escala"<<setw(10)<<"Nombre"<<endl;
    for (int i=0; alumno_Codigo[i]; i++) {
        arch<<left<<setw(10)<<alumno_Codigo[i]<<setw(5)<<alumno_Modalidad[i]
                <<setw(5)<<alumno_Porcentaje[i]<<setw(5)<<alumno_Escala[i]
                <<alumno_Nombre[i]<<endl;
    }
}

void lecturaCursos(const char *nombArch, int *alumno_Codigo, int *alumno_Escala, 
        char **&curso_Nombre, double *&curso_Credito, int **&curso_Alumnos) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    leerCursos(arch, alumno_Codigo, alumno_Escala, curso_Nombre, curso_Credito, 
            curso_Alumnos);
}

void leerCursos(ifstream &arch, int *alumno_Codigo, int *alumno_Escala, 
        char **&curso_Nombre, double *&curso_Credito, int **&curso_Alumnos) {
    int buffAlumnos[100][50]{0}, numDat=0, codAlumno, pos;
    char *buffNombre[100];
    double buffCredito[100];
    while (true) {
        arch>>codAlumno;
        if (arch.eof()) break;
        arch.get();
        buffNombre[numDat]=leerCadena(arch, ',');
        arch>>buffCredito[numDat];
        pos=buscarCurso(buffNombre, numDat);        
        if (pos==numDat)
            numDat++;   
        agregarAlumno(codAlumno, alumno_Codigo, alumno_Escala, buffAlumnos, pos);
    }
    leerCursosExactos(curso_Nombre, curso_Credito, curso_Alumnos, buffNombre, 
            buffCredito, buffAlumnos, numDat);
}

int buscarCurso(char **buffNombre, int numDat) {
    for (int i=0; i<numDat; i++)
        if (buffNombre[i]==buffNombre[numDat])
            return i;
    return numDat;
}

void agregarAlumno(int codAlumno, int *alumno_Codigo, int *alumno_Escala, 
        int buffAlumnos[100][50], int pos) {
    int posA=-1;
    for (int i=0; alumno_Codigo[i]; i++)
        if (alumno_Codigo[i]==codAlumno) posA=i;
    if (posA==-1) return;
    for (int i=0; i<50; i++)
        if (buffAlumnos[pos][i]==0) {
            buffAlumnos[pos][i] = alumno_Codigo[posA];
            buffAlumnos[pos][i+1] = alumno_Escala[posA];
        }
}

void leerCursosExactos(char **&curso_Nombre, double *&curso_Credito, 
        int **&curso_Alumnos, char **buffNombre, double *buffCredito, 
        int buffAlumnos[100][50], int numDat) {
    curso_Nombre = new char*[numDat+1];
    curso_Alumnos = new int*[numDat+1];
    curso_Credito = new double[numDat+1];
    int numAlumnos;
    for (int i=0; i<numDat; i++) {
        curso_Nombre[i]=buffNombre[i];
        numAlumnos=0;
        while (buffAlumnos[i][numAlumnos]) numAlumnos++;        
        curso_Alumnos[i]=new int[numAlumnos+1];
        for (int j=0; j<numAlumnos; j++)
            curso_Alumnos[i][j]=buffAlumnos[i][j];
        curso_Alumnos[i][numAlumnos]=0;
        curso_Credito[i]=buffCredito[i];
    }    
    curso_Nombre[numDat]=nullptr;
    curso_Alumnos[numDat]=nullptr;
    curso_Credito[numDat]=0;
}

void pruebaDeLecturaCursos(const char *nombArch, char **&curso_Nombre, 
        double *&curso_Credito, int **&curso_Alumnos) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    imprimirReporteDeCursos(arch, curso_Nombre, curso_Credito, curso_Alumnos);    
}

void imprimirReporteDeCursos(ofstream &arch, char **curso_Nombre, 
        double *curso_Credito, int **curso_Alumnos) {
    arch.precision(2);
    arch<<fixed;
    arch<<"Nombre"<<setw(5)<<"Credito"<<endl;
    for (int i=0; curso_Nombre[i]; i++)
        arch<<left<<setw(60)<<curso_Nombre[i]<<curso_Credito[i]<<endl;
}

void reporteDeRecaudacionPorModalidad(const char *nombArch, int *alumno_Codigo, 
        char *alumno_Modalidad, int *alumno_Porcentaje, char **alumno_Nombre,
        char **curso_Nombre, double *curso_Credito, int **curso_Alumnos) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }    
    imprimirCabeceraPrincipal(arch);
    for (int i=0; curso_Nombre[i]; i++)
        imprimirCabeceraCurso(arch, curso_Nombre, curso_Credito, i);
}

void imprimirCabeceraPrincipal(ofstream &arch) {
    arch<<setw(50)<<"ENTIDAD EDUCATIVA LP1"<<endl;
    arch<<setw(53)<<"LISTADOS DE CLASE"<<endl;
}

void imprimirCabeceraCurso(ofstream &arch, char **curso_Nombre, 
        double *curso_Credito, int i) {
    imprimirLinea(arch, '=', MAX_LINEA);
    arch.precision(2);
    arch<<fixed;
    arch.fill('0');
    arch<<right<<setw(2)<<i<<")";
    arch.fill(' ');
    arch<<right<<setw(5)<<" "<<left<<setw(20)<<"Curso:"<<setw(40)<<curso_Nombre[i]
            <<setw(8)<<"Creditos:"<<curso_Credito[i]<<endl;
}

void imprimirLinea(ofstream &arch, char c, int n) {
    for (int i=0; i<n; i++) arch.put(c);
    arch.put('\n');
}