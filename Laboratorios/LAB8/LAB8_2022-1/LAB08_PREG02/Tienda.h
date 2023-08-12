/* 
 * Proyecto:    LAB08_PREG01
 * Archivo:     Tienda.h
 * Autor:       CosmoDev
 *
 * Creado el 16 de junio de 2023, 02:48 AM
 */

#ifndef TIENDA_H
#define TIENDA_H

#include "Pedido.h"
#include "Cliente.h"

class Tienda {
private:
    class Pedido lpedidos[200];
    class Cliente lclientes[50];
public:
    void carga();
    void cargaPedidos(ifstream &);
    bool buscarProducto(int, char *, double &, int &);
    void cargaClientes(ifstream &);
    void muestra();
    void fecha_a_ddmmaa(int, int &, int &, int &);
    void actualiza(int);
};

#endif /* TIENDA_H */

