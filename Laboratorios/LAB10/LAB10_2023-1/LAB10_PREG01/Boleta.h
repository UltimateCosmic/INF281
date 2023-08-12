/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boleta.h
 * Author: alulab14
 *
 * Created on 30 de junio de 2023, 08:13 AM
 */

#ifndef BOLETA_H
#define BOLETA_H

#include "Alumno.h"

class Boleta {
private:
    class Alumno *pboleta;
public:
    Boleta();
    void cargarDatos(ifstream &arch);
    int cmp(Boleta &);
    Alumno *retornaAlumno();
    void imprimeLinea(ofstream &arch);
};

#endif /* BOLETA_H */

