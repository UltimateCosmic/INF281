/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: alulab14
 * 
 * Created on 11 de julio de 2023, 08:29 AM
 */

#include "Nodo.h"

Nodo::Nodo() {
    anterior = siguiente = nullptr;
}

void Nodo::leerAlumno(ifstream &arch) {
    dato.leerDato(arch);
}

void Nodo::imprimeDato(ofstream &arch) {    
    dato.imprimirAlumno(arch);    
}

