#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;

#include "FuncionesAuxiliares.h"
#define MAX_LINEA 110
      
void crearArchBin(const char *nombArchBin) {    
    ofstream archBin(nombArchBin, ios::out|ios::binary);
    if (not archBin.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchBin<<endl;
        exit(1);
    }    
}

void crearBinarios(const char *nombArchAlumnosXCursos, 
        const char *nombArchCursos, const char *nombArchAlumnos, 
        const char *nombArchClases, const char *nombArchEscalas) {
    // Creamos previamente los binarios como output para evitar conflictos
    crearArchBin("Cursos.bin");
    crearArchBin("Alumnos.bin");
    crearArchBin("ListaDeClases.bin");
    crearArchBin("Escalas.bin");
    ifstream archAlumnosXCursos(nombArchAlumnosXCursos, ios::in);
    if (not archAlumnosXCursos.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchAlumnosXCursos<<endl;
        exit(1);
    }
    ofstream archCursos(nombArchCursos, ios::out|ios::binary);
    if (not archCursos.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchCursos<<endl;
        exit(1);
    }
    fstream archAlumnos(nombArchAlumnos, ios::in|ios::out|ios::binary);
    if (not archAlumnos.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchAlumnos<<endl;
        exit(1);
    }
    ofstream archClases(nombArchClases, ios::out|ios::binary);
    if (not archClases.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchClases<<endl;
        exit(1);
    }
    ofstream archEscalas(nombArchEscalas, ios::out|ios::binary);
    if (not archEscalas.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchEscalas<<endl;
        exit(1);
    }
    leerCursos(archAlumnosXCursos, archCursos, archAlumnos, archClases, 
            archEscalas);
}

void leerCursos(ifstream &input, ofstream &archCursos, fstream &archAlumnos, 
        ofstream &archClases, ofstream &archEscalas) {    
    int codProfesor, cantAlumnos;
    char codCurso[7], nombCurso[60], nombProfesor[60];
    double creditos, totalIngresos;
    while (true) {
        input>>codCurso;
        if (input.eof()) break;
        input>>nombCurso>>creditos>>codProfesor>>nombProfesor;
        cantAlumnos=totalIngresos=0;
        leerAlumnos(input, archAlumnos, archClases, archEscalas, cantAlumnos, 
                codCurso, creditos);
        escribirCursos(codCurso, nombCurso, creditos, codProfesor, nombProfesor, 
                cantAlumnos, totalIngresos, archCursos);
    }    
}

void leerAlumnos(ifstream &input, fstream &archAlumnos, ofstream &archClases, 
        ofstream &archEscalas, int &cantAlumnos, char *codCurso, double creditos) {
    int semestre, codigo, porcV, escala;
    char nombre[60], modalidad[20], c;
    double costoSem=0;    
    while (true) {        
        input>>semestre>>c>>codigo>>nombre;
        elegirModalidad(modalidad, porcV, input);
        input>>escala;
        escribirClases(archClases, codCurso, semestre, codigo);
        escribirEscalas(archEscalas, escala);               
        escribirAlumnos(semestre, codigo, nombre, modalidad, porcV, creditos, 
                costoSem, archAlumnos, escala);
        cantAlumnos++;
        input>>ws;
        if (input.eof()) break;
        if (verificarFinDeAlumnos(input)) break;
    }
}

void elegirModalidad(char *modalidad, int &porcV, ifstream &input) {
    input>>ws;
    char c = input.get();    
    if (c=='V') {
        strcpy(modalidad, "VIRTUAL");
        porcV = 0;
    } else if (c=='S') {
        strcpy(modalidad, "SEMIPRESENCIAL");
        input>>porcV;
    } else {
        input.unget();
        strcpy(modalidad, "PRESENCIAL");
        porcV = 0;
    }
}

void escribirClases(ofstream &archClases, char *codCurso, int semestre, 
        int codigo) {
    archClases.write(reinterpret_cast<const char*>(codCurso), sizeof(char)*7);
    archClases.write(reinterpret_cast<const char*>(&semestre), sizeof(int));
    archClases.write(reinterpret_cast<const char*>(&codigo), sizeof(int));
}

void escribirEscalas(ofstream &archEscalas, int escala) {
    archEscalas.write(reinterpret_cast<const char*>(&escala), sizeof(int));
}

void escribirAlumnos(int semestre, int codigo, char *nombre, char *modalidad, 
        int porcV, double creditos, double costoSem, fstream &out, int escala) {    
    if (not alumnoRepetido(semestre, codigo, out, creditos)) {
        out.seekg(0, ios::end);
        out.write(reinterpret_cast<const char*>(&semestre), sizeof(int));
        out.write(reinterpret_cast<const char*>(&codigo), sizeof(int));
        out.write(reinterpret_cast<const char*>(nombre), sizeof(char)*60);
        out.write(reinterpret_cast<const char*>(modalidad), sizeof(char)*20);
        out.write(reinterpret_cast<const char*>(&porcV), sizeof(int));
        out.write(reinterpret_cast<const char*>(&creditos), sizeof(double));
        out.write(reinterpret_cast<const char*>(&costoSem), sizeof(double));
        out.write(reinterpret_cast<const char*>(&escala), sizeof(int));
    }
}

