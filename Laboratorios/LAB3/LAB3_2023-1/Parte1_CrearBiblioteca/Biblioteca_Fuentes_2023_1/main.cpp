/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 28 de abril de 2023, 08:01 AM
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "OperadoresSobrecargados.h"
#include "AperturaDeArchivos.h"
#include "Estructuras.h"

int main(int argc, char** argv) {

    ifstream archCursos, archAlumnos, archMatricula;
    
    // Lectura 1:
    struct StCurso curso;
    AperturaDeUnArchivoDeTextosParaLeer(archCursos, "Cursos.txt");
    archCursos>>curso;
   /* cout<<curso.codigoDelCurso<<endl<<curso.nombreDelCurso<<endl
            <<curso.creditos<<endl<<curso.codigoDelProfesor<<endl
            <<curso.nombreDelProfesor<<endl<<endl; */
    
    // Lectura 2:
    struct StAlumno alumno;
    AperturaDeUnArchivoDeTextosParaLeer(archAlumnos, "Alumnos.txt");
    archAlumnos>>alumno;
    /* cout<<alumno.semestre<<endl<<alumno.codigo<<endl<<alumno.nombre<<endl
            <<alumno.modalidad<<endl<<alumno.escala<<endl
            <<alumno.numeroDeCursos<<endl<<alumno.costoTotal<<endl<<endl; */
    
    // Lectura 3:
    struct StRegistroDeMatricula registroMat;
    AperturaDeUnArchivoDeTextosParaLeer(archMatricula, "Matricula.txt");
    archMatricula>>registroMat;
    /* cout<<registroMat.codigoDelCurso<<endl<<registroMat.codigodelAlumno<<endl
            <<registroMat.codigodelAlumno<<endl<<endl; */
    
    // Agregación 1:
    struct StCurso curso2, arregloCursos[10];
    archCursos>>curso2;
    strcpy(arregloCursos[0].codigoDelCurso, "XXXXXX");
    arregloCursos+=curso;
    arregloCursos+=curso2;
    /* for (int i=0; strcmp(arregloCursos[i].codigoDelCurso, "XXXXXX")!=0; i++) 
        cout<<arregloCursos[i].codigoDelCurso<<endl
                <<arregloCursos[i].nombreDelCurso<<endl
                <<arregloCursos[i].creditos<<endl
                <<arregloCursos[i].codigoDelProfesor<<endl
                <<arregloCursos[i].nombreDelProfesor<<endl; */ 
    
    // Agregación 2:
    struct StAlumno alumno2, arregloAlumno[10];
    archAlumnos>>alumno2;
    arregloAlumno[0].semestre=0;
    arregloAlumno+=alumno;
    arregloAlumno+=alumno2;
    /* for (int i=0; arregloCursos[i].semestre; i++) 
        cout<<arregloAlumno[i].semestre<<endl<<arregloAlumno[i].codigo<<endl
                <<arregloAlumno[i].nombre<<endl<<arregloAlumno[i].modalidad
                <<endl<<arregloAlumno[i].escala<<endl
                <<arregloAlumno[i].numeroDeCursos<<endl
                <<arregloAlumno[i].costoTotal<<endl; */
    
    // Agregación 3:
    for (int i=0; true; i++) {
        if (not (archMatricula>>registroMat)) break;
        arregloCursos*=registroMat;
    }
    
    ofstream archReporte, archReporte2;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte, "Reporte.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte2, "Reporte2.txt");
    
    // Impresión 1:
    for (int i=0; strcmp(arregloCursos[i].codigoDelCurso, "XXXXXX")!=0; i++)
        archReporte<<arregloCursos[i];    
    
    // Impresión 2:
    for (int i=0; arregloAlumno[i].codigo; i++) {
        archReporte2<<arregloAlumno[i];    
    }
}

