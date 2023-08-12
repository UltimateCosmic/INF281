/* 
 * Proyecto:    Lab09_Deudas2022-1
 * Archivo:     ClienteC.h
 * Autor:       CosmoDev
 *
 * Creado el 21 de junio de 2023, 11:21 PM
 */

#ifndef CLIENTEC_H
#define CLIENTEC_H

#include <fstream>
using namespace std;

#include "Cliente.h"

class ClienteC : public Cliente {
private:
    double flete;
public:
    void SetFlete(double flete);
    double GetFlete() const;
    void lee(ifstream &);
    void imprime(ofstream &);  
};

#endif /* CLIENTEC_H */

