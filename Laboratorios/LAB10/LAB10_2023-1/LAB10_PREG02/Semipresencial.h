/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Semipresencial.h
 * Author: alulab14
 *
 * Created on 30 de junio de 2023, 08:09 AM
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H

#include "Alumno.h"

class Semipresencial : public Alumno {
private:
    double descuento;
    double total;
public:
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &);
    void imprime(ofstream &arch); 
    void actualiza(double precio);
};

#endif /* SEMIPRESENCIAL_H */

