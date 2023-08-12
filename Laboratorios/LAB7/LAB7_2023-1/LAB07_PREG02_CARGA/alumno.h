/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   alumno.h
 * Author: alulab14
 *
 * Created on 9 de junio de 2023, 08:03 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include "Nota.h"
#include "alumno.h"

class alumno {
private:
    int codigo;
    char *nombre;
    int numcursos;
    int numaprobados;
    int numprimera;
    int numsegunda;
    int numtercera;
    class Nota lnotas[20];
public:
    alumno();
    virtual ~alumno();
    void SetNumtercera(int numtercera);
    int GetNumtercera() const;
    void SetNumsegunda(int numsegunda);
    int GetNumsegunda() const;
    void SetNumprimera(int numprimera);
    int GetNumprimera() const;
    void SetNumaprobados(int numaprobados);
    int GetNumaprobados() const;
    void SetNumcursos(int numcursos);
    int GetNumcursos() const;
    void SetNombre(char* nombre);
    char* GetNombre(char *) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void operator +=(class Nota &);
};

void operator >>(ifstream &, class alumno &);
void operator <<(ofstream &, const class alumno &);

#endif /* ALUMNO_H */

