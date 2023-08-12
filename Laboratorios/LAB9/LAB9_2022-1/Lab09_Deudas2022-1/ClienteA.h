/* 
 * Proyecto:    Lab09_Deudas2022-1
 * Archivo:     ClienteA.h
 * Autor:       CosmoDev
 *
 * Creado el 21 de junio de 2023, 11:18 PM
 */

#ifndef CLIENTEA_H
#define CLIENTEA_H

#include <fstream>
using namespace std;

#include "Cliente.h"

class ClienteA : public Cliente {
private:
    double descuento;
public:
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &);
    void imprime(ofstream &);    
};

#endif /* CLIENTEA_H */

