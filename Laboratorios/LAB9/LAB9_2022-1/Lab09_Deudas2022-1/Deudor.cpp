/* 
 * Proyecto:    Lab09_Deudas2022-1
 * Archivo:     Deudor.cpp
 * Autor:       CosmoDev
 *
 * Creado el 21 de junio de 2023, 11:24 PM
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "Cliente.h"
#include "ClienteA.h"
#include "ClienteB.h"
#include "ClienteC.h"
#include "Deudor.h"

Deudor::Deudor() {
    cdeudor = nullptr;
}

Deudor::~Deudor() {
    if (cdeudor!=nullptr) delete cdeudor;
}

void Deudor::asignaCliente(ifstream &arch) {
    char categoria, c;
    arch>>categoria>>c;
    if (arch.eof()) return;
    if (categoria=='A')
        cdeudor = new class ClienteA;
    else if (categoria=='B')
        cdeudor = new class ClienteB;
    else if (categoria=='C')
        cdeudor = new class ClienteC;
    cdeudor->lee(arch);
    arch>>ws;
}

void Deudor::imprimeCliente(ofstream &arch) {    
    cdeudor->imprime(arch);
}

