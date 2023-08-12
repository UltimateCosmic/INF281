/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   alumnonota.cpp
 * Author: alulab14
 * 
 * Created on 9 de junio de 2023, 08:01 AM
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "alumnonota.h"

alumnonota::alumnonota() {
    codcurso = nullptr;
}

alumnonota::~alumnonota() {
    if (codcurso!=nullptr) delete codcurso;
}

void alumnonota::SetNota(int nota) {
    this->nota = nota;
}

int alumnonota::GetNota() const {
    return nota;
}

void alumnonota::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int alumnonota::GetCiclo() const {
    return ciclo;
}

void alumnonota::SetCodcurso(char* cod) {
    if (codcurso!=nullptr) delete codcurso;
    codcurso = new char[strlen(cod)+1];
    strcpy(codcurso, cod);
}

char* alumnonota::GetCodcurso(char *cod) const {
    if (codcurso==nullptr) codcurso[0]=0;
    strcpy(cod, codcurso);
}

void alumnonota::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int alumnonota::GetCodigo() const {
    return codigo;
}

void alumnonota::operator &(class Nota &notaB) {
    notaB.SetNota(nota);
    notaB.SetCiclo(ciclo);
}

void operator >>(ifstream &arch, class alumnonota &alumnonota) {
    int cod, ciclo, nota;
    char curso[7];
    arch>>cod;
    if (arch.eof()) return;
    arch.get();
    arch.getline(curso, 7, ',');
    arch>>ciclo;
    arch.get();
    arch>>nota;
    alumnonota.SetCodigo(cod);
    alumnonota.SetCodcurso(curso);
    alumnonota.SetCiclo(ciclo);
    alumnonota.SetNota(nota);
}
