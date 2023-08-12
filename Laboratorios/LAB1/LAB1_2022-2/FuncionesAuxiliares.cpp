#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "FuncionesAuxiliares.h"
#define MAX_LINEA 120

void leerEspecialidadesYFecha(char especialidadA[], char especialidadB[], 
        int &fechaDelProceso) {    
    int dd, mm, aaaa;
    char c;
    cin>>especialidadA>>especialidadB>>dd>>c>>mm>>c>>aaaa;
    imprimirCabeceraPrincipal(especialidadA, especialidadB, dd, mm, aaaa);
    fechaDelProceso = juntarFecha(dd, mm, aaaa);
}

void imprimirCabeceraPrincipal(char especialidadA[], char especialidadB[], 
        int dd, int mm, int aaaa) {    
    cout<<setw(71)<<"EMPRESA PRESTADORA DE SALUD"<<endl;
    imprimirLinea('=', MAX_LINEA);
    cout<<"ESPECIALIDADES A VERIFICAR: "<<especialidadA<<" Y "<<especialidadB
            <<endl;
    cout.fill('0');
    cout<<"FECHA DEL PROCESO: "<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)
            <<aaaa<<endl;
    cout.fill(' ');
}

void imprimirLinea(char c, int n) {
    for (int i=0; i<n; i++) cout.put(c);
    cout.put('\n');
}

int juntarFecha(int dd, int mm, int aaaa) {
    return aaaa*10000 + mm*100 + dd;
}

void imprimirReporteDeEmpresa(char especialidadA[], char especialidadB[], 
        int fechaDelProceso) {    
    int cantMedA=0, cantMedB=0, cantPacA=0, cantPacB=0, cantVenA=0, cantVenB=0;
    char codigo[8], nombre[60], especialidad[20];
    while (true) {
        if (not leerDatosMedico(codigo, nombre)) break;        
        if (perteneceEspecialidad(nombre, especialidadA)) 
            imprimirTablaDeMedico(codigo, nombre, cantMedA, cantPacA, cantVenA,
                    especialidadA, fechaDelProceso);
        else if (perteneceEspecialidad(nombre, especialidadB))
            imprimirTablaDeMedico(codigo, nombre, cantMedB, cantPacB, cantVenB,
                    especialidadB, fechaDelProceso);
        else
            saltarHastaSiguienteMedico();
    }
    imprimirResumen(cantMedA, cantPacA, cantVenA, cantMedB, cantPacB, cantVenB, 
            especialidadA, especialidadB);
}

bool leerDatosMedico(char codigo[], char nombre[]) {    
    cin>>codigo;
    if (cin.eof()) return false;
    cin>>nombre;
    return true;
}

bool perteneceEspecialidad(char nombre[], char especialidad[]) {
    int j = 0, k = 0;
    char comparar[20];
    for (int i=0; nombre[i]!=0; i++) {
        if (nombre[i]=='_') {
            j = 0;
            k = i;
        }           
        else {
            comparar[j] = nombre[i];
            comparar[j] = convertirMayuscula(comparar[j]);
            j++;
        }            
    }
    comparar[j] = 0;    
    if (strcmp(comparar, especialidad)==0) return true;
    else return false;
}

char convertirMayuscula(char c) {
    if (c>='A' && c<='Z') return c;
    else return c-32;
}

void imprimirTablaDeMedico(char codigo[], char nombre[], int &cantMed, 
        int &cantPac, int &cantVen, char especialidad[], 
        int fechaDelProceso) {
    imprimirCabeceraSecundaria(nombre, codigo, especialidad);
    imprimirPacientes(cantMed, cantPac, cantVen, fechaDelProceso);
}

void imprimirCabeceraSecundaria(char nombre[], char codigo[], 
        char especialidad[]) {
    imprimirLinea('=', MAX_LINEA);
    cout<<left<<setw(8)<<"Medico:"<<setw(60)<<nombre<<"Especialidad: "
            <<especialidad<<endl;
    imprimirLinea('-', MAX_LINEA);    
    cout<<right<<setw(30)<<"Pacientes atendidos"<<setw(62)
            <<"Medicinas Recibidas"<<endl;
    imprimirLinea('-', MAX_LINEA);    
    cout<<setw(8)<<"DNI"<<setw(13)<<"Nombre"<<setw(27)<<"Cantidad"<<setw(10)
            <<"Codigo"<<setw(15)<<"Descripcion"<<setw(32)<<"F. de V"<<setw(15)
            <<"Observacion"<<endl;
    imprimirLinea('-', MAX_LINEA);
}

