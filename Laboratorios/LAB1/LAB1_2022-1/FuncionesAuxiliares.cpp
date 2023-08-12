#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "FuncionesAuxiliares.h"
#define MAX_LINEA 130

void leerDescuentos(double &descA, double &descB, double &descC, 
        char producto[]) {    
    char c;
    cin>>c>>descA>>c>>c>>descB>>c>>c>>descC>>c>>producto;
}

void imprimirReporteDeGastos(double descA, double descB, double descC, 
        char producto[]) {
    imprimirCabeceraPrincipal();    
    int dni, telefono;
    double mayorDescuento = 0, totalIngresoProducto = 0;
    char nombre[60], clienteConMasDescuento[60], nombreProducto[30];    
    while (true) {
        cin>>dni;
        if (cin.eof()) break;
        cin>>nombre>>telefono;
        imprimirGastosDeCliente(dni, nombre, telefono, descA, descB, descC, 
                producto, clienteConMasDescuento, mayorDescuento, 
                totalIngresoProducto, nombreProducto);
    }
    imprimirDetallesFinales(clienteConMasDescuento, mayorDescuento, producto, 
            totalIngresoProducto, nombreProducto);
}

void imprimirCabeceraPrincipal() {
    cout<<setw(76)<<"EMPRESA COMERCIALIZADORA DE ABARROTES"<<endl;
    imprimirLinea('=', MAX_LINEA);
    cout<<"GASTOS DE LOS CLIENTES REGISTRADOS:"<<endl;
}

void imprimirLinea(char c, int n) {
    for (int i=0; i<n; i++) cout.put(c);
    cout.put('\n');
}

void imprimirGastosDeCliente(int dni, char nombre[], int telefono, double descA, 
        double descB, double descC, char producto[], char cliente[], 
        double &mayorDescuento, double &totalIngresoProducto, 
        char nombreProducto[]) {
    char categoria = verificarCategoria(nombre);
    double descuento = seleccionarDescuento(categoria, descA, descB, descC);
    imprimirCabeceraCliente(dni, nombre, telefono, categoria, descuento);        
    int i=1, dd, mm, aaaa;
    double totalAPagar = 0, totalDescuento = 0, descuentoAdicional, precio, 
            cantidad;    
    char codigo[7], descripcion[50], c;       
    while (true) {        
        cin>>codigo>>descripcion;
        descuentoAdicional = verificarDescuento();
        cin>>cantidad>>precio>>dd>>c>>mm>>c>>aaaa;
        imprimirProducto(i, codigo, descripcion, precio, cantidad, descuento, 
                descuentoAdicional, dd, mm, aaaa, producto, 
                totalIngresoProducto, nombreProducto, totalAPagar, 
                totalDescuento);
        cin>>ws;
        if (cin.eof() || verificarFinDeProductos()) break;
        i++;
    }  
    if (totalDescuento>mayorDescuento) {
        mayorDescuento = totalDescuento;
        strcpy(cliente, nombre);
    }    
    imprimirTotal(totalAPagar, totalDescuento);
}

char verificarCategoria(char nombre[]) {    
    char categoria[3] = {nombre[strlen(nombre)-2],
                         nombre[strlen(nombre)-1],
                         nombre[strlen(nombre)]};
    if (strcmp(categoria, "-A")==0 || strcmp(categoria, "-B")==0 || 
            strcmp(categoria, "-C")==0) {        
        nombre[strlen(nombre)-1] = 0;
        return categoria[1];
    }
    return '-';
}

double seleccionarDescuento(char categoria, double a, double b, double c) {
    switch (categoria) {
        case 'A':
            return a;
        case 'B':
            return b;
        case 'C':
            return c;
        default:
            return 0;
    }
}

