/* 
 * Proyecto:    LAB1_2020-2
 * Archivo:     FuncionesAuxiliares.h
 * Autor:       CosmoDev
 *
 * Creado el 3 de abril de 2023, 02:45 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void imprimirReporteAcademico();
void imprimirTitulo();
void imprimirEstudiantes(int &);
void leerEstudiante();
int calcularCodigo(char []);
void imprimirDatosEstudiante(char [], int, int);
void corregirNombre(char []);
void imprimirLinea(char, int);
void imprimirCurso(int, int, char [], double, int, int, int, int, int &, int &, 
        double &, double &, double &, double &, double &, double &, int &);
int calcularEspacios(int);
void imprimirFormato(int);
void imprimirFecha(int, int, int);
int imprimirObservacion(int, int, int);
void imprimirCabeceraDeCursos();
void imprimirCabeceraCurso();
void leerCurso(int, int, int &, int &, double &, double &, double &, double &, 
        double &, double &, int &);
void imprimirCursos(int);
bool verificarFinDeCursos();
double calcularRelacionCreditos(double, double);
void imprimirResumen(int, int, int, double, double, double, double, double, 
        double, int);
void imprimirTotalDeAlumnos(int);

#endif /* FUNCIONESAUXILIARES_H */

