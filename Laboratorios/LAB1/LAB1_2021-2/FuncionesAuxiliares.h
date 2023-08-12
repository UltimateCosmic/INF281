/* 
 * Proyecto:    LAB1_2021-2
 * Archivo:     FuncionesAuxiliares.h
 * Autor:       CosmoDev
 *
 * Creado el 1 de abril de 2023, 11:35 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void imprimirCabeceraPrincipal(int &, int &, int &);
void imprimirLinea(char, int);
void imprimirFechasLimite(int &, int &, int &);
int leerFecha();
int juntarFecha(int, int, int);
void imprimirReporte(int, int, int);
int elegirFechaLimite(char, int, int, int);
void corregirNombre(char []);
char convertirMayuscula(char);
void imprimirUsuario(int, char, char *, int);
void imprimirCabeceraUsuario(int, char, char *);
void imprimirCategoria(char);
int imprimirLibro(int, int, char, double &);
void imprimirFechaDeRetiro(int, int, int);
void imprimirObservacion(int, int, int, int, double, char, int &, double &);
double calcularMulta(double, char);
double calcularPorcentaje(double, double);
bool finDeLectura();
void imprimirResumen(int, double);

#endif /* FUNCIONESAUXILIARES_H */

