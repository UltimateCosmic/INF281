#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "FuncionesAuxiliares.h"
#define MAX_LINEA 110
#define MAX_ERROR 72

void imprimirReporteAcademico() {
    int totalAlumnos = 0;
    imprimirTitulo();
    imprimirEstudiantes(totalAlumnos);
    imprimirTotalDeAlumnos(totalAlumnos);
}

void imprimirTitulo() {
    cout<<setw(64)<<"INFORMACION ACADEMICA DE LOS ESTUDIANTES"<<endl;
}

void imprimirEstudiantes(int &totalAlumnos) {
    while (true) {
        leerEstudiante();
        if (cin.eof()) break;
        totalAlumnos++;
    }
}

void leerEstudiante() {
    int codigo, anio;
    char c, nombre[60], fecha[4];
    cin>>codigo;
    if (cin.eof()) return;
    else if (cin.fail()) {
        cin.clear();
        fecha[0] = cin.get();
        fecha[1] = cin.get();
        fecha[2] = cin.get();
        fecha[3] = 0;
        codigo = calcularCodigo(fecha);
    }
    cin>>c>>anio>>nombre;
    imprimirDatosEstudiante(nombre, anio, codigo);
}

int calcularCodigo(char fecha[]) {    
    if (strcmp(fecha, "Ene")==0) return 1;
    else if (strcmp(fecha, "May")==0) return 5;
    else if (strcmp(fecha, "Abr")==0) return 4;
    else if (strcmp(fecha, "Nov")==0) return 11;
}

void imprimirDatosEstudiante(char nombre[], int anio, int codigo) {
    corregirNombre(nombre);
    imprimirLinea('=', MAX_LINEA);
    cout<<setw(15)<<"Alumno: "<<left<<setw(38)<<nombre;
    cout<<"Codigo: "<<anio<<" - ";
    cout.fill('0');
    cout<<setw(6)<<codigo<<right<<endl;  
    cout.fill(' ');
    imprimirCursos(anio);
}

void corregirNombre(char nombre[]) {
    for (int i=0; nombre[i]!=0; i++)
        if (nombre[i]=='/') nombre[i]=' ';
}

void imprimirLinea(char c, int n) {
    for (int i=0; i<n; i++) cout.put(c);
    cout.put('\n');
}

void imprimirCursos(int anio) {
    imprimirCabeceraDeCursos();
    int i=0, cursosConError=0, cursosMatri=0, cantApro=0;    
    double promGen=0, promApro=0, totalCred=0, credApro=0, credDesa=0, 
            credAproMatri=0;
    while (true) {
        leerCurso(anio, i, cursosConError, cursosMatri, promGen, promApro, 
                totalCred, credApro, credDesa, credAproMatri, cantApro);
        if (verificarFinDeCursos()) break;
        i++;
    }
    credAproMatri = calcularRelacionCreditos(credApro, credApro+credDesa);
    imprimirResumen(i, cursosConError, cursosMatri, promGen, promApro, 
            totalCred, credApro, credDesa, credAproMatri, cantApro);
}

void imprimirCabeceraDeCursos() {
    imprimirLinea('-', MAX_LINEA);
    cout<<setw(30)<<"CURSOS APROBADOS"<<setw(42)<<"CURSOS DESAPROBADOS"
            <<setw(35)<<"OBSERVACION"<<endl;
    cout<<"No."<<setw(9);
    imprimirCabeceraCurso();
    cout<<setw(15);
    imprimirCabeceraCurso();
    cout<<endl;
    imprimirLinea('-', MAX_LINEA);
}

void imprimirCabeceraCurso() {
    cout<<"CODIGO"<<setw(11)<<"CREDITOS"<<setw(8)<<"NOTA"<<setw(10)<<"FECHA";
}

