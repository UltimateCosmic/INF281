#include <iostream>
#include <cstring>
using namespace std;

#include "FuncionesAuxiliares.h"
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include "OperadoresSobrecargados.h"

void leerCursos(struct StCurso cursos[], const char *nombArch) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);
    for (int i=0; true; i++)
        if (not (arch>>cursos[i])) break;    
}

void leerAlumnos(struct StAlumno alumnos[], const char *nombArch) {    
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);
    for (int i=0; true; i++)
        if (not (arch>>alumnos[i])) break; 
}

void leerMatricula(struct StCurso cursos[], struct StAlumno alumnos[],
        const char *nombArch) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);
    struct StRegistroDeMatricula registroMat;
    while (true) {
        if (not (arch>>registroMat)) break;
        cursos+=registroMat;
        alumnos+=registroMat;
    }
}

void calcularTotales(struct StAlumno alumnos[], struct StCurso cursos[],
        const char *nombArch) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);
    double escalas[5], n=5;
    leerEscalas(arch, escalas);
    for (int i=0; alumnos[i].semestre; i++) {
        for (int j=0; alumnos[i].cursos[j])
    }
}

void leerEscalas(ifstream &arch, double escalas[]) {
    int i;
    char c;
    while (true) {
        arch>>c;
        if (arch.eof()) break;
        arch>>i>>escalas[i];
    }
}