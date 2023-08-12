/* 
 * Proyecto:    LAB10_PREG02
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 29 de junio de 2023, 05:44 PM
 */

#include <iostream>
using namespace std;

#include "Promociones.h"

int main(int argc, char** argv) {
    Promociones pro;
    
    pro.leepedidos();
    pro.actualizapedidos();
    pro.imprimepedidos();
    return 0;
}


