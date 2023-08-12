/* 
 * File:   Nodo.h
 * Author: aml
 *
 * Created on 26 de junio de 2023, 09:48 AM
 */

#ifndef NODO_H
#define NODO_H

#include "Pedido.h"
#include "Lista.h"

class Nodo {
private:
    class Pedido* ped;
    class Nodo* sig;
    class Nodo* ant;
public:
    Nodo() {
        sig = ant = nullptr;
    };
    friend class Lista;
};

#endif /* NODO_H */

