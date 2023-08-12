/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: alulab14
 *
 * Created on 30 de junio de 2023, 08:14 AM
 */

#ifndef NODO_H
#define NODO_H

#include "Boleta.h"

class Nodo {
private:
    class Boleta dboleta;
    class Nodo *izq;
    class Nodo *der;
public:
    Nodo();
    friend class Arbol;
};

#endif /* NODO_H */

