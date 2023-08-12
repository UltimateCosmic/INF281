#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "BibliotecaPilaGenerica.h"
#include "PilaConEnteros.h"

void construirPila(void *&p){
    void **pila = new void*[2];
    int *cantElementos = new int{0};
    pila[0] = nullptr;
    pila[1] = cantElementos;
    p = pila;
}

bool pilaVacia(void *p){
    void **pila = (void**)p;
    return pila[0] == nullptr;
}

void *crearNuevoNodo(void *elementoPila, void *sgte){
    void **nuevoNodo = new void*[2];
    nuevoNodo[0] = elementoPila;
    nuevoNodo[1] = sgte;
    return nuevoNodo;
}

void push(void *p, void *d){
    void **pila = (void**)p, *nuevoNodo;
    int *cantElementos;
    nuevoNodo = crearNuevoNodo(d, pila[0]);
    pila[0] = nuevoNodo;
    cantElementos = (int*)(pila[1]);
    (*cantElementos)++;
    pila[1] = cantElementos;
}

void *pop(void *p){
    void *nodo, **elementoPila, **pila =(void**)p, *dato;
    int *cantElementos;
    nodo = pila[0]; //apunto al primer nodo de mi pila
    elementoPila = (void**)nodo; //casteo para poder usar indices
    dato = elementoPila[0]; //saco el dato del primer nodo de mi pila
    pila[0] = elementoPila[1]; //cambio el primer nodo de mi pila
    cantElementos = (int*)(pila[1]);
    (*cantElementos)--;
    pila[1] = cantElementos;
    delete elementoPila;
    return dato;
}

void imprimePila(void *p, void (*fImprime)(void *, ofstream &), 
        const char *nombArch){
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"Error no se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **nodo, **pila = (void**)p;
    if (not pilaVacia(p)) {
        arch<<"  Codigo"<<setw(25)<<"Nombre medicamento"<<setw(25)<<"Peso caja"<<endl;
        for(int i = 0; i < 120; i++) arch<<'=';
        arch<<endl;
        nodo = (void**)pila[0];
        while(nodo != nullptr){
            fImprime(nodo[0], arch);
            nodo = (void**)nodo[1];
        }   
    } else
        arch<<"La pila esta vacia"<<endl;
}

