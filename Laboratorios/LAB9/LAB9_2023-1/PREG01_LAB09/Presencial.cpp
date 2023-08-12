/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Presencial.cpp
 * Author: alulab14
 * 
 * Created on 23 de junio de 2023, 08:05 AM
 */

#include <fstream>
using namespace std;

#include "Presencial.h"

void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}

void Presencial::lee(ifstream &arch) {
    Alumno::lee(arch);
    arch>>recargo;
    total = 0;    
}

void Presencial::imprime(ofstream &arch) {
    Alumno::imprime(arch);
    arch<<recargo<<endl;
}

