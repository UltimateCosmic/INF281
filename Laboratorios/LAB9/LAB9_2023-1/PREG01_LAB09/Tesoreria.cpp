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
#include <fstream>
using namespace std;

#include "Tesoreria.h"
#include "Escala.h"

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
    ofstream arch("ReporteDePrueba.txt", ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo ReporteDePrueba.txt"<<endl;
        exit(1);
    }
    for (int i=0; lboleta[i]!=nullptr; i++)
        lboleta[i].imprimirBoleta(arch);
}