#include <iostream>
#include <fstream>
using namespace std;

#include "FuncionesDeArchivos.h"

void abrirArchivoLectura(ifstream &archivo, const char *nombre) {
    archivo.open(nombre, ios::in);
    if (not archivo.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombre<<endl;
        exit(1);
    }
}

void abrirArchivoEscritura(ofstream &archivo, const char *nombre) {
    archivo.open(nombre, ios::out);
    if (not archivo.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombre<<endl;
        exit(1);
    }
}

