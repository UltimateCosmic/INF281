#include <iostream>
#include <iomanip>
using namespace std;

#include "FuncionesAuxiliares.h"
#define MAX_LINEA 113

void imprimirCabeceraPrincipal(int &fechaDocentes, int &fechaEstudiantes, 
        int &fechaPersonal) {
    cout<<setw(75)<<"BIBLIOTECA GENERAL DE LA UNIVERSIDAD"<<endl;
    imprimirLinea('=', MAX_LINEA);
    imprimirFechasLimite(fechaDocentes, fechaEstudiantes, fechaPersonal);
}

void imprimirLinea(char c, int n) {
    for (int i=0; i<n; i++) cout.put(c);
    cout.put('\n');
}

void imprimirFechasLimite(int &fechaDocentes, int &fechaEstudiantes, 
        int &fechaPersonal) {
    cout<<"Fechas limite de devolucion:"<<endl;
    cout<<setw(17)<<"Docentes: "<<setw(9);
    fechaDocentes = leerFecha();
    cout<<setw(20)<<"Estudiantes: "<<setw(6);
    fechaEstudiantes = leerFecha();
    cout<<setw(23)<<"Administrativo: "<<setw(3);
    fechaPersonal = leerFecha();
}

int leerFecha() {    
    int dd, mm, aaaa;
    char c;
    cin>>dd>>c>>mm>>c>>aaaa;
    cout<<dd<<"/"<<mm<<"/"<<aaaa<<endl;
    return juntarFecha(dd,mm,aaaa);
}

int juntarFecha(int dd, int mm, int aaaa) {
    return aaaa*10000+mm*100+dd;
}

void imprimirReporte(int fechaDocentes, int fechaEstudiantes, 
        int fechaPersonal) {    
    int carne, fechaLimite;
    char calidad, nombre[60];
    while (true) {
        cin>>carne;
        if (cin.eof()) break;
        cin>>calidad>>nombre;
        fechaLimite = elegirFechaLimite(calidad, fechaDocentes, fechaPersonal,
                fechaEstudiantes);
        imprimirUsuario(carne, calidad, nombre, fechaLimite);
    }
}

int elegirFechaLimite(char calidad, int fechaDocentes, int fechaPersonal, 
        int fechaEstudiantes) {
    int fechaLimite;
    switch (calidad) {
        case 'D':
            fechaLimite = fechaDocentes;
            break;
        case 'A':
            fechaLimite = fechaPersonal;
            break;
        case 'E':
            fechaLimite = fechaEstudiantes;
            break;
    }
    return fechaLimite;   
}

void corregirNombre(char nombre[]) {
    for (int i=0; nombre[i]!=0; i++)
        if (nombre[i]>='a' && nombre[i]<='z')
            nombre[i] = convertirMayuscula(nombre[i]);            
}

char convertirMayuscula(char nombre) {
    return nombre-32;
}

void imprimirUsuario(int carne, char calidad, char *nombre, int fechaLimite) {
    corregirNombre(nombre);
    imprimirCabeceraUsuario(carne, calidad, nombre);
    int librosAdeudados=0, i=0;
    double totalDeudas=0;
    while (true) {        
        librosAdeudados += imprimirLibro(i, fechaLimite, calidad, totalDeudas);
        if (finDeLectura()) break;
        i++;
    }
    imprimirLinea('=', MAX_LINEA);
    imprimirResumen(i, totalDeudas);
    imprimirLinea('=', MAX_LINEA);
    imprimirLinea('/', MAX_LINEA);
}

void imprimirCabeceraUsuario(int carne, char calidad, char *nombre) {
    imprimirLinea('-', MAX_LINEA);
    cout<<setw(21)<<"USUARIO"<<setw(74)<<"LIBROS PRESTADOS"<<endl;
    imprimirLinea('-', MAX_LINEA);
    cout<<"Carne No."<<setw(11)<<"Nombre"<<setw(31)<<"Tipo"<<setw(25)<<"Codigo"
            <<setw(18)<<"F. de retiro"<<setw(15)<<"Observacion"<<endl;
    imprimirLinea('-', MAX_LINEA);
    cout<<left<<setw(14)<<carne<<setw(33)<<nombre<<left;
    imprimirCategoria(calidad);
}

void imprimirCategoria(char calidad) {
    if (calidad=='A')
        cout<<setw(23)<<"Administrativo";
    else if (calidad=='E')
        cout<<setw(23)<<"Estudiante";
    else if (calidad=='D')
        cout<<setw(23)<<"Docente";
}

int imprimirLibro(int i, int fechaLimite, char calidad, double &totalDeudas) {
    int  dd, mm, aaaa, adeudado;
    double valor, multa;
    char codigo[8], c, n;
    cin>>codigo>>dd>>c>>mm>>c>>aaaa>>valor;
    if( i==0) n=0;
    else n=77;
    cout<<right<<setw(n)<<codigo<<setw(7)<<" ";
    imprimirFechaDeRetiro(dd, mm, aaaa);    
    imprimirObservacion(dd, mm, aaaa, fechaLimite, valor, calidad, adeudado, 
            totalDeudas);
    return adeudado;
}

void imprimirFechaDeRetiro(int dd, int mm, int aaaa) {
    cout.fill('0');
    cout<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)<<aaaa;
    cout.fill(' ');
}

void imprimirObservacion(int dd, int mm, int aaaa, int fechaLimite, 
        double valor, char calidad, int &n, double &totalDeudas) {
    double multa=0;
    if (juntarFecha(dd, mm, aaaa)<fechaLimite) {
        cout<<setw(12)<<"EN DEUDA"<<endl;
        cout.precision(2);
        cout<<fixed;
        multa=calcularMulta(valor, calidad);
        cout<<setw(107)<<"Multa: $ "<<multa<<endl;
        cout.fixed;
        n=1;
    } else {
        cout<<setw(7)<<"---"<<endl;
        n=0;
    }
    totalDeudas+=multa;
}

double calcularMulta(double valor, char calidad) {
    switch (calidad) {
        case 'D':
            return calcularPorcentaje(valor, 2.25);
        case 'A':
            return calcularPorcentaje(valor, 1.5);
        case 'E':
            return calcularPorcentaje(valor, 1);
    }
}

double calcularPorcentaje(double valor, double porcentaje) {
    return 1.5*valor/100;
}

bool finDeLectura() {
    cin>>ws;
    if (cin.eof())
        return true;
    else {
        char c = cin.get();
        cin.unget();    
        if (c>='0' && c<='9')
            return true;
        else
            return false;
    }
}

void imprimirResumen(int cantidadLibrosAdeudados, double totalDeudas) {
    cout<<setw(7)<<" "<<left<<setw(36)<<"Cantidad de libros adeudados:"<<cantidadLibrosAdeudados<<right<<endl;
    cout<<setw(7)<<" "<<left<<setw(36)<<"Total de deudas por multa:"<<totalDeudas<<right<<endl;
}