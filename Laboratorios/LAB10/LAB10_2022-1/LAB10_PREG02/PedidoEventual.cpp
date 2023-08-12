/* 
 * File:   PedidoEventual.cpp
 * Author: aml
 * 
 * Created on 26 de junio de 2023, 09:46 AM
 */

#include <iomanip>
#include <fstream>
using namespace std;

#include "PedidoEventual.h"

void PedidoEventual::SetFlete(double flete) {
    this->flete = flete;
}

double PedidoEventual::GetFlete() const {
    return flete;
}

void PedidoEventual::lee(ifstream &arch) {
    char c;
    arch>>c>>flete>>c;
    Pedido::lee(arch);
    double monto = GetTotal();
    monto *= (1+flete/100);
    SetTotal(monto);
}

void PedidoEventual::imprime(ofstream &arch) {
    Pedido::imprime(arch);
    arch<<"Flete:"<<setw(15)<<flete<<'%'<<endl;
}

void PedidoEventual::descuentaFlete() {
    flete = 0;
};

