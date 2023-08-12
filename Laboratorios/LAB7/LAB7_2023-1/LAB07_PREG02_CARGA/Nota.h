/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nota.h
 * Author: alulab14
 *
 * Created on 9 de junio de 2023, 08:23 AM
 */

#ifndef NOTA_H
#define NOTA_H

class Nota {
private:
    char *codcurso;
    int ciclo;
    int nota;
public:
    Nota();
    virtual ~Nota();
    void SetNota(int nota);
    int GetNota() const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void SetCodcurso(char* codcurso);
    char* GetCodcurso(char *) const;
};

#endif /* NOTA_H */

