#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

#include "FuncionesAuxiliares.h"
#define MAX_LINEA 80

void crearBinarios(const char *nombArchBinA, const char *nombArchBinB){    
    ofstream archBinA(nombArchBinA, ios::out|ios::binary);
    if (not archBinA.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchBinA<<".\n"<<endl;
        exit(1);
    }
    ofstream archBinB(nombArchBinB, ios::out|ios::binary);
    if (not archBinB.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchBinB<<".\n"<<endl;
        exit(1);
    }
}

void separarInformacion(const char *nombArchLectura, const char *nombArchMedicos, 
        const char *nombArchPacientes, const char *nombArchConsultas,
        const char *nombArchMedicinas) {        
    ifstream archLectura(nombArchLectura, ios::in);
    if (not archLectura.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchLectura<<".\n"<<endl;
        exit(1);
    }
    ofstream archMedicos(nombArchMedicos, ios::out);
    if (not archMedicos.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchMedicos<<".\n"<<endl;
        exit(1);
    }
    fstream archPacientes(nombArchPacientes, ios::out|ios::in|ios::binary);
    if (not archPacientes.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchPacientes<<".\n"<<endl;
        exit(1);
    }
    ofstream archConsultas(nombArchConsultas, ios::out);
    if (not archConsultas.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchConsultas<<".\n"<<endl;
        exit(1);
    }
    fstream archMedicinas(nombArchMedicinas, ios::out|ios::in|ios::binary);
    if (not archMedicinas.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchMedicinas<<".\n"<<endl;
        exit(1);
    }    
    leerMedicos(archLectura, archMedicos, archPacientes, archConsultas, 
            archMedicinas);    
}

void leerMedicos(ifstream &archLectura, ofstream &archMedicos, 
        fstream &archPacientes, ofstream &archConsultas, 
        fstream &archMedicinas) {    
    char codigo[8], nombre[60], especialidad[30];    
    while (true) {        
        archLectura>>codigo;
        if (archLectura.eof()) break;
        archLectura>>nombre;
        leerEspecialidad(especialidad, nombre);        
        escribirMedicos(archMedicos, codigo, nombre, especialidad);
        leerPacientes(archLectura, archPacientes, archConsultas, archMedicinas);
    }
    archMedicos<<endl;
}

void leerEspecialidad(char *especialidad, char *nombre) {    
    int j=0, k;
    for (int i=0; nombre[i]; i++, j++) {        
        if(nombre[i]=='_') {
            j=0;
            k=i;
        }
        especialidad[j] = nombre[i+1];
    }  
    especialidad[j]=0;
    nombre[k]=0;
}

void escribirMedicos(ofstream &archMedicos, char *codigo, char *nombre, 
        char *especialidad) {     
    archMedicos<<codigo<<" "<<nombre<<" "<<especialidad<<" ";
}

void leerPacientes(ifstream &archLectura, fstream &archPacientes, 
        ofstream &archConsultas, fstream &archMedicinas) {    
    int dni;
    char nombre[60];
    while (true) {
        archLectura>>dni>>nombre;
        escribirPacienes(archPacientes, dni, nombre);        
        leerConsultas(archLectura, archConsultas, archMedicinas, dni);
        archLectura>>ws;
        if (archLectura.eof()) break;
        if (finDePacientes(archLectura)) break;
    }    
}

void escribirPacienes(fstream &archPacientes, int dni, char *nombre) {
    double gasto=0;    
    if (not pacienteRepetido(dni, archPacientes)) {
        archPacientes.seekg(0, ios::end);
        archPacientes.write(reinterpret_cast<const char*>(&dni), sizeof(int));
        archPacientes.write(reinterpret_cast<const char*>(nombre), sizeof(char)*60);
        archPacientes.write(reinterpret_cast<const char*>(&gasto), sizeof(double));
    }
}

bool pacienteRepetido(int dni, fstream &arch) {    
    int tamReg, tamArch, numReg, dniReg;
    tamReg = sizeof(int) + sizeof(char)*60 + sizeof(double);    
    tamArch = calcularTamArch(arch);    
    numReg = tamArch/tamReg;    
    arch.seekg(0, ios::beg);
    for(int i=0; i<numReg-1; i++) {
        arch.seekg(tamReg*i, ios::beg);                
        arch.read(reinterpret_cast<char*>(&dniReg), sizeof(int));            
        if (dni==dniReg) return true;
    }
    return false;
}

