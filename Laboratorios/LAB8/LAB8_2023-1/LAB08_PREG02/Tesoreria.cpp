/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.cpp
 * Author: alulab14
 * 
 * Created on 16 de junio de 2023, 08:16 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Tesoreria.h"
#define MAX_LINEA 90

void Tesoreria::cargaescalas() {
    ifstream arch("escalas.csv", ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo escalas.csv"<<endl;
        exit(1);
    }
    int escala, numEsc=0;
    double costo;
    while (true) {
        arch>>escala;
        if (arch.eof()) break;
        arch.get();
        arch>>costo;
        lescala[numEsc].SetCodigo(escala);
        lescala[numEsc].SetPrecio(costo);
        numEsc++;
    }
    lescala[numEsc].SetCodigo(0);
}

void Tesoreria::cargaalumnos() {
    ifstream arch("Alumnos.csv", ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo Alumnos.csv"<<endl;
        exit(1);
    } 
    int codigo, escala, nP=0, nS=0, nV=0;
    char tipo, nombre[60], licencia[10], c;
    double descuento, recarga;
    while (true) {
        arch>>tipo;
        if (arch.eof()) break;
        arch>>c>>codigo>>c;
        arch.getline(nombre, 60, ',');
        if (tipo=='S') {
            arch>>descuento>>c>>escala;            
            lsemipresencial[nS].SetDescuento(descuento);
            lsemipresencial[nS].Semipresencial::SetTotal(0);
            // class Alumno:
            lsemipresencial[nS].Alumno::SetTotal(0);
            lsemipresencial[nS].SetCodigo(codigo);
            lsemipresencial[nS].SetNombre(nombre);
            lsemipresencial[nS].SetEscala(escala);
            nS++;
        } else if (tipo=='P') {
            arch>>recarga>>c>>escala;
            lpresencial[nP].SetRecargo(recarga);
            lpresencial[nP].Presencial::SetTotal(0);
            // class Alumno:
            lpresencial[nP].Alumno::SetTotal(0);
            lpresencial[nP].SetCodigo(codigo);
            lpresencial[nP].SetNombre(nombre);
            lpresencial[nP].SetEscala(escala);
            nP++;
        } else if (tipo=='V') {
            arch.getline(licencia, 10, ',');
            arch>>escala;
            lvirtual[nV].SetLicencia(licencia);
            lvirtual[nV].Virtual::SetTotal(0);
            // class Alumno:
            lvirtual[nV].Alumno::SetTotal(0);
            lvirtual[nV].SetCodigo(codigo);
            lvirtual[nV].SetNombre(nombre);
            lvirtual[nV].SetEscala(escala);
            nV++;
        }        
    }
    lsemipresencial[nS].SetCodigo(0);
    lpresencial[nP].SetCodigo(0);
    lvirtual[nV].SetCodigo(0);
}

void Tesoreria::actualiza(int cant) {
    double precio, descuento, recargo, licencia;
    for (int i=0; lsemipresencial[i].GetCodigo(); i++) {
        precio = buscarPrecio(lsemipresencial[i].GetEscala());
        descuento = lsemipresencial[i].GetDescuento();
        lsemipresencial[i].Semipresencial::SetTotal(precio*cant);
        lsemipresencial[i].Alumno::SetTotal(precio*cant*(1-(descuento/100)));
    }
    for (int i=0; lpresencial[i].GetCodigo(); i++) {
        precio = buscarPrecio(lpresencial[i].GetEscala());
        recargo = lpresencial[i].GetRecargo();
        lpresencial[i].Presencial::SetTotal(precio*cant);
        lpresencial[i].Alumno::SetTotal(precio*cant*(1+(recargo/100)));
    }
    for (int i=0; lvirtual[i].GetCodigo(); i++) {
        precio = buscarPrecio(lpresencial[i].GetEscala());
        licencia = 100.00;
        lvirtual[i].Virtual::SetTotal(precio*cant);
        lvirtual[i].Alumno::SetTotal(precio*cant+licencia);
    }    
}

double Tesoreria::buscarPrecio(int escala) {
    for (int i=0; lescala[i].GetCodigo(); i++)
        if (escala==lescala[i].GetCodigo())
            return lescala[i].GetPrecio();
}

void Tesoreria::imprime() {
    ofstream arch("ReporteDeAlumnos.txt", ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo ReporteDeAlumnos.txt"<<endl;
        exit(1);
    } 
    arch.precision(2);
    arch<<fixed;
    imprimirCabecera(arch); 
    imprimeP(arch);
    imprimeV(arch);
    imprimeS(arch);
}

void Tesoreria::imprimeP(ofstream &arch) {
    int codigo, escala; 
    char nombre[60];
    double total;    
    for (int i=0; lpresencial[i].GetCodigo(); i++) {
        // Alumno
        codigo = lpresencial[i].GetCodigo();
        lpresencial[i].GetNombre(nombre);
        escala = lsemipresencial[i].GetEscala();
        total = lpresencial[i].Alumno::GetTotal();  
        arch<<left<<setw(15)<<codigo<<setw(40)<<nombre<<setw(23)<<escala
                <<total<<endl;             
    }
}

void Tesoreria::imprimeV(ofstream &arch) {
    int codigo, escala; 
    char nombre[60], licencia[10];
    double total;    
    for (int i=0; lvirtual[i].GetCodigo(); i++) {        
        lvirtual[i].GetLicencia(licencia);
        // Alumno
        codigo = lvirtual[i].GetCodigo();
        lvirtual[i].GetNombre(nombre);
        escala = lvirtual[i].GetEscala();
        total = lvirtual[i].Alumno::GetTotal();  
        arch<<left<<setw(15)<<codigo<<setw(40)<<nombre<<setw(10)<<escala<<setw(13)
                <<setw(13)<<licencia<<total<<endl;             
    }
}

void Tesoreria::imprimeS(ofstream &arch) {
    int codigo, escala; 
    char nombre[60], licencia[10];
    double total;    
    for (int i=0; lsemipresencial[i].GetCodigo(); i++) {
        // Alumno
        codigo = lsemipresencial[i].GetCodigo();
        lsemipresencial[i].GetNombre(nombre);
        escala = lsemipresencial[i].GetEscala();
        total = lsemipresencial[i].Alumno::GetTotal();  
        arch<<left<<setw(15)<<codigo<<setw(40)<<nombre<<setw(23)<<escala
                <<total<<endl;             
    }
}

void Tesoreria::imprimirCabecera(ofstream &arch) {    
    arch<<right<<"Codigo"<<setw(15)<<"Nombre"<<setw(38)<<"Escala"<<setw(14)
            <<"Licencia"<<setw(10)<<"Total"<<endl;
    imprimirLinea(arch, '=', MAX_LINEA);
}

void Tesoreria::imprimirLinea(ofstream &arch, char c, int n) {
    for (int i=0; i<n; i++) arch.put(c);
    arch.put('\n');    
}