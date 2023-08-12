/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.h
 * Author: alulab14
 *
 * Created on 23 de junio de 2023, 08:11 AM
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Boleta.h"
#include "Escala.h"

class Tesoreria {
private:
    class Boleta lboleta[100];
    class Escala lescala[5];
public:
    void cargaescalas();
    void cargaalumnos();
    void imprimeboleta();
    void imprimirCabecera(ofstream &);
    void imprimirLinea(ofstream &, char, int);
    void actualizaboleta();
    double buscarPrecio(int);
};

#endif /* TESORERIA_H */

