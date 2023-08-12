/* 
 * File:   FuncionesAuxiliares.h
 * Author: alulab14
 *
 * Created on 21 de abril de 2023, 08:09 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void crearArchBin(const char *);
void crearBinarios(const char *, const char *, const char *, const char *, 
        const char *);
void leerCursos(ifstream &, ofstream &, fstream &, ofstream &, ofstream &);
void leerAlumnos(ifstream &, fstream &, ofstream &, ofstream &, int &, char *, 
        double);
void elegirModalidad(char *, int &, ifstream &);
void escribirClases(ofstream &, char *, int, int);
void escribirEscalas(ofstream &, int);
void escribirAlumnos(int, int, char *, char *, int, double, double, fstream &, 
        int);
bool alumnoRepetido(int, int, fstream &, double);
bool verificarFinDeAlumnos(ifstream &);
void escribirCursos(char *, char *, double, int, char *, int , double, 
        ofstream &);
void imprimirReporteDeVerificacion(const char *, const char *, const char *, 
        const char *, const char *);
void imprimirCursos(ofstream &, ifstream &); 
void imprimirEncabezadoCursos(ofstream &);
void imprimirLinea(ofstream &, char, int);
void imprimirAlumnos(ofstream &, ifstream &);
void imprimirEncabezadoAlumnos(ofstream &);
void imprimirClases(ofstream &, ifstream &);
void imprimirEncabezadoClases(ofstream &);

#endif /* FUNCIONESAUXILIARES_H */

