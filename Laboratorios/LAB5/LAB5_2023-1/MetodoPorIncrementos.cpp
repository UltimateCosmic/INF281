#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "MetodoPorIncrementos.h"
#define MAX 100
#define INCREMENTO 5
#define MAX_LINEA 100

void cargarCursos(const char *nombArch, char ***&cursos_datos, 
        int *&cursos_credito, char ****&cursos_alumnos, 
        double **&cursos_informacion_economica) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);       
    }  
    cursos_datos = nullptr;
    cursos_credito = nullptr;
    cursos_alumnos = nullptr;
    cursos_informacion_economica = nullptr;    
    leerCursos(arch, cursos_datos, cursos_credito, cursos_alumnos, 
            cursos_informacion_economica);
}

void leerCursos(ifstream &arch, char ***&cursos_datos, int *&cursos_credito, 
        char ****&cursos_alumnos, double **&cursos_informacion_economica) {
    char *codCurso, *nombCurso;  
    int credCurso, numCur=0, capCur=0, posCur;
    while (true) {
        codCurso = leerCadena(arch, ',');
        if (arch.eof()) break;
        nombCurso = leerCadena(arch, ',');
        arch>>credCurso;
        arch.get();
        asignarCurso(codCurso, nombCurso, credCurso, cursos_datos, 
                cursos_credito, cursos_alumnos, cursos_informacion_economica, 
                numCur, capCur);
        leerAlumnos(arch, cursos_alumnos[numCur-1], 
                cursos_informacion_economica[numCur-1], credCurso);
        numCur++;
    }
}

char *leerCadena(ifstream &arch, char delim='\n') {
    char buff[60], *cad;
    arch.getline(buff, 60, delim);
    cad = new char[strlen(buff)+1];
    strcpy(cad, buff);
    return cad;
}

int asignarCurso(char *codCurso, char *nombCurso, double credCurso, 
        char ***&cursos_datos, int *&cursos_credito, char ****&cursos_alumnos, 
        double **&cursos_informacion_economica, int &nd, int &cap) {
    if (nd==cap)
        agregarEspacios(cursos_datos, cursos_credito, cursos_alumnos, 
                cursos_informacion_economica, nd, cap);
    cursos_datos[nd-1] = new char*[2]{};
    cursos_datos[nd-1][0] = codCurso;
    cursos_datos[nd-1][1] = nombCurso;
    cursos_credito[nd-1] = credCurso;
    // Inicializamos punteros que se relacionen con alumnos
    cursos_alumnos[nd-1] = new char**[cap]{};
    cursos_informacion_economica[nd-1] = new double[cap]{};
}

void agregarEspacios(char ***&cursos_datos, int *&cursos_credito, 
        char ****&cursos_alumnos, double **&cursos_informacion_economica, 
        int &nd, int &cap) {
    int *auxCC;
    char ***auxCD, ****auxCA;
    double **auxIE;    
    cap += INCREMENTO;
    if (cursos_datos==nullptr) { // Primera vez
        cursos_datos = new char**[cap]{};   
        cursos_credito = new int[cap]{};
        cursos_alumnos = new char***[cap]{};
        cursos_informacion_economica = new double*[cap]{};
        nd=1;
    } else {
        auxCD = new char**[cap]{};   
        auxCC = new int[cap]{};
        auxCA = new char***[cap]{};
        auxIE = new double*[cap]{};
        for (int i=0; i<nd; i++) {
            auxCD[i] = cursos_datos[i];
            auxCC[i] = cursos_credito[i];
            auxCA[i] = cursos_alumnos[i];
            auxIE[i] = cursos_informacion_economica[i];            
        }
        delete cursos_datos;
        delete cursos_credito;
        delete cursos_alumnos;
        delete cursos_informacion_economica;
        cursos_datos = auxCD;
        cursos_credito = auxCC;
        cursos_alumnos = auxCA;
        cursos_informacion_economica = auxIE;
    }
}

void leerAlumnos(ifstream &arch, char ***&cursos_alumnos, 
        double *&cursos_informacion_economica, double creditos) {
    char *codigo, *nombre, *escala = new char[2];
    int nd=0, cap=0;
    cursos_informacion_economica = new double[2]{};
    cursos_informacion_economica[0] = 0.0;
    cursos_informacion_economica[1] = 0.0;  
    while (true) {
        nombre = leerCadena(arch, ',');
        codigo = leerCadena(arch, '.');
        strcat(codigo, ".");
        escala[0] = arch.get();
        escala[1] = 0;
        strcat(codigo, escala);        
        if (nd==cap)
            agregarEspacios(cursos_alumnos, cursos_informacion_economica, nd, cap);
        cursos_alumnos[nd-1] = new char*[2];
        cursos_alumnos[nd-1][0] = codigo;
        cursos_alumnos[nd-1][1] = nombre;
        cursos_informacion_economica[0]++;
        cursos_informacion_economica[1]+=creditos*
                valorEscala(codigo[strlen(codigo)-1]);
        if (arch.get()=='\n' || arch.eof()) break;
        nd++;
    }    
}