bool alumnoRepetido(int semestre, int codigo, fstream &out, double creditos) {
    int tamReg, tamArch, numReg, semReg, codReg;
    double credReg;
    out.seekg(0, ios::end);
    tamReg = sizeof(int) + sizeof(int) + sizeof(char)*60 + sizeof(char)*20 
            + sizeof(int)+ sizeof(double) + sizeof(double) + sizeof(int);
    tamArch = out.tellg();    
    numReg = tamArch/tamReg;    
    for (int i=0; i<numReg-1; i++) {
        out.seekg(tamReg*i, ios::beg);
        out.read(reinterpret_cast<char*>(&semReg), sizeof(int));
        out.read(reinterpret_cast<char*>(&codReg), sizeof(int));
        if (semReg==semestre && codReg==codigo) {
            out.seekg(sizeof(char)*60 + sizeof(char)*20 + sizeof(int), ios::cur);
            out.read(reinterpret_cast<char*>(&credReg), sizeof(double));
            credReg += creditos;
            out.seekg(tamReg*i + sizeof(int) + sizeof(int) + sizeof(char)*60 + 
                    sizeof(char)*20 + sizeof(int), ios::beg);
            out.write(reinterpret_cast<const char*>(&credReg), sizeof(double));
            out.flush();
            return true;
        }
    }
    return false;
}

bool verificarFinDeAlumnos(ifstream &input) {
    input>>ws;
    char c = input.get();
    input.unget();
    return c>='A' && c<='Z';
}

void escribirCursos(char *codCurso, char *nombCurso, double creditos, 
        int codProfesor, char *nombProfesor, int cantAlumnos, 
        double totalIngresos, ofstream &archCursos) {
    archCursos.write(reinterpret_cast<const char*>(codCurso), sizeof(char)*7);
    archCursos.write(reinterpret_cast<const char*>(nombCurso), sizeof(char)*60);
    archCursos.write(reinterpret_cast<const char*>(&creditos), sizeof(double));
    archCursos.write(reinterpret_cast<const char*>(&codProfesor), sizeof(int));
    archCursos.write(reinterpret_cast<const char*>(nombProfesor), sizeof(char)*60);
    archCursos.write(reinterpret_cast<const char*>(&cantAlumnos), sizeof(int));
    archCursos.write(reinterpret_cast<const char*>(&totalIngresos), sizeof(double));
}

void imprimirReporteDeVerificacion(const char *nombArchOutput, 
        const char *nombArchCursos, const char *nombArchAlumnos, 
        const char *nombArchClases, const char *nombArchEscalas) {    
    ofstream archOutput(nombArchOutput, ios::out);
    if (not archOutput.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchOutput<<endl;
        exit(1);
    }
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
    ifstream archClases(nombArchClases, ios::in|ios::binary);
    if (not archClases.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchClases<<endl;
        exit(1);
    }
    ifstream archEscalas(nombArchEscalas, ios::in|ios::binary);
    if (not archEscalas.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchEscalas<<endl;
        exit(1);
    }
    imprimirCursos(archOutput, archCursos);
    imprimirAlumnos(archOutput, archAlumnos);
    imprimirClases(archOutput, archClases);
}

void imprimirCursos(ofstream &out, ifstream &in) {
    imprimirEncabezadoCursos(out);
    int tamReg, tamArch, numReg, codProfesor, cantAlumnos;
    char codCurso[7], nombCurso[60], nombProfesor[60];
    double creditos, totalIngresos;
    in.seekg(0, ios::end);
    tamArch = in.tellg();
    tamReg = sizeof(char)*7 + sizeof(char)*60 + sizeof(double) + sizeof(int)
            + sizeof(char)*60 + sizeof(int) + sizeof(double);
    numReg = tamArch/tamReg;
    out.precision(2);
    out<<fixed;    
    for (int i=0; i<numReg-1; i++) {
        in.seekg(tamReg*i, ios::beg);
        in.read(reinterpret_cast<char*>(codCurso), sizeof(char)*7);
        in.read(reinterpret_cast<char*>(nombCurso), sizeof(char)*60);
        in.read(reinterpret_cast<char*>(&creditos), sizeof(double));
        in.read(reinterpret_cast<char*>(&codProfesor), sizeof(int));
        in.read(reinterpret_cast<char*>(nombProfesor), sizeof(char)*60);
        in.read(reinterpret_cast<char*>(&cantAlumnos), sizeof(int));
        in.read(reinterpret_cast<char*>(&totalIngresos), sizeof(double)); 
        out<<right<<setw(2)<<i<<") "<<left<<setw(10)<<codCurso<<setw(60)
                <<nombCurso<<setw(10)<<cantAlumnos<<setw(5)<<totalIngresos
                <<endl;
    }
}

