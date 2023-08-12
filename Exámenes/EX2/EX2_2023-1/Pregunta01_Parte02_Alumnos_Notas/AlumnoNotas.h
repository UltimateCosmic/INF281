/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlumnoNotas.h
 * Author: alulab14
 *
 * Created on 11 de julio de 2023, 08:27 AM
 */

#ifndef ALUMNONOTAS_H
#define ALUMNONOTAS_H

#include <vector>
#include <fstream>
using namespace std;

#include "Nota.h"
#include "Alumno.h"

class AlumnoNotas {
private:
    Alumno alumno;
    vector <class Nota> notas;
public:
    AlumnoNotas();
    AlumnoNotas(const AlumnoNotas& orig);
    virtual ~AlumnoNotas();
    void leerDato(ifstream &arch);
    int obtenerCodigo();
    void insertarNota(class Nota &notaAlumno);
    void imprimirAlumno(ofstream &arch);
    void actualizarDato();
    void actualizar();
    void borrarNotaRepetida(const char *, int i);
    void totalizar();
};

#endif /* ALUMNONOTAS_H */

