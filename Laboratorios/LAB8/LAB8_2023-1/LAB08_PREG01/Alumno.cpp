/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: alulab14
 * 
 * Created on 16 de junio de 2023, 08:03 AM
 */

#include <cstring>
#include "Alumno.h"

Alumno::Alumno() {
    nombre = nullptr;
    total = 0;
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

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(const char* nomb) {
    if (nombre!=nullptr) delete nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
}

void Alumno::GetNombre(char *nomb) const {
    if (nombre==nullptr) nomb[0]=0;
    else strcpy(nomb, nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

