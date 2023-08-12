/* 
 * File:   PedidoUsual.h
 * Author: aml
 *
 * Created on 26 de junio de 2023, 09:44 AM
 */

#ifndef PEDIDOUSUAL_H
#define PEDIDOUSUAL_H

#include "Pedido.h"

class PedidoUsual : public Pedido {
private:
    double descuento;
    double flete;
public:
    void SetFlete(double flete);
    double GetFlete() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &);
    void imprime(ofstream &);
    void descuentaFlete();
};

#endif /* PEDIDOUSUAL_H */

