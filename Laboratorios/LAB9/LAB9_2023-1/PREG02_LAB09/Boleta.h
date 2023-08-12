/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boleta.h
 * Author: alulab14
 *
 * Created on 23 de junio de 2023, 08:09 AM
 */

#ifndef BOLETA_H
#define BOLETA_H

#include <fstream>

#include "Alumno.h"

class Boleta {
private:
    class Alumno* pboleta;
public:
    void asignarBoleta(ifstream &);
    void imprimirBoleta(ofstream &);
    void actualizarBoleta(double);
    int obtenerEscala();
    void operator =(class Alumno *);
    bool operator !=(class Alumno *);
};

#endif /* BOLETA_H */

