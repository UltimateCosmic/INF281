#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#include "AperturaDeArchivos.h"
#define CAD 60
#define INCREMENTO 5

void cargarCursosYEscalas(char ***&cursos, double *&cursos_cred, double *escalas, 
        const char *nombArchCursos, const char *nombArchEscalas) {
    ifstream archCursos;
    AperturaDeUnArchivoDeTextosParaLeer(archCursos, nombArchCursos);
    cursos = nullptr;
    cursos_cred = nullptr;
    cargarCursos(archCursos, cursos, cursos_cred);
    ifstream archEscalas;
    AperturaDeUnArchivoDeTextosParaLeer(archEscalas, nombArchEscalas);
    cargarEscalas(archEscalas, escalas);            
}

void cargarCursos(ifstream &arch, char ***&cursos, double *&cursos_cred) {
    int nd=0, cap=0, auxC;
    char *codigo, *nombre, *profesor;
    double creditos;
    while (true) {
        codigo = leerCadena(arch, ',');
        if (arch.eof()) break;
        nombre = leerCadena(arch, ',');
        arch>>creditos;
        arch.get();
        arch>>auxC;
        arch.get();
        profesor = leerCadena(arch, '\n');
        if (nd==cap)
            aumentarEspacios(cursos, cursos_cred, nd, cap);
        cargarCurso(cursos[nd-1], cursos_cred[nd-1], codigo, nombre, profesor, 
                creditos);
        nd++;
    }
}

char *leerCadena(ifstream &arch, char delim='\n') {
    char buff[CAD], *cad;
    arch.getline(buff, CAD, delim);
    cad = new char[strlen(buff)+1];
    strcpy(cad, buff);
    return cad;
}

void aumentarEspacios(char ***&cursos, double *&cursos_cred, int &nd, int &cap) {
    char ***auxCur;
    double *auxCred;
    cap += INCREMENTO;
    if (cursos==nullptr) {
        cursos = new char**[cap]{};
        cursos_cred = new double[cap]{};
        nd=1;
    } else {
        auxCur = new char**[cap]{};
        auxCred = new double[cap]{};
        for (int i=0; i<nd; i++) {
            auxCur[i] = cursos[i];
            auxCred[i] = cursos_cred[i];
        }
        delete cursos;
        delete cursos_cred;
        cursos = auxCur;
        cursos_cred = auxCred;
    }
}

void cargarCurso(char **&curso, double &creditos, char *codigo, char *nombre, 
        char *profesor, double cred) {
    curso = new char*[3];   
    curso[0] = codigo;
    curso[1] = nombre;
    curso[2] = profesor; 
    creditos = cred;
}

void cargarEscalas(ifstream &arch, double *escalas) {
    for (int i=0; i<5; i++) {
        leerCadena(arch, ',');
        if (arch.eof()) break;
        arch>>escalas[i];
    }    
}

void pruebaDeCargaDeCursos(char ***cursos, double *cursos_cred, double *escalas, 
        const char *nombArchReporte) {
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte, nombArchReporte);    
    imprimirEncabezadoCursos(archReporte);
    for (int i=0; cursos[i]; i++)
        imprimirCurso(archReporte, cursos[i], cursos_cred[i]);
}

void imprimirEncabezadoCursos(ofstream &arch) {
    arch<<"Codigo"<<setw(10)<<"Nombre"<<setw(62)<<"Profesor"<<setw(50)
            <<"Creditos"<<endl;    
}

void imprimirCurso(ofstream &arch, char **curso, double creditos) {
    arch<<left<<setw(10)<<curso[0]<<setw(60)<<curso[1]<<setw(50)<<curso[2]
            <<creditos<<endl;
}

void cargarAlumnos(int *&alumnos_cod, int **&alumnos, char ***&alumnos_nom_mod, 
        const char *nombArch) {
    ifstream archAlumnos;
    AperturaDeUnArchivoDeTextosParaLeer(archAlumnos, nombArch);
    alumnos_cod = nullptr;
    alumnos = nullptr;
    alumnos_nom_mod = nullptr;
    leerAlumnos(archAlumnos, alumnos_cod, alumnos, alumnos_nom_mod);
}

