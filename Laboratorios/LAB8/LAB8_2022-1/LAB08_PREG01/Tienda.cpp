/* 
 * Proyecto:    LAB08_PREG01
 * Archivo:     Tienda.cpp
 * Autor:       CosmoDev
 *
 * Creado el 16 de junio de 2023, 02:48 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Tienda.h"

void Tienda::carga() {
    ifstream archPedidos("pedidos3.csv", ios::in);
    if (not archPedidos.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo pedidos3.csv"<<endl;
        exit(1);
    }
    cargaPedidos(archPedidos);
    ifstream archClientes("clientes2.csv", ios::in);
    if (not archClientes.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo clientes2.csv"<<endl;
        exit(1);
    }
    cargaClientes(archClientes);
}

void Tienda::cargaPedidos(ifstream &arch) {    
    int codigo, cantidad, dni, dd, mm, aaaa, stock, numPed=0;
    double precio;
    char c, nombre[100];   
    while (true) {
        arch>>codigo; 
        if (arch.eof()) break;
        arch>>c>>cantidad>>c>>dni>>c>>dd>>c>>mm>>c>>aaaa;
        lpedidos[numPed].SetCodigo(codigo);
        lpedidos[numPed].SetCantidad(cantidad);
        lpedidos[numPed].SetDni(dni);
        lpedidos[numPed].SetFecha(aaaa*10000+mm*100+dd);
        if (buscarProducto(codigo, nombre, precio, stock)) {
            lpedidos[numPed].SetCodprod(codigo);
            lpedidos[numPed].SetNombre(nombre);
            lpedidos[numPed].SetPrecio(precio);
            lpedidos[numPed].SetStock(stock);
        }
        numPed++;
    }
    lpedidos[numPed].SetCodigo(0);
}

bool Tienda::buscarProducto(int codigo, char *nombre, double &precio, int &stock) {
    ifstream archProductos("productos3.csv", ios::in);
    if (not archProductos.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo productos3.csv"<<endl;
        exit(1);
    }
    int cod;
    char c;
    while (true) {
        archProductos>>cod;
        if (archProductos.eof()) break;
        archProductos>>c;
        archProductos.getline(nombre, 100, ',');                
        archProductos>>precio>>c>>stock;
        if (cod==codigo) return true;
    }
    return false;
}

void Tienda::cargaClientes(ifstream &arch) {
    int dni, numCli=0;
    char nombre[60], categoria, c;   
    while (true) {
        arch>>dni; 
        if (arch.eof()) break;
        arch>>c;
        arch.getline(nombre, 60, ',');
        arch>>categoria;
        lclientes[numCli].SetDni(dni);
        lclientes[numCli].SetNombre(nombre);
        lclientes[numCli].SetCategoria(categoria);
        numCli++;
    }
    lclientes[numCli].SetDni(0);
}

void Tienda::muestra() {    
    ofstream arch("Reporte.txt", ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    arch<<left<<setw(12)<<"Fecha"<<setw(8)<<"Codigo"<<setw(45)
            <<"Descripcion del Prod."<<setw(7)<<"Cant."<<setw(8)<<"Precio"
            <<setw(8)<<"Total"<<"Observaciones"<<endl;
    int fech, dd,mm,aa;
    char nomb[100], ob[100];
    arch.precision(2);
    arch<<fixed;    
    for (int i=0; lpedidos[i].GetCodigo(); i++) {
        fech = lpedidos[i].GetFecha();
        lpedidos[i].GetNombre(nomb);
        lpedidos[i].GetObs(ob);
        fecha_a_ddmmaa(fech, dd,mm,aa);
        arch<<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)
                <<aa<<setfill(' ')<<setw(8)<<lpedidos[i].GetCodigo()<<" "<<left
                <<setw(40)<<nomb<<right<<setw(6)<<lpedidos[i].GetCantidad()
                <<setw(10)<<lpedidos[i].GetPrecio()<<setw(8)
                <<lpedidos[i].GetCantidad()*lpedidos[i].GetPrecio()<<" "<<left
                <<ob<<endl;
    }
}

void Tienda::fecha_a_ddmmaa(int fecha, int &dd, int &mm, int &aa) {
    aa = fecha/10000;
    fecha %= 10000;
    mm = fecha/100;
    dd = fecha%100;
}

