/* 
 * File:   BibliotecaMemoriaDinamica.h
 * Author: alulab14
 *
 * Created on 2 de mayo de 2023, 04:23 PM
 */

#ifndef BIBLIOTECAMEMORIADINAMICA_H
#define BIBLIOTECAMEMORIADINAMICA_H

void cargarConductores(int *&, char **&);
char *leerCadena(ifstream &);
void cargarConductoresExactos(int *&, char **&, int [], char *[], int);
void reporteConductores(int *, char **);
void cargarInfracciones(int *&, char *&, double *&);
char omitirCadena(ifstream &);
void cargarInfraccionesExactos(int *&, char *&, double *&, int [], char [], 
        double [], int);
void reporteInfracciones(int *, char *, double *);
void reporteDeFaltas(int *, char **, int *, char *, double *);
void reporteDeGravedad(ofstream &, int *, char **, int *, char *, double *, 
        const char);
void imprimirCabecera(ofstream &, const char);
void imprimirLinea(ofstream &, char, int);
void leerFaltas(ifstream &, ofstream &, int *, char **, int *, char *, double *, 
        const char);
int buscarConductor(int *, int);
char *leerCadenaComa(ifstream &);
void saltearFecha(ifstream &);
int buscarGravedad(int *, int);
void imprimirFaltas(ofstream &, int *, char **, int *, double *);

#endif /* BIBLIOTECAMEMORIADINAMICA_H */

