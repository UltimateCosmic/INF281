/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   alumnonota.h
 * Author: alulab14
 *
 * Created on 9 de junio de 2023, 08:01 AM
 */

#ifndef ALUMNONOTA_H
#define ALUMNONOTA_H

#include "Nota.h"

class alumnonota {
private:
    int codigo;
    char *codcurso;
    int ciclo;
    int nota;
public:
    alumnonota();
    virtual ~alumnonota();
    void SetNota(int nota);
    int GetNota() const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void SetCodcurso(char* codcurso);
    char* GetCodcurso(char *) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void operator &(class Nota &);
};

void operator >>(ifstream &, class alumnonota &);

#endif /* ALUMNONOTA_H */