void agregarEspacios(char ***&cursos_alumnos, double *&cursos_informacion_economica, 
        int &nd, int &cap) {
    char ***auxCA;
    double *auxIE;
    cap += INCREMENTO;
    if (cursos_alumnos==nullptr) {
        cursos_alumnos = new char**[cap]{};
        cursos_informacion_economica = new double[cap]{};
        nd=1;
    } else {
        auxCA = new char**[cap]{};
        auxIE = new double[cap]{};
        for (int i=0; i<nd; i++) {
            auxCA[i] = cursos_alumnos[i];
            auxIE[i] = cursos_informacion_economica[i];
        }
        delete cursos_alumnos;
        delete cursos_informacion_economica;
        cursos_alumnos = auxCA;
        cursos_informacion_economica = auxIE;
    }
}

double valorEscala(char c) {
    if (c=='1')      return 282.3;
    else if (c=='2') return 362;
    else if (c=='3') return 454.2;
    else if (c=='4') return 556.7;
    else if (c=='5') return 666.9;
    else return 0;    
}

void pruebaCursos(const char *nombArch, char ***cursos_datos, 
        int *cursos_credito, char ****cursos_alumnos, 
        double **cursos_informacion_economica) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);       
    }  
    double totalRec=0;
    for (int i=0; cursos_datos[i]; i++) {
        imprimirCabeceraCursos(arch);
        arch<<left<<setw(10)<<cursos_datos[i][0]<<setw(35)<<cursos_datos[i][1]
                <<cursos_credito[i]<<endl;
        imprimirLinea(arch, '-', MAX_LINEA);
        arch<<right<<setw(15)<<"Codigo"<<setw(15)<<"Nombre"<<setw(25)<<"Pago Total"
                <<endl;
        imprimirLinea(arch, '-', MAX_LINEA);
        imprimirAlumnos(arch, cursos_alumnos[i], cursos_informacion_economica[i], 
                cursos_credito[i], totalRec);
        imprimirLinea(arch, '=', MAX_LINEA);
    }
}

void imprimirCabeceraCursos(ofstream &arch) {
    arch<<right<<"Codigo"<<setw(10)<<"Nombre"<<setw(33)<<"Creditos"<<endl;
    imprimirLinea(arch, '=', MAX_LINEA);
}

void imprimirLinea(ofstream &arch, char c, int n) {
    for (int i=0; i<n; i++) arch.put(c);
    arch.put('\n');
}

void imprimirAlumnos(ofstream &arch, char ***cursos_alumnos, 
        double *cursos_informacion_economica, double cred, double &totalRec) {
    arch.precision(2);
    arch<<fixed;
    char escala;
    double valor, total;
    for (int i=0; cursos_alumnos[i]; i++) {
        escala = cursos_alumnos[i][0][9];
        valor = cred*valorEscala(escala);   
        cursos_alumnos[i][0][8]=0;
        arch<<right<<' '<<i;
        if (i<10) arch<<' ';
        arch<<setw(4)<<' '<<left<<setw(12)<<cursos_alumnos[i][0]
                <<setw(35)<<cursos_alumnos[i][1]<<valor<<endl;  
        total += valor;
    }
    totalRec += total;
    imprimirLinea(arch, '-', MAX_LINEA);
    arch<<right<<setw(19)<<' '<<left<<setw(34)<<"TOTAL:"<<total<<endl;
}

void reporteDeAlumnosPorCurso(const char *nombArch, char ***cursos_datos, 
        int *cursos_credito, char ****cursos_alumnos, 
        double **cursos_informacion_economica) {    
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);       
    }
    double totalRec=0;
    imprimirCabeceraPrincipal(arch);
    for (int i=0; cursos_datos[i]; i++) {
        imprimirCabeceraRelacion(arch, cursos_datos[i], cursos_credito[i]);
        imprimirAlumnos(arch, cursos_alumnos[i], cursos_informacion_economica[i], 
                cursos_credito[i], totalRec);
    }
    imprimirLinea(arch, '=', MAX_LINEA);
    arch<<right<<setw(15)<<"TOTAL RECAUDADO 2023-1: "<<totalRec<<endl;
}

void imprimirCabeceraPrincipal(ofstream &arch) {
    arch<<setw(55)<<"CURSOS EN EL CICLO 2023-1"<<endl;    
}

void imprimirCabeceraRelacion(ofstream &arch, char **curso, int cred) {
    imprimirLinea(arch, '=', MAX_LINEA);
    arch<<right<<"RELACION DE ALUMNOS POR CURSO"<<endl;
    imprimirLinea(arch, '=', MAX_LINEA);
    arch<<"CODIGO"<<setw(10)<<"NOMBRE"<<setw(20)<<"Creditos:"<<setw(10)<<cred<<endl;
    arch<<left<<setw(10)<<curso[0]<<curso[1]<<endl;
    imprimirLinea(arch, '-', MAX_LINEA);
    arch<<"RELACION DE ALUMNOS MATRICULADOS:"<<endl;
    imprimirLinea(arch, '-', MAX_LINEA);
    arch<<right<<setw(13)<<"CODIGO"<<setw(12)<<"Nombre"<<setw(36)<<"Pago total"
            <<endl;
    imprimirLinea(arch, '-', MAX_LINEA);    
}

