#include <iostream>
#include <fstream>
using namespace std;

#include "FuncionesDeArchivo.h"

void abrirArchivoLectura(ifstream &arch, const char *nombArch) {
    arch.open(nombArch, ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
}

void abrirArchivoEscritura(ofstream &arch, const char *nombArch) {
    arch.open(nombArch, ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
}