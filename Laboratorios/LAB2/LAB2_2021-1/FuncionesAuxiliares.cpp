#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

#include "FuncionesAuxiliares.h"

void crearPrimerosBinarios(const char *nombArchTxt, const char *nombArchCond, 
        const char *nombArchFalt) {    
    ifstream archTxt(nombArchTxt, ios::in);
    if (not archTxt.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchTxt<<endl;
        exit(1);
    }
    ofstream archConductores(nombArchCond, ios::out|ios::binary);
    if (not archConductores.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchCond<<endl;
        exit(1);
    }
    ofstream archFaltas(nombArchFalt, ios::out|ios::binary);
    if (not archFaltas.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchFalt<<endl;
        exit(1);
    }
    leerConductores(archTxt, archConductores, archFaltas);
}

void leerConductores(ifstream &archTxt, ofstream &archCond, ofstream &archFalt) {    
    int licencia;
    char nombre[60];
    while (true) {
        archTxt>>licencia;
        if (archTxt.eof()) break;
        archTxt>>nombre;
        archCond.write(reinterpret_cast<const char*>(&licencia),sizeof(int));
        archCond.write(reinterpret_cast<const char*>(nombre),sizeof(char)*60);
        omitirInfracciones(archTxt, archCond, archFalt, licencia);
    }    
}

void omitirInfracciones(ifstream &archTxt, ofstream &archCond, 
        ofstream &archFalt, int licencia) {    
    int dd, mm, aaaa, a=0, fecha, codigo;
    char placa[8], c, gravedad[15];
    double b=0;
    while (true) {        
        archTxt>>placa>>dd>>c>>mm>>c>>aaaa>>c>>codigo;
        fecha = juntarFecha(dd, mm, aaaa);
        elegirGravedad(gravedad, c);
        escribirConductores(archFalt, placa, licencia, fecha, gravedad, codigo, b);
        archTxt>>ws;
        if (archTxt.eof()) break;
        if (verificarFinInfracciones(archTxt)) break;
    }
    escribirInfracciones(archCond, a, b);    
}

int juntarFecha(int dd, int mm, int aaaa) {
    return aaaa*10000 + mm*100 + dd;
}

void elegirGravedad(char *gravedad, char codigo) {
    switch (codigo) {        
        case 'L':
            strcpy(gravedad, "LEVE");
            break;
        case 'G':
            strcpy(gravedad, "GRAVE");
            break;
        case 'M':
            strcpy(gravedad, "MUY GRAVE");
            break;     
    }
}

void escribirConductores(ofstream &archFalt, char *placa, int licencia, 
        int fecha, char *gravedad, int codigo, double b) {    
    archFalt.write(reinterpret_cast<const char*>(placa),sizeof(char)*8);
    archFalt.write(reinterpret_cast<const char*>(&licencia),sizeof(int));
    archFalt.write(reinterpret_cast<const char*>(&fecha),sizeof(int));
    archFalt.write(reinterpret_cast<const char*>(gravedad),sizeof(char)*15);
    archFalt.write(reinterpret_cast<const char*>(&codigo),sizeof(int));
    archFalt.write(reinterpret_cast<const char*>(&b),sizeof(double));
}

bool verificarFinInfracciones(ifstream &arch) {
    arch>>ws;
    char c = arch.get();
    arch.unget();
    return c>='0' && c<='9';        
}

void escribirInfracciones(ofstream &archCond, int a, double b) {    
    archCond.write(reinterpret_cast<const char*>(&a),sizeof(int));
    archCond.write(reinterpret_cast<const char*>(&a),sizeof(int));
    archCond.write(reinterpret_cast<const char*>(&a),sizeof(int));
    archCond.write(reinterpret_cast<const char*>(&b),sizeof(double));
    archCond.write(reinterpret_cast<const char*>(&b),sizeof(double));
    archCond.write(reinterpret_cast<const char*>(&b),sizeof(double));
    archCond.write(reinterpret_cast<const char*>(&b),sizeof(double));
}

void crearReporteDeVerificacion(const char *nombArchTxt, const char *nombArchCond, 
        const char *nombArchFalt) {
    ofstream archTxt(nombArchTxt, ios::out);
    if (not archTxt.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchTxt<<endl;
        exit(1);
    }
    ifstream archConductores(nombArchCond, ios::in|ios::binary);
    if (not archConductores.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchCond<<endl;
        exit(1);
    }
    ifstream archFaltas(nombArchFalt, ios::in|ios::binary);
    if (not archFaltas.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchFalt<<endl;
        exit(1);
    }
    imprimirReporteDeVerificacion(archTxt, archConductores, archFaltas);
}

