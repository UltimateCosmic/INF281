/* 
 * Proyecto:    Lab09_Deudas2022-1
 * Archivo:     ClienteB.h
 * Autor:       CosmoDev
 *
 * Creado el 21 de junio de 2023, 11:20 PM
 */

#ifndef CLIENTEB_H
#define CLIENTEB_H

#include <fstream>
using namespace std;

#include "Cliente.h"

class ClienteB : public Cliente {
private:
    double descuento;
    double flete;
public:
    void SetFlete(double flete);
    double GetFlete() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &);
    void imprime(ofstream &);  
};

#endif /* CLIENTEB_H */

