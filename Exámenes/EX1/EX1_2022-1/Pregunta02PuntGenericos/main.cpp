/* 
 * Proyecto:    Pregunta02PuntGenericos
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 15 de mayo de 2023, 09:38 PM
 */

#include <iostream>
using namespace std;

#include "PunterosGenericos.h"
#include "MuestraPunteros.h"

int main(int argc, char** argv) {    
    void *productos, *pedidos, *clientes;    
    cargaproductos(productos);    
    cargapedidos(pedidos);
    procesaclientes(productos, pedidos, clientes);    
    imprimereporte(clientes);    
    return 0;
}

