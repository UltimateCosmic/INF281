/* 
 * File:   Alumno.cpp
 * Author: alulab14
 * 
 * Created on 30 de junio de 2023, 08:02 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

#include "Alumno.h"

Alumno::Alumno() {
    nombre = nullptr;
    total = 0.0;
}

Alumno::~Alumno() {
    if (nombre!=nullptr) delete nombre;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(const char* nombre) {
    if (this->nombre!=nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Alumno::GetNombre(char* nombre) const {
    if (this->nombre==nullptr) nombre[0]=0;
    else strcpy(nombre, this->nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::lee(ifstream &arch) {
    char c, cad[60];
    arch>>codigo>>c;
    arch.getline(cad, 60, ',');
    SetNombre(cad);
    arch>>escala>>c>>creditos>>c;
}

void Alumno::imprime(ofstream &arch) {
    arch<<left<<setw(20)<<codigo<<setw(40)<<nombre<<setw(10)<<escala<<setw(10)
            <<creditos;
}

void Alumno::actualiza(double precio) {
    total = precio*creditos;    
}

