/* 
 * Proyecto:    Lab420202-MemoriaDinamica
 * Archivo:     Laboratorio04_Funciones.h
 * Autor:       CosmoDev
 *
 * Creado el 4 de mayo de 2023, 03:25 PM
 */

#ifndef LABORATORIO04_FUNCIONES_H
#define LABORATORIO04_FUNCIONES_H

void cargarMedicos(char **&, char **&, double *&);
void leerMedicos(ifstream &, char **&, char **&, double *&);
char *leerCadena(ifstream &);
char *leerCadena(ifstream &, char);
char *leerCadena(ifstream &, int, char);
void exactosMedicos(char **&, char **&, double *&, char *[], char *[], 
        double [], int);
void reporteMedicos(char **, char **, double *);
void reporteDeIngresos(char **, char **, double *);
void reservarEspacios(int *&, char **&, double *&, int *&, char **);
void cargarPacientes(char *, int *&, char **&, double *&, int *&);
char *leerCodMedico(ifstream &);
int buscarPaciente(int, int *, int);
void reservarEspacios(int *&, char **&, double *&, int *&, int *, char **, 
        double *, int *, int);
bool leerFecha(ifstream &);
void reporteDelMedico(char *, char **, char **, double *, int *, char **, 
        double *, int *, ofstream &);
int imprimirCabeceraMedico(char *, char **, char **, double *, ofstream &);
int buscarMedico(char *, char **);
void imprimirLinea(ofstream &, char, int);
void imprimirCabeceraPacientes(ofstream &);
void calcularPagoYSeguro(double, double, double &, double &, int);
void liberarEspacios(int *&, char **&, double *&, int *&);

#endif /* LABORATORIO04_FUNCIONES_H */

