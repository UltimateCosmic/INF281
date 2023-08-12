/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: alulab14
 *
 * Created on 11 de julio de 2023, 08:29 AM
 */

#ifndef NODO_H
#define NODO_H

#include <fstream>

#include "ListaDoble.h"
#include "AlumnoNotas.h"

class Nodo {
private:
    AlumnoNotas dato;
    Nodo *siguiente;
    Nodo *anterior;
public:
    Nodo();
    void leerAlumno(ifstream &arch);
    void imprimeDato(ofstream &arch);
    friend class ListaDoble;
};

#endif /* NODO_H */