int calcularTamArch(fstream &arch) {    
    arch.seekg(0, ios::end);
    return arch.tellg();        
}

void leerConsultas(ifstream &archLectura, ofstream &archConsultas, 
        fstream &archMedicinas, int dni) {    
    int dd, mm, aaaa, cantMed;
    char codMedico[8], c;    
    archLectura>>codMedico>>dd>>c>>mm>>c>>aaaa>>cantMed;
    escribirConsultas(archConsultas, dni, codMedico, juntarFecha(dd, mm, aaaa), 
            cantMed);        
    leerMedicinas(cantMed, archLectura, archConsultas, archMedicinas);
    archConsultas<<endl;
}

int juntarFecha(int dd, int mm, int aaaa) {
    return aaaa*10000 + mm*100 + dd;    
}

void escribirConsultas(ofstream &archConsultas, int dni, char *codMedico, 
        int fecha, int cantMed) {        
    archConsultas<<dni<<" "<<codMedico<<" "<<fecha<<" "<<cantMed<<" ";
}

void leerMedicinas(int cantMed, ifstream &archLectura, ofstream &archConsultas, 
        fstream &archMedicinas) {
    int codigo;
    char descripcion[100];
    double precio;
    for (int i=0; i<cantMed; i++) {
        archLectura>>codigo>>descripcion>>precio;
        escribirCodigosMedicinas(codigo, archConsultas);
        escribirMedicamentos(archMedicinas, codigo, descripcion, precio);
        archLectura>>ws;
        if (archLectura.eof()) break;
    }
}

void escribirCodigosMedicinas(int codigo, ofstream &archConsultas) {    
    archConsultas<<codigo<<" ";    
}

void escribirMedicamentos(fstream &archMedicinas, int codigo, char *descripcion, 
        double precio) {    
    if (not medicamentoRepetido(codigo, archMedicinas)) {          
        archMedicinas.seekg(0, ios::end);
        archMedicinas.write(reinterpret_cast<const char*>(&codigo), sizeof(int));
        archMedicinas.write(reinterpret_cast<const char*>(descripcion), 
                sizeof(char)*100);
        archMedicinas.write(reinterpret_cast<const char*>(&precio), 
                sizeof(double));
    }
}

bool medicamentoRepetido(int cod, fstream &arch) {    
    int tamReg, tamArch, numReg, codReg;
    tamReg = sizeof(int) + sizeof(char)*100 + sizeof(double);    
    tamArch = calcularTamArch(arch);
    numReg = tamArch/tamReg;
    arch.seekg(0, ios::beg);
    for(int i=0; i<numReg-1; i++) {  
        arch.seekg(tamReg*i, ios::beg);
        arch.read(reinterpret_cast<char*>(&codReg), sizeof(int));     
        if (cod==codReg) return true;
    }    
    return false;
}

bool finDePacientes(ifstream &in) {    
    in>>ws;
    char c = in.get();
    in.unget();
    return c>='A' && c<='Z';    
}

void imprimirReporteDeVerificacion(const char *nombArchMedicos, 
        const char *nombArchPacientes, const char *nombArchConsultas,
        const char *nombArchMedicinas, const char *nombArchSalida){
    ofstream archSalida(nombArchSalida, ios::out);
    if (not archSalida.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchSalida<<".\n"<<endl;
        exit(1);
    }
    ifstream archMedicos(nombArchMedicos, ios::in);
    if (not archMedicos.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchMedicos<<".\n"<<endl;
        exit(1);
    }
    ifstream archPacientes(nombArchPacientes, ios::in|ios::binary);
    if (not archPacientes.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchPacientes<<".\n"<<endl;
        exit(1);
    }
    ifstream archConsultas(nombArchConsultas, ios::in);
    if (not archConsultas.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchConsultas<<".\n"<<endl;
        exit(1);
    }
    ifstream archMedicinas(nombArchMedicinas, ios::in|ios::binary);
    if (not archMedicinas.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchMedicinas<<".\n"<<endl;
        exit(1);
    }    
    imprimirMedicos(archSalida, archMedicos);
    imprimirPacientes(archSalida, archPacientes);
    imprimirMedicinas(archSalida, archMedicinas);
    imprimirConsultas(archSalida, archConsultas);
}