void imprimirReporteDeVerificacion(ofstream &archTxt, ifstream &archConductores, 
        ifstream &archFaltas) {    
    imprimirConductores(archTxt, archConductores);
    archTxt<<endl;
    imprimirFaltas(archTxt, archFaltas);    
}

void imprimirConductores(ofstream &archTxt, ifstream &archBin) {    
    int licencia, numLev, numGra, numMGrav;
    char nombre[60];
    double mLev, mGra, mMGrav, total;
    archTxt.precision(2);
    archTxt<<fixed;    
    while (true) {        
        leerArchivoConductores(archBin, licencia, nombre, numLev, numGra, 
                numMGrav, mLev, mGra, mMGrav, total);        
        archTxt<<left<<setw(10)<<licencia<<setw(40)<<nombre<<setw(5)<<numLev
                <<setw(5)<<numGra<<setw(7)<<numMGrav<<setw(7)<<mLev<<setw(7)
                <<mGra<<setw(7)<<mMGrav<<setw(7)<<total<<endl;
        archBin>>ws;
        if (archBin.eof()) break;
    }
}

void leerArchivoConductores(ifstream &archBin, int &licencia, char *nombre, 
        int &numLev, int &numGra, int &numMGrav, double &mLev, double &mGra, 
        double &mMGrav, double &total) {
    archBin.read(reinterpret_cast<char*>(&licencia),sizeof(int));
    archBin.read(reinterpret_cast<char*>(nombre),sizeof(char)*60);
    archBin.read(reinterpret_cast<char*>(&numLev),sizeof(int));
    archBin.read(reinterpret_cast<char*>(&numGra),sizeof(int));
    archBin.read(reinterpret_cast<char*>(&numMGrav),sizeof(int));
    archBin.read(reinterpret_cast<char*>(&mLev),sizeof(double));
    archBin.read(reinterpret_cast<char*>(&mGra),sizeof(double));
    archBin.read(reinterpret_cast<char*>(&mMGrav),sizeof(double));
    archBin.read(reinterpret_cast<char*>(&total),sizeof(double));
}

void imprimirFaltas(ofstream &archTxt, ifstream &archBin) {    
    char placa[8], gravedad[15];
    int licencia, fecha, codigo;
    double b=0;
    while (true) {        
        leerArchivoFaltas(archBin, placa, licencia, fecha, gravedad, codigo, b);  
        archTxt<<left<<setw(10)<<placa<<setw(10)<<licencia<<setw(5);
        imprimirFecha(archTxt, fecha);
        archTxt<<setw(3)<<" "<<left<<setw(10)<<gravedad<<setw(10)<<codigo
                <<setw(15)<<b<<endl;
        archBin>>ws;
        if (archBin.eof()) break;
    }
}

void leerArchivoFaltas(ifstream &archBin, char *placa, int &licencia, int &fecha, 
        char *gravedad, int &codigo, double &b) {
    archBin.read(reinterpret_cast<char*>(placa),sizeof(char)*8);
    archBin.read(reinterpret_cast<char*>(&licencia),sizeof(int));
    archBin.read(reinterpret_cast<char*>(&fecha),sizeof(int));
    archBin.read(reinterpret_cast<char*>(gravedad),sizeof(char)*15);
    archBin.read(reinterpret_cast<char*>(&codigo),sizeof(int));
    archBin.read(reinterpret_cast<char*>(&b),sizeof(double));
}

void imprimirFecha(ofstream &archTxt, int fecha) {
    int dd, mm, aaaa;
    separarFecha(fecha, dd, mm, aaaa);
    archTxt.fill('0');
    archTxt<<right<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)<<aaaa;
    archTxt.fill(' ');
    archTxt<<setw(7);
}

void separarFecha(int fecha, int &dd, int &mm, int &aaaa) {
    aaaa = fecha/10000;
    fecha -= aaaa*10000;    
    mm = fecha/100;
    dd = fecha - mm*100;
}

void crearArchInfracciones(const char *nombArchTxt, const char *nombArchBin) {    
    ifstream archTxt(nombArchTxt, ios::in);
    if (not archTxt.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchTxt<<endl;
        exit(1);
    }
    ofstream archBin(nombArchBin, ios::out|ios::binary);
    if (not archBin.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchBin<<endl;
        exit(1);
    }    
    leerInfracciones(archTxt, archBin);
}

