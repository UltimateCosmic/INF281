/* 
 * Proyecto:    LAB08_PREG01
 * Archivo:     Cliente.cpp
 * Autor:       CosmoDev
 *
 * Creado el 16 de junio de 2023, 02:32 AM
 */

#include <cstring>
#include "Cliente.h"

Cliente::Cliente() {
    nombre = nullptr;
}

Cliente::~Cliente() {
    if (nombre!=nullptr) delete nombre;
}

void Cliente::SetNombre(const char* nombre) {
    if (this->nombre!=nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Cliente::GetNombre(char *nombre) const {
    if (this->nombre==nullptr) nombre[0]=0;
    else strcpy(nombre, this->nombre);
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

