/* 
 * Proyecto:    Lab09_Deudas2022-1
 * Archivo:     Procesa.cpp
 * Autor:       CosmoDev
 *
 * Creado el 21 de junio de 2023, 11:27 PM
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "Procesa.h"

void Procesa::carga() {
    cargaPedidos("pedidos4.csv");
    cargaClientes("clientes3.csv");
}

void Procesa::cargaPedidos(const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numPed = 0;
    while (true) {
        arch>>lpedidos[numPed];
        if (arch.eof()) break;
        numPed++;
    }    
    lpedidos[numPed].SetCodigo(0);
}

void Procesa::cargaClientes(const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numCli = 0;
    while (true) {
        ldeudor[numCli].asignaCliente(arch);
        if (arch.eof()) break;
        numCli++;
    }
    // ldeudor[numCli] = nullptr;
}

void Procesa::muestra() {
    ofstream arch("ReporteDePrueba.txt", ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo ReporteDePrueba.txt"<<endl;
        exit(1);
    }
    muestraClientes(arch);
    // muestraPedidos(arch);
}

void Procesa::muestraClientes(ofstream &arch) {        
    for (int i=0; i<19; i++)
        ldeudor[i].imprimeCliente(arch);
}

