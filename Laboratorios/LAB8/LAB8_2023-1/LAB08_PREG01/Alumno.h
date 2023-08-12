/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: alulab14
 *
 * Created on 16 de junio de 2023, 08:03 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno {
private:
    int codigo;
    char *nombre;
    int escala;
    double total;
public:
    Alumno();
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char* nomb);
    void GetNombre(char *nomb) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};

#endif /* ALUMNO_H */

