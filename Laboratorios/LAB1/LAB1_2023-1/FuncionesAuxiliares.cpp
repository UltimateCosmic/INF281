#include <iostream>
#include <iomanip>
using namespace std;

#include "FuncionesAuxiliares.h"
#define MAX_LINEA 110

void imprimirCabeceraPrincipal() {    
    cout<<setw(69)<<"ENTIDAD EDUCATIVA LP1"<<endl;
    cout<<setw(67)<<"LISTADOS DE CLASE"<<endl;    
}

void imprimirReporteDeListadoDeClase() { 
    int codigoProfesor, cont=0;
    char codigoCurso[7], nombreCurso[50], nombreProfesor[60];
    double creditos, totalGeneral = 0;        
    while (true) {
        cin>>codigoCurso;
        if (cin.eof()) break;
        cin>>nombreCurso>>creditos>>codigoProfesor>>nombreProfesor;
        imprimirInformacionCurso(++cont, nombreCurso, codigoCurso, nombreProfesor, 
                codigoProfesor, creditos, totalGeneral);
    }
    imprimirTotalGeneral(totalGeneral);
}

void imprimirInformacionCurso(int cont, char nombreCurso[], char codigoCurso[], 
        char nombreProfesor[], int codigoProfesor, double creditos, 
        double &totalGeneral) {
    imprimirCabeceraCurso(cont, nombreCurso, codigoCurso, nombreProfesor, 
            codigoProfesor, creditos);
    imprimirAlumnosMatriculados(creditos, totalGeneral);
}

void imprimirCabeceraCurso(int cont, char nombreCurso[], char codigoCurso[], 
        char nombreProfesor[], int codigoProfesor, double creditos) {
    imprimirLinea('=', MAX_LINEA);
    cout.fill('0');
    cout<<right<<setw(2)<<cont<<")";
    cout.fill(' ');
    cout.precision(2);
    cout<<fixed;
    corregirNombreCurso(nombreCurso);
    cout<<left<<setw(6)<<" "<<setw(15)<<"Curso:"<<nombreCurso<<" ["
            <<codigoCurso<<"]"<<endl;
    corregirNombreUsuario(nombreProfesor);
    cout<<setw(9)<<" "<<setw(15)<<"Profesor:"<<nombreProfesor<<" ("
            <<codigoProfesor<<")"<<endl;
    cout<<setw(9)<<" "<<setw(17)<<"Creditos:"<<creditos<<right<<endl;
}

void imprimirLinea(char c, int n) {
    for (int i=0; i<n; i++) cout.put(c);
    cout.put('\n');    
}

void corregirNombreCurso(char nombre[]) {    
    for (int i=0; nombre[i]!=0; i++) {
        nombre[i] = convertirMayuscula(nombre[i]);  
        if (nombre[i]=='_') nombre[i] = ' ';
    }          
}

char convertirMayuscula(char c) {
    return (c>='a' && c<='z')?c-32:c;    
}

void corregirNombreUsuario(char nombre[]) {   
    for (int i=1; nombre[i]!=0; i++) {        
        nombre[i] = convertirMinuscula(nombre[i]);
        if (nombre[i]=='_' || nombre[i]=='/' || nombre[i]=='-') {
            nombre[i] = ' ';
            i++;
        }            
    }          
}

char convertirMinuscula(char c) {
    return (c>='A' && c<='Z')?c+32:c;    
}

void imprimirAlumnosMatriculados(double creditos, double &totalGeneral) {    
    imprimirCabeceraAlumnos();        
    int semestre, codigo, escala, i=0, porcVirtualidad;
    char c, nombre[60], modalidad;
    double recaudacionP=0, recaudacionS=0, recaudacionV=0;    
    while (true) {        
        cin>>semestre>>c>>codigo>>nombre;
        leerDatosDeModalidad(modalidad, porcVirtualidad);
        cin>>escala;
        imprimirAlumno(++i, codigo, semestre, nombre, escala, modalidad, 
                porcVirtualidad, recaudacionP, recaudacionS, recaudacionV, 
                creditos);
        cin>>ws;
        if (cin.eof() || verificarFinDeAlumnos()) break;        
    }
    imprimirRecaudacionPorModalidad(recaudacionP, recaudacionS, recaudacionV);
    totalGeneral += (recaudacionP + recaudacionS + recaudacionV);
}

