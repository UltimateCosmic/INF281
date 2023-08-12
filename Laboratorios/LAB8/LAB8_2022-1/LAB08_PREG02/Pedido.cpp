/* 
 * Proyecto:    LAB08_PREG01
 * Archivo:     Pedido.cpp
 * Autor:       CosmoDev
 *
 * Creado el 16 de junio de 2023, 02:41 AM
 */

#include <cstring>
#include "Pedido.h"

Pedido::Pedido() {    
    obs = new char[2]{};
    *obs = ' ';
}

Pedido::~Pedido() {
    if (obs==nullptr) delete obs;
}

void Pedido::SetObs(const char* obs) {
    if (this->obs!=nullptr) delete this->obs;
    this->obs = new char[strlen(obs)+1];
    strcpy(this->obs, obs);
}

void Pedido::GetObs(char *obs) const {
    if (this->obs==nullptr) obs[0]=0;
    else strcpy(obs, this->obs);
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

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