void leerAlumnos(ifstream &arch, int *&alumnos_cod, int **&alumnos, 
        char ***&alumnos_nom_mod) {
    int codigo, escala, nd=0, cap=0;
    char *nombre, modalidad;
    int porcentaje;
    while (true) {
        arch>>codigo;
        if (arch.eof()) break;
        arch.get();
        nombre = leerCadena(arch, ',');
        modalidad = leerModalidad(arch, porcentaje);
        arch.get();
        arch>>escala;
        if (nd==cap)
            aumentarEspacios(alumnos_cod, alumnos, alumnos_nom_mod, nd, cap);
        cargarAlumno(alumnos_cod[nd-1], alumnos[nd-1], alumnos_nom_mod[nd-1], 
                codigo, nombre, modalidad, escala, porcentaje);
        nd++;
    }    
}

void aumentarEspacios(int *&alumnos_cod, int **&alumnos, char ***&alumnos_nom_mod, 
        int &nd, int &cap) {
    int *auxC, **auxA;
    char ***auxNM;
    cap += INCREMENTO;
    if (alumnos_cod==nullptr) {
        alumnos_cod = new int[cap]{};        
        alumnos = new int*[cap]{};        
        alumnos_nom_mod = new char**[cap]{};
        nd=1;
    } else {
        auxC = new int[cap]{};        
        auxA = new int*[cap]{};        
        auxNM = new char**[cap]{};
        for (int i=0; i<nd; i++) {
            auxC[i] = alumnos_cod[i];
            auxA[i] = alumnos[i];
            auxNM[i] = alumnos_nom_mod[i];            
        }
        delete alumnos_cod;
        delete alumnos;
        delete alumnos_nom_mod;
        alumnos_cod = auxC;
        alumnos = auxA;
        alumnos_nom_mod = auxNM;
    }    
}

char leerModalidad(ifstream &arch, int &porcentaje) {
    porcentaje=0;
    char c = arch.get();
    if (c=='S') {
        arch.get();
        arch>>porcentaje;
        arch.get();
    } else if (c=='V')
        arch.get();
    else {
        arch.unget();
        c = 'P';
    }
    return c;
}

void cargarAlumno(int &alumnos_cod, int *&alumnos, char **&alumnos_nom_mod,
        int codigo, char *nombre, char modalidad, int escala, int porcentaje) {
    alumnos_cod = codigo;
    alumnos = new int[3];
    alumnos[0] = codigo;
    alumnos[1] = escala;
    alumnos[2] = porcentaje;
    alumnos_nom_mod = new char*[2];
    alumnos_nom_mod[0] = nombre;
    alumnos_nom_mod[1] = new char;
    *alumnos_nom_mod[1] = modalidad;
}

void pruebaDeCargaDeAlumnos(int *alumnos_cod, int **alumnos, 
        char ***alumnos_nom_mod, const char *nombArch) {
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte, nombArch);
    imprimirCabeceraAlumnos(archReporte);
    for (int i=0; alumnos_cod[i]; i++) 
        imprimirAlumno(archReporte, alumnos_cod[i], alumnos[i], 
                alumnos_nom_mod[i]);         
}

void imprimirCabeceraAlumnos(ofstream &arch) {
    arch<<"Codigo"<<setw(12)<<"Codigo"<<setw(10)<<"Escala"<<setw(11)
            <<"Porcentaje"<<setw(10)<<"Nombre"<<setw(40)<<"Modalidad"<<endl;
}

void imprimirAlumno(ofstream &arch, int alumnos_cod, int *alumnos, 
        char **alumnos_nom_mod) {    
    arch<<left<<setw(12)<<alumnos_cod<<setw(12)<<alumnos[0]<<setw(5)
            <<alumnos[1]<<setw(14)<<alumnos[2]<<setw(40)<<alumnos_nom_mod[0]
            <<alumnos_nom_mod[1]<<endl;
}
