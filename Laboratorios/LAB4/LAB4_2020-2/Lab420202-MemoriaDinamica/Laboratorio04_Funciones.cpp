#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Laboratorio04_Funciones.h"
#define MAX_LINEA 53

void cargarMedicos(char **&codigoMed, char **&medicos, double *&tarifas) {
    ifstream arch("RelacionMedicos.csv", ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo RelacionMedicos.csv"<<endl;
        exit(1);
    }
    leerMedicos(arch, codigoMed, medicos, tarifas);
}

void leerMedicos(ifstream &arch, char **&codigoMed, char **&medicos, 
        double *&tarifas) {
    int numDat=0;
    char *buffCodigo[50], *buffNombre[50];
    double buffTarifas[50];    
    while (true) {
        buffCodigo[numDat] = leerCadena(arch, ',');
        if (arch.eof()) break;
        buffNombre[numDat] = leerCadena(arch, ',');
        leerCadena(arch, ',');
        arch>>buffTarifas[numDat];  
        arch.get();    
        numDat++;        
    }
    exactosMedicos(codigoMed, medicos, tarifas, buffCodigo, buffNombre, 
            buffTarifas, numDat);
}

char *leerCadena(ifstream &arch) {
    char buffCad[60], *cad;
    arch.getline(buffCad, 60);
    cad = new char[strlen(buffCad)+1];
    strcpy(cad, buffCad);
    return cad;
}

char *leerCadena(ifstream &arch, char delim) {
    char buffCad[60], *cad;
    arch.getline(buffCad, 60, delim);
    cad = new char[strlen(buffCad)+1];
    strcpy(cad, buffCad);
    return cad;
}

char *leerCadena(ifstream &arch, int num, char delim) {
    char buffCad[60], *cad;
    arch.getline(buffCad, num, delim);
    cad = new char[strlen(buffCad)+1];
    strcpy(cad, buffCad);
    return cad;
}

void exactosMedicos(char **&codigoMed, char **&medicos, double *&tarifas, 
        char *buffCodigo[], char *buffNombre[], double buffTarifas[], int numDat) {
    codigoMed = new char*[numDat+1];
    medicos = new char*[numDat+1];
    tarifas = new double[numDat+1];
    for (int i=0; i<numDat; i++) {
        codigoMed[i]=buffCodigo[i];
        medicos[i]=buffNombre[i];
        tarifas[i]=buffTarifas[i];        
    }
    codigoMed[numDat]=nullptr;
    medicos[numDat]=nullptr;
    tarifas[numDat]=0.0;    
}

void reporteMedicos(char **codigoMed, char **medicos, double *tarifas) {
    for (int i=0; codigoMed[i]; i++) 
        cout<<left<<setw(10)<<codigoMed[i]<<setw(45)<<medicos[i]<<tarifas[i]<<endl;
}

void reporteDeIngresos(char **codigoMed, char **medicos, double *tarifas) {
    int *codigoPac, *veces;
    char **pacientes, codMed[7];
    double *porcentajes;    
    ifstream arch("Medicos.csv", ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo Medicos.csv"<<endl;
        exit(1);
    }
    ofstream out("ReporteDelMedico.txt", ios::out);
    if (not out.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo ReporteDelMedico.txt"<<endl;
        exit(1);
    }
    while (true) {
        arch>>codMed;
        if (arch.eof()) break;        
        cargarPacientes(codMed,codigoPac, pacientes, porcentajes,veces);
        reporteDelMedico(codMed, codigoMed, medicos, tarifas, codigoPac, 
                pacientes, porcentajes, veces, out);
        liberarEspacios(codigoPac, pacientes, porcentajes,veces);
    }
}

void cargarPacientes(char *codMed, int *&codigoPac, char **&pacientes, 
        double *&porcentajes, int *&veces) {
    ifstream arch("Pacientes-Atencion.csv", ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo Pacientes-Atencion.csv"<<endl;
        exit(1);
    }    
    int buffCodigoPac[100], buffVeces[100]{}, numDat=0, codPac, pos;
    char *buffPacientes[100], estado, *nombPac, *codMedA;
    double buffPorcentajes[100], porc;
    while (true) {
        leerCadena(arch, ',');
        if (arch.eof()) break;
        while (true) {
            estado=arch.get();
            arch.get();
            arch>>codPac;
            arch.get();
            nombPac=leerCadena(arch, ',');
            arch>>porc;
            arch.get();
            codMedA=leerCodMedico(arch);
            if (strcmp(codMed, codMedA)==0 && estado=='A') {
                pos = buscarPaciente(codPac, buffCodigoPac, numDat);
                if (pos==numDat) {
                    buffCodigoPac[pos]=codPac;
                    buffPacientes[pos]=nombPac;
                    buffPorcentajes[pos]=porc;
                    numDat++;
                }
                buffVeces[pos]++;
            }
            if (arch.get()=='\n') break;
        }
    }    
    reservarEspacios(codigoPac, pacientes, porcentajes, veces, buffCodigoPac, 
            buffPacientes, buffPorcentajes, buffVeces, numDat);
}

