/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escala.cpp
 * Author: alulab14
 * 
 * Created on 23 de junio de 2023, 08:03 AM
 */

#include <fstream>
using namespace std;

#include "Escala.h"

void Escala::SetPrecio(double precio) {
    this->precio = precio;
}

double Escala::GetPrecio() const {
    return precio;
}

void Escala::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Escala::GetCodigo() const {
    return codigo;
}

void operator >>(ifstream &arch, class Escala &escala) {
    int numero;
    double costo;
    arch>>numero;
    if (arch.eof()) return;
    arch.get();
    arch>>costo;
    escala.SetCodigo(numero);
    escala.SetPrecio(costo);
}

