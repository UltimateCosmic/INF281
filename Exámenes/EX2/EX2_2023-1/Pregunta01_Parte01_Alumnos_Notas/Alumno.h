/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: alulab14
 *
 * Created on 11 de julio de 2023, 08:10 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno {
private:
    int codigo_alumno;
    char* nombre;
    double promedio;
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetPromedio(double promedio);
    double GetPromedio() const;
    void SetNombre(const char* nombre);
    void GetNombre(char* nombre) const;
    void SetCodigo_alumno(int codigo_alumno);
    int GetCodigo_alumno() const;
    void imprimeAlumno(ofstream &arch);
};

void operator >>(ifstream &arch, class Alumno &alumno);

#endif /* ALUMNO_H */

