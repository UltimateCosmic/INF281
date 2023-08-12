/* 
 * Proyecto:    LAB07_PREG01_CLASES
 * Archivo:     Cliente.cpp
 * Autor:       CosmoDev
 *
 * Creado el 9 de junio de 2023, 02:01 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Cliente.h"
#include "Pedido.h"

Cliente::Cliente() {
    nombre = nullptr;
    numped = 0;
    total = 0;
}

Cliente::~Cliente() {
    if (nombre!=nullptr) delete nombre;
}

void Cliente::SetTotal(double total) {
    this->total = total;
}

double Cliente::GetTotal() const {
    return total;
}

void Cliente::SetNumped(int numped) {
    this->numped = numped;
}

int Cliente::GetNumped() const {
    return numped;
}

void Cliente::SetNombre(char* nomb) {    
    if (nombre!=nullptr) delete nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
}

void Cliente::GetNombre(char *nomb) const {
    if (nombre==nullptr) nomb[0]=0;
    strcpy(nomb, nombre);
}

void Cliente::SetCategoria(char categoria) {
    this->categoria = categoria;
}

char Cliente::GetCategoria() const {
    return categoria;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::operator =(const class Pedido &pedido) {
    int cant;
    double prec;    
    lped[numped] = pedido;
    cant = pedido.GetCantidad();
    prec = pedido.GetPrecio();
    total += cant*prec;
    numped++;    
}

void Cliente::operator -=(const class Pedido &ped) {
    for (int i=0; i<numped; i++) {
        if (lped[i]==ped) {
            for (int k=i+1; k<numped; k++)
                lped[k-1] = lped[k];
            numped--;
            return;
        }        
    }    
}

void Cliente::operator /(double porcentaje) {
    double precio;
    for (int i=0; i<numped; i++) {
        precio = lped[i].GetPrecio();
        precio *= (1-porcentaje/100); 
        lped[i].SetPrecio(precio);
    }
    total *= (1-porcentaje/100);
}

void operator >>(ifstream &arch, class Cliente &cliente) {
    int dni;
    char nombre[60], cat;
    arch>>dni;
    if (arch.eof()) return;
    arch.get();
    arch.getline(nombre, 60, ',');
    arch>>cat;
    cliente.SetDni(dni);
    cliente.SetNombre(nombre);
    cliente.SetCategoria(cat);
}

void Cliente::imprimeLinea(ofstream &arch, char c, int n) const {
    for (int i=0; i<n; i++) arch.put(c);
    arch.put('\n');
}

void Cliente::imprimeProductos(ofstream &arch) const {
    for (int i=0; i<numped; i++)
        arch<<lped[i];
}

void operator <<(ofstream &arch, const class Cliente &cliente) {
    char nomb[60];
    arch.precision(2);
    arch<<fixed;
    cliente.GetNombre(nomb);
    arch<<left<<setw(25)<<cliente.GetDni()<<nomb<<endl;
    cliente.imprimeLinea(arch, '=', 100);
    cliente.imprimeProductos(arch);
    /*arch<<left<"# de pedidos:"<<right<<setw(7)<<cliente.GetNumped()<<endl;
    arch<<left<"Monto total: "<<right<<setw(10)<<cliente.GetTotal()<<endl;*/
}

