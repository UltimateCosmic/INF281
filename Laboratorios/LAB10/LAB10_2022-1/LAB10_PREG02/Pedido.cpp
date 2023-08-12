/* 
 * File:   Pedido.cpp
 * Author: aml
 * 
 * Created on 26 de junio de 2023, 09:33 AM
 */

#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Pedido.h"

Pedido::Pedido() {
    nombre = nullptr;
    total = 0;
}

Pedido::~Pedido() {
    if (nombre!=nullptr) delete nombre;
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetNombre(const char* nombre) {
    if (this->nombre!=nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Pedido::GetNombre(char* nombre) const {
    if (this->nombre==nullptr) nombre[0]=0;
    else strcpy(nombre, this->nombre);
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::lee(ifstream &arch) {
    int dd, mm, aaaa;
    char nombre[100], c;
    arch.getline(nombre, 100, ',');
    SetNombre(nombre);
    arch>>cantidad>>c>>total>>c>>dni>>c>>dd>>c>>mm>>c>>aaaa;
    fecha = aaaa*10000 + mm*100 + dd;
}

void Pedido::imprime(ofstream &arch) {    
    int dd, mm, aaaa;
    separarFecha(dd, mm, aaaa);
    arch.fill('0');
    arch<<right<<endl<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aaaa<<endl;
    arch.fill(' ');
    arch<<left<<setw(10)<<codigo<<nombre<<endl;
    arch<<right<<"DNI:"<<setw(17)<<dni<<endl;
    arch<<"Monto total:"<<setw(9)<<total<<endl;
}

void Pedido::separarFecha(int &dd, int &mm, int &aaaa) {
    int f = fecha;
    aaaa = f/10000;
    f -= aaaa*10000;
    mm = f/100;
    dd = f-mm*100;
}

