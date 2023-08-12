/* 
 * File:   PedidoEspecial.h
 * Author: aml
 *
 * Created on 26 de junio de 2023, 09:42 AM
 */

#ifndef PEDIDOESPECIAL_H
#define PEDIDOESPECIAL_H

#include "Pedido.h"

class PedidoEspecial : public Pedido {
private:
    double descuento;
public:
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &);
    void imprime(ofstream &);
    void descuentaFlete();
};

#endif /* PEDIDOESPECIAL_H */

