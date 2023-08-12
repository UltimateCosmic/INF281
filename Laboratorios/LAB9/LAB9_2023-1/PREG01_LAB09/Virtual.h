/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.h
 * Author: alulab14
 *
 * Created on 23 de junio de 2023, 08:07 AM
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include "Alumno.h"

class Virtual : public Alumno {
private:
    char *licencia;
    double total;
public:
    Virtual();
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char*);
    void GetLicencia(char*) const;
    void lee(ifstream &);
    void imprime(ofstream &);
};

#endif /* VIRTUAL_H */

