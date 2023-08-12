#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Laboratorio04_Funciones.h"
#include "FuncionesDeArchivos.h"
#define MAX 100
#define MAX_LINEA 58
#define INCREMENTO 5

void leerMedicos(char **&codMed, char **&nombMed, double *&tarifas) {
    ifstream archMedicos;
    abrirArchivoLectura(archMedicos, "RelacionMedicos.csv");
    int numDat=0;
    char *buffC[MAX], *buffN[MAX];
    double buffT[MAX];    
    while (true) {
        buffC[numDat] = leerCadena(archMedicos, ',');
        if (archMedicos.eof()) break;
        buffN[numDat] = leerCadena(archMedicos, ',');
        leerCadena(archMedicos, ',');
        archMedicos>>buffT[numDat];
        archMedicos.get();
        numDat++;
    }    
    cargarMedicosExactos(codMed, nombMed, tarifas, buffC, buffN, buffT, numDat);
}

void cargarMedicosExactos(char **&codMed, char **&nombMed, double *&tarifas, 
        char **buffC, char **buffN, double *buffT, int numDat) {
    codMed = new char*[numDat+1];
    nombMed = new char*[numDat+1];
    tarifas = new double[numDat+1];
    for (int i=0; i<numDat; i++) {
        codMed[i]=buffC[i];        
        nombMed[i]=buffN[i];        
        tarifas[i]=buffT[i];        
    }   
    codMed[numDat]=nullptr;
    nombMed[numDat]=nullptr;
    tarifas[numDat]=0;
}

char *leerCadena(ifstream &arch, char delim='\n') {
    char buff[60], *cad;
    arch.getline(buff, 60, delim);    
    cad = new char[strlen(buff)+1];
    strcpy(cad, buff);
    return cad;
}

void repMedicos(char **codMed, char **nombMed, double *tarifas) {
    ofstream archReporte;
    abrirArchivoEscritura(archReporte, "ReporteMedicos.csv");
    imprimirReporteMedicos(archReporte, codMed, nombMed, tarifas);
}

void imprimirReporteMedicos(ofstream &arch, char **codMed, char **nombMed, 
        double *tarifas) {
    arch.precision(2);
    arch<<fixed;
    imprimirCabeceraMedicos(arch);
    for (int i=0; codMed[i]; i++)
        arch<<left<<setw(8)<<codMed[i]<<setw(43)<<nombMed[i]<<tarifas[i]<<endl;
}

void imprimirCabeceraMedicos(ofstream &arch) {
    arch<<"Codigo"<<setw(8)<<"Nombre"<<setw(44)<<"Tarifas"<<endl;
    imprimirLinea(arch, '=', MAX_LINEA);
}

void imprimirLinea(ofstream &arch, char c, int n) {
    for (int i=0; i<n; i++) arch.put(c);    
    arch.put('\n');
}

void leerAtenciones(char **codMed, int **&codPac, char ***&nombPac, 
        double **&porcPac, int **&veces) {
    ifstream archPacientes;
    abrirArchivoLectura(archPacientes, "Pacientes-Atencion.csv");
    int nd=0;
    while (codMed[nd]) nd++;
    codPac = new int*[nd+1]{};    
    nombPac = new char**[nd+1]{};    
    porcPac = new double*[nd+1]{};    
    veces = new int*[nd+1]{};    
    cargarPacientesIncrementos(archPacientes, codMed, codPac, nombPac, porcPac, 
            veces);
}

void cargarPacientesIncrementos(ifstream &arch, char **codMed, int **&codPac, 
        char ***&nombPac, double **&porcPac, int **&veces) {
    int nd[MAX]{}, cap[MAX]{};     
    while (true) {
        leerCadena(arch, ',');
        if (arch.eof()) break;
        leerPacientes(arch, codMed, codPac, nombPac, porcPac, veces, nd, cap);
    }
}

void leerPacientes(ifstream &arch, char **codMed, int **&codPac, 
        char ***&nombPac, double **&porcPac, int **&veces, int *nd, int *cap) {
    int auxCP, pos;
    char auxE, *auxN, *auxCM;
    double auxP;
    while (true) {
        auxE = arch.get();
        arch.get();
        arch>>auxCP;
        arch.get();
        auxN = leerCadena(arch, ',');
        arch>>auxP;
        arch.get();
        auxCM = leerCadenaGet(arch, ',');
        if(auxCM[6]=='\n') auxCM[6]=0;
        pos = buscarMedico(codMed, auxCM);        
        // cout<<auxE<<"  "<<auxCP<<"  "<<auxP<<"  "<<auxCM<<endl;
        if (pos!=-1) 
            asignarPaciente(codPac[pos], nombPac[pos], porcPac[pos], veces[pos], 
                    nd[pos], cap[pos], auxCP, auxN, auxP);
        if (arch.get()=='\n' || arch.eof()) break;
    }
}

char *leerCadenaGet(ifstream &arch, char delim='\n') {
    char buff[60], *cad;    
    arch.get(buff, 60, delim);    
    cad = new char[strlen(buff)+1];
    strcpy(cad, buff);
    return cad;
}

int buscarMedico(char **codMed, char *codigo) {
    for (int i=0; codMed[i]; i++)
        if (strcmp(codMed[i], codigo)==0) return i;
    return -1;
}

