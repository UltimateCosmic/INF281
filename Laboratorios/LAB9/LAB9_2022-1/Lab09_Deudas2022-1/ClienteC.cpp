/* 
 * Proyecto:    Lab09_Deudas2022-1
 * Archivo:     ClienteC.cpp
 * Autor:       CosmoDev
 *
 * Creado el 21 de junio de 2023, 11:21 PM
 */

#include <fstream>
using namespace std;

#include "ClienteC.h"

void ClienteC::SetFlete(double flete) {
    this->flete = flete;
}

double ClienteC::GetFlete() const {
    return flete;
}

void ClienteC::lee(ifstream &arch) {
    char c;
    arch>>flete>>c;
    Cliente::lee(arch);
}

void ClienteC::imprime(ofstream &arch) {    
    Cliente::imprime(arch);
    arch<<"Flete: "<<flete<<endl<<endl;
}

