/* 
 * Proyecto:    LAB07_PREG01_CLASES
 * Archivo:     Pedido.cpp
 * Autor:       CosmoDev
 *
 * Creado el 9 de junio de 2023, 01:18 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Pedido.h"

Pedido::Pedido() {
    nombre = nullptr;
}

Pedido::~Pedido() {
    if (nombre!=nullptr) delete nombre;
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

void Pedido::SetPrecio(double precio) {
    this->precio = precio;
}

double Pedido::GetPrecio() const {
    return precio;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetNombre(char* nomb) {
    if (nombre!=nullptr) delete nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
}

void Pedido::GetNombre(char *nomb) const {
    if (nombre==nullptr) nomb[0]=0;
    strcpy(nombre, nomb);
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::separarFecha(int fecha, int &dd, int &mm, int &aaaa) const {
    aaaa = fecha/10000;
    fecha %= 10000;
    mm = fecha/100;
    dd = fecha%100;
}

bool Pedido::operator ==(const class Pedido &ped) {
    return dni==ped.dni and fecha==ped.fecha and codigo==ped.codigo;
}

void operator >>(ifstream &arch, class Pedido &pedido) {
    int codigo, cantidad, dni, dd, mm, aaaa;
    char nombre[100], c;
    double precio;
    arch>>codigo;
    if (arch.eof()) return;
    arch.get();
    arch.getline(nombre, 100, ',');
    arch>>cantidad>>c>>precio>>c>>dni>>c>>dd>>c>>mm>>c>>aaaa;
    pedido.SetCodigo(codigo);
    pedido.SetNombre(nombre);
    pedido.SetCantidad(cantidad);
    pedido.SetPrecio(precio);
    pedido.SetDni(dni);
    pedido.SetFecha(aaaa*10000 + mm*100 + dd);    
}

void operator <<(ofstream &arch, const class Pedido &pedido) {
    int fecha, dd, mm, aaaa;
    char nomb[100];
    fecha = pedido.GetFecha();
    pedido.GetNombre(nomb);
    pedido.separarFecha(fecha, dd, mm, aaaa);
    arch<<setfill('0')<<right<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aaaa
            <<setfill(' ')<<setw(10)<<pedido.GetCodigo()<<"   "<<left<<setw(40)
            <<nomb<<right<<setw(10)<<pedido.GetCantidad()<<setw(10)
            <<pedido.GetPrecio()<<endl;
}

