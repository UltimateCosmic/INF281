#include <iostream>
#include <fstream>
using namespace std;

#include "BibliotecaPilaGenerica.h"
#include "PilaConEnteros.h"

int cmpnumero(const void *a, const void *b) {
    void **av = (void**)a, **bv = (void**)b;
    int *num1 = (int*)(*av), *num2 = (int*)(*bv);
    return *num2 - *num1;
} 

void *leenumero(ifstream &arch) {
    int xnum;
    int *numero;
    arch>>num;
    if(arch.eof())return nullptr;
    numero = new int{num};
    return numero;
}

void imprimenumero(void *d, ofstream &arch) {
    int *dato = (int *)d;
    arch<<*dato<<endl;
}


void cargaarreglo(void *&a, int (*cmp)(const void *, const void *),
        void *(*lee)(ifstream &), const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"Error no se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void *reg;
    void **buff = new void*[50]{};
    int numDat = 0;
    void **arreglo;
    while(true){
        reg = lee(arch);
        if(arch.eof())break;
        buff[numDat] = reg;
        numDat++;
    }
    arreglo = new void*[numDat+1];
    arreglo[numDat] = nullptr;
    for(int i = 0; i < numDat; i++){
        arreglo[i] = buff[i];
    }
    delete buff;
    a = arreglo;
    qsort(a, numDat, sizeof(void*), cmp);
}

void cargaPila(void *&p, void *a) {
    void **arr = (void**)a;
    int *dato;
    construirPila(p);
    for (int i=0; arr[i]; i++) {
        dato = (int*)(arr[i]);
        push(p, dato);
    }    
}

void muevepila(void *&pilaini, void *&pilafin) {
    void *pilaAux, **aux = (void**)pilaini, **nodo;
    int numDat = 0;
    nodo = (void**)(aux[0]);
    while(nodo != nullptr){
        numDat++;
        nodo = (void**)(nodo[1]);
    }
    construirPila(pilaAux);
    construirPila(pilafin);
    hanoi(numDat, pilaini, pilaAux, pilafin);
}

void hanoi(int numDat, void *&pilaini, void *&pilaAux, void *&pilafin){
    int *dato;
    if(numDat == 1){
        dato = (int*)pop(pilaini);
        push(pilafin, dato);
    }
    else{
        hanoi(numDat-1, pilaini, pilafin, pilaAux);
        dato = (int*)pop(pilaini);
        push(pilafin, dato);
        hanoi(numDat-1, pilaAux, pilaini, pilafin);
    }
}