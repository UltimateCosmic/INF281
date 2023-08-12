/* 
 * Proyecto:    Pregunta02PuntGenericos
 * Archivo:     PunterosGenericos.h
 * Autor:       CosmoDev
 *
 * Creado el 15 de mayo de 2023, 09:43 PM
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

void cargaproductos(void *&);
void leerProductos(ifstream &, void *&);
char *leerCadena(ifstream &, char);
void *cargarProducto(int, char *, double, int);
void cargapedidos(void *&);
void leerPedidos(ifstream &, void *&);
int juntarFecha(int, int, int);
void *cargarPedido(int, char *, int, int, int, char);
void procesaclientes(void *, void *, void *&);
void atenderPedidos(void *, void *);
void procesarPedido(void *, void *);
int buscarPosProducto(int, void *);
int retornarCodigo(void *);
int *retornarStock(void *);
void colocarDatosClientes(void *&, void *);
void leerClientes(ifstream &, void *&, void *);
void *leerRegCli(ifstream &, void *);
void *agregarPedidos(int, void *);
int retornarDni(void *);
void *agregarPedido(void *);
void imprimereporte(void *);
void imprimirLinea(ofstream &, char, int);
void imprimirCliente(ofstream &, void *);
void imprimirPedidos(ofstream &, void *);
void imprimirPedido(ofstream &, void *);

#endif /* PUNTEROSGENERICOS_H */