void asignarPaciente(int *&codPac, char **&nombPac, double *&porcPac, 
        int *&veces, int &nd, int &cap, int auxCP, char *auxN, double auxP) {
    int pos=nd;
    for (int i=0; i<nd; i++)
        if (codPac[i]==auxCP) {
            pos=i;
            break;
        }
    if (pos==nd) {
        if (nd==cap)
            aumentarEspacios(codPac, nombPac, porcPac, veces, nd, cap);
        codPac[nd]=0;
        codPac[nd-1]=auxCP;
        nombPac[nd]=nullptr;
        nombPac[nd-1]=auxN;
        porcPac[nd]=0.0;
        porcPac[nd-1]=auxP;
        veces[nd]=0;
        veces[nd-1]=1;
        nd++;
    } else {
        veces[pos]++;
    }
}

void aumentarEspacios(int *&codPac, char **&nombPac, double *&porcPac, 
        int *&veces, int &nd, int &cap) {
    int *auxC, *auxV;
    char **auxN;
    double *auxP;
    cap+=INCREMENTO;
    if (codPac==nullptr) {
        codPac = new int[cap];
        nombPac = new char*[cap];
        porcPac = new double[cap];
        veces = new int[cap];
        nd=1;
    } else {
        auxC = new int[cap];
        auxN = new char*[cap];
        auxP = new double[cap];
        auxV = new int[cap];
        for (int i=0; i<nd; i++) {
            auxC[i] = codPac[i];            
            auxN[i] = nombPac[i];            
            auxP[i] = porcPac[i];   
            auxV[i] = veces[i];
        }
        delete codPac;
        delete nombPac;
        delete porcPac;
        delete veces;
        codPac = auxC;
        nombPac = auxN;
        porcPac = auxP;
        veces = auxV;
    }
}

void repDeIngresos(char **codMed, char **nombMed, double *tarifas, int **codPac, 
        char ***nombPac, double **porcPac, int **veces) {
    ofstream archReporte;
    abrirArchivoEscritura(archReporte, "ReporteDeIngresos.txt");
    ifstream archMedicos;
    abrirArchivoLectura(archMedicos, "Medicos.csv");
    imprimirReporteDeIngresos(archReporte, archMedicos, codMed, nombMed, 
            tarifas, codPac, nombPac, porcPac, veces);
}

void imprimirReporteDeIngresos(ofstream &archOut, ifstream &archIn, char **codMed, 
        char **nombMed, double *tarifas, int **codPac, char ***nombPac, 
        double **porcPac, int **veces) {
    int pos;
    char *codigo;
    while (true) {
        codigo = leerCadena(archIn);
        if (archIn.eof()) break;
        pos = buscarMedico(codMed, codigo);
        if (pos!=-1)
            imprimirMedico(archOut, codMed[pos], nombMed[pos], tarifas[pos], 
                    codPac[pos], nombPac[pos], porcPac[pos], veces[pos]);
    }
}

void imprimirMedico(ofstream &arch, char *codMed, char *nombMed, double tarifas, 
        int *codPac, char **nombPac, double *porcPac, int *veces) {
    arch.precision(2);
    arch<<fixed;
    arch<<"Medico: "<<nombMed<<endl;
    arch<<"Codigo: "<<codMed<<endl;
    arch<<"Honorarios por cita: "<<tarifas<<endl;
    imprimirPacientes(arch, codPac, nombPac, porcPac, veces, tarifas);
}

void imprimirPacientes(ofstream &arch, int *codPac, char **nombPac, 
        double *porcPac, int *veces, double tarifas) {
    imprimirCabeceraPacientes(arch);
    double montoTotal=0, montoSolicitado=0, total, pago, seguro;
    int totalCitas=0;
    for (int i=0; codPac[i]; i++) {
        arch<<i+1<<")";
        if (i<9) arch<<' ';
        total = veces[i]*tarifas;
        pago = calcularPorcentaje(total, porcPac[i]);
        seguro = total-pago;
        arch<<setw(13)<<codPac[i]<<setw(10)<<veces[i]<<setw(13)<<pago<<setw(13)
                <<seguro<<endl;
        montoTotal += pago;
        montoSolicitado += seguro;
        totalCitas++;
    }
    imprimirResumen(arch, montoTotal, montoSolicitado, totalCitas);
}

void imprimirCabeceraPacientes(ofstream &arch) {        
    imprimirLinea(arch, '=', MAX_LINEA);
    arch<<"Pacientes atendidos:"<<endl;
    imprimirLinea(arch, '-', MAX_LINEA);
    arch<<"No."<<setw(15)<<"Paciente"<<setw(10)<<"Veces"<<setw(9)<<"Pago"
            <<setw(15)<<"Seguro"<<endl;
}

double calcularPorcentaje(double valor, double porcentaje) {
    return valor*porcentaje/100;    
}

void imprimirResumen(ofstream &arch, double montoT, double montoS, int totalC) {
    imprimirLinea(arch, '=', MAX_LINEA); 
    arch<<right<<"Monto total recibido por pacientes:"<<setw(10)<<montoT<<endl;
    arch<<"Monto a solicitar al seguro:"<<setw(17)<<montoS<<endl;
    arch<<"Total de citas atendidas:"<<setw(17)<<totalC<<endl;
    imprimirLinea(arch, '=', MAX_LINEA);
}