void imprimirPacientes(int &cantMed, int &cantPac, int &cantVen, 
        int fechaDelProceso) {    
    int i=0, dni, cantidad;
    char nombre[60];    
    while (true) {
        cin>>dni;
        if (verificarFinPacientes()) break;
        cin>>nombre>>cantidad;
        leerMedicamentos(i, dni, nombre, cantMed, cantVen, fechaDelProceso, 
                cantidad);
        i++;
    }
    cantPac+=i;
}

bool verificarFinPacientes() {
    if (cin.fail()) {
        cin.clear();
        return true;        
    }
    return false;
}

void leerMedicamentos(int i, int dni, char nombre[], int &cantMed, int &cantVen, 
        int fechaDelProceso, int cantidad) {    
    imprimirPaciente(i, dni, nombre, cantidad);
    int cant, codigo, dd, mm, aaaa, j=0;
    char descripcion[40], c;
    for (int k=0; k<cantidad; k++) {
        cin>>codigo>>descripcion>>dd>>c>>mm>>c>>aaaa;
        imprimirMedicamento(j, codigo, descripcion, dd, mm, aaaa, cantVen,
                fechaDelProceso);
        j++;
    }   
    cantMed += j;
}

void imprimirPaciente(int i, int dni, char nombre[], int cant) {
    cout.fill('0');
    cout<<right<<setw(2)<<i<<") ";
    cout.fill(' ');
    cout<<left<<setw(11)<<dni<<setw(29)<<nombre<<setw(8)<<cant;
}

void imprimirMedicamento(int j, int codigo, char descripcion[], int dd, int mm, 
        int aaaa, int &cantVen, int fechaDelProceso) {    
    int n=57;
    if (j==0){
        n=0;
        cout<<setw(n)<<codigo;
    }
    else 
        cout<<right<<setw(n)<<codigo;
    cout<<left<<setw(5)<<" "<<setw(36)<<descripcion;
    cout.fill('0');
    cout<<right<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aaaa;
    cout.fill(' ');
    imprimirVencida(fechaDelProceso, juntarFecha(dd, mm, aaaa), cantVen);
}

void imprimirVencida(int fechaDelProceso, int fechaVenc, int &cantVen) {
    if (fechaVenc<fechaDelProceso) {
        cout<<setw(10)<<"VENCIDA";
        cantVen++;
    }
    cout<<endl;    
}

void saltarHastaSiguienteMedico() {
    int dni, cant, codigo, dd, mm, aaaa, cantidad;
    char descripcion[40], nombre[60], c;    
    while (true) {
        cin>>dni;
        if (verificarFinPacientes()) break;
        cin>>nombre>>cantidad;        
        for (int k=0; k<cantidad; k++)
            cin>>codigo>>descripcion>>dd>>c>>mm>>c>>aaaa;  
    }   
}

void imprimirResumen(int cantMedA, int cantPacA, int cantVenA, int cantMedB, 
        int cantPacB, int cantVenB, char espA[], char espB[]) {    
    imprimirLinea('=', MAX_LINEA);
    cout<<"RESUMEN"<<endl;
    imprimirResumenEspecialidad(cantMedA, cantPacA, cantVenA, espA, 2);    
    imprimirResumenEspecialidad(cantMedB, cantPacB, cantVenB, espB, 4);       
    imprimirLinea('=', MAX_LINEA);    
}

void imprimirResumenEspecialidad(int cantMed, int cantPac, int cantVen, 
        char especialidad[], int n) {
    cout<<left<<"Especialidad "<<especialidad<<setw(n)<<":"<<right;
    cout.fill('0');
    cout<<setw(2)<<cantMed<<" medicos, ";
    cout.fill(' ');
    cout<<setw(2)<<cantPac<<" pacientes, ";
    cout<<setw(2)<<cantVen<<" medicinas vencidas."<<endl;
}