#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "OperadoresSobrecargados.h"
#include "Estructuras.h"
#define MAX_MED 40

// Lectura:
bool operator >>(ifstream &arch, struct StMedico &medico) {
    arch>>medico.codigo;
    if (arch.eof()) return false;
    arch>>medico.nombre>>medico.tarifaPoxConsulta;
    asignarEspecialidad(medico);      
    return true;
}

void asignarEspecialidad(struct StMedico &medico) {
    int k=0;
    for (int i=0; medico.nombre[i]; i++)
        if (medico.nombre[i]=='_') k=i;
    for (int i=0, j=k+1; medico.nombre[j-1]; i++, j++)
        medico.especialidad[i]=medico.nombre[j];
    medico.nombre[k]=0;
}

bool operator >>(ifstream &arch, struct StPaciente &paciente) {
    arch>>paciente.dni;
    if (arch.eof()) return false;
    arch>>paciente.nombre>>paciente.telefono;
    paciente.numeroDeCitas=paciente.totalGastado=0;
    return true;
}

int operator >>(ifstream &arch, struct StCita &cita) {
    int dni, dd, mm, aaaa;
    char c;
    arch>>dni;
    if (arch.eof()) return -1;
    arch>>cita.codigoDelMedico>>dd>>c>>mm>>c>>aaaa;
    cita.fecha = juntarFecha(dd, mm, aaaa);
    cita.tarifaPorConsulta=0;
    return dni;
}

int juntarFecha(int dd, int mm, int aaaa) {
    return aaaa*10000 + mm*100 + dd;
}

// Búsqueda:
bool operator <=(struct StCita &cita, struct StMedico arregloMedico[]) {
    int i=buscarMedico(arregloMedico, cita.codigoDelMedico);
    if (i==-1) return false;
    strcpy(cita.especialidad, arregloMedico[i].especialidad);
    cita.tarifaPorConsulta=arregloMedico[i].tarifaPoxConsulta;    
    return true;
}

int buscarMedico(struct StMedico arregloMedico[], int codigo) {
    for (int i=0; i<MAX_MED; i++) 
        if (arregloMedico[i].codigo==codigo) return i;    
    return -1;
}

// Agregación:
void operator +=(struct StPaciente &paciente, struct StCita cita) {    
    paciente.citas[paciente.numeroDeCitas] = cita;
    paciente.numeroDeCitas++;
}

// Gastos:
void operator ++(struct StPaciente &paciente) {
    for (int i=0; i<paciente.numeroDeCitas; i++)
        paciente.totalGastado += paciente.citas[i].tarifaPorConsulta;
}

// Impresión:
void operator <<(ofstream &arch, struct StPaciente paciente) {    
    imprimirCabeceraPaciente(arch, paciente);
    arch.precision(2);
    arch<<fixed;
    for (int i=0; i<paciente.numeroDeCitas; i++) {
        arch<<i+1<<left<<setw(4)<<')';
        imprimirFecha(arch, paciente.citas[i].fecha);
        arch<<setw(10)<<' '<<left<<setw(15)<<paciente.citas[i].codigoDelMedico
                <<setw(21)<<paciente.citas[i].especialidad
                <<paciente.citas[i].tarifaPorConsulta<<endl;
    }
    arch<<"MONTO TOTAL GASTADO: "<<paciente.totalGastado<<endl;
}

void imprimirCabeceraPaciente(ofstream &arch, struct StPaciente paciente) {    
    arch<<setw(5)<<"DNI"<<setw(28)<<"NOMBRE"<<setw(22)<<"TELEFONO"<<endl;
    arch<<left<<setw(23)<<paciente.dni<<setw(23)<<paciente.nombre
            <<paciente.telefono<<right<<endl;
    arch<<"RELACION DE CITAS"<<endl;
    arch<<"No."<<setw(7)<<"FECHA"<<setw(27)<<"CODIGO DEL MEDICO"<<setw(15)
            <<"ESPECIALIDAD"<<setw(15)<<"TARIFA"<<endl;
}

void imprimirFecha(ofstream &arch, int fecha) {
    int dd, mm, aaaa;
    separarFecha(fecha, dd, mm, aaaa);
    arch.fill('0');
    arch<<right<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aaaa;
    arch.fill(' ');
}

void separarFecha(int fecha, int &dd, int &mm, int &aaaa) {
    aaaa = fecha/10000;
    fecha -= aaaa*10000;
    mm = fecha/100;
    dd = fecha-mm*100;    
}