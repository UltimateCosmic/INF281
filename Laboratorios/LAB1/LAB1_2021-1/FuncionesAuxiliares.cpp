#include <iostream>
#include <iomanip>
#include <ostream>
#include <ios>
#include <istream>
#include <streambuf>
using namespace std;

#include "FuncionesAuxiliares.h"
#define MAX_LINEA 110

void imprimirCabeceraPrincipal() {    
    cout<<setw(60)<<"REGULADORA DE TRANSPORTE URBANO"<<endl;
}

void imprimirReporteDeReguladora() {
    int licencia;
    char nombre[60];
    while (true) {
        cin>>licencia;
        if (cin.eof()) break;
        cin>>nombre;
        imprimirReporteConductor(licencia, nombre);
    }   
}

void imprimirReporteConductor(int licencia, char nombre[]) {
    imprimirCabeceraSecundaria();
    imprimirConductor(licencia, nombre);
    int i=0, dd, mm, aaaa, cLeves=0, cGraves=0, cMuyGraves=0, pLeves=0, 
            pGraves=0, pMuyGraves=0;
    char placa[8], infraccion[5], palabraMulta[7], c;
    double multa, mLeves=0, mGraves=0, mMuyGraves=0;
    while (true) {
        leerInfraccion(placa, dd, mm, aaaa, infraccion, palabraMulta, multa);
        if(cin.eof()) break;
        imprimirInfraccion(cLeves, cGraves, cMuyGraves, pLeves, pGraves, 
                pMuyGraves, mLeves, mGraves, mMuyGraves, placa, dd, mm, aaaa, 
                infraccion, multa, i);
        if(verificarFinDeInfracciones()) break;
        i++;
    }
    imprimirResumen(cLeves, cGraves, cMuyGraves, pLeves, pGraves, pMuyGraves, 
            mLeves, mGraves, mMuyGraves);
}

void imprimirCabeceraSecundaria() {
    imprimirLinea('=', MAX_LINEA);
    cout<<setw(25)<<"CONDUCTOR"<<setw(70)<<"INFRACCIONES"<<endl;
    imprimirLinea('-', MAX_LINEA);
    cout<<"Licencia No."<<setw(8)<<"Nombre"<<setw(31)<<"Placa"<<setw(15)
            <<"Fecha"<<setw(13)<<"Codigo"<<setw(12)<<"Gravedad"<<setw(10)
            <<"Puntos"<<setw(9)<<"Multa"<<endl;
    imprimirLinea('-', MAX_LINEA);
}

void imprimirLinea(char c, int n) {
    for (int i=0; i<n; i++) cout.put(c);
    cout.put('\n');
}

void imprimirConductor(int licencia, char nombre[]) {
    cout<<left<<setw(13)<<licencia<<setw(33)<<nombre;
}

void leerInfraccion(char placa[], int &dd, int &mm, int &aaaa, 
        char infraccion[], char palabraMulta[], double &multa) {
    cin>>placa;
    if (cin.eof()) return;
    cin>>dd>>mm;
    if (cin.fail()) {
        aaaa=dd;
        mm=dd=0;
        cin.clear();
        cin>>infraccion>>palabraMulta>>multa;
    } else {
        cin>>aaaa;
        if (cin.fail()) {
            aaaa=mm;
            mm=dd;
            dd=0;
            cin.clear();
        }
        cin>>infraccion>>palabraMulta>>multa;
    }
}

void imprimirInfraccion(int &cLeves, int &cGraves, int &cMuyGraves, int &pLeves, 
        int &pGraves, int &pMuyGraves, double &mLeves, double &mGraves, 
        double &mMuyGraves, char placa[], int dd, int mm, int aaaa, 
        char infraccion[], double multa, int i) {
    char n;
    i==0?n=6:n=53;    
    cout<<right<<setw(n)<<placa<<setw(8)<<" ";        
    imprimirFecha(dd, mm, aaaa);
    cout<<setw(8)<<infraccion<<setw(6)<<" ";
    imprimirDetallesInfraccion(cLeves, cGraves, cMuyGraves, pLeves, pGraves, 
                pMuyGraves, mLeves, mGraves, mMuyGraves, infraccion, multa);
}

void imprimirFecha(int dd, int mm, int aaaa) {
    cout.fill('0');
    cout<<setw(2);
    if(dd==0) cout<<"--";
    else cout<<dd;
    cout<<"/"<<setw(2);
    if(mm==0) cout<<"--";
    else cout<<mm;
    cout<<"/"<<setw(4)<<aaaa;
    cout.fill(' ');
}

void imprimirDetallesInfraccion(int &cLeves, int &cGraves, int &cMuyGraves, 
        int &pLeves, int &pGraves, int &pMuyGraves, double &mLeves, 
        double &mGraves, double &mMuyGraves, char infraccion[], double multa) {
    cout.precision(2);
    cout<<fixed;
    switch (infraccion[0]) {
        case 'L':
            cout<<"Leve"<<right<<setw(11)<<5<<setw(10)<<multa<<endl;
            cLeves++;
            pLeves+=5;
            mLeves+=multa;
            break;
        case 'G':
            cout<<"Grave"<<right<<setw(10)<<70<<setw(10)<<multa<<endl;
            cGraves++;
            pGraves+=70;
            mGraves+=multa;
            break;
        case 'M':
            cout<<"Muy grave"<<right<<setw(6)<<150<<setw(10)<<multa<<endl;
            cMuyGraves++;
            pMuyGraves+=150;
            mMuyGraves+=multa;
            break;
    }
}

bool verificarFinDeInfracciones() {
    cin>>ws;
    char c = cin.get();
    cin.unget();    
    return (c>='0' && c<='9')?true:false;
}

void imprimirResumen(int cLeves, int cGraves, int cMuyGraves, int pLeves, 
        int pGraves, int pMuyGraves, double mLeves, double mGraves, 
        double mMuyGraves) {    
    imprimirCabeceraResumen();
    cout<<left<<setw(24)<<"Multas leves: "<<right<<cLeves<<setw(20)<<mLeves<<setw(20)
            <<pLeves<<endl;
    cout<<left<<setw(24)<<"Multas graves: "<<right<<cGraves<<setw(20)<<mGraves<<setw(20)
            <<pGraves<<endl;
    cout<<left<<setw(24)<<"Multas muy graves: "<<right<<cMuyGraves<<setw(20)
            <<mMuyGraves<<setw(20)<<pMuyGraves<<endl<<right;
    imprimirTotal(cLeves+cGraves+cMuyGraves, mLeves+mGraves+mMuyGraves, 
            pLeves+pGraves+pMuyGraves);
}

void imprimirCabeceraResumen() {
    imprimirLinea('=', MAX_LINEA);
    cout<<"RESUMEN:"<<endl;
    cout<<"Gravedad"<<setw(20)<<"Cantidad"<<setw(20)<<"Multas pagadas"<<right
            <<setw(20)<<"Puntos perdidos"<<endl;
}

void imprimirTotal(int cTotal, double mTotal, int pTotal) {
    imprimirLinea('-', MAX_LINEA);
    cout.precision(2);
    cout<<fixed;
    cout<<"Total:"<<setw(19)<<cTotal<<setw(20)<<mTotal<<setw(20)<<pTotal<<endl;
    imprimirLinea('=', MAX_LINEA);
    imprimirLinea('/', MAX_LINEA);
}