void leerCurso(int anio, int i, int &cursosConError, int &cursosMatri, 
        double &promGen, double &promApro, double &totalCred, double &credApro, 
        double &credDesa, double &credAproMatri, int &cantApro) {
    char codigo[7], c;
    double creditos;
    int nota, dd, mm, aaaa;
    cin>>codigo>>creditos>>nota>>dd>>c>>mm>>c>>aaaa;
    imprimirCurso(anio, i, codigo, creditos, nota, dd, mm, aaaa, cursosConError, 
            cursosMatri, promGen, promApro, totalCred, credApro, credDesa, 
            credAproMatri, cantApro);
}

void imprimirCurso(int anio, int i, char codigo[], double creditos, int nota, 
        int dd, int mm, int aaaa, int &cursosConError, int &cursosMatri, 
        double &promGen, double &promApro, double &totalCred, double &credApro, 
        double &credDesa, double &credAproMatri, int &cantApro) {
    int n = calcularEspacios(nota), m = MAX_ERROR-n;
    imprimirFormato(i);
    cout<<setw(n)<<codigo<<setw(9)<<creditos<<setw(9)<<nota<<setw(4)<<" ";
    imprimirFecha(dd, mm, aaaa);
    cursosConError += imprimirObservacion(aaaa, anio, m);
    cout<<endl;
    cursosMatri = i;
    promGen += nota;
    promApro += nota>=11?nota:0;
    totalCred += creditos;
    credApro += nota>=11?creditos:0;
    credDesa += nota<11?creditos:0;
    if (anio>aaaa) 
        credAproMatri += nota>=11?creditos:0;
    cantApro += nota>=11?1:0;
}

int calcularEspacios(int nota) {
    return nota>=11?9:53;    
}

void imprimirFormato(int i) {
    cout.fill('0');
    cout<<setw(3)<<i;
    cout.fill(' ');
    cout.precision(2);
    cout<<fixed;
}

void imprimirFecha(int dd, int mm, int aaaa) {
    cout.fill('0');
    cout<<setw(4)<<aaaa<<"/"<<setw(2)<<mm<<"/"<<setw(2)<<dd;
    cout.fill(' ');
}

int imprimirObservacion(int aaaa, int anio, int n) {
    if (anio>aaaa) {
        cout<<setw(n)<<"ERROR FECHA";
        return 1;
    } else return 0;
}

bool verificarFinDeCursos() {
    cin>>ws;
    cin.unget();
    char c=cin.get();
    cin.unget();
    if (c=='\n') return true;
    else return false;
}

double calcularRelacionCreditos(double credApro, double credMatri) {    
    return credApro*100/credMatri;
}

void imprimirResumen(int i, int cursosConError, int cursosMatri, double promGen, 
        double promApro, double totalCred, double credApro, double credDesa, 
        double credAproMatri, int cantApro) {
    imprimirLinea('=', MAX_LINEA);
    cout<<setw(16)<<"RESUMEN:"<<endl;
    cout<<setw(28)<<"Cursos matriculados:"<<setw(3)<<cursosMatri<<setw(37)
            <<"Total de creditos:"<<setw(12)<<totalCred<<endl;
    cout<<setw(27)<<"Creditos aprobados:"<<setw(7)<<credApro<<setw(38)
            <<"Creditos desaprobados:"<<setw(8)<<credDesa<<endl;
    cout<<setw(40)<<"Creditos aprobados/matriculados:"<<setw(7)<<credAproMatri
            <<"%"<<endl;
    imprimirLinea('-', MAX_LINEA);
    cout<<setw(26)<<"Promedio general: "<<setw(19)<<promGen/i<<endl;
    cout<<setw(39)<<"Promedio general de aprobados: "<<setw(6)
            <<promApro/cantApro<<endl;
    imprimirLinea('-', MAX_LINEA);
    cout.fill('0');
    cout<<setw(20)<<"Cursos con error no considerados: "<<setw(2)
            <<cursosConError<<endl;
    cout.fill(' ');
    imprimirLinea('=', MAX_LINEA);
}

void imprimirTotalDeAlumnos(int totalAlumnos) {
    imprimirLinea('=', MAX_LINEA);
    cout<<"TOTAL DE ALUMNOS REGISTRADOS: "<<totalAlumnos<<endl;
}