/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: alulab14
 * 
 * Created on 23 de junio de 2023, 07:58 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Alumno.h"

Alumno::Alumno() {
    nombre = nullptr;
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
    char c, nomb[60];
    arch>>c>>codigo>>c;            
    arch.getline(nomb, 60, ',');
    SetNombre(nomb);
    arch>>escala>>c>>creditos>>c;
}

void Alumno::imprime(ofstream &arch) {
    arch.precision(2);
    arch<<fixed;
    arch<<left<<setw(15)<<codigo<<setw(42)<<nombre<<setw(9)<<escala
            <<setw(12)<<creditos;
}

