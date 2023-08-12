/* 
 * Proyecto:    Lab09_Deudas2022-1
 * Archivo:     Pedido.cpp
 * Autor:       CosmoDev
 *
 * Creado el 21 de junio de 2023, 11:23 PM
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "Pedido.h"

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

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void operator >>(ifstream &arch, class Pedido &ped) {    
    int cod, cant, dni, dd, mm, aaaa;
    double monto;
    char c;
    arch>>cod;
    if (arch.eof()) return;
    arch>>c>>cant>>c>>monto>>c>>dni>>c>>dd>>c>>mm>>c>>aaaa;
    ped.SetCodigo(cod);
    ped.SetCantidad(cant);
    ped.SetTotal(monto);
    ped.SetDni(dni);
    ped.SetFecha(aaaa*10000+mm*100+dd);
}

