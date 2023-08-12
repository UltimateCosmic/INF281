/* 
 * Proyecto:    Lab09_Deudas2022-1
 * Archivo:     ClienteB.cpp
 * Autor:       CosmoDev
 *
 * Creado el 21 de junio de 2023, 11:20 PM
 */

#include <fstream>
using namespace std;

#include "ClienteB.h"

void ClienteB::SetFlete(double flete) {
    this->flete = flete;
}

double ClienteB::GetFlete() const {
    return flete;
}

void ClienteB::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double ClienteB::GetDescuento() const {
    return descuento;
}

void ClienteB::lee(ifstream &arch) {
    char c;
    arch>>descuento>>c>>flete>>c;
    Cliente::lee(arch);
}

void ClienteB::imprime(ofstream &arch) {    
    Cliente::imprime(arch);
    arch<<"Descuento: "<<descuento<<endl;
    arch<<"Flete: "<<flete<<endl<<endl;
}

