/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.h
 * Author: alulab14
 *
 * Created on 30 de junio de 2023, 08:21 AM
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Arbol.h"

class Tesoreria {
private:
    class Arbol aboleta;
public:
    void cargaalumnos();
    void imprimeboleta();    
    void imprimirCabecera(ofstream &);
    void imprimirLinea(ofstream &, char, int);
};

#endif /* TESORERIA_H */

