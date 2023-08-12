/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MetodoPorIncrementos.h
 * Author: alulab14
 *
 * Created on 12 de mayo de 2023, 08:07 AM
 */

#ifndef METODOPORINCREMENTOS_H
#define METODOPORINCREMENTOS_H

void cargarCursos(const char *, char ***&, int *&, char ****&, double **&);
void leerCursos(ifstream &, char ***&, int *&, char ****&, double **&);
char *leerCadena(ifstream &, char);
int asignarCurso(char *, char *, double, char ***&, int *&, char ****&, 
        double **&, int &, int &);
void agregarEspacios(char ***&, int *&, char ****&, double **&, int &nd, int &);
void leerAlumnos(ifstream &, char ***&, double *&, double);
void agregarEspacios(char ***&, double *&, int &, int &);
double valorEscala(char);
void pruebaCursos(const char *, char ***, int *, char ****, double **);
void imprimirCabeceraCursos(ofstream &);
void imprimirLinea(ofstream &, char, int);
void imprimirAlumnos(ofstream &, char ***, double *, double, double &);
void reporteDeAlumnosPorCurso(const char *, char ***, int *, char ****, double **);
void imprimirCabeceraPrincipal(ofstream &);
void imprimirCabeceraRelacion(ofstream &, char **, int);

#endif /* METODOPORINCREMENTOS_H */

