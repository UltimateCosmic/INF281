/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: alulab14
 * 
 * Created on 11 de julio de 2023, 08:10 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Alumno.h"

Alumno::Alumno() {
    nombre = nullptr;
    promedio = 0;
}

Alumno::Alumno(const Alumno& orig) {
    nombre = nullptr;
    *this = orig;
}

Alumno::~Alumno() {
    if (nombre) delete nombre;
}

void Alumno::SetPromedio(double promedio) {
    this->promedio = promedio;
}

double Alumno::GetPromedio() const {
    return promedio;
}

void Alumno::SetNombre(const char* nombre) {
    if (this->nombre) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Alumno::GetNombre(char* nombre) const {
    if (this->nombre==nullptr) nombre[0]=0;
    else strcpy(nombre, this->nombre);
}

void Alumno::SetCodigo_alumno(int codigo_alumno) {
    this->codigo_alumno = codigo_alumno;
}

int Alumno::GetCodigo_alumno() const {
    return codigo_alumno;
}

void Alumno::imprimeAlumno(ofstream &arch) {
    char cad[60];
    GetNombre(cad);
    arch.precision(2);
    arch<<fixed;
    arch<<left<<setw(13)<<codigo_alumno<<setw(40)<<nombre<<promedio<<endl;    
}

void operator >>(ifstream &arch, class Alumno &alumno) {
    int codigo;
    char nomb[60], c;
    arch>>codigo;
    if (arch.eof()) return;
    arch>>c;
    arch.getline(nomb, 60);
    alumno.SetCodigo_alumno(codigo);
    alumno.SetNombre(nomb);    
}
