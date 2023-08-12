/* 
 * Proyecto:    LAB06_TrasladaPila
 * Archivo:     PilaConEnteros.h
 * Autor:       CosmoDev
 *
 * Creado el 1 de junio de 2023, 11:13 PM
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H

int cmpnumero(const void *, const void *);
void *leenumero(ifstream &);
void cargaarreglo(void *&, int (*)(const void *, const void *), 
        void *(*)(ifstream &), const char *);
void cargaPila(void *&, void *);
void imprimenumero(void *, ofstream &);
void muevepila(void *&, void *&);
void hanoi(int, void *&, void *&, void *&);

#endif /* PILACONENTEROS_H */

