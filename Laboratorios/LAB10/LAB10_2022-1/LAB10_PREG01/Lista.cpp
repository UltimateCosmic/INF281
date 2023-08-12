/* 
 * File:   Lista.cpp
 * Author: aml
 * 
 * Created on 26 de junio de 2023, 09:55 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Lista.h"
#include "PedidoEspecial.h"
#include "PedidoEventual.h"
#include "PedidoUsual.h"
#define MAX_LINEA 100

Lista::Lista() {
    lini = nullptr;
    lfin = nullptr;
}

Lista::~Lista() {
    class Nodo* sale;
    while (lini) {
        sale = lini;
        lini = lini->sig;
        delete sale;
    }
}

void Lista::crearLista(ifstream &arch) {
    int cod;
    class Nodo *nuevo;    
    while (true) {
        arch>>cod;
        if (arch.eof()) break;
        nuevo = new class Nodo;
        if (cod<400000)
            nuevo->ped = new class PedidoEspecial;
        else if (cod>=400000 && cod<600000)
            nuevo->ped = new class PedidoUsual;
        else
            nuevo->ped = new class PedidoEventual;
        nuevo->ped->SetCodigo(cod);
        nuevo->ped->lee(arch);
        insertar(nuevo);
    }    
}

void Lista::insertar(class Nodo* nuevo) {
    class Nodo *p = lini, *ant = nullptr;
    if (lini==nullptr)
        lini = lfin = nuevo;
    else {    
        while (p) {
            if (p->ped->GetDni() > nuevo->ped->GetDni() or 
                p->ped->GetDni() == nuevo->ped->GetDni() and 
                p->ped->GetFecha() > nuevo->ped->GetFecha()) break;
            ant = p;
            p = p->sig;
        }
        nuevo->sig = p;
        nuevo->ant = ant;
        if (ant!=nullptr) ant->sig = nuevo;
        else lini = nuevo;
        if (p!=nullptr) p->ant = nuevo;
        else lfin = nuevo;
    }
}

void Lista::imprimeLista(ofstream &arch) {
    class Nodo *p = lini;
    if (lini==nullptr)
        arch<<"No existe ningun elemento en la lista"<<endl;
    else {    
        arch.precision(2);
        arch<<fixed;
        imprimeCabecera(arch);
        while (p) {
            p->ped->imprime(arch);
            p = p->sig;
        }
    }
}

void Lista::imprimeCabecera(ofstream &arch) {    
    arch<<setw(50)<<"REPORTE DE PROMOCIONES"<<endl;
    imprimeLinea(arch, '=', MAX_LINEA);
}

void Lista::imprimeLinea(ofstream &arch, char c, int n) {    
    for (int i=0; i<n; i++) arch.put(c);
    arch.put('\n');
}

