/* 
 * Proyecto:    BibliotecaCompilada
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 27 de abril de 2023, 09:13 PM
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "OperadoresSobrecargados.h"
#include "StructConductor.h"

int main(int argc, char** argv) {
    struct ConductorSt conductor;
    ifstream archConductores("Conductores.txt", ios::in);
    if (not archConductores) {
        cout<<"ERROR: No se pudo abrir el archivo Conductores.txt"<<endl;
        exit(1);
    }
    ofstream archReporte("Reporte.txt", ios::out);
    if (not archReporte) {
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }    
    while (true) {
        if(not (archConductores>>conductor)) break;
        archReporte<<conductor;
    }    
    return 0;
}

