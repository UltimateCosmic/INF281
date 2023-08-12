/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boleta.cpp
 * Author: alulab14
 * 
 * Created on 23 de junio de 2023, 08:09 AM
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "Boleta.h"
#include "Semipresencial.h"
#include "Presencial.h"
#include "Virtual.h"

void Boleta::asignarBoleta(ifstream &arch) {
    char tipo;
    arch>>tipo;
    if (arch.eof()) return;
    switch (tipo) {
        case 'S':
            pboleta = new class Semipresencial;
            break;
        case 'P':
            pboleta = new class Presencial;
            break;
        case 'V':
            pboleta = new class Virtual;
            break;      
    }
    pboleta->lee(arch);
}

void Boleta::imprimirBoleta(ofstream &arch) {
    pboleta->imprime(arch);        
}

void Boleta::actualizarBoleta(double precio) {
    pboleta->actualizatotal(precio);        
}

int Boleta::obtenerEscala() {
    return pboleta->GetEscala();    
}

void Boleta::operator =(class Alumno *pt) {
    pboleta = pt;
}

bool Boleta::operator !=(class Alumno *pt) {
    return pboleta != pt;
}

