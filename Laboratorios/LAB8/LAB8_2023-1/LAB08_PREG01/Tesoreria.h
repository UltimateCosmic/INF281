/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.h
 * Author: alulab14
 *
 * Created on 16 de junio de 2023, 08:16 AM
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Escala.h"

class Tesoreria {
private:
    class Presencial lpresencial[100];
    class Semipresencial lsemipresencial[100];
    class Virtual lvirtual[100];
    class Escala lescala[10];
public:
    void cargaescalas();
    void cargaalumnos();
    void actualiza(int cant);
    double buscarPrecio(int escala);
    void imprime();
    void imprimirCabeceraS(ofstream &arch);
    void imprimirCabeceraP(ofstream &arch);
    void imprimirCabeceraV(ofstream &arch);
    void imprimirLinea(ofstream &, char, int n);
};

#endif /* TESORERIA_H */

