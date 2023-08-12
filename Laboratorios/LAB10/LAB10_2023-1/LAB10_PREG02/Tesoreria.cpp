/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.cpp
 * Author: alulab14
 * 
 * Created on 30 de junio de 2023, 08:21 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Tesoreria.h"
#define MAX_LINEA 100

void Tesoreria::cargaalumnos() {
    ifstream arch("Alumnos.csv", ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo Alumnos.csv"<<endl;
        exit(1);        
    }
    Boleta bole;
    while (true) {
        bole.cargarDatos(arch);
        if (arch.eof()) break;
        aboleta.inserta(bole);
    }    
}

void Tesoreria::imprimeboleta() {
    ofstream arch("ReporteDeAlumnos.txt", ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo ReporteDeAlumnos.txt"<<endl;
        exit(1);        
    }
    arch.precision(2);
    arch<<fixed;
    imprimirCabecera(arch);
    aboleta.imprimir(arch);
}

void Tesoreria::imprimirCabecera(ofstream &arch) {    
    arch<<"Codigo"<<setw(20)<<"Nombre"<<setw(38)<<"Escala"<<setw(11)<<"Cred."
            <<setw(13)<<"Licencia"<<setw(9)<<"Total"<<endl;
    imprimirLinea(arch, '=', MAX_LINEA);
}

void Tesoreria::imprimirLinea(ofstream &arch, char c, int n) {    
    for (int i=0; i<n; i++) arch.put(c);
    arch.put('\n');
}

void Tesoreria::actualizaboleta() {    
    ifstream arch("escalas.csv", ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo escalas.csv"<<endl;
        exit(1);        
    }
    aboleta.actualiza(arch);
}

