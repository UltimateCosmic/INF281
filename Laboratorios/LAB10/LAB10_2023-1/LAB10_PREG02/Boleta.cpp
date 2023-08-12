/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boleta.cpp
 * Author: alulab14
 * 
 * Created on 30 de junio de 2023, 08:13 AM
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "Boleta.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"

Boleta::Boleta() {
    pboleta = nullptr;
}

void Boleta::cargarDatos(ifstream &arch) {
    char tip;
    arch>>tip;
    if (arch.eof()) return;
    arch.get();
    switch (tip) {
        case 'P':
            pboleta = new Presencial;
            break;
        case 'S':
            pboleta = new Semipresencial;
            break;
        case 'V':
            pboleta = new Virtual;
            break;        
    }
    pboleta->lee(arch);
}

int Boleta::cmp(Boleta &bol) {
    int cod = pboleta->GetCodigo();
    Alumno *auxAlu = bol.retornaAlumno();
    return cod>auxAlu->GetCodigo();    
}

Alumno *Boleta::retornaAlumno() {
    return pboleta;
}

void Boleta::imprimeLinea(ofstream &arch) {
    pboleta->imprime(arch);
}

int Boleta::obtenerEscala() {
    return pboleta->GetEscala();
}

void Boleta::actualizarBoleta(double precio) {
    pboleta->actualiza(precio);
}