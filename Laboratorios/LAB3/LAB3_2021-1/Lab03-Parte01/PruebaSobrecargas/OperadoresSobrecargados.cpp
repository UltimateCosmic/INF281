#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "OperadoresSobrecargados.h"
#include "StructConductor.h"
#include "StructInfraccion.h"
#include "StructInfraccionEstab.h"
#define MAX_LINEA 61

// Lectura:
bool operator >>(ifstream &arch, struct ConductorSt &conductor) {    
    arch>>conductor.licencia;
    if (arch.eof()) return false;
    arch>>conductor.nombre;
    conductor.numFaltas=conductor.numFaltasLeves=conductor.numFaltasGraves=
            conductor.numFaltasMuyGraves=conductor.montoFaltasLeves=
            conductor.montoFaltasGraves=conductor.montoFaltasMuyGraves=0;
    return true;
}

bool operator >>(ifstream &arch, struct InfraccionSt &infraccion) {
    int dd, mm, aaaa;
    char c;
    arch>>infraccion.licencia;
    if (arch.eof()) return false;
    arch>>infraccion.placa>>dd>>c>>mm>>c>>aaaa;
    infraccion.fecha = aaaa*10000 + mm*100 + dd;
    arch>>infraccion.codInf;
    return true;
}

bool operator >>(ifstream &arch, struct InfraccionEstabSt &infraccionEst) {
    char descripcion[200];
    arch>>infraccionEst.codigo;
    if (arch.eof()) return false;
    arch>>descripcion>>infraccionEst.gravedad>>infraccionEst.multa;
    return true;
}

// Agregación:
void operator +(struct ConductorSt &conductor, struct InfraccionSt infraccion) {
    conductor.faltas[conductor.numFaltas].codInf = infraccion.codInf;
    conductor.faltas[conductor.numFaltas].fecha = infraccion.fecha;
    strcpy(conductor.faltas[conductor.numFaltas].placa, infraccion.placa);
    conductor.numFaltas++;
}

void operator +(struct ConductorSt &conductor, struct InfraccionEstabSt infraccionEst) {
    for (int i=0; i<conductor.numFaltas; i++)    
        if (conductor.faltas[i].codInf==infraccionEst.codigo) {
            strcpy(conductor.faltas[i].gravedad, infraccionEst.gravedad);
            conductor.faltas[i].multa=infraccionEst.multa;
        }
}

// Cálculo de las infracciones cometidas:
void operator ++(struct ConductorSt &conductor) {    
    for (int i=0; i<conductor.numFaltas; i++) {
        if (strcmp(conductor.faltas[i].gravedad, "Leve")==0) {
            conductor.montoFaltasLeves += conductor.faltas[i].multa;
            conductor.numFaltasLeves++;
        } else if (strcmp(conductor.faltas[i].gravedad, "Grave")==0) {
            conductor.montoFaltasGraves += conductor.faltas[i].multa;
            conductor.numFaltasGraves++;
        } else if (strcmp(conductor.faltas[i].gravedad, "Muy grave")==0) {
            conductor.montoFaltasMuyGraves += conductor.faltas[i].multa;
            conductor.numFaltasMuyGraves++;
        }
    }
}

// Amnistía de infracciones: 
void operator *(struct ConductorSt &conductor, int fecha) {    
    for (int i=0; i<conductor.numFaltas; i++) {
        if (conductor.faltas[i].fecha<fecha) {            
            if (strcmp(conductor.faltas[i].gravedad, "Leve")==0) {
                conductor.faltas[i].multa = 0;
                conductor.montoFaltasLeves--;
                desplazarFaltas(i, conductor);
                conductor.numFaltas--;
            } else if (strcmp(conductor.faltas[i].gravedad, "Grave")==0)              
                conductor.faltas[i].multa -= conductor.faltas[i].multa*0.25;
            else if (strcmp(conductor.faltas[i].gravedad, "Muy grave")==0)
                conductor.faltas[i].multa -= conductor.faltas[i].multa*0.8;
        }
    }
}

void desplazarFaltas(int i, struct ConductorSt &conductor) {
    for (int j=i+1; j<conductor.numFaltas; j++, i++)
        intercambiarFalta(conductor.faltas[i], conductor.faltas[j]);
}

void intercambiarFalta(struct FaltaSt &faltaAnt, struct FaltaSt &faltaNue) {
    faltaNue = faltaAnt;
}

void operator <<(ofstream &arch, struct ConductorSt conductor) {    
    imprimirConductor(arch, conductor.nombre, conductor.licencia);
    imprimirInfracciones(arch, conductor);
    imprimirResumen(arch, conductor);
}

void imprimirConductor(ofstream &arch, char *nombre, int licencia) {
    arch<<"Conductor   : "<<nombre<<endl;
    arch<<"Licencia No.: "<<licencia<<endl;
}

void imprimirInfracciones(ofstream &arch, struct ConductorSt conductor) {
    imprimirCabeceraInfracciones(arch);
    arch.precision(2);
    arch<<fixed;
    for (int i=0; i<conductor.numFaltas; i++) {
        arch<<right<<i<<")"<<setw(4)<<' ';
        imprimirFecha(arch, conductor.faltas[i].fecha);
        arch<<setw(10)<<conductor.faltas[i].placa<<setw(10)
                <<conductor.faltas[i].codInf<<setw(7)<<' ';
        arch<<left<<setw(12)<<conductor.faltas[i].gravedad
                <<conductor.faltas[i].multa<<endl;
    }
}

void imprimirCabeceraInfracciones(ofstream &arch) {
    imprimirLinea(arch, '=', MAX_LINEA);
    arch<<"Infracciones cometidas:"<<endl;
    imprimirLinea(arch, '-', MAX_LINEA);
    arch<<"No."<<setw(8)<<"Fecha"<<setw(13)<<"Placa"<<setw(16)<<"Infraccion"
            <<setw(11)<<"Gravedad"<<setw(9)<<"Multa"<<endl;
}

void imprimirLinea(ofstream &arch, char c, int n) {
    for (int i=0; i<n; i++) arch.put(c);
    arch.put('\n');
}

void imprimirFecha(ofstream &arch, int fecha) {
    int dd, mm, aaaa;
    separarFecha(fecha, dd, mm, aaaa);
    arch.fill('0');
    arch<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)<<aaaa;
    arch.fill(' ');
}
    
void separarFecha(int fecha, int &dd, int &mm, int &aaaa) {
    aaaa = fecha/10000;
    fecha -= aaaa*10000;
    mm = fecha/100;
    dd = fecha - mm*100;
}

void imprimirResumen(ofstream &arch, struct ConductorSt conductor) {
    imprimirLinea(arch, '=', MAX_LINEA);
    arch<<right<<setw(37)<<"Cantidad"<<setw(10)<<"Total"<<endl;
    arch<<left<<setw(32)<<"Infracciones leves:"<<setw(13)
            <<conductor.numFaltasLeves<<conductor.montoFaltasLeves<<endl;
    arch<<left<<setw(32)<<"Infracciones graves:"<<setw(11)
            <<conductor.numFaltasGraves<<conductor.montoFaltasGraves<<endl;
    arch<<left<<setw(32)<<"Infracciones muy graves:"<<setw(13)
            <<conductor.numFaltasMuyGraves<<conductor.montoFaltasMuyGraves<<endl;
}

