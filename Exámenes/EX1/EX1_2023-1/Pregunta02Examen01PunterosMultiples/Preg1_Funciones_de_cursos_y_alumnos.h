/* 
 * File:   Preg1_Funciones_de_cursos_y_alumnos.h
 * Author: alulab14
 *
 * Created on 16 de mayo de 2023, 08:06 AM
 */

#ifndef PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H
#define PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H

void cargarCursosYEscalas(char ***&, double *&, double *, const char *, const char *);
void cargarCursos(ifstream &, char ***&, double *&);
char *leerCadena(ifstream &, char);
void aumentarEspacios(char ***&, double *&, int &, int &);
void cargarCurso(char **&, double &, char *, char *, char *, double);
void cargarEscalas(ifstream &, double *);
void pruebaDeCargaDeCursos(char ***, double *, double *, const char *);
void imprimirEncabezadoCursos(ofstream &);
void imprimirCurso(ofstream &, char **, double);
void cargarAlumnos(int *&, int **&, char ***&, const char *);
void leerAlumnos(ifstream &, int *&, int **&, char ***&);
void aumentarEspacios(int *&, int **&, char ***&, int &, int &);
char leerModalidad(ifstream &, int &);
void cargarAlumno(int &, int *&, char **&, int, char *, char, int, int);
void pruebaDeCargaDeAlumnos(int *, int **, char ***, const char *);
void imprimirCabeceraAlumnos(ofstream &);
void imprimirAlumno(ofstream &, int, int *, char **);

#endif /* PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H */

