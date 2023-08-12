#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#include "Preg2_Funciones_de_cursos_y_alumnos.h"
#include "AperturaDeArchivos.h"
#define MAX 100

void cargarNotas(char ***&cursos_cod, int ***&cursos_nota_sem_veces, 
        double **&costos, int **alumnos, char ***alumnos_nom_mod, double *escalas, 
        char ***cursos, double *cursos_cred, const char *nombArch) {
    ifstream archCursos;
    AperturaDeUnArchivoDeTextosParaLeer(archCursos, nombArch);
    leerNotas(archCursos, cursos_cod, cursos_nota_sem_veces, costos, alumnos, 
            alumnos_nom_mod, escalas, cursos, cursos_cred);    
}

void leerNotas(ifstream &arch, char ***&cursos_cod, int ***&cursos_nota_sem_veces, 
        double **&costos, int **alumnos, char ***alumnos_nom_mod, double *escalas, 
        char ***cursos, double *cursos_cred) {
    int **buffNSV[MAX], codAlumno, ciclo, nota, pos, numDat[MAX]{}, nd=0;
    char **buffCod[MAX], *codCurso;
    double *buffCos[MAX];
    for (int i=0; i<MAX; i++) {
        buffNSV[i] = new int*[20]{};
        buffCod[i] = new char*[20]{};
        buffCos[i] = new double[20]{};
    }
    while (alumnos[nd]) nd++;
    while (true) {
        arch>>codAlumno;
        if (arch.eof()) break;
        arch.get();
        codCurso = leerCadena(arch, ',');
        arch>>ciclo;
        arch.get();
        arch>>nota;
        pos = buscarPosAlumno(codAlumno, alumnos);
        if (pos!=-1) {
            agregarCurso(buffCod[pos], numDat[pos], codCurso);
            agregarCosto(buffCos[pos], numDat[pos], calcularCosto(codCurso, 
                    cursos, cursos_cred, codAlumno, alumnos, escalas));
            agregarNSV(buffNSV[pos], numDat[pos], nota, ciclo);
            numDat[pos]++;            
        }
    }
    cursos_cod = new char**[nd+1]{};
    cursos_nota_sem_veces = new int**[nd+1]{};
    costos = new double*[nd+1]{};
    for (int i=0; i<nd; i++) {
        cursos_cod[i] = buffCod[i];
        cursos_nota_sem_veces[i] = buffNSV[i];
        costos[i] = buffCos[i];
    }
    cursos_cod[nd] = nullptr;
    cursos_nota_sem_veces[nd] = nullptr;
    costos[nd] = nullptr;
}

int buscarPosAlumno(int codAlumno, int **alumnos) {
    for (int i=0; alumnos[i]; i++)
        if (codAlumno==retornarCod(alumnos[i]))
            return i;
    return -1;    
}

int retornarCod(int *alumno) {
    return alumno[0];    
}

/*bool cursoRepetido(char *codCurso, char ***buffCod) {
    for (int i=0; buffCod[i]; i++)
        if (strcmp(codCurso, buffCod[i])==0)
            return true;    
    return false;
}*/

void agregarCurso(char **buffCod, int pos, char *codCurso) {
    buffCod[pos] = codCurso;    
}

void agregarCosto(double *buffCos, int pos, double costo) {
    buffCos[pos] = costo;    
}

double calcularCosto(char *codCurso, char ***cursos, double *cursos_cred, 
        int codAlumno, int **alumnos, double *escalas) {
    int posCurso = buscarPosCurso(codCurso, cursos);
    if (posCurso==-1) return 0;
    double cred = cursos_cred[posCurso];
    int posAlumno = buscarPosAlumno(codAlumno, alumnos);
    if (posAlumno==-1) return 0;
    double escala = escalas[posAlumno];
    return cred*escala;
}

int buscarPosCurso(char *codCurso, char ***cursos) {
    for (int i=0; cursos[i]; i++) 
        if (compararCursos(codCurso, cursos[i])==0)
            return i;     
    return -1;
}

bool compararCursos(char *codCurso, char **cursos) {
    if (strcmp(codCurso, cursos[0])==0) return true;
    return false;
}

void agregarNSV(int **buffNSV, int pos, int nota, int ciclo) {
    buffNSV[pos] = new int[3];
    agregarDatosNSV(buffNSV[pos], nota, ciclo);    
}

void agregarDatosNSV(int *buffNSV, int nota, int ciclo) {
    buffNSV[0] = nota;
    buffNSV[1] = ciclo;
    buffNSV[2] = 0;
}

void pruebaDeCargaDeNotas(char ***cursos_cod, int ***cursos_nota_sem_veces, 
        double **costos, int **alumnos, char ***alumnos_nom_mod, 
        double *escalas, char ***cursos, double *cursos_cred, 
        const char *nombArch) {
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte, nombArch);
    imprimirCabeceraAlumnos(archReporte);
    for (int i=0; alumnos[i]; i++) {
        imprimirAlumno(archReporte, alumnos[i], alumnos_nom_mod[i]); 
        imprimirNotas(archReporte, cursos_cod[i], cursos_nota_sem_veces[i], costos[i]);
    }    
}

void imprimirAlumno(ofstream &arch, int *alumnos, char **alumnos_nom_mod) {    
    arch<<left<<setw(12)<<alumnos[0]<<setw(5)<<alumnos[1]<<setw(14)<<alumnos[2]
            <<setw(40)<<alumnos_nom_mod[0]<<alumnos_nom_mod[1]<<endl;
}

void imprimirNotas(ofstream &arch, char **cursos_cod, int **cursos_nota_sem_veces, 
        double *costos) {
    imprimirCabeceraNotas(arch);
    for (int i=0; cursos_cod[i]; i++)
        arch<<"     - "<<left<<setw(10)<<cursos_cod[i]<<setw(6)
                <<cursos_nota_sem_veces[i][0]<<setw(6)
                <<cursos_nota_sem_veces[i][1]<<setw(6)
                <<cursos_nota_sem_veces[i][2]<<costos[i];
}

void imprimirCabeceraNotas(ofstream &arch) {
    arch<<right<<"Codigo"<<setw(10)<<"Ultima nota"<<setw(10)<<"Ultimo semestre"
            <<setw(10)<<"Veces"<<setw(10)<<"Costo"<<endl;
}