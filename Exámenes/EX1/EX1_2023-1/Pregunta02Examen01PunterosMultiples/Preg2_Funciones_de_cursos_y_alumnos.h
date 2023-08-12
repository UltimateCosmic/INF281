/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Preg2_Funciones_de_cursos_y_alumnos.h
 * Author: alulab14
 *
 * Created on 16 de mayo de 2023, 09:36 AM
 */

#ifndef PREG2_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H
#define PREG2_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H

void cargarNotas(char ***&, int ***&, double **&, int **, char ***, double *, 
        char ***, double *, const char *);
void leerNotas(ifstream &, char ***&, int ***&, double **&, int **, char ***, 
        double *, char ***, double *);
int buscarPosAlumno(int, int **);
int retornarCod(int *);
bool cursoRepetido(char *, char **);
void agregarCurso(char **, int, char *);
void agregarCosto(double *, int, double);
double calcularCosto(char *, char ***, double *, int, int **, double *);
int buscarPosCurso(char *, char ***);
bool compararCursos(char *, char **);
void agregarNSV(int **, int, int, int);
void agregarDatosNSV(int *, int, int);
void pruebaDeCargaDeNotas(char ***, int ***, double **, int **, char ***,
        double *, char ***, double *, const char *);
void imprimirAlumno(ofstream &, int *, char **);
void imprimirNotas(ofstream &, char **, int **, double *);
void imprimirCabeceraNotas(ofstream &);

#endif /* PREG2_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H */

