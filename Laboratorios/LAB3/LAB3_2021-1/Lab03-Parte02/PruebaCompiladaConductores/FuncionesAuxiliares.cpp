#include <iostream>
#include <fstream>
using namespace std;

#include "OperadoresSobrecargados.h"
#include "FuncionesAuxiliares.h"
#include "StructConductor.h"
#include "StructInfraccion.h"
#include "StructInfraccionEstab.h"

void leerConductores(const char *nombArchivo, struct ConductorSt conductor[], 
        int &numConductores) {
    ifstream input(nombArchivo, ios::in);
    if (not input) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchivo<<endl;
        exit(1);
    }
    while (true) {
        if (not (input>>conductor[numConductores])) break;
        numConductores++;
    }    
}

void leerFaltas(const char *nombArchivo, struct ConductorSt conductor[], 
        int numConductores) {
    ifstream input(nombArchivo, ios::in);
    if (not input) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchivo<<endl;
        exit(1);
    }
    struct InfraccionSt infraccion;
    while (true) {
        if (not (input>>infraccion)) break;
        asignarFalta(infraccion, conductor, numConductores);
    }
}

void asignarFalta(struct InfraccionSt infraccion, struct ConductorSt conductor[], 
        int numConductores) {
    for (int i=0; i<numConductores; i++) 
        if (infraccion.licencia==conductor[i].licencia) conductor[i]+infraccion;
}

void completarMulta(const char *nombArchivo, struct ConductorSt conductor[], 
        int numConductores) {    
    ifstream input(nombArchivo, ios::in);
    if (not input) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchivo<<endl;
        exit(1);
    }
    struct InfraccionEstabSt infraccionEstab;
    while (true) {
        if (not (input>>infraccionEstab)) break;
        asignarMulta(infraccionEstab, conductor, numConductores);
    }    
}

void asignarMulta(struct InfraccionEstabSt infraccionEstab, 
        struct ConductorSt conductor[], int numConductores) {    
    for (int i=0; i<numConductores; i++) conductor[i]+infraccionEstab;
}

void calculaMonto(struct ConductorSt conductor[], int numConductores) {    
    for (int i=0; i<numConductores; i++)
        ++(conductor[i]);    
}

void emitirReporte(const char *nombArchivo, struct ConductorSt conductor[], 
        int numConductores) {
    ofstream output(nombArchivo, ios::out);
    if (not output) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchivo<<endl;
        exit(1);
    }
    for (int i=0; i<numConductores; i++) 
        output<<conductor[i];
}

void aplicarAmnistia(struct ConductorSt conductor[], int numConductores) {    
    int dd, mm, aaaa, fecha;
    cout<<"Ingrese la fecha (dd mm aaaa): ";
    cin>>dd>>mm>>aaaa;
    fecha = juntarFecha(dd, mm, aaaa);
    for (int i=0; i<numConductores; i++) 
        conductor[i]*fecha;
}

int juntarFecha(int dd, int mm, int aaaa) {
    return aaaa*10000 + mm*100 + dd;
}