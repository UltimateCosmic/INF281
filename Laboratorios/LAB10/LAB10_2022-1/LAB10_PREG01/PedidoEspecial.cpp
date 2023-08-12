/* 
 * File:   PedidoEspecial.cpp
 * Author: aml
 * 
 * Created on 26 de junio de 2023, 09:42 AM
 */

#include <iomanip>
#include <fstream>
using namespace std;

#include "PedidoEspecial.h"

void PedidoEspecial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoEspecial::GetDescuento() const {
    return descuento;
}

void PedidoEspecial::lee(ifstream &arch) {
    char c;
    arch>>c>>descuento>>c;
    Pedido::lee(arch);
    double monto = GetTotal();
    monto *= (1-descuento/100);
    SetTotal(monto);
}

void PedidoEspecial::imprime(ofstream &arch) {
    Pedido::imprime(arch);
    arch<<"Descuento:"<<setw(11)<<descuento<<'%'<<endl;
}

