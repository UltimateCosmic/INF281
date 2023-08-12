/* 
 * Proyecto:    UsoDePunterosMultiples
 * Archivo:     Laboratorio04_Funciones.h
 * Autor:       CosmoDev
 *
 * Creado el 11 de mayo de 2023, 11:36 AM
 */

#ifndef LABORATORIO04_FUNCIONES_H
#define LABORATORIO04_FUNCIONES_H

void leerMedicos(char **&, char **&, double *&);
void leerMedicosExactos(ifstream &, char **&, char **&, double *&);
void cargarMedicosExactos(char **&, char **&, double *&, char **, char **, 
        double *, int);
char *leerCadena(ifstream &, char);
void repMedicos(char **, char **, double *);
void imprimirReporteMedicos(ofstream &, char **, char **, double *);
void imprimirCabeceraMedicos(ofstream &);
void imprimirLinea(ofstream &, char, int);
void leerAtenciones(char **, int **&, char ***&, double **&, int **&);
void cargarPacientesIncrementos(ifstream &, char **, int **&, char ***&, 
        double **&, int **&);
void leerPacientes(ifstream &, char **, int **&, char ***&, double **&, int **&, 
        int *, int *);
char *leerCadenaGet(ifstream &, char);
int buscarMedico(char **, char *);
void asignarPaciente(int *&, char **&, double *&, int *&, int &, int &, int, 
        char *, double);
void aumentarEspacios(int *&, char **&, double *&, int *&, int &, int &);
void repDeIngresos(char **, char **, double *, int **, char ***, double **, 
        int **);
void imprimirReporteDeIngresos(ofstream &, ifstream &, char **, char **, 
        double *, int **, char ***, double **, int **);
void imprimirMedico(ofstream &, char *, char *, double , int *, char **, 
        double *, int *);
void imprimirPacientes(ofstream &, int *, char **, double *, int *, double);
void imprimirCabeceraPacientes(ofstream &);
double calcularPorcentaje(double, double);
void imprimirResumen(ofstream &, double, double, int);

#endif /* LABORATORIO04_FUNCIONES_H */

