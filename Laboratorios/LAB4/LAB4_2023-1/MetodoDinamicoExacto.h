/* 
 * File:   MetodoDinamicoExacto.h
 * Author: alulab14
 *
 * Created on 5 de mayo de 2023, 08:07 AM
 */

#ifndef METODODINAMICOEXACTO_H
#define METODODINAMICOEXACTO_H

void lecturaAlumnos(const char *, int *&, char **&, char *&, int *&, int *&);
void leerAlumnos(ifstream &, int *&, char **&, char *&, int *&, int *&);
char *leerCadena(ifstream &);
char *leerCadena(ifstream &, char);
void leerAlumnosExactos(int *&, char **&, char *&, int *&, int *&, int *, 
        char **, char *, int *, int *, int);
void pruebaLecturaAlumnos(const char *, int *, char **, char *, int *, int *);
void imprimirReporteDeAlumnos(ofstream &, int *, char **, char *, int *, int *);
void lecturaCursos(const char *, int *, int *, char **&, double *&, int **&);
void leerCursos(ifstream &, int *, int *, char **&, double *&, int **&);
int buscarCurso(char **, int);
void agregarAlumno(int, int *, int *, int [100][50], int);
void leerCursosExactos(char **&, double *&, int **&, char **, double *, 
        int [100][50], int);
void pruebaDeLecturaCursos(const char *, char **&, double *&, int **&);
void imprimirReporteDeCursos(ofstream &, char **, double *, int **);
void reporteDeRecaudacionPorModalidad(const char *, int *, char *, int *, char **,
        char **, double *, int **);
void imprimirCabeceraPrincipal(ofstream &);
void imprimirCabeceraCurso(ofstream &, char **, double *, int);
void imprimirLinea(ofstream &, char, int);

#endif /* METODODINAMICOEXACTO_H */

