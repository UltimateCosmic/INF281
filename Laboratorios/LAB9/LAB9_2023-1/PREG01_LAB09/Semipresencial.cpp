/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Semipresencial.cpp
 * Author: alulab14
 * 
 * Created on 23 de junio de 2023, 08:06 AM
 */

#include <fstream>
using namespace std;

#include "Semipresencial.h"

void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
    return descuento;
}

void Semipresencial::lee(ifstream &arch) {
    Alumno::lee(arch);
    arch>>descuento;
    total = 0;
}

void Semipresencial::imprime(ofstream &arch) {
    Alumno::imprime(arch);
    arch<<descuento<<endl;
}

