/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escala.h
 * Author: alulab14
 *
 * Created on 16 de junio de 2023, 08:07 AM
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
};

#endif /* ESCALA_H */

