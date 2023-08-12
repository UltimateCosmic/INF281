/* 
 * Proyecto:    LAB07_PREG01_CLASES
 * Archivo:     Cliente.h
 * Autor:       CosmoDev
 *
 * Creado el 9 de junio de 2023, 02:01 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pedido.h"
#include <fstream>
using namespace std;

class Cliente {
private:
    int dni;
    char categoria;
    char *nombre;
    class Pedido lped[100];
    int numped;
    double total;
public:
    Cliente();
    virtual ~Cliente();
    void SetTotal(double total);
    double GetTotal() const;
    void SetNumped(int numped);
    int GetNumped() const;
    void SetNombre(char* nombre);
    void GetNombre(char *) const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    void operator =(const class Pedido &);
    void operator -=(const class Pedido &);
    void operator /(double);
    void imprimeLinea(ofstream &, char, int) const;
    void imprimeProductos(ofstream &) const;
};

void operator >>(ifstream &, class Cliente &);
void operator <<(ofstream &, const class Cliente &);

#endif /* CLIENTE_H */

