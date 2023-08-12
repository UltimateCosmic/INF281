/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.cpp
 * Author: alulab14
 * 
 * Created on 30 de junio de 2023, 08:16 AM
 */

#include "Arbol.h"

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::~Arbol() {
    borrarArbol(raiz);
}

void Arbol::borrarArbol(class Nodo *arbol) {
    if (arbol) {
        borrarArbol(arbol->izq);
        borrarArbol(arbol->der);
        delete arbol;
    }    
}

void Arbol::inserta(class Boleta &bole) {
    insertaArbol(raiz, bole);
}

void Arbol::insertaArbol(class Nodo *&arbol, class Boleta &bole) {
    if (arbol==nullptr) {
        arbol = new class Nodo;
        arbol->dboleta = bole;
        return;
    }
    if ((arbol->dboleta.cmp(bole))>0)
        insertaArbol(arbol->der, bole);
    else
        insertaArbol(arbol->izq, bole);    
}

void Arbol::imprimir(ofstream &arch) {
    imprimirArbol(raiz, arch);
}

void Arbol::imprimirArbol(class Nodo *arbol, ofstream &arch) {
    if (arbol==nullptr) return;
    imprimirArbol(arbol->der, arch);
    arbol->dboleta.imprimeLinea(arch);
    imprimirArbol(arbol->izq, arch);
}

