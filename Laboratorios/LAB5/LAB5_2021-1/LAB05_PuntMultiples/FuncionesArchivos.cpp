#include <iostream>
#include <fstream>
using namespace std;

#include "FuncionesArchivos.h"

void abrirArchivoEntrada(ifstream &arch, const char *nombre) {
    arch.open(nombre, ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombre<<endl;
        exit(1);
    }
}

void abrirArchivoSalida(ofstream &arch, const char *nombre) {
    arch.open(nombre, ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombre<<endl;
        exit(1);
    }
}

