/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.cpp
 * Author: alulab14
 * 
 * Created on 30 de junio de 2023, 08:11 AM
 */

#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
}

Virtual::~Virtual() {
    if (licencia!=nullptr) delete licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(const char* licencia) {
    if (this->licencia!=nullptr) delete this->licencia;
    this->licencia = new char[strlen(licencia)+1];
    strcpy(this->licencia, licencia);
}

void Virtual::GetLicencia(char* licencia) const {
    if (this->licencia==nullptr) licencia[0]=0;
    else strcpy(licencia, this->licencia);
}

void Virtual::lee(ifstream &arch) {
    Alumno::lee(arch);
    char cad[15];
    arch.getline(cad, 15);
    SetLicencia(cad);
}

void Virtual::imprime(ofstream &arch) {
    Alumno::imprime(arch);
    arch<<setw(11)<<licencia<<total<<endl;    
}

void Virtual::actualiza(double precio) {
    Alumno::actualiza(precio);
    total = Alumno::GetTotal()+100;
}

