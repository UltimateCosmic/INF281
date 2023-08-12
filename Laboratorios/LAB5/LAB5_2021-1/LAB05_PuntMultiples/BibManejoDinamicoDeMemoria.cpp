#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "BibManejoDinamicoDeMemoria.h"
#include "FuncionesArchivos.h"
#define INCREMENTO 5
#define MAX_LINEA 80
enum EMulta {L, G, MG};

void cargarConductores(int *&licencia, char **&conductor) {
    ifstream archConductores;
    abrirArchivoEntrada(archConductores, "Conductores.csv");
    licencia = nullptr;
    conductor = nullptr;
    leerConductores(archConductores, licencia, conductor);
}

void leerConductores(ifstream &arch, int *&licencia, char **&conductor) {
    int nd=0, cap=0, auxL;
    char *auxC;
    while (true) {
        arch>>auxL;
        if (arch.eof()) break;
        arch.get();
        auxC = leerCadena(arch);
        if (nd==cap)
            aumentarEspacios(licencia, conductor, nd, cap);
        licencia[nd] = 0;        
        licencia[nd-1] = auxL;
        conductor[nd] = nullptr;
        conductor[nd-1] = auxC;
        nd++;
    }
}

char *leerCadena(ifstream &arch, char delim) { 
    char buff[200], *cad;
    arch.getline(buff, 200, delim);
    cad = new char[strlen(buff)+1];
    strcpy(cad, buff);
    return cad;
}

void aumentarEspacios(int *&licencia, char **&conductor, int &numDat, int &cap) {
    int *auxL;
    char **auxC;
    cap += INCREMENTO;
    if (licencia==nullptr) {
        licencia = new int[cap];
        conductor = new char*[cap];
        licencia[0]=0;
        conductor[0]=nullptr;
        numDat=1;
    } else {
        auxL = new int[cap];
        auxC = new char*[cap];
        for (int i=0; i<numDat; i++) {
            auxL[i] = licencia[i];
            auxC[i] = conductor[i];
        }
        delete licencia;
        delete conductor;
        licencia = auxL;
        conductor = auxC;
    }
}

void reporteConductores(int *licencia, char **conductor) {
    ofstream archReporte;
    abrirArchivoSalida(archReporte, "ReporteConductores.txt");
    imprimirConductores(archReporte, licencia, conductor);
}

void imprimirConductores(ofstream &arch, int *licencia, char **conductor) {
    imprimirCabeceraConductores(arch);   
    for (int i=0; licencia[i]; i++)
        arch<<licencia[i]<<"  "<<conductor[i]<<endl;
}

void imprimirCabeceraConductores(ofstream &arch) {
    arch<<"Licencia"<<setw(8)<<"Nombre"<<endl;
    imprimirLinea(arch, '=', MAX_LINEA-30);
}

void imprimirLinea(ofstream &arch, char c, int n) {
    for (int i=0; i<n; i++) arch.put(c);
    arch.put('\n');
}

void cargarFaltas(int *licencia, char ***&placa, int **&falta) {
    ifstream archFaltas;
    abrirArchivoEntrada(archFaltas, "RegistroDeFaltas.csv");
    int nd=0;
    while (licencia[nd]) nd++;
    placa = new char**[nd]{nullptr};
    falta = new int*[nd]{nullptr};
    leerFaltas(archFaltas, licencia, placa, falta);
}

void leerFaltas(ifstream &arch, int *licencia, char ***&placa, int **&falta) {
    int nd[200]={0}, cap[200]={0}, auxL, auxF, pos;
    char *auxP;
    while (true) {
        arch>>auxL;
        if (arch.eof()) break;
        arch.get();
        auxP = leerCadena(arch, ',');
        leerCadena(arch, ',');  // Saltar fecha
        arch>>auxF;
        pos = buscarConductor(licencia, auxL);   
        if (pos!=-1)
            agregarFalta(placa[pos], falta[pos], nd[pos], cap[pos], auxP, auxF);
    }    
}

int buscarConductor(int *licencia, int auxL) {
    for (int i=0; licencia[i]; i++)
        if (licencia[i]==auxL) return i;
    return -1;    
}

