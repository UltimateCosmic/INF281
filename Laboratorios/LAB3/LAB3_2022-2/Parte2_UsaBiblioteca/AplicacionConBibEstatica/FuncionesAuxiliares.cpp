#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "OperadoresSobrecargados.h"
#include "FuncionesAuxiliares.h"
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#define MAX_LINEA 80

void leerMedicos(struct StMedico medico[], int &numMedicos, const char *nombArch) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);
    while (true) {
        if (not (arch>>medico[numMedicos])) break; 
        numMedicos++;
    }    
}

void leerPacientes(struct StPaciente paciente[], int &numPacientes, 
        const char *nombArch) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);
    while (true) {
        if (not (arch>>paciente[numPacientes])) break;
        numPacientes++;
    }    
}

void leerCitas(struct StMedico medico[], int numMedicos, 
        struct StPaciente paciente[], int numPacientes, const char *nombArch) {        
    ifstream arch;    
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);
    int dni;
    struct StCita cita;
    while (true) {
        dni = arch>>cita;
        if (dni==-1) break;
        completarInformacion(cita, medico, numMedicos);
        agregarCita(dni, cita, paciente, numPacientes);
    }    
}

void completarInformacion(struct StCita &cita, struct StMedico medico[], int n) {    
    cita<=medico;
}

void agregarCita(int dni, struct StCita cita, struct StPaciente paciente[], int n) {
    for (int i=0; i<n; i++)
        if (paciente[i].dni==dni)
            paciente[i]+=cita;          
}

void emitirReporte(struct StPaciente paciente[], int n, const char *nombArch) {
    ofstream archOutput;
    AperturaDeUnArchivoDeTextosParaEscribir(archOutput, nombArch);
    imprimirCabeceraPrincipal(archOutput);
    for (int i=0; i<n; i++) {
        imprimirLinea(archOutput, '=', MAX_LINEA);    
        ++(paciente[i]);
        archOutput<<paciente[i];
    }    
}

void imprimirCabeceraPrincipal(ofstream &archOutput) {    
    archOutput<<setw(40)<<"EMPRESA PRESTADORA DE SALUD LP1"<<endl;
    archOutput<<setw(41)<<"PACIENTES QUE FUERON ATENDIDOS"<<endl;        
}

void imprimirLinea(ofstream &arch, char c, int n) {
    for (int i=0; i<n; i++) arch.put(c);
    arch.put('\n');
}