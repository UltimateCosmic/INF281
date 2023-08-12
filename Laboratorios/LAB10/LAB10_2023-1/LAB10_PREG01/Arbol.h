/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.h
 * Author: alulab14
 *
 * Created on 30 de junio de 2023, 08:16 AM
 */

#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"
#include "Escala.h"
#include "Boleta.h"

class Arbol {
private:
    class Nodo *raiz;
    class Escala lescala[10];
    void borrarArbol(class Nodo *);
    void insertaArbol(class Nodo *&, class Boleta &);
    void imprimirArbol(class Nodo *arbol, ofstream &arch);
public:
    Arbol();
    virtual ~Arbol();    
    void inserta(class Boleta &bole);
    void imprimir(ofstream &arch);
};

#endif /* ARBOL_H */

