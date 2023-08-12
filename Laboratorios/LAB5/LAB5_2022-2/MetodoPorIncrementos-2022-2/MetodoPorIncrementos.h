/* 
 * Proyecto:    MetodoPorIncrementos-2022-2
 * Archivo:     MetodoPorIncrementos.h
 * Autor:       CosmoDev
 *
 * Creado el 11 de mayo de 2023, 08:59 PM
 */

#ifndef METODOPORINCREMENTOS_H
#define METODOPORINCREMENTOS_H

void cargarCitas(const char *, char ***&, double *&, char ****&, int **&, 
        double ***&);
void leerCitas(ifstream &, char ***&, double *&, char ****&, int **&, 
        double ***&);
char *leerCadena(ifstream &, char);
double leerTiempo(ifstream &);
double calcularHora(int, int, int);
void asignarCita(char *, char *, char *, char *, double, double, char ***&, 
        double *&, char ****&, int **&, double ***&, int &, int &, int *, int *);
int buscarMed(char *, char ***, int);
void aumentarEspaciosMed(char ***&, double *&, char ****&, int **&, double ***&, 
        int &, int &);
void aumentarEspaciosPac(char ***&, int *&, double **&, int &, int &);
int buscarPac(char *, char ***, int);

#endif /* METODOPORINCREMENTOS_H */

