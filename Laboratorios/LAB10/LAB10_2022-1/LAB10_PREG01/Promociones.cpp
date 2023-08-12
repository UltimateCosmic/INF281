/* 
 * File:   Promociones.cpp
 * Author: aml
 * 
 * Created on 26 de junio de 2023, 09:57 AM
 */

#include <iostream>
using namespace std;

#include "Promociones.h"

void Promociones::leepedidos() {
    ifstream arch("pedidos5.csv", ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo pedidos5.csv"<<endl;
        exit(1);
    }
    lpedidos.crearLista(arch);
}

void Promociones::imprimepedidos() {
    ofstream arch("ReporteDePrueba.txt", ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo ReporteDePrueba.txt"<<endl;
        exit(1);
    }
    lpedidos.imprimeLista(arch);
}

