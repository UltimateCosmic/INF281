#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "OperadoresSobrecargados.h"
#include "Estructuras.h"

// Lectura:
bool operator >>(ifstream &arch, struct StCurso &curso) {
    arch>>curso.codigoDelCurso;
    if (arch.eof()) return false;
    arch>>curso.nombreDelCurso>>curso.creditos>>curso.codigoDelProfesor
            >>curso.nombreDelProfesor;
    curso.numeroDeAlumnos=curso.ingresos=0;
    return true;
}

bool operator >>(ifstream &arch, struct StAlumno &alumno) {
    arch>>alumno.semestre;
    if (arch.eof()) return false;
    arch.get();
    arch>>alumno.codigo>>alumno.nombre;
    leerModalidad(arch, alumno.modalidad, alumno.porcentaje);
    arch>>ws;
    arch.get();
    arch>>alumno.escala;    
    alumno.numeroDeCursos=alumno.costoTotal=0;
    return true;
}

void leerModalidad(ifstream &arch, char modalidad[], int &porcentaje) {
    arch>>ws;
    char c = arch.get();
    if (c=='V') {
        strcpy(modalidad, "VIRTUAL");
        porcentaje=0;
    } else if (c=='S') {
        strcpy(modalidad, "SEMIPRESENCIAL");
        arch>>porcentaje;
    } else {
        arch.unget();
        strcpy(modalidad, "PRESENCIAL");   
        porcentaje=0;
    }
}

bool operator >>(ifstream &arch, struct StRegistroDeMatricula &registroMat) {
    arch>>registroMat.codigoDelCurso;
    if (arch.eof()) return false;
    arch>>registroMat.semestreDelAlumno;
    arch.get();
    arch>>registroMat.codigodelAlumno;    
    return true;
}

// Agregación:
void operator +=(struct StCurso arregloCursos[], struct StCurso curso) {
    int i;
    for (i=0; strcmp(arregloCursos[i].codigoDelCurso, "XXXXXX")!=0; i++);
    arregloCursos[i]=curso;
    strcpy(arregloCursos[i+1].codigoDelCurso, "XXXXXX");
}

void operator +=(struct StAlumno arregloAlumnos[], struct StAlumno alumno) {
    int i;
    for (i=0; arregloAlumnos[i].semestre; i++);
    arregloAlumnos[i]=alumno;
    arregloAlumnos[i+1].semestre=0;
}

void operator *=(struct StCurso arregloCursos[], 
        struct StRegistroDeMatricula registroMat) {
    for (int i=0; strcmp(arregloCursos[i].codigoDelCurso, "XXXXXX")!=0; i++) 
        if (strcmp(arregloCursos[i].codigoDelCurso, registroMat.codigoDelCurso)==0) {
            arregloCursos[i].alumnos[arregloCursos[i].numeroDeAlumnos]
                    =registroMat.semestreDelAlumno*10000+registroMat.codigodelAlumno;
            arregloCursos[i].numeroDeAlumnos++;
            break;
        }    
}

void operator *=(struct StAlumno arregloAlumnos[], 
        struct StRegistroDeMatricula registroMat) {
    for (int i=0; arregloAlumnos[i].semestre; i++) 
        if (arregloAlumnos[i].codigo==registroMat.codigodelAlumno) {
            strcpy(arregloAlumnos[i].cursos[arregloAlumnos[i].numeroDeCursos],
                    registroMat.codigoDelCurso);
            arregloAlumnos[i].numeroDeCursos++;
            break;
        }    
}

// Impresión 1:
void operator <<(ofstream &arch, struct StCurso curso) {    
    arch<<right<<"CODIGO"<<setw(13)<<"NOMBRE"<<setw(23)<<"CREDITOS"<<endl;
    arch<<left<<setw(12)<<curso.codigoDelCurso<<setw(24)<<curso.nombreDelCurso
            <<curso.creditos<<endl;
    arch<<"Alumnos matriculados:"<<endl;
    arch<<setw(12)<<"Semestre"<<"Codigo"<<right<<endl;
    int codigo, semestre;
    for (int i=0; i<curso.numeroDeAlumnos; i++) {
        separarCodigoYSemestre(codigo, semestre, curso.alumnos[i]);
        arch<<right<<setw(7)<<semestre<<setw(9)<<codigo<<endl;                
    }
    arch<<"Numero de alumnos: "<<curso.numeroDeAlumnos<<endl;
    arch<<"Total ingresado: "<<curso.ingresos<<endl;
}

void separarCodigoYSemestre(int &codigo, int &semestre, int alumno) {
    semestre = alumno/10000;
    codigo = alumno-semestre*10000;
}

// Impresión 2:
void operator <<(ofstream &arch, struct StAlumno alumno) {
    arch<<right<<"SEMESTRE"<<setw(13)<<"CODIGO"<<setw(15)<<"NOMBRE"<<setw(25)
            <<"MODALIDAD"<<setw(20)<<"ESCALA"<<endl;
    arch<<left<<setw(15)<<alumno.semestre<<setw(15)<<alumno.codigo<<setw(45)
            <<alumno.nombre<<setw(20)<<alumno.modalidad<<"CON "<<right<<setw(2)
            <<alumno.porcentaje<<"%"<<setw(6)<<alumno.escala<<endl;
    arch<<"Codigo de cursos matriculados:"<<endl;
    for (int i=0; i<alumno.numeroDeCursos; i++)
        arch<<setw(10)<<alumno.cursos[i]<<endl;
    arch<<"Numero de cursos: "<<alumno.numeroDeCursos<<endl;
    arch<<"Costo total: "<<alumno.costoTotal<<endl;
}
