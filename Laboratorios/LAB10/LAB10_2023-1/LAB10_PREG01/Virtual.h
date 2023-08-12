/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.h
 * Author: alulab14
 *
 * Created on 30 de junio de 2023, 08:11 AM
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
    void SetLicencia(const char* licencia);
    void GetLicencia(char* licencia) const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* VIRTUAL_H */

