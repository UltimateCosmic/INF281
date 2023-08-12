/* 
 * Proyecto:    Lab09_Deudas2022-1
 * Archivo:     ClienteA.cpp
 * Autor:       CosmoDev
 *
 * Creado el 21 de junio de 2023, 11:18 PM
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "ClienteA.h"

void ClienteA::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double ClienteA::GetDescuento() const {
    return descuento;
}

void ClienteA::lee(ifstream &arch) {
    char c;
    arch>>descuento>>c;
    Cliente::lee(arch);
}

void ClienteA::imprime(ofstream &arch) {    
    Cliente::imprime(arch);
    arch<<"Descuento: "<<descuento<<endl<<endl;
}

