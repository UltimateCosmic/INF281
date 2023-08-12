/* 
 * File:   PedidoUsual.cpp
 * Author: aml
 * 
 * Created on 26 de junio de 2023, 09:44 AM
 */

#include <iomanip>
#include <fstream>
using namespace std;

#include "PedidoUsual.h"

void PedidoUsual::SetFlete(double flete) {
    this->flete = flete;
}

double PedidoUsual::GetFlete() const {
    return flete;
}

void PedidoUsual::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoUsual::GetDescuento() const {
    return descuento;
}

void PedidoUsual::lee(ifstream &arch) {
    char c;
    arch>>c>>descuento>>c>>flete>>c;
    Pedido::lee(arch);
    double monto = GetTotal();    
    monto *= (1+flete/100);
    monto *= (1-descuento/100);
    SetTotal(monto);
}

void PedidoUsual::imprime(ofstream &arch) {
    Pedido::imprime(arch);
    arch<<"Descuento:"<<setw(11)<<descuento<<'%'<<endl;
    arch<<"Flete:"<<setw(15)<<flete<<'%'<<endl;
}

void PedidoUsual::descuentaFlete() {
    flete = 0;
};