void leerInfracciones(ifstream &archTxt, ofstream &archBin) {    
    int codigo;
    char descripcion[200], gravedad[15];
    double multa;    
    while (true) {        
        archTxt>>codigo;
        if (archTxt.eof()) break;
        archTxt>>descripcion>>gravedad>>multa;
        escribirDetallesDeInfracciones(archBin, codigo, descripcion, gravedad, 
                multa);
    }    
}

void escribirDetallesDeInfracciones(ofstream &archBin, int codigo, 
        char *descripcion, char *gravedad, double multa) {    
    archBin.write(reinterpret_cast<const char*>(&codigo),sizeof(int));
    archBin.write(reinterpret_cast<const char*>(descripcion),sizeof(char)*200);
    archBin.write(reinterpret_cast<const char*>(gravedad),sizeof(char)*15);
    archBin.write(reinterpret_cast<const char*>(&multa),sizeof(double));    
}

void crearReporteDeInfracciones(const char *nombArchTxt, const char *nombArchBin) {    
    ofstream archTxt(nombArchTxt, ios::out);
    if (not archTxt.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchTxt<<endl;
        exit(1);
    }
    ifstream archBin(nombArchBin, ios::in|ios::binary);
    if (not archBin.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchBin<<endl;
        exit(1);
    }    
    imprimirReporteDeInfracciones(archTxt, archBin);    
}

void imprimirReporteDeInfracciones(ofstream &archTxt, ifstream &archBin) {    
    int codigo;
    char descripcion[200], gravedad[15];
    double multa;    
    while (true) {        
        leerDetallesDeInfracciones(archBin, codigo, descripcion, gravedad, multa);
        if (archBin.eof()) break;
        archTxt.precision(2);
        archTxt<<fixed;
        archTxt<<left<<setw(8)<<codigo<<setw(200)<<descripcion<<setw(20)
                <<gravedad<<multa<<endl;
    }    
}

void leerDetallesDeInfracciones(ifstream &archBin, int &codigo, char *descripcion, 
        char *gravedad, double &multa) {
    archBin.read(reinterpret_cast<char*>(&codigo),sizeof(int));
    if (archBin.eof()) return;
    archBin.read(reinterpret_cast<char*>(descripcion),sizeof(char)*200);
    archBin.read(reinterpret_cast<char*>(gravedad),sizeof(char)*15);
    archBin.read(reinterpret_cast<char*>(&multa),sizeof(double));    
}

void completarBinarios(const char *nombArchCond, const char *nombArchFalt, 
        const char *nombArchInf) {    
    fstream archCond(nombArchCond, ios::in|ios::out|ios::binary);
    if (not archCond.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchCond<<endl;
        exit(1);
    }  
    fstream archFalt(nombArchFalt, ios::in|ios::out|ios::binary);
    if (not archFalt.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchFalt<<endl;
        exit(1);
    }  
    ifstream archInf(nombArchInf, ios::in|ios::binary);
    if (not archInf.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchInf<<endl;
        exit(1);
    }
    llenarMultaFaltas(archFalt, archInf);
    modificarArchConductores(archCond, archFalt);    
}

void llenarMultaFaltas(fstream &archFalt, ifstream &archInf) {    
    int tamReg, tamArch, numReg, codigo;
    double multa;
    archFalt.seekg(0, ios::end);
    tamReg = sizeof(char)*8 + sizeof(int) + sizeof(int) + sizeof(char)*15 + 
            sizeof(int) + sizeof(double);
    tamArch = archFalt.tellg();
    numReg = tamArch/tamReg;    
    for (int i=0; i<numReg-1; i++) {
        archFalt.seekg(tamReg*i+sizeof(char)*8 + sizeof(int) + sizeof(int) + 
                sizeof(char)*15, ios::beg);
        archFalt.read(reinterpret_cast<char*>(&codigo), sizeof(int));
        multa = buscarMulta(codigo, archInf);
        archFalt.write(reinterpret_cast<const char*>(&multa), sizeof(double));
        archFalt.flush();
    }
}

