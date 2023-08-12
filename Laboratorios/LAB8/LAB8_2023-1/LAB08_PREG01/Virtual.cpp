/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.cpp
 * Author: alulab14
 * 
 * Created on 16 de junio de 2023, 08:12 AM
 */

#include <cstring>
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

void Virtual::SetLicencia(const char *lic) {
    if (licencia!=nullptr) delete licencia;
    licencia = new char[strlen(lic)+1];
    strcpy(licencia, lic);
}

void Virtual::GetLicencia(char *lic) const {
    if (licencia==nullptr) lic[0]=0;
    else strcpy(lic, licencia);
}

