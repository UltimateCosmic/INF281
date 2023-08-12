/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escala.h
 * Author: alulab14
 *
 * Created on 30 de junio de 2023, 08:08 AM
 */

#ifndef ESCALA_H
#define ESCALA_H

class Escala {
private:
    int codigo;
    double precio;
public:
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void leeEscala(ifstream &arch);
};

#endif /* ESCALA_H */

