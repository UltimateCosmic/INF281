/* 
 * Proyecto:    PruebaSobrecargas
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 27 de abril de 2023, 02:31 PM
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "OperadoresSobrecargados.h"
#include "StructConductor.h"
#include "StructInfraccion.h"
#include "StructInfraccionEstab.h"

int main(int argc, char** argv) {
    
    struct ConductorSt conductor;
    struct InfraccionSt infraccion;    
    struct InfraccionEstabSt infraccionEst;    
    bool lectura;        
        
    // Lectura:     
    ifstream archCond("Conductores.txt", ios::in);
    lectura = archCond>>conductor;
    cout<<lectura<<", ";
    lectura = archCond>>conductor;
    cout<<lectura<<endl;
    
    ifstream archInf("RegistroDeFallas.txt", ios::in);
    lectura = archInf>>infraccion;
    cout<<lectura<<", ";
    lectura = archInf>>infraccion;
    cout<<lectura<<endl;
    
    ifstream archFal("Infracciones.txt", ios::in);
    lectura = archFal>>infraccionEst;
    cout<<lectura<<", ";
    lectura = archFal>>infraccionEst;
    cout<<lectura<<endl<<endl;
    
    // Agreación:
    conductor+infraccion;
    cout<<infraccion.codInf<<" - ";
    cout<<conductor.faltas[conductor.numFaltas-1].codInf<<endl;
    
    infraccionEst.codigo = conductor.faltas[conductor.numFaltas-1].codInf;
    conductor+infraccionEst;
    cout<<infraccionEst.gravedad<<" - ";
    cout<<conductor.faltas[conductor.numFaltas-1].gravedad<<endl<<endl;
       
    // Cálculo de las infracciones cometidas:
    cout<<conductor.numFaltas<<" = "<<conductor.numFaltasLeves<<" + "
            <<conductor.numFaltasGraves<<" + "<<conductor.numFaltasMuyGraves<<endl;
    cout<<conductor.montoFaltasLeves<<" + "<<conductor.montoFaltasGraves<<" + "
            <<conductor.montoFaltasMuyGraves<<endl;
    ++conductor;
    cout<<conductor.numFaltas<<" = "<<conductor.numFaltasLeves<<" + "
            <<conductor.numFaltasGraves<<" + "<<conductor.numFaltasMuyGraves<<endl;
    cout<<conductor.montoFaltasLeves<<" + "<<conductor.montoFaltasGraves<<" + "
            <<conductor.montoFaltasMuyGraves<<endl<<endl;
    
    // Amnistía de infracciones:
    cout<<conductor.faltas[0].gravedad<<" / "<<conductor.faltas[0].multa<<endl;
    conductor*20230427;
    cout<<conductor.faltas[0].gravedad<<" / "<<conductor.faltas[0].multa<<endl<<endl;
    
    // Impresión:
    ofstream archRep("Reporte.txt", ios::out);
    archRep<<conductor;
    
    return 0;
}