void imprimirMedicos(ofstream &archSalida, ifstream &archMedicos) {    
    imprimirEncabezadoMedicos(archSalida);    
    char codigo[8], nombre[60], especialidad[30];
    for (int i=0; true; i++) {
        archMedicos>>codigo;
        if (archMedicos.eof()) break;
        archMedicos>>nombre>>especialidad;
        archSalida<<setw(3)<<i<<")   "<<left<<setw(10)<<codigo<<setw(38)
                <<nombre<<especialidad<<right<<endl;
    }
    archSalida<<endl;
}

void imprimirEncabezadoMedicos(ofstream &archSalida) {    
    imprimirLinea(archSalida, '=', MAX_LINEA);   
    archSalida<<setw(23)<<"STAFF DE MEDICOS"<<endl;
    imprimirLinea(archSalida, '=', MAX_LINEA);    
}

void imprimirLinea(ofstream &out, char c, int n) {    
    for (int i=0; i<n; i++) out.put(c);
    out.put('\n');
}

void imprimirPacientes(ofstream &archSalida, ifstream &archPacientes) {
    imprimirEncabezadoPacientes(archSalida);    
    char nombre[60];
    double gasto;    
    int tamReg, tamArch, numReg, dni;    
    archPacientes.seekg(0, ios::end);
    tamArch = archPacientes.tellg();        
    tamReg = sizeof(int) + sizeof(char)*60 + sizeof(double);
    numReg = tamArch/tamReg;
    archPacientes.seekg(0, ios::beg);
    for (int i=0; i<numReg-1; i++) {
        archPacientes.read(reinterpret_cast<char*>(&dni), sizeof(int));
        archPacientes.read(reinterpret_cast<char*>(nombre), sizeof(char)*60);
        archPacientes.read(reinterpret_cast<char*>(&gasto), sizeof(double));
        archSalida<<setw(3)<<i<<")   "<<left<<setw(10)<<dni<<setw(23)
                <<nombre<<gasto<<right<<endl;
    }
    archSalida<<endl;
}

void imprimirEncabezadoPacientes(ofstream &archSalida) {
    imprimirLinea(archSalida, '=', MAX_LINEA);   
    archSalida<<setw(28)<<"PACIENTES REGISTRADOS"<<endl;
    imprimirLinea(archSalida, '=', MAX_LINEA);        
}

void imprimirMedicinas(ofstream &archSalida, ifstream &archMedicinas) {
    imprimirEncabezadoMedicinas(archSalida);    
    char descripcion[100];
    double precio;    
    int tamReg, tamArch, numReg, codigo;    
    archMedicinas.seekg(0, ios::end);
    tamArch = archMedicinas.tellg();        
    tamReg = sizeof(int) + sizeof(char)*100 + sizeof(double);
    numReg = tamArch/tamReg;
    archMedicinas.seekg(0, ios::beg);
    for (int i=0; i<numReg-1; i++) {
        archMedicinas.read(reinterpret_cast<char*>(&codigo), sizeof(int));
        archMedicinas.read(reinterpret_cast<char*>(descripcion), 
                sizeof(char)*100);
        archMedicinas.read(reinterpret_cast<char*>(&precio), 
                sizeof(double));
        archSalida<<setw(3)<<i<<")   "<<left<<setw(10)<<codigo<<setw(35)
                <<descripcion<<precio<<right<<endl;
    }
    archSalida<<endl;
}

void imprimirEncabezadoMedicinas(ofstream &archSalida) {
    imprimirLinea(archSalida, '=', MAX_LINEA);   
    archSalida<<setw(25)<<"MEDICINAS EN STOCK"<<endl;
    imprimirLinea(archSalida, '=', MAX_LINEA);   
}

void imprimirConsultas(ofstream &archSalida, ifstream &archConsultas) {    
    imprimirEncabezadoConsultas(archSalida);    
    int dni, fecha, dd, mm, aaaa, cantMed;
    char codMedico[8];
    for (int i=0; true; i++) {
        archConsultas>>dni;
        if (archConsultas.eof()) break;
        archConsultas>>codMedico>>fecha>>cantMed;
        archSalida<<setw(3)<<i<<")   "<<left<<setw(10)<<dni<<setw(10)
                <<codMedico<<right;
        separarFecha(dd, mm, aaaa, fecha);
        imprimirFecha(archSalida, dd, mm, aaaa);
        imprimirCodigos(archSalida, archConsultas, cantMed);
    }
}

