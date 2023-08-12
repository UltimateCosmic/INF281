/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.cpp
 * Author: alulab14
 * 
 * Created on 23 de junio de 2023, 08:11 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Tesoreria.h"
#include "Escala.h"
#define MAX_LINEA 100

void Tesoreria::cargaescalas() {
    ifstream arch("escalas.csv", ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo escalas.csv"<<endl;
        exit(1);
    }
    int nd=0;
    while (true) {
        arch>>lescala[nd];
        if (arch.eof()) break;        
        nd++;
    }
    lescala[nd].SetCodigo(0);
}

void Tesoreria::cargaalumnos() {
    ifstream arch("Alumnos.csv", ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo Alumnos.csv"<<endl;
        exit(1);
    }
    int nd=0;
    while (true) {
        lboleta[nd].asignarBoleta(arch);
        if (arch.eof()) break;        
        nd++;
    }
    lboleta[nd]=nullptr;
}

void Tesoreria::imprimeboleta() {
    ofstream arch("ReporteDeAlumnos.txt", ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo ReporteDeAlumnos.txt"<<endl;
        exit(1);
    }
    imprimirCabecera(arch);
    for (int i=0; lboleta[i]!=nullptr; i++)
        lboleta[i].imprimirBoleta(arch);
}

void Tesoreria::imprimirCabecera(ofstream &arch) {
    arch<<right<<"Codigo"<<setw(15)<<"Nombre"<<setw(40)<<"Escala"<<setw(10)
            <<"Cred."<<setw(15)<<"Licencia"<<setw(10)<<"Total"<<endl;
    imprimirLinea(arch, '=', MAX_LINEA);
}

void Tesoreria::imprimirLinea(ofstream &arch, char c, int n) {
    for (int i=0; i<n; i++) arch.put(c);
    arch.put('\n');
}

void Tesoreria::actualizaboleta() {
    double precio;
    int escala;    
    for (int i=0; lboleta[i]!=nullptr; i++) {
        escala = lboleta[i].obtenerEscala();
        precio = buscarPrecio(escala);
        lboleta[i].actualizarBoleta(precio);
    }
}

double Tesoreria::buscarPrecio(int escala) {    
    for (int i=0; lescala[i].GetCodigo(); i++)
        if (escala==lescala[i].GetCodigo())
            return lescala[i].GetPrecio();    
}