void imprimirCabeceraCliente(int dni, char nombre[], int telefono, 
        char categoria, double descuento) {    
    imprimirLinea('=', MAX_LINEA);    
    cout<<left<<setw(14)<<"DNI"<<setw(45)<<"Nombre"<<setw(18)<<"Telefono"
            <<setw(20)<<"Categoria"<<"Descuento"<<endl;
    corregirNombre(nombre);
    cout<<setw(14)<<dni<<setw(45)<<nombre<<setw(22)<<telefono<<setw(18)
            <<categoria<<descuento<<right<<endl;
    imprimirLinea('-', MAX_LINEA);
    cout<<"PRODUCTOS ADQUIRIDOS:"<<endl;
    imprimirLinea('-', MAX_LINEA);
    cout<<setw(13)<<"Codigo"<<setw(14)<<"Descripcion"<<setw(36)<<"P.U."
            <<setw(12)<<"Cantidad"<<setw(9)<<"Total"<<setw(16)<<"Descuentos %"
            <<setw(9)<<"A Pagar"<<setw(12)<<"Descuento"<<setw(7)<<"Fecha"<<endl;
    imprimirLinea('-', MAX_LINEA);
}

void corregirNombre(char nombre[]) {    
    for (int i=0; nombre[i]!=0; i++)
        if (nombre[i]=='/' || nombre[i]=='-' || nombre[i]=='_') nombre[i] = ' ';   
}

double verificarDescuento() {    
    cin>>ws;
    char c = cin.get();
    double descuentoAdicional = 0;
    if (c=='%')
        cin>>descuentoAdicional;
    else
        cin.unget();
    return descuentoAdicional;
}

void imprimirProducto(int i, char codigo[], char descripcion[], double precio, 
        double cantidad, double descuento, double descuentoAdicional, int dd, 
        int mm, int aaaa, char producto[], double &totalIngresoProducto, 
        char nombreProducto[], double &totalAPagar, double &totalDescuento) {    
    double total = cantidad * precio, aPagar, desc;
    cout.precision(2);
    cout<<fixed;
    cout<<right<<setw(2)<<i<<setw(11)<<codigo<<left<<setw(3)<<" "<<setw(40)
            <<descripcion<<right<<setw(8)<<precio<<setw(10)<<cantidad<<setw(10)
            <<total<<setw(8);
    if (descuentoAdicional<0.0001)
        cout<<"-.--";
    else
        cout<<descuento;
    cout<<"| "<<setw(5)<<descuentoAdicional; 
    aPagar = calcularDescuento(total, descuentoAdicional, descuento);
    desc = total - aPagar;
    cout<<setw(9)<<aPagar<<setw(7)<<desc<<setw(3)<<" ";
    cout.fill('0');
    cout<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)<<aaaa<<endl;
    cout.fill(' '); 
    if (strcmp(producto, codigo)==0) {
        totalIngresoProducto += total;
        strcpy(nombreProducto, descripcion);
    } 
    totalAPagar += aPagar;
    totalDescuento += desc;
}

double calcularDescuento(double costo, double descA, double descB) {
    double aPagar = costo;
    aPagar -= hallarPorcentaje(costo, descA);
    aPagar -= hallarPorcentaje(aPagar, descA);
    return aPagar;
}

double hallarPorcentaje(double a, double porc) {
    return porc*a/100;
}


bool verificarFinDeProductos() {
    cin>>ws;
    char c = cin.get();
    cin.unget();
    return (c>='0' && c<='9')?true:false;
}

void imprimirTotal(double totalAPagar, double totalDescuento) {
    imprimirLinea('-', MAX_LINEA);
    cout.precision(2);
    cout<<fixed;
    cout<<left<<setw(7)<<" "<<setw(95)<<"TOTAL:"<<setw(7)<<totalAPagar
            <<totalDescuento<<endl;
    imprimirLinea('=', MAX_LINEA);
    cout<<right<<endl;
}

void imprimirDetallesFinales(char clienteConMasDescuento[], 
        double mayorDescuento, char producto[], double totalIngresoProducto, 
        char nombreProducto[]) {
    imprimirLinea('=', MAX_LINEA);
    cout.precision(2);
    cout.fixed;
    corregirNombre(nombreProducto);
    cout<<"CLIENTE QUE RECIBIO MAS DESCUENTO: "<<left<<setw(48)
            <<clienteConMasDescuento<<"DESCUENTO TOTAL: "<<mayorDescuento<<endl;
    cout<<"PRODUCTO A VERIFICAR: "<<nombreProducto<<" ["<<producto<<setw(8)
            <<"]"<<"TOTAL INGRESADO POR EL PRODUCTO: "<<totalIngresoProducto
            <<endl;
}