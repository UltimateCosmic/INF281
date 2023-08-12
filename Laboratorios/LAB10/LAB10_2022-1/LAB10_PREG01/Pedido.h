/* 
 * File:   Pedido.h
 * Author: aml
 *
 * Created on 26 de junio de 2023, 09:33 AM
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include <fstream>


class Pedido {
private:
    int codigo;
    char* nombre;
    int cantidad;
    int dni;
    int fecha;
    double total;
public:
    Pedido();
    virtual ~Pedido();
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(ifstream &);
    virtual void imprime(ofstream &);
    void separarFecha(int &, int &, int &);
};

#endif /* PEDIDO_H */

