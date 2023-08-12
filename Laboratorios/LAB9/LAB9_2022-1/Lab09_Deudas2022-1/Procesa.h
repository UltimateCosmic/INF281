/* 
 * Proyecto:    Lab09_Deudas2022-1
 * Archivo:     Procesa.h
 * Autor:       CosmoDev
 *
 * Creado el 21 de junio de 2023, 11:27 PM
 */

#ifndef PROCESA_H
#define PROCESA_H

#include "Pedido.h"
#include "Deudor.h"

class Procesa {
private:
    class Pedido lpedidos[200];
    class Deudor ldeudor[50];
public:
    void carga();
    void cargaPedidos(const char*);
    void cargaClientes(const char*);
    void muestra();
    void muestraClientes(ofstream &);
};

#endif /* PROCESA_H */

