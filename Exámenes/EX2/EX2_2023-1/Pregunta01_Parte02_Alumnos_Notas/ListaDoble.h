/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaDoble.h
 * Author: alulab14
 *
 * Created on 11 de julio de 2023, 08:29 AM
 */

#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <fstream>
using namespace std;

#include "Nodo.h"

class ListaDoble {
private:
    class Nodo *inicio;
    class Nodo *fin;
public:
    ListaDoble();
    void insertarNodo(ifstream &arch);
    void agregarNodo(class Nodo *nuevo);
    void leerNotasAlumno(ifstream &arch);
    void insertarNota(class Nota &, int);
    void imprimeLista(ofstream &);    
    void imprimeLinea(char c, int n, ofstream &arch);
    void actualizarNotasAlumnos();
};

#endif /* LISTADOBLE_H */

