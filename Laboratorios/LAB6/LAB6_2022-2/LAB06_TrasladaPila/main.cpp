/* 
 * Proyecto:    LAB06_TrasladaPila
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 1 de junio de 2023, 06:43 PM
 */

#include <iostream>
using namespace std;

#include "BibliotecaPilaGenerica.h"
#include "PilaConEnteros.h"
#include "PilaConRegistros.h"

int main(int argc, char** argv) {
    
    void *arreglo, *pilaini, *pilafin;  
    
    cargaarreglo(arreglo,cmpnumero,leenumero,"numeros.txt");
    cargaPila(pilaini, arreglo);
    muevepila(pilaini, pilafin);
    imprimePila(pilafin, imprimenumero, "repnumeros.txt");
    
    cargaarreglo(arreglo,cmpregistro,leeregistro,"medicinas.csv");
    cargaPila(pilaini, arreglo);
    muevepila(pilaini, pilafin);
    imprimePila(pilafin, imprimeregistro, "repmedicinas.txt");
    
    return 0;
}

