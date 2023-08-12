#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "MetodoPorIncrementos.h"
#include "FuncionesDeArchivos.h"
#define MAX 100
#define INCREMENTO 5

void cargarCitas(const char *nombArch, char ***&medicoDatos, 
        double *&medicoTarifaHora, char ****&citaPaciente, int **&citaCantidad, 
        double ***&citaTiempoYPago) {
    ifstream archCitas;
    abrirArchivoLectura(archCitas, nombArch);    
    medicoDatos = nullptr;
    medicoTarifaHora = nullptr;
    citaPaciente = nullptr;
    citaCantidad = nullptr;
    citaTiempoYPago = nullptr;
    leerCitas(archCitas, medicoDatos, medicoTarifaHora, citaPaciente, 
            citaCantidad, citaTiempoYPago);
}

void leerCitas(ifstream &arch, char ***&medicoDatos, double *&medicoTarifaHora, 
        char ****&citaPaciente, int **&citaCantidad, double ***&citaTiempoYPago) {
    int nd=0, ndP[MAX]{}, cap=0, capP[MAX]{};
    char *nombPac, *codMed, *nombMed, *dniPac;
    double tarifa, tiempo;    
    while (true) {
        dniPac=leerCadena(arch, ',');
        if (arch.eof()) break;
        arch.get();
        nombPac = leerCadena(arch, ',');
        codMed = leerCadena(arch, ',');
        nombMed = leerCadena(arch, ',');
        arch>>tarifa;
        arch.get();
        leerCadena(arch, ',');  // Salteamos la fecha
        tiempo = leerTiempo(arch); 
        // cout<<dniPac<<"   "<<codMed<<"   "<<tiempo<<endl;        
        asignarCita(dniPac, nombPac, codMed, nombMed, tarifa, tiempo, 
                medicoDatos, medicoTarifaHora, citaPaciente, citaCantidad, 
                citaTiempoYPago, nd, cap, ndP, capP);
    }    
}

char *leerCadena(ifstream &arch, char delim='\n') {
    char buff[60], *cad;
    arch.getline(buff, 60, delim);
    cad = new char[strlen(buff)+1];
    strcpy(cad, buff);
    return cad;
}

double leerTiempo(ifstream &arch) {
    int h, m, s;
    char c;
    double hIni, hFin;
    arch>>h>>c>>m>>c>>s>>c; 
    hIni = calcularHora(h,m,s);
    arch>>h>>c>>m>>c>>s;
    arch.get();
    hFin = calcularHora(h,m,s);
    return hFin-hIni;
}

double calcularHora(int h, int m, int s) {
    return h + (double)m/60 + (double)s/60/60;
}

void asignarCita(char *dniPac, char *nombPac, char *codMed, char *nombMed, 
        double tarifa, double tiempo, char ***&medicoDatos, 
        double *&medicoTarifaHora, char ****&citaPaciente, int **&citaCantidad, 
        double ***&citaTiempoYPago, int &nd, int &cap, int *ndP, int *capP) {
    int posMed = buscarMed(codMed, medicoDatos, nd), posPac=0;        
    if (posMed==nd) {  // Nuevo medico
        if (nd==cap)
            aumentarEspaciosMed(medicoDatos, medicoTarifaHora, citaPaciente, 
                    citaCantidad, citaTiempoYPago, nd, cap);
        medicoDatos[nd-1]=new char*[2];
        medicoDatos[nd-1][0]=codMed;
        medicoDatos[nd-1][1]=nombMed;
        medicoTarifaHora[nd-1]=tarifa;   
        aumentarEspaciosPac(citaPaciente[nd-1], citaCantidad[nd-1], 
                citaTiempoYPago[nd-1], ndP[posMed], capP[posMed]);
        citaPaciente[nd-1][posPac] = new char*[2];
        citaPaciente[nd-1][posPac][0] = dniPac;        
        citaPaciente[nd-1][posPac][1] = nombPac;        
        citaCantidad[nd-1][posPac] = 1;
        citaTiempoYPago[nd-1][posPac] = new double[2];
        citaTiempoYPago[nd-1][posPac][0] = tiempo;
        citaTiempoYPago[nd-1][posPac][1] = tiempo*tarifa;
        nd++;
        ndP[posMed]++;
    } else {    // Medico repetido   
        posPac = buscarPac(dniPac, citaPaciente[posMed], ndP[posMed]);
        // Nuevo paciente
        if (posPac==ndP[posMed]) {  
            if (ndP[posMed]==capP[posMed]) 
                aumentarEspaciosPac(citaPaciente[posMed], citaCantidad[posMed],
                        citaTiempoYPago[posMed], ndP[posMed], capP[posMed]);
            citaPaciente[posMed][ndP[posMed]-1] = new char*[2];
            citaPaciente[posMed][ndP[posMed]-1][0]=dniPac;        
            citaPaciente[posMed][ndP[posMed]-1][1]=nombPac;
            citaCantidad[posMed][ndP[posMed]-1]=1;       
            citaTiempoYPago[posMed][ndP[posMed]-1] = new double[2];
            citaTiempoYPago[posMed][ndP[posMed]-1][0] = tiempo;
            citaTiempoYPago[posMed][ndP[posMed]-1][1] = tiempo*tarifa;
            ndP[posMed]++;            
        } else {    // Paciente repetido
            citaCantidad[posMed][posPac]++; 
            citaTiempoYPago[posMed][posPac][0] += tiempo;
            citaTiempoYPago[posMed][posPac][1] += tiempo*tarifa;
        }
    }   
}

