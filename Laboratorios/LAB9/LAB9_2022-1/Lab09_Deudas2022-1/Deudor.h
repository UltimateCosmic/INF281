/* 
 * Proyecto:    Lab09_Deudas2022-1
 * Archivo:     Deudor.h
 * Autor:       CosmoDev
 *
 * Creado el 21 de junio de 2023, 11:24 PM
 */

#ifndef DEUDOR_H
#define DEUDOR_H

#include <fstream>

#include "Cliente.h"

class Deudor {
private:
    class Cliente* cdeudor;
public:
    Deudor();
    virtual ~Deudor();
    void asignaCliente(ifstream &);
    void imprimeCliente(ofstream &);
};

#endif /* DEUDOR_H */

