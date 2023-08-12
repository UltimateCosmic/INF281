/* 
 * Proyecto:    LAB1_2021-1
 * Archivo:     FuncionesAuxiliares.h
 * Autor:       CosmoDev
 *
 * Creado el 2 de abril de 2023, 12:33 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void imprimirCabeceraPrincipal();
void imprimirReporteDeReguladora();
void imprimirReporteConductor(int, char []);
void imprimirCabeceraSecundaria();
void imprimirLinea(char, int);
void imprimirConductor(int, char []);
void leerInfraccion(char [], int &, int &, int &, char [], char [], double &);
void imprimirFecha(int, int, int);
void imprimirDetallesInfraccion(int &, int &, int &, int &, int &, int &, 
        double &, double &, double &, char [], double);
void imprimirInfraccion(int &, int &, int &, int &, int &, int &, double &, 
        double &, double &, char[], int, int, int, char[], double, int);
bool verificarFinDeInfracciones();
void imprimirResumen(int, int, int, int, int, int, double, double, double);
void imprimirCabeceraResumen();
void imprimirTotal(int, double, int);

#endif /* FUNCIONESAUXILIARES_H */

