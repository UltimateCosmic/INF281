/* 
 * Proyecto:    LAB06_TrasladaPila
 * Archivo:     BibliotecaPilaGenerica.h
 * Autor:       CosmoDev
 *
 * Creado el 1 de junio de 2023, 06:49 PM
 */

#ifndef BIBLIOTECAPILAGENERICA_H
#define BIBLIOTECAPILAGENERICA_H

void construirPila(void *&);
bool pilaVacia(void *);
void *crearNuevoNodo(void *, void *);
void push(void *, void *);
void *pop(void *);
void imprimePila(void *, void (*)(void *, ofstream &), const char *);

#endif /* BIBLIOTECAPILAGENERICA_H */

