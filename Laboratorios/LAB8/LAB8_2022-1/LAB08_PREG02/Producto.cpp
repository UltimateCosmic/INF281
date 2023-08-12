/* 
 * Proyecto:    LAB08_PREG01
 * Archivo:     Producto.cpp
 * Autor:       CosmoDev
 *
 * Creado el 16 de junio de 2023, 02:39 AM
 */

#include <cstring>
#include "Producto.h"

Producto::Producto() {
    nombre = nullptr;
    stock = 0;
}

Producto::~Producto() {
    if (nombre!=nullptr) delete nombre;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetNombre(const char *nombre) {
    if (this->nombre!=nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Producto::GetNombre(char *nombre) const {
    if (this->nombre==nullptr) nombre[0]=0;
    else strcpy(nombre, this->nombre);
}

void Producto::SetCodprod(int codprod) {
    this->codprod = codprod;
}

int Producto::GetCodprod() const {
    return codprod;
}

