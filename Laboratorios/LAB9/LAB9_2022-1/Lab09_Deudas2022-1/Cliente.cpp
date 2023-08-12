/* 
 * Proyecto:    Lab09_Deudas2022-1
 * Archivo:     Cliente.cpp
 * Autor:       CosmoDev
 *
 * Creado el 21 de junio de 2023, 11:08 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Cliente.h"

Cliente::Cliente() {
    nombre = nullptr;
    cantped = 0;
    totalped = 0.0;
}

Cliente::~Cliente() {
    if (nombre!=nullptr) delete nombre;
}

void Cliente::SetTotalped(double totalped) {
    this->totalped = totalped;
}

double Cliente::GetTotalped() const {
    return totalped;
}

void Cliente::SetCantped(int cantped) {
    this->cantped = cantped;
}

int Cliente::GetCantped() const {
    return cantped;
}

void Cliente::SetNombre(const char* nombre) {    
    if (this->nombre!=nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Cliente::GetNombre(char* nombre) const {
    if (this->nombre==nullptr) nombre[0] = 0;
    strcpy(nombre, this->nombre);    
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

void Cliente::lee(ifstream &arch) {
    char c, nomb[60];
    arch>>dni>>c;
    arch.getline(nomb, 60);
    SetNombre(nomb);
}

void Cliente::imprime(ofstream &arch) {    
    arch<<left<<setw(12)<<dni<<setw(45)<<nombre<<setw(7)<<categoria<<endl;
}

