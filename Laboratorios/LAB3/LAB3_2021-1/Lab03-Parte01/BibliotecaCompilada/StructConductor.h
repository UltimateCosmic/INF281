/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   StructConductor.h
 * Author: alulab14
 *
 * Created on 25 de abril de 2023, 04:57 PM
 */

#ifndef STRUCTCONDUCTOR_H
#define STRUCTCONDUCTOR_H

#include "StructFalta.h"

struct ConductorSt {
    int licencia;
    char nombre[60];
    struct FaltaSt faltas[20];
    int numFaltas;
    int numFaltasLeves;
    int numFaltasGraves;
    int numFaltasMuyGraves;
    double montoFaltasLeves;
    double montoFaltasGraves;
    double montoFaltasMuyGraves;    
};

#endif /* STRUCTCONDUCTOR_H */

