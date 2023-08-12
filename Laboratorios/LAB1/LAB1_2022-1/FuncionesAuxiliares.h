/* 
 * Proyecto:    LAB1_2022-1
 * Archivo:     FuncionesAuxiliares.h
 * Autor:       CosmoDev
 *
 * Creado el 13 de abril de 2023, 08:49 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerDescuentos(double &, double &, double &, char []);
void imprimirReporteDeGastos(double, double, double, char []);
void imprimirCabeceraPrincipal();
void imprimirLinea(char, int);
void imprimirGastosDeCliente(int, char [], int, double, double, double, char [], 
        char [], double &, double &, char []);
char verificarCategoria(char []);
double seleccionarDescuento(char, double, double, double);
void imprimirCabeceraCliente(int, char [], int, char, double);
void corregirNombre(char []);
double verificarDescuento();
void imprimirProducto(int, char [], char [], double, double, double, double, int, 
        int, int, char [], double &, char [], double &, double &);
double calcularDescuento(double, double, double);
double hallarPorcentaje(double, double);
bool verificarFinDeProductos();
void imprimirTotal(double, double);
void imprimirDetallesFinales(char [], double, char [], double, char []);

#endif /* FUNCIONESAUXILIARES_H */