int buscarMed(char *codMed, char ***medicoDatos, int nd) {
    if (medicoDatos==nullptr) return nd;
    for (int i=0; medicoDatos[i]; i++)
        if (strcmp(codMed, medicoDatos[i][0])==0)
            return i;
    return nd;
}

void aumentarEspaciosMed(char ***&medicoDatos, double *&medicoTarifaHora, 
        char ****&citaPaciente, int **&citaCantidad, double ***&citaTiempoYPago, 
        int &nd, int &cap) {
    int **auxCC;
    char ***auxMD, ****auxCP;
    double *auxMT, ***auxTP;
    cap += INCREMENTO;        
    if (medicoDatos==nullptr) {        
        medicoDatos = new char**[cap]{};
        medicoTarifaHora = new double[cap]{};
        citaPaciente = new char***[cap]{};      // * Nivel 2 y 3 se reserva dsp.  
        citaCantidad = new int*[cap]{};         // * Nivel 2 se reserva dsp.  
        citaTiempoYPago = new double**[cap]{};  // * Nivel 2 y 3 se reserva dsp.      
        nd = 1;
    } else {
        auxMD = new char**[cap]{};
        auxMT = new double[cap]{};
        auxCP = new char***[cap]{}; 
        auxCC = new int*[cap]{};
        auxTP = new double**[cap]{};
        for (int i=0; i<nd; i++) {
            auxMD[i] = medicoDatos[i];
            auxMT[i] = medicoTarifaHora[i];
            auxCP[i] = citaPaciente[i];
            auxCC[i] = citaCantidad[i];
            auxTP[i] = citaTiempoYPago[i];
        }        
        delete medicoDatos;
        delete medicoTarifaHora;
        delete citaPaciente;
        delete citaCantidad;
        delete citaTiempoYPago;     
        medicoDatos = auxMD;
        medicoTarifaHora = auxMT;
        citaPaciente = auxCP;
        citaCantidad = auxCC;
        citaTiempoYPago = auxTP;
    }
}

void aumentarEspaciosPac(char ***&citaPaciente, int *&citaCantidad, 
        double **&citaTiempoYPago, int &nd, int &cap) {
    int *auxCC;
    char ***auxCP;    
    double **auxTP;
    cap += INCREMENTO;
    if (citaPaciente==nullptr) {
        citaPaciente = new char**[cap]{};
        citaCantidad = new int[cap]{};
        citaTiempoYPago = new double*[cap]{};     
        nd = 1;
    } else {        
        auxCP = new char**[cap]{};
        auxCC = new int[cap]{};
        auxTP = new double*[cap]{};
        for (int i=0; i<nd; i++) {
            auxCP[i] = citaPaciente[i];
            auxCC[i] = citaCantidad[i];
            auxTP[i] = citaTiempoYPago[i];
        }   
        delete citaPaciente;
        delete citaCantidad;
        delete citaTiempoYPago;
        citaPaciente = auxCP;
        citaCantidad = auxCC;
        citaTiempoYPago = auxTP;
    }    
}

int buscarPac(char *dniPac, char ***citaPaciente, int nd) {    
    if (citaPaciente==nullptr) return nd;
    for (int i=0; citaPaciente[i]; i++) {
        if (strcmp(dniPac,citaPaciente[i][0])==0)
            return i;
    }
    return nd;
}