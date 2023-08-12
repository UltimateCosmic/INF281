#include <iostream>
#include <fstream>
using namespace std;

#include "AperturaDeArchivos.h"

void abrirArchivoLectura(ifstream &arch, const char *nombre) {
    arch.open(nombre, ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombre<<endl;
        exit(1);
    }    
}

void abrirArchivoEscritura(ofstream &arch, const char *nombre) {
    arch.open(nombre, ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombre<<endl;
        exit(1);
    }    
}