char *leerCodMedico(ifstream &arch) {
    int i;
    char *cod, c=arch.get();
    cod = new char[7];
    for (i=0; c!=',' && c!='\n'; i++) {
        cod[i]=c;
        c = arch.get();        
    }
    arch.unget();
    cod[i]=0;
    return cod;    
}

int buscarPaciente(int codPac, int *codigoPac, int numDat) {
    for (int i=0; i<numDat; i++)
        if (codPac==codigoPac[i])
            return i;
    return numDat;
}

void reservarEspacios(int *&codigoPac, char **&pacientes, double *&porcentajes, 
        int *&veces, int *buffCodigoPac, char **buffPacientes, 
        double *buffPorcentajes, int *buffVeces, int numDat) {
    codigoPac = new int[numDat+1]{};
    pacientes = new char*[numDat+1]{};
    porcentajes = new double[numDat+1]{};
    veces = new int[numDat+1]{};
    for (int i=0; i<numDat; i++) {
        codigoPac[i]=buffCodigoPac[i];        
        pacientes[i]=buffPacientes[i];        
        porcentajes[i]=buffPorcentajes[i];        
        veces[i]=buffVeces[i];        
    }
    codigoPac[numDat]=0;
    pacientes[numDat]=nullptr;
    porcentajes[numDat]=0.0;
    veces[numDat]=0;
}

bool leerFecha(ifstream &arch) {
    char *fecha, c;
    fecha=leerCadena(arch, ',');
}

void reporteDelMedico(char *codMed, char **codigoMed, char **medicos, 
        double *tarifas, int *codigoPac, char **pacientes, double *porcentajes, 
        int *veces, ofstream &out) {
    int pos = imprimirCabeceraMedico(codMed, codigoMed, medicos, tarifas, out);
    if (pos==-1) return;    
    imprimirCabeceraPacientes(out);
    double pago, seguro;
    out.precision(2);
    out<<fixed;
    for (int i=0; codigoPac[i]; i++) {
        out<<i+1<<")";
        if (i<9) out<<" ";
        calcularPagoYSeguro(porcentajes[i], tarifas[pos], pago, seguro, veces[i]);
        out<<left<<setw(7)<<" "<<setw(14)<<codigoPac[i]<<setw(11)<<pago
                <<setw(13)<<seguro<<veces[i]<<endl;
    } 
    imprimirLinea(out, '=', MAX_LINEA);
}

int imprimirCabeceraMedico(char *codMed, char **codigoMed, char **medicos, 
        double *tarifas, ofstream &arch) {
    int pos = buscarMedico(codMed, codigoMed);
    if (pos==-1) return -1;
    arch<<"Medico: "<<medicos[pos]<<endl;
    arch<<"Codigo: "<<codigoMed[pos]<<endl;
    arch<<"Honorarios por cita: "<<tarifas[pos]<<endl;
    imprimirLinea(arch, '=', MAX_LINEA);
    return pos;
}

int buscarMedico(char *codMed, char **codigoMed) {
    for (int i=0; codigoMed[i]; i++)
        if (strcmp(codMed,codigoMed[i])==0) return i;
    return -1;
}

void imprimirLinea(ofstream &arch, char c, int n) {
    for (int i=0; i<n; i++) arch.put(c);
    arch.put('\n');
}

void imprimirCabeceraPacientes(ofstream &arch) {
    arch<<"Pacientes atendidos:"<<endl;
    imprimirLinea(arch, '-', MAX_LINEA);
    arch<<right<<"No."<<setw(15)<<"Paciente"<<setw(10)<<"Pago"<<setw(13)
            <<"Seguro"<<setw(10)<<"Veces"<<endl;
}

void calcularPagoYSeguro(double porcentajes, double tarifa, double &pago, 
        double &seguro, int veces) {
    double total = veces*tarifa;
    pago = total*(porcentajes/100);
    seguro = total-pago;
}

void liberarEspacios(int *&codigoPac, char **&pacientes, double *&porcentajes, 
        int *&veces) {
    free(codigoPac);
    free(pacientes);
    free(porcentajes);
    free(veces);
}