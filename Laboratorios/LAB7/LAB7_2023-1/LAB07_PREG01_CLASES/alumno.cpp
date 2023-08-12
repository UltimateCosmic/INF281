/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   alumno.cpp
 * Author: alulab14
 * 
 * Created on 9 de junio de 2023, 08:03 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "alumno.h"
#include "Nota.h"
#include "alumnonota.h"

alumno::alumno() {
    nombre = nullptr;
    numcursos = 0;
    numaprobados = 0;
    numprimera = 0;
    numsegunda = 0;
    numtercera = 0;
}

alumno::~alumno() {
    if (nombre!=nullptr) delete nombre;
}

void alumno::SetNumtercera(int numtercera) {
    this->numtercera = numtercera;
}

int alumno::GetNumtercera() const {
    return numtercera;
}

void alumno::SetNumsegunda(int numsegunda) {
    this->numsegunda = numsegunda;
}

int alumno::GetNumsegunda() const {
    return numsegunda;
}

void alumno::SetNumprimera(int numprimera) {
    this->numprimera = numprimera;
}

int alumno::GetNumprimera() const {
    return numprimera;
}

void alumno::SetNumaprobados(int numaprobados) {
    this->numaprobados = numaprobados;
}

int alumno::GetNumaprobados() const {
    return numaprobados;
}

void alumno::SetNumcursos(int numcursos) {
    this->numcursos = numcursos;
}

int alumno::GetNumcursos() const {
    return numcursos;
}

void alumno::SetNombre(char* nomb) {
    if (nombre!=nullptr) delete nombre;
    nombre = new char[strlen(nomb)+1];
    strcpy(nombre, nomb);
}

char* alumno::GetNombre(char *nomb) const {
    if (nombre==nullptr) nombre[0]=0;
    strcpy(nomb, nombre);
}

void alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int alumno::GetCodigo() const {
    return codigo;
}

void alumno::operator +=(class Nota &nota) {
    lnotas[numcursos] = nota;
    numcursos++;
    if (nota.GetNota()>=11) numaprobados++;   
}

void operator >>(ifstream &arch, class alumno &alumno) {
    int cod;
    char nomb[60], buff[60];
    arch>>cod;
    if (arch.eof()) return;
    arch.get();
    arch.getline(nomb, 60, ',');
    alumno.SetCodigo(cod);
    alumno.SetNombre(nomb);
    arch.getline(buff, 60); // Hasta el salto de linea
}

void operator <<(ofstream &arch, const class alumno &alumno) {
    arch<<"Codigo del Alumno: "<<alumno.GetCodigo()<<endl;
    char nomb[60];
    alumno.GetNombre(nomb);
    arch<<"Nombre del Alumno: "<<nomb<<endl;
    arch<<"Detalle de Cursos:"<<endl;
    arch<<"Cursados Aprobados  1ra Vez   2da Vez   3ra Vez"<<endl;
    arch<<right<<setw(5)<<alumno.GetNumcursos()<<setw(10)<<alumno.GetNumaprobados()
            <<setw(10)<<alumno.GetNumprimera()<<setw(10)<<alumno.GetNumsegunda()
            <<setw(10)<<alumno.GetNumtercera()<<endl;
}

