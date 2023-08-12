/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: alulab14
 *
 * Created on 23 de junio de 2023, 07:58 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

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
    void SetNombre(const char*);
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(ifstream &);
    virtual void imprime(ofstream &);
};

#endif /* ALUMNO_H */