void imprimirCabeceraAlumnos() {    
    imprimirLinea('-', MAX_LINEA);
    cout<<"ALUMNOS Matriculados"<<endl;
    imprimirLinea('-', MAX_LINEA);
    cout<<setw(87)<<"PAGOS"<<endl;
    cout<<setw(9)<<"CODIGO"<<setw(10)<<"SEMESTRE"<<setw(8)<<"NOMBRE"<<setw(36)
            <<"ESCALA"<<setw(13)<<"PRESENCIAL"<<setw(18)<<"SEMI PRESENCIAL"
            <<setw(14)<<"VIRTUAL"<<endl;    
    imprimirLinea('-', MAX_LINEA);
}

void leerDatosDeModalidad(char &modalidad, int &porcVirtualidad) {    
    cin>>ws;
    char c = cin.get();   
    if (c=='V') {
        modalidad = 'V';
        porcVirtualidad = 0;
    } else if (c=='S') { 
        int dato;
        modalidad = 'S';
        cin>>dato;
        porcVirtualidad = dato;
    } else {
        cin.unget();
        modalidad = 'P';
        porcVirtualidad = 0;        
    }    
}

void imprimirAlumno(int i, int codigo, int semestre, char nombre[], int escala, 
        char modalidad, double porcVirtualidad, double &recaudacionP, 
        double &recaudacionS, double &recaudacionV, double creditos) {    
    cout.fill('0');
    cout<<right<<setw(2)<<i<<")";
    cout.fill(' ');
    corregirNombreUsuario(nombre);
    cout<<setw(5)<<codigo<<setw(8);
    imprimirCodigoString(semestre);
    cout<<setw(3)<<" "<<left<<setw(40)<<nombre<<setw(7)
            <<escala<<right;    
    double recaudacion;
    if (modalidad=='P') {
        recaudacion = pagoPorEscala(escala)*creditos;
        recaudacionP += recaudacion;
        cout<<setw(5);
    } else if (modalidad=='S') {
        recaudacion = pagoPorEscala(escala)*creditos*((double)porcVirtualidad/100);
        recaudacionS += recaudacion;
        cout<<setw(23);
    } else if (modalidad=='V') {
        recaudacion = pagoPorEscala(escala)*creditos*0.45;
        recaudacionV += recaudacion;
        cout<<setw(40);
    }
    cout<<recaudacion<<endl;
}

void imprimirCodigoString(int semestre) {
    int dato1, dato2;
    dato1 = semestre/10;
    dato2 = semestre%10;
    cout<<semestre/10<<'-'<<semestre%10;
}

double pagoPorEscala(int escala) {
    switch (escala) {
        case 5:
            return 666.90;
        case 4: 
            return 556.70;
        case 3:
            return 454.20;
        case 2: 
            return 362.00;
        case 1:
            return 282.30;
    }    
}

bool verificarFinDeAlumnos() {
    cin>>ws;
    char c = cin.get();
    cin.unget();
    return (c>='A' && c<='Z')?true:false;    
}

void imprimirRecaudacionPorModalidad(double recaudacionP, double recaudacionS, 
        double recaudacionV) {    
    imprimirLinea('=', MAX_LINEA);
    cout.precision(2);
    cout<<fixed;
    cout<<left<<setw(67)<<"RECAUDACION POR MODALIDAD DE ESTUDIO"<<setw(16)
            <<recaudacionP<<setw(16)<<recaudacionS<<recaudacionV<<endl;
    imprimirLinea('-', MAX_LINEA);
    cout<<setw(99)<<"TOTAL RECAUDADO:"<<recaudacionP+recaudacionS+recaudacionV
            <<endl;
    imprimirLinea('-', MAX_LINEA);
}

void imprimirTotalGeneral(double totalGeneral) {
    cout.precision(2);
    cout<<fixed;
    cout<<right<<"TOTAL GENERAL RECAUDADO: "<<setw(82)<<totalGeneral<<endl;    
    imprimirLinea('=', MAX_LINEA);
}