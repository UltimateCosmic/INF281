/* 
 * Proyecto:    Pregunta01PunterosMultiples
 * Archivo:     FuncionesExamen01Pregunta01.h
 * Autor:       CosmoDev
 *
 * Creado el 15 de mayo de 2023, 08:52 AM
 */

#ifndef FUNCIONESEXAMEN01PREGUNTA01_H
#define FUNCIONESEXAMEN01PREGUNTA01_H

void CargarProductosPedidos(int **&, char **&, int **&, const char *);
void leerProductosPedidos(ifstream &, int **&, char **&, int **&);
int buscarPosProd(int, int **, int);
int retornarCod(int *);
void leerProductos(ifstream &, int, int *&, char *&, int *&, int, int);
char *leerCadena(ifstream &, char);
int juntarFecha(int, int, int);
void cargarProductosExactos(int **&, char **&, int **&, int **, char **, int **, 
        int, int);
void PruebaProductosPedidos(int **, char **, int **, const char *);
void imprimirProductosPedidos(ofstream &, int **, char **, int **);
void imprimirProducto(ofstream &, int *, char *);
void imprimirPedido(ofstream &, int *);
void ordenarPedidos(int **&);
void quickSortPedidos(int **&, int, int);
void cambiar(int *&, int *&);
bool enDesordenFecha(int *&, int *&);
void asignarPedidos(int ***&, int **, int **);
int buscarPosDNI(int *, int ***);
int retornarDNI(int **);
void agregarEspacios(int ***&, int &, int &);
int buscarTelefono(int, int **);
int retornarDNI(int *);
int retornarTelefono(int *);
void agregarEspacios(int *&, int &, int &);
int buscarPosProd(int **, int);

#endif /* FUNCIONESEXAMEN01PREGUNTA01_H */