double buscarMulta(int codigo, ifstream &archInf) {    
    int tamReg, tamArch, numReg, codReg;
    double multa;
    archInf.seekg(0, ios::end);
    tamReg = sizeof(int) + sizeof(char)*200 + sizeof(char)*15 + sizeof(double);
    tamArch = archInf.tellg();
    numReg = tamArch/tamReg;
    for (int i=0; i<numReg-1; i++) {
        archInf.seekg(tamReg*i, ios::beg);
        archInf.read(reinterpret_cast<char*>(&codReg), sizeof(int));   
        if (codigo==codReg) {  
            archInf.seekg(sizeof(char)*200 + sizeof(char)*15, ios::cur);
            archInf.read(reinterpret_cast<char*>(&multa), sizeof(double));  
            return multa;
        }
    }
} 

/*  archBin.read(reinterpret_cast<char*>(&licencia),sizeof(int));
    archBin.read(reinterpret_cast<char*>(nombre),sizeof(char)*60);
    archBin.read(reinterpret_cast<char*>(&a),sizeof(int));
    archBin.read(reinterpret_cast<char*>(&a),sizeof(int));
    archBin.read(reinterpret_cast<char*>(&a),sizeof(int));
    archBin.read(reinterpret_cast<char*>(&b),sizeof(double));
    archBin.read(reinterpret_cast<char*>(&b),sizeof(double));
    archBin.read(reinterpret_cast<char*>(&b),sizeof(double));
    archBin.read(reinterpret_cast<char*>(&b),sizeof(double));    */


void modificarArchConductores(fstream &archCond, fstream &archFalt) {
    int licencia, numLev, numGra, numMGrav, tamReg, tamArch, numReg;
    char nombre[60];
    double mLev, mGra, mMGrav, total;  
    archCond.seekg(0, ios::end);
    tamReg = sizeof(int) + sizeof(char)*60 + sizeof(int)*3 + sizeof(double)*4;    
    tamArch = archCond.tellg();
    numReg = tamArch/tamReg;
    for (int i=0; i<numReg; i++) {        
        archCond.seekg(tamReg*i, ios::beg);
        archCond.read(reinterpret_cast<char*>(&licencia),sizeof(int));
        archCond.read(reinterpret_cast<char*>(nombre),sizeof(char)*60);
        numLev = numGra = numMGrav = mLev = mGra = mMGrav = 0;
        buscarFaltas(licencia, numLev, numGra, numMGrav, mLev, mGra, mMGrav, 
                archFalt);
        total = mLev + mGra + mMGrav;
        archCond.write(reinterpret_cast<const char*>(&numLev),sizeof(int));
        archCond.write(reinterpret_cast<const char*>(&numGra),sizeof(int));
        archCond.write(reinterpret_cast<const char*>(&numMGrav),sizeof(int));
        archCond.write(reinterpret_cast<const char*>(&mLev),sizeof(double));
        archCond.write(reinterpret_cast<const char*>(&mGra),sizeof(double));
        archCond.write(reinterpret_cast<const char*>(&mMGrav),sizeof(double));        
        archCond.write(reinterpret_cast<const char*>(&total),sizeof(double));
        archCond.flush();
    }
}

void buscarFaltas(int licencia, int &numLev, int &numGra, int &numMGrav, 
        double &mLev, double &mGra, double &mMGrav, fstream &archFalt) {    
    int tamReg, numReg, tamArch, licenciaReg, codigo;
    char gravedad[15];
    double monto;
    archFalt.seekg(0, ios::end);
    tamReg = sizeof(char)*8 + sizeof(int) + sizeof(int) + sizeof(char)*15 + 
            + sizeof(int) + sizeof(double);
    tamArch = archFalt.tellg();
    numReg = tamArch/tamReg;    
    for (int i=0; i<numReg-1; i++) {
        archFalt.seekg(tamReg*i + sizeof(char)*8,ios::beg);
        archFalt.read(reinterpret_cast<char*>(&licenciaReg), sizeof(int));             
        if (licencia==licenciaReg) {                    
            archFalt.seekg(sizeof(int),ios::cur);
            archFalt.read(reinterpret_cast<char*>(gravedad), sizeof(char)*15);
            archFalt.read(reinterpret_cast<char*>(&codigo), sizeof(int));
            archFalt.read(reinterpret_cast<char*>(&monto), sizeof(double));            
            if (gravedad[0]=='L') {
                mLev += monto;
                numLev++;
            } else if (gravedad[0]=='G') {
                mGra += monto;
                numGra++;
            } else if (gravedad[0]=='M') {
                mMGrav += monto;
                numMGrav++;
            }
            break;
        }
    }
}