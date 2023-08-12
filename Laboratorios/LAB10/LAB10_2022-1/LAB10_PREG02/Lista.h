/* 
 * File:   Lista.h
 * Author: aml
 *
 * Created on 26 de junio de 2023, 09:55 AM
 */

#ifndef LISTA_H
#define LISTA_H

#include <fstream>
using namespace std;

#include "Nodo.h"

class Lista {
private:
    class Nodo* lini;
    class Nodo* lfin;
    void insertar(class Nodo*); // Preservamos el encapsulamiento
public:
    Lista();
    virtual ~Lista();
    void crearLista(ifstream &);
    void imprimeLista(ofstream &);
    void imprimeCabecera(ofstream &);
    void imprimeLinea(ofstream &, char, int);
    void actualiza(ifstream &);
    void actualizaCliente(int, int);
};

#endif /* LISTA_H */