void agregarFalta(char **&placa, int *&falta, int &nd, int &cap, char *auxP, int auxF) {
    if(nd==cap)
        aumentarEspaciosFaltas(placa, falta, nd, cap);
    placa[nd]=nullptr;
    placa[nd-1]=auxP;
    falta[nd]=0;
    falta[nd-1]=auxF;
    nd++;
}

void aumentarEspaciosFaltas(char **&placa, int *&falta, int &numDat, int &cap) {
    int *auxF;
    char **auxP;
    cap += INCREMENTO;
    if (falta==nullptr) {
        falta = new int[cap];
        placa = new char*[cap];
        falta[0]=0;
        placa[0]=nullptr;
        numDat=1;
    } else {
        auxF = new int[cap];
        auxP = new char*[cap];
        for (int i=0; i<numDat; i++) {
            auxF[i] = falta[i];
            auxP[i] = placa[i];
        }
        delete placa;
        delete falta;
        placa = auxP;
        falta = auxF;
    }
}

void reporteFaltas(int *licencia, char **conductor, char ***placa, int **falta) {
    ofstream archReporte;
    abrirArchivoSalida(archReporte, "ReporteFaltas.txt");
    imprimirFaltas(archReporte, licencia, conductor, placa, falta);
}

void imprimirFaltas(ofstream &arch, int *licencia, char **conductor, 
        char ***placa, int **falta) {
    imprimirCabeceraConductores(arch);   
    for (int i=0; licencia[i]; i++) {
        arch<<licencia[i]<<"  "<<conductor[i]<<endl;
        if (placa[i]) imprimirFaltasDeConductor(arch, placa[i], falta[i]);
    }
}

void imprimirFaltasDeConductor(ofstream &arch, char **placa, int *falta) {
    imprimirCabeceraFaltas(arch);   
    for (int i=0; falta[i]; i++)
        arch<<setw(15)<<placa[i]<<"  "<<falta[i]<<endl;
}

void imprimirCabeceraFaltas(ofstream &arch) {
    arch<<setw(13)<<"Placa"<<setw(9)<<"Falta"<<endl;
    arch<<setw(8)<<' ';
    imprimirLinea(arch, '=', MAX_LINEA-38);
}

void resumenMultas(int *licencia, int **falta, double **&multa) {
    int nd=0;
    while (licencia[nd]) nd++;
    multa = new double*[nd];
    for (int i=0; i<nd; i++)
        multa[i] = new double[3]{};
    leerMultas(licencia, falta, multa);
}

void leerMultas(int *licencia, int **falta, double **&multa) {
    for (int i=0; licencia[i]; i++)
        if (falta[i])
            for (int j=0; falta[i][j]; j++)
                agregarMulta(falta[i][j], multa[i]);
}

void agregarMulta(int falta, double *&multa) {
    ifstream arch;
    abrirArchivoEntrada(arch, "Infracciones.csv");
    int i;
    char gravedad;
    double monto = buscarMulta(arch, falta, gravedad);
    if (monto<0.0001) return;
    switch (gravedad) {
        case 'L':
            i=0;
            break;
        case 'G':
            i=1;
            break;
        case 'M':
            i=2;
            break;
    }
    multa[i]+=monto;
}

double buscarMulta(ifstream &arch, int falta, char &gravedad) {
    int auxF;
    char *auxG;
    double auxM;
    while (true) {
        arch>>auxF;
        if (arch.eof()) break;
        arch.get();
        leerCadena(arch, ',');
        auxG = leerCadena(arch, ',');
        arch>>auxM;
        if (falta==auxF) {
            gravedad = auxG[0];
            return auxM;
        }
    }    
    return -1;
}

void reporteMultas(int *licencia, char **conductor, double **multa) {
    ofstream archReporte;
    abrirArchivoSalida(archReporte, "ReporteMultas.txt");
    imprimirMultas(archReporte, licencia, conductor, multa);
}

void imprimirMultas(ofstream &arch, int *licencia, char **conductor, 
        double **multa) {    
    arch.precision(2);
    arch<<fixed;
    imprimirCabeceraConductores(arch);   
    for (int i=0; licencia[i]; i++) {
        arch<<licencia[i]<<"  "<<conductor[i]<<endl;
        arch<<"    * Multa Leves:      "<<multa[i][0]<<endl;
        arch<<"    * Multa Graves:     "<<multa[i][1]<<endl;
        arch<<"    * Multa Muy Graves: "<<multa[i][2]<<endl;
    }
}
