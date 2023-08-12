/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaDoble.cpp
 * Author: alulab14
 * 
 * Created on 11 de julio de 2023, 08:29 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "ListaDoble.h"
#include "Nodo.h"
#define MAX_LINEA 60

ListaDoble::ListaDoble() {
    inicio = fin = nullptr;
}

void ListaDoble::insertarNodo(ifstream &arch) {    
    class Nodo *nuevo = new Nodo;    
    nuevo->leerAlumno(arch);
    if (arch.eof()) return;
    agregarNodo(nuevo);
}

void ListaDoble::agregarNodo(class Nodo *nuevo) {    
    Nodo *p, *rec = nullptr;
    p = inicio;
    while (p) {
        if (p->dato.obtenerCodigo()>=nuevo->dato.obtenerCodigo()) break;
        rec = p;
        p = p->siguiente;
    }
    nuevo->siguiente = p;
    nuevo->anterior = rec;
    if (rec==nullptr) {
        inicio = nuevo;
        if (p==nullptr) fin = nuevo;
    } else {
        rec->siguiente = nuevo;
        if (rec==fin) fin = nuevo;
    }
}

void ListaDoble::insertarNota(class Nota &notaAlumno, int codigo) {    
    Nodo *rec = inicio;
    while (rec) {
        if (rec->dato.obtenerCodigo()==codigo) {
            rec->dato.insertarNota(notaAlumno);
            break;
        }
        rec = rec->siguiente;
    }
}

void ListaDoble::imprimeLista(ofstream &arch) {    
    Nodo *rec = inicio;
    arch<<right<<"Codigo"<<setw(13)<<"Nombre"<<setw(40)<<"Promedio"<<endl;
    imprimeLinea('=', MAX_LINEA, arch);
    while (rec) {
        rec->dato.imprimirAlumno(arch);
        rec = rec->siguiente;
    }
}

void ListaDoble::imprimeLinea(char c, int n, ofstream &arch) {    
    for (int i=0; i<n; i++) arch.put(c);
    arch.put('\n');
}