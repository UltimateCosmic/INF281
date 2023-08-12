/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: alulab14
 *
 * Created on 30 de junio de 2023, 08:02 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <fstream>
using namespace std;

class Alumno {
private:
    int codigo;
    char *nombre;
    int escala;
    double creditos;
    double total;
public:
    Alumno();
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char* nombre);
    void GetNombre(char* nombre) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
};

#endif /* ALUMNO_H */

