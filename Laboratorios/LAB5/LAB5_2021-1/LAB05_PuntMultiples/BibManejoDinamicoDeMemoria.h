/* 
 * Proyecto:    LAB05_PuntMultiples
 * Archivo:     BibManejoDinamicoDeMemoria.h
 * Autor:       CosmoDev
 *
 * Creado el 10 de mayo de 2023, 12:00 AM
 */

#ifndef BIBMANEJODINAMICODEMEMORIA_H
#define BIBMANEJODINAMICODEMEMORIA_H

void cargarConductores(int *&, char **&);
void leerConductores(ifstream &, int *&, char **&);
char *leerCadena(ifstream &, char='\n');
void aumentarEspacios(int *&, char **&, int &, int &);
void reporteConductores(int *, char **);
void imprimirConductores(ofstream &, int *, char **);
void imprimirCabeceraConductores(ofstream &);
void imprimirLinea(ofstream &, char, int);
void cargarFaltas(int *, char ***&, int **&);
void leerFaltas(ifstream &, int *, char ***&, int **&);
int buscarConductor(int *, int);
void agregarFalta(char **&, int *&, int &, int &, char *, int);
void aumentarEspaciosFaltas(char **&, int *&, int &, int &);
void reporteFaltas(int *, char **, char ***, int **);
void imprimirFaltas(ofstream &, int *, char **, char ***, int **);
void imprimirFaltasDeConductor(ofstream &, char **, int *);
void imprimirCabeceraFaltas(ofstream &);
void resumenMultas(int *, int **, double **&);
void leerMultas(int *, int **, double **&); 
void agregarMulta(int, double *&);
double buscarMulta(ifstream &, int, char &);
void reporteMultas(int *, char **, double **);
void imprimirMultas(ofstream &, int *, char **, double **);

#endif /* BIBMANEJODINAMICODEMEMORIA_H */

