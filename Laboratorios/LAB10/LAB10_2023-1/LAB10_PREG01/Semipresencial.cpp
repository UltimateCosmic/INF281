/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Semipresencial.cpp
 * Author: alulab14
 * 
 * Created on 30 de junio de 2023, 08:09 AM
 */

#include <fstream>
#include <iomanip>
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
}

void Semipresencial::imprime(ofstream &arch) {
    Alumno::imprime(arch);
    arch<<right<<setw(18)<<total<<endl;    
}