void imprimirEncabezadoConsultas(ofstream &archSalida) {
    imprimirLinea(archSalida, '=', MAX_LINEA);   
    archSalida<<setw(28)<<"RELACION DE CONSULTAS"<<endl;
    imprimirLinea(archSalida, '=', MAX_LINEA);            
}

void separarFecha(int &dd, int &mm, int &aaaa, int fecha) {
    aaaa = fecha/10000;
    fecha -= aaaa*10000;
    mm = fecha/100;
    dd = fecha-mm*100;
}

void imprimirFecha(ofstream &out, int dd, int mm, int aaaa) {
    out.fill('0');
    out<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)<<aaaa;
    out.fill(' ');    
}

void imprimirCodigos(ofstream &archSalida, ifstream &archConsultas, int cantMed) {    
    archSalida<<setw(5)<<cantMed<<setw(15);
    int codigo;
    for (int i=0; i<cantMed; i++) {
        archConsultas>>codigo;
        archSalida<<right<<setw(10)<<codigo;        
    }
    archSalida<<endl;    
}

void modificarPacientes(const char *nombArchConsultas, 
        const char *nombArchMedicinas, const char *nombArchPacientes) {
    ifstream archConsultas(nombArchConsultas, ios::in);
    if (not archConsultas.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchConsultas<<".\n"<<endl;
        exit(1);
    }
    ifstream archMedicinas(nombArchMedicinas, ios::in|ios::binary);
    if (not archMedicinas.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchMedicinas<<".\n"<<endl;
        exit(1);
    }
    fstream archPacientes(nombArchPacientes, ios::out|ios::in|ios::binary);
    if (not archPacientes.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchPacientes<<".\n"<<endl;
        exit(1);
    }
    modificarGastos(archConsultas, archMedicinas, archPacientes);
}

void modificarGastos(ifstream &archConsultas, ifstream &archMedicinas, 
        fstream &archPacientes) {
    int dni, fecha, cantMed, medicina;
    double precio, gasto;
    char codMed[8];
    while (true) {
        archConsultas>>dni;
        if (archConsultas.eof()) break;
        archConsultas>>codMed>>fecha>>cantMed;
        for (int i=0; i<cantMed; i++) {
            archConsultas>>medicina;
            precio = buscarPrecioMedicina(medicina, archMedicinas);
            gasto = precio;
            modificarRegistro(archPacientes, gasto, dni);
        }
    }
}

double buscarPrecioMedicina(int codigo, ifstream &archMedicinas) {    
    int tamReg, tamArch, numReg, cod;
    double precio;
    archMedicinas.seekg(0, ios::end);
    tamArch = archMedicinas.tellg();
    tamReg = sizeof(int) + sizeof(char)*100 + sizeof(double);
    numReg = tamArch/tamReg;
    archMedicinas.seekg(0, ios::beg);
    for (int i=0; i<numReg-1; i++) {
        archMedicinas.seekg(tamReg*i, ios::beg);
        archMedicinas.read(reinterpret_cast<char*>(&cod), sizeof(int));
        if (cod==codigo) {
            archMedicinas.seekg(sizeof(char)*100, ios::cur);
            archMedicinas.read(reinterpret_cast<char*>(&precio), sizeof(double));
            return precio;
        }
    }
}

void modificarRegistro(fstream &archPacientes, double precio, int dni) {
    int tamReg, tamArch, numReg, dniReg;
    double gasto;
    archPacientes.seekg(0, ios::end);
    tamArch = archPacientes.tellg();
    tamReg = sizeof(int) + sizeof(char)*60 + sizeof(double);
    numReg = tamArch/tamReg;
    archPacientes.seekg(0, ios::beg);
    for (int i=0; i<numReg-1; i++) {
        archPacientes.seekg(tamReg*i, ios::beg);
        archPacientes.read(reinterpret_cast<char*>(&dniReg), sizeof(int));
        if(dniReg==dni) {
            archPacientes.seekg(sizeof(char)*60, ios::cur);
            archPacientes.read(reinterpret_cast<char*>(&gasto), sizeof(double));
            gasto += precio;
            archPacientes.seekg(tamReg*i+sizeof(int)+sizeof(char)*60, ios::beg);
            archPacientes.write(reinterpret_cast<const char*>(&gasto), 
                    sizeof(double));
            break;
        }
    }
}