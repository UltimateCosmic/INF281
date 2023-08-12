#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

#include "BibliotecaMemoriaDinamica.h"
#define MAX_LINEA 59

void cargarConductores(int *&licencia, char **&conductor) {
    ifstream arch("Conductores.csv", ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo Conductores.csv"<<endl;
        exit(1);
    }    
    int buffLicencia[200], numDat=0;
    char *buffConductor[200];    
    while (true) {
        arch>>buffLicencia[numDat];
        if (arch.eof()) break;        
        buffConductor[numDat] = leerCadena(arch);
        numDat++;
    }
    cargarConductoresExactos(licencia, conductor, buffLicencia, buffConductor, 
            numDat);
}

char *leerCadena(ifstream &arch) {
    char buffCad[60], *nombre;
    arch.get();
    arch.getline(buffCad, 60);
    nombre = new char[strlen(buffCad)+1];
    strcpy(nombre, buffCad);
    return nombre;
}

void cargarConductoresExactos(int *&licencia, char **&conductor, 
        int buffLicencia[], char *buffConductor[], int numDat) {    
    licencia = new int[numDat+1];
    conductor = new char*[numDat+1];
    for (int i=0; i<numDat; i++) {
        licencia[i] = buffLicencia[i];
        conductor[i] = buffConductor[i];        
    }
    licencia[numDat]=0;
    conductor[numDat]=nullptr;
}

void reporteConductores(int *licencia, char **conductor) {
    for (int i=0; licencia[i]; i++) {
        cout.fill('0');
        cout<<right<<setw(3)<<i<<") ";
        cout.fill(' ');
        cout<<left<<setw(10)<<licencia[i]<<conductor[i]<<endl;
    }
}

void cargarInfracciones(int *&infraccion, char *&gravedad, double *&multa) {    
    ifstream arch("Infracciones.csv", ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo Infracciones.csv"<<endl;
        exit(1);
    }    
    int buffInfraccion[200], numDat=0;
    char buffGravedad[200];
    double buffMulta[200];
    while (true) {
        arch>>buffInfraccion[numDat];
        if (arch.eof()) break;        
        buffGravedad[numDat] = omitirCadena(arch);
        arch>>buffMulta[numDat];
        numDat++;  
    }
    cargarInfraccionesExactos(infraccion, gravedad, multa, buffInfraccion, 
            buffGravedad, buffMulta, numDat);
}

char omitirCadena(ifstream &arch) {
    char cad[300], gravedad[15];
    arch.get();
    arch.getline(cad, 300, ',');
    arch.getline(gravedad, 15, ',');
    return gravedad[0];
}

void cargarInfraccionesExactos(int *&infraccion, char *&gravedad, 
        double *&multa, int buffInfraccion[], char buffGravedad[], 
        double buffMulta[], int numDat) {
    infraccion = new int[numDat+1];
    gravedad = new char[numDat+1];
    multa = new double[numDat+1];
    for (int i=0; i<numDat; i++) {
        infraccion[i] = buffInfraccion[i];       
        gravedad[i] = buffGravedad[i];       
        multa[i] = buffMulta[i];       
    }
    infraccion[numDat]=0;
    gravedad[numDat]=0;
    multa[numDat]=0;
}

void reporteInfracciones(int *infraccion, char *gravedad, double *multa) {
    cout.precision(2);
    cout<<fixed;
    for (int i=0; infraccion[i]; i++)
        cout<<left<<setw(5)<<infraccion[i]<<setw(3)<<gravedad[i]<<multa[i]<<endl;    
}

void reporteDeFaltas(int *licencia, char **conductor, int *infraccion, 
        char *gravedad, double *multa) {
    ofstream out("Reporte.txt", ios::out);
    if (not out.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    reporteDeGravedad(out, licencia, conductor, infraccion, gravedad, multa, 'L');    
    reporteDeGravedad(out, licencia, conductor, infraccion, gravedad, multa, 'G');    
    reporteDeGravedad(out, licencia, conductor, infraccion, gravedad, multa, 'M');    
}

void reporteDeGravedad(ofstream &out, int *licencia, char **conductor, 
        int *infraccion, char *gravedad, double *multa, const char g) {
    ifstream arch("RegistroDeFaltas.csv", ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo RegistroDeFaltas.csv"<<endl;
        exit(1);
    }    
    imprimirCabecera(out, g);
    leerFaltas(arch, out, licencia, conductor, infraccion, gravedad, multa, g);
    imprimirLinea(out, '*', MAX_LINEA);
}  

void imprimirCabecera(ofstream &arch, const char gravedad) {
    switch (gravedad) {        
        case 'L':
            arch<<"FALTAS LEVES"<<endl;
            break;
        case 'G':
            arch<<"FALTAS GRAVES"<<endl;
            break;   
        case 'M':
            arch<<"FALTAS MUY GRAVES"<<endl;
            break;
    }    
    imprimirLinea(arch, '=', MAX_LINEA);
    arch<<"No."<<setw(12)<<"Licencia"<<setw(13)<<"Placa"<<setw(15)<<"Cantidad"
            <<setw(12)<<"Monto"<<endl;
    imprimirLinea(arch, '-', MAX_LINEA);    
}

void imprimirLinea(ofstream &arch, char c, int n) {
    for (int i=0; i<n; i++) arch.put(c);  
    arch.put('\n');
}

void leerFaltas(ifstream &arch, ofstream &out, int *licencia, char **conductor, 
        int *infraccion, char *gravedad, double *multa, const char g) {    
    char **placa;
    int *cantidad, numDat=0, lic, pos, inf, posG;
    double *monto;    
    while (licencia[numDat]) numDat++;    
    placa = new char*[numDat+1];
    cantidad = new int[numDat+1]{};
    monto = new double[numDat+1]{};    
    while (true) {
        arch>>lic;
        if (arch.eof()) break;
        pos = buscarConductor(licencia, lic);
        if (pos!=-1) {
            placa[pos] = leerCadenaComa(arch);
            saltearFecha(arch);
            arch>>inf;
            posG = buscarGravedad(infraccion, inf);
            if (gravedad[posG]==g) {                
                cantidad[pos]++;
                monto[pos] += multa[posG];
            } 
        }
    }
    imprimirFaltas(out, licencia, placa, cantidad, monto);
}

int buscarConductor(int *licencia, int lic) {    
    for (int i=0; licencia[i]; i++)
        if (licencia[i]==lic) return i;
    return -1;
}

char *leerCadenaComa(ifstream &arch) {
    char buffPlaca[8], *placa;
    arch.get();
    arch.getline(buffPlaca, 8, ',');
    placa = new char[strlen(buffPlaca)+1];
    strcpy(placa, buffPlaca);
    return placa;
}

void saltearFecha(ifstream &arch) {
    int n;
    char c;
    arch>>n>>c>>n>>c>>n>>c;
}

int buscarGravedad(int *infraccion, int inf) {
    for (int i=0; infraccion[i]; i++)
        if (infraccion[i]==inf) return i;
    return -1;    
}

void imprimirFaltas(ofstream &arch, int *licencia, char **placa, int *cantidad,
        double *monto) {
    arch.precision(2);
    arch<<fixed;
    for (int i=0, j=1; licencia[i]; i++) {
        if (cantidad[i]) {
            arch<<left<<j<<setw(12)<<")"<<setw(15)<<licencia[i]<<setw(10)
                    <<placa[i]<<setw(10)<<monto[i]<<endl;
            j++;
        }
    }
}