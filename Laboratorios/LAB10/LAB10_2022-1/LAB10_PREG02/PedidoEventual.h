/* 
 * File:   PedidoEventual.h
 * Author: aml
 *
 * Created on 26 de junio de 2023, 09:46 AM
 */

#ifndef PEDIDOEVENTUAL_H
#define PEDIDOEVENTUAL_H

#include "Pedido.h"

class PedidoEventual : public Pedido {
private:
    double flete;
public:
    void SetFlete(double flete);
    double GetFlete() const;
    void lee(ifstream &);
    void imprime(ofstream &);
    void descuentaFlete();
};

#endif /* PEDIDOEVENTUAL_H */

