/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Facultad.h
 * Author: alulab14
 *
 * Created on 11 de julio de 2023, 08:28 AM
 */

#ifndef FACULTAD_H
#define FACULTAD_H

#include "ListaDoble.h"

class Facultad {
private:
    ListaDoble alumnosxNotas;
public:
    void leerAlumnosNotas (const char *, const char *);
    void leerAlumnos (ifstream &arch);
    void leerNotas (ifstream &arch);
    void insertarNota(class Nota &notaAlumno, int codigo);
    void imprimeAlumnosNotas (const char *nombArchReporte);
};

#endif /* FACULTAD_H */