/*
archCursos.write(reinterpret_cast<const char*>(codCurso), sizeof(char)*7);
archCursos.write(reinterpret_cast<const char*>(nombCurso), sizeof(char)*60);
archCursos.write(reinterpret_cast<const char*>(&creditos), sizeof(double));
archCursos.write(reinterpret_cast<const char*>(&codProfesor), sizeof(int));
archCursos.write(reinterpret_cast<const char*>(nombProfesor), sizeof(char)*60);
archCursos.write(reinterpret_cast<const char*>(&cantAlumnos), sizeof(int));
archCursos.write(reinterpret_cast<const char*>(&totalIngresos), sizeof(double));
 */

void imprimirEncabezadoCursos(ofstream &out) {
    out<<right<<setw(30)<<"LISTADO DE CURSOS"<<endl;
    imprimirLinea(out, '=', MAX_LINEA);
}

void imprimirLinea(ofstream &out, char c, int n) {
    for (int i=0; i<n; i++) out.put(c);
    out.put('\n');
}

void imprimirAlumnos(ofstream &out, ifstream &in) {    
    imprimirEncabezadoAlumnos(out);
    int tamReg, tamArch, numReg, semestre, codigo, porcV;
    char nombre[60], modalidad[20];
    double creditos, costoSem, escala;
    in.seekg(0, ios::end);
    tamArch = in.tellg();
    tamReg = sizeof(int)*2 + sizeof(char)*80 + sizeof(int)*2 + sizeof(double)*2;
    numReg = tamArch/tamReg;
    out.precision(2);
    out<<fixed;    
    for (int i=0; i<numReg-1; i++) {
        in.seekg(tamReg*i, ios::beg);
        in.read(reinterpret_cast<char*>(&semestre), sizeof(int));
        in.read(reinterpret_cast<char*>(&codigo), sizeof(int));
        in.read(reinterpret_cast<char*>(nombre), sizeof(char)*60);
        in.read(reinterpret_cast<char*>(modalidad), sizeof(char)*20);
        in.read(reinterpret_cast<char*>(&porcV), sizeof(int));
        in.read(reinterpret_cast<char*>(&creditos), sizeof(double));
        in.read(reinterpret_cast<char*>(&costoSem), sizeof(double));
        in.read(reinterpret_cast<char*>(&escala), sizeof(int));
        out<<right<<setw(2)<<i<<") "<<left<<setw(10)<<semestre<<setw(7)<<codigo
                <<setw(60)<<nombre<<setw(20)<<modalidad<<setw(5)<<porcV
                <<setw(10)<<creditos<<setw(5)<<costoSem<<setw(10)<<escala
                <<endl;
    }
}

/*
out.write(reinterpret_cast<const char*>(&semestre), sizeof(int));
out.write(reinterpret_cast<const char*>(&codigo), sizeof(int));
out.write(reinterpret_cast<const char*>(nombre), sizeof(char)*60);
out.write(reinterpret_cast<const char*>(modalidad), sizeof(char)*20);
out.write(reinterpret_cast<const char*>(&porcV), sizeof(int));
out.write(reinterpret_cast<const char*>(&creditos), sizeof(double));
out.write(reinterpret_cast<const char*>(&costoSem), sizeof(double));
out.write(reinterpret_cast<const char*>(&escala), sizeof(int));
 */

void imprimirEncabezadoAlumnos(ofstream &out) {
    out<<right<<setw(30)<<"LISTADO DE ALUMNOS"<<endl;
    imprimirLinea(out, '=', MAX_LINEA);
}

void imprimirClases(ofstream &out, ifstream &in) {
    imprimirEncabezadoClases(out);
    int tamReg, tamArch, numReg, semestre, codigo;
    char codCurso[7];
    in.seekg(0, ios::end);
    tamArch = in.tellg();
    tamReg = sizeof(char)*7 + sizeof(int)*2;
    numReg = tamArch/tamReg;
    out.precision(2);
    out<<fixed;    
    for (int i=0; i<numReg-1; i++) {
        in.seekg(tamReg*i, ios::beg);
        in.read(reinterpret_cast<char*>(codCurso), sizeof(char)*7);
        in.read(reinterpret_cast<char*>(&semestre), sizeof(int));
        in.read(reinterpret_cast<char*>(&codigo), sizeof(int));
        out<<right<<setw(2)<<i<<") "<<left<<setw(10)<<codCurso<<setw(10)
                <<semestre<<setw(10)<<codigo<<endl;
    }
}

/*
archClases.write(reinterpret_cast<const char*>(codCurso), sizeof(char)*7);
archClases.write(reinterpret_cast<const char*>(&semestre), sizeof(int));
archClases.write(reinterpret_cast<const char*>(&codigo), sizeof(int));
*/

void imprimirEncabezadoClases(ofstream &out) {
    out<<right<<setw(30)<<"LISTA DE CLASES"<<endl;
    imprimirLinea(out, '=', MAX_LINEA);
}