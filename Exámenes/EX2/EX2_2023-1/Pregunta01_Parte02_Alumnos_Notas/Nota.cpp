/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nota.cpp
 * Author: alulab14
 * 
 * Created on 11 de julio de 2023, 08:05 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Nota.h"

Nota::Nota() {
    codigo_curso = nullptr;
    vez = 0;
}

Nota::Nota(const Nota& orig) {
    codigo_curso = nullptr;
    vez = 0;
}

Nota::~Nota() {
    if (codigo_curso!=nullptr) delete codigo_curso;
}

void Nota::SetVez(int vez) {
    this->vez = vez;
}

int Nota::GetVez() const {
    return vez;
}

void Nota::SetCalificacion(int calificacion) {
    this->calificacion = calificacion;
}

int Nota::GetCalificacion() const {
    return calificacion;
}

void Nota::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Nota::GetCreditos() const {
    return creditos;
}

void Nota::SetCodigo_curso(const char* codigo_curso) {
    if (this->codigo_curso!=nullptr) delete this->codigo_curso;
    this->codigo_curso = new char[strlen(codigo_curso)+1];
    strcpy(this->codigo_curso, codigo_curso);
}

void Nota::GetCodigo_curso(char* codigo_curso) const {
    if (this->codigo_curso==nullptr) codigo_curso[0]=0;
    else strcpy(codigo_curso, this->codigo_curso);
}

void Nota::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int Nota::GetCiclo() const {
    return ciclo;
}

void Nota::imprimeNota(ofstream &arch) {
    char cad[10];
    GetCodigo_curso(cad);
    arch<<left<<setw(10)<<setw(10)<<ciclo<<cad<<setw(10)<<creditos
            <<setw(15)<<calificacion<<endl;
}

void operator >>(ifstream &arch, class Nota &notaAlumno) {
    char c, curso[10];
    double creditos;
    int calificacion;
    arch.getline(curso, 10, ',');
    arch>>creditos>>c>>calificacion;
    notaAlumno.SetCodigo_curso(curso);
    notaAlumno.SetCreditos(creditos);
    notaAlumno.SetCalificacion(calificacion);
}

