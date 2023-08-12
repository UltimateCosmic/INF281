/* 
 * Proyecto:    LAB08_PREG01
 * Archivo:     Pedido.h
 * Autor:       CosmoDev
 *
 * Creado el 16 de junio de 2023, 02:41 AM
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include "Producto.h"

class Pedido : public Producto{
private:
    int codigo;
    int cantidad;
    int dni;
    int fecha;
    double total;
    char *obs;
public:
    Pedido();
    virtual ~Pedido();
    void SetObs(const char *);
    void GetObs(char *) const;
    void SetTotal(double);
    double GetTotal() const;
    void SetFecha(int);
    int GetFecha() const;
    void SetDni(int);
    int GetDni() const;
    void SetCantidad(int);
    int GetCantidad() const;
    void SetCodigo(int);
    int GetCodigo() const;
};

#endif /* PEDIDO_H */

