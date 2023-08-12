#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "BibliotecaPilaGenerica.h"
#include "PilaConEnteros.h"
#include "PilaConRegistros.h"

int cmpregistro(const void *a, const void *b) {
    void **ai = (void**)a, **bi = (void**)b;
    void **regA = (void**)(*ai), **regB = (void**)(*bi);
    double *pesoA = (double*)regA[2], *pesoB = (double*)regB[2];
    return *pesoB - *pesoA;
} 

void *leeregistro(ifstream &arch) {    
    int cod, *codigo = new int;
    char *nombre;
    double pe, *peso = new double;
    arch>>cod;
    if (arch.eof()) return nullptr;
    *codigo = cod;
    arch.get();
    nombre = leerCadena(arch);
    arch>>pe;
    *peso = pe;
    void **reg = new void*[3];
    reg[0] = codigo;
    reg[1] = nombre;
    reg[2] = peso;
    return reg;
}

char *leerCadena(ifstream &arch) {
    char buff[60], *cad;
    arch.getline(buff, 60, ',');
    cad = new char[strlen(buff)+1];
    strcpy(cad, buff);
    return cad;    
}

void imprimeregistro(void *d, ofstream &arch) {
    void **dato = (void **)d;
    int *codigo = (int *)dato[0];
    char *nombre = (char *)dato[1];
    double *peso = (double *)dato[2];
    arch.precision(2);
    arch<<fixed;
    arch<<setw(8)<<*codigo<<"     "<<left<<setw(35)<<nombre<<right<<setw(8)<<*peso<<endl;
}
