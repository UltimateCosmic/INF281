/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Alumno: Johan Carlo Amador Egoavil
 * Código: 20203350
 *
 * Created on 16 de junio de 2023, 08:02 AM
 */

#include <iostream>
using namespace std;

#include "Tesoreria.h"

int main(int argc, char** argv) {
    Tesoreria caja;
    caja.cargaescalas();
    caja.cargaalumnos();
    caja.actualiza(20);
    caja.imprime();
    return 0;
}

