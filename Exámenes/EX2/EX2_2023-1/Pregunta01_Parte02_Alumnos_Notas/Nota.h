/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nota.h
 * Author: alulab14
 *
 * Created on 11 de julio de 2023, 08:05 AM
 */

#ifndef NOTA_H
#define NOTA_H

class Nota {
private:
    int ciclo;
    char* codigo_curso;
    double creditos;
    int calificacion;
    int vez;
public:
    Nota();
    Nota(const Nota& orig);
    virtual ~Nota();
    void SetVez(int vez);
    int GetVez() const;
    void SetCalificacion(int calificacion);
    int GetCalificacion() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetCodigo_curso(const char* codigo_curso);
    void GetCodigo_curso(char* codigo_curso) const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void imprimeNota(ofstream &arch);
};

void operator >>(ifstream &arch, class Nota &notaAlumno);

#endif /* NOTA_H */

