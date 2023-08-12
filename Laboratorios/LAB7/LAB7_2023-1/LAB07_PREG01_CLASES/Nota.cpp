/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nota.cpp
 * Author: alulab14
 * 
 * Created on 9 de junio de 2023, 08:23 AM
 */

#include <cstring>
#include "Nota.h"

Nota::Nota() {
    codcurso = nullptr;
}

Nota::~Nota() {
    if (codcurso!=nullptr) delete codcurso;
}

void Nota::SetNota(int nota) {
    this->nota = nota;
}

int Nota::GetNota() const {
    return nota;
}

void Nota::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int Nota::GetCiclo() const {
    return ciclo;
}

void Nota::SetCodcurso(char* cod) {
    if (codcurso=nullptr) delete codcurso;
    codcurso = new char[strlen(cod)+1];
    strcpy(codcurso, cod);
}

char* Nota::GetCodcurso(char *cod) const {
    if (codcurso==nullptr) codcurso[0]=0;
    strcpy(cod, codcurso);
}