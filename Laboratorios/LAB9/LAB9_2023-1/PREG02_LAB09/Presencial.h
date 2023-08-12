/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Presencial.h
 * Author: alulab14
 *
 * Created on 23 de junio de 2023, 08:05 AM
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H

#include "Alumno.h"

class Presencial : public Alumno {
private:
    double recargo;
    double total;
public:
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void lee(ifstream &);
    void imprime(ofstream &);
    void actualizatotal(double);
};

#endif /* PRESENCIAL_H */

