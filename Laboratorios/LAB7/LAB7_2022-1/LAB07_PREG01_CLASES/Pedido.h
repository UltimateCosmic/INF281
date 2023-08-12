/* 
 * Proyecto:    LAB07_PREG01_CLASES
 * Archivo:     Pedido.h
 * Autor:       CosmoDev
 *
 * Creado el 9 de junio de 2023, 01:18 AM
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include <fstream>
using namespace std;

class Pedido {
private:
    int codigo;
    char *nombre;
    int cantidad;
    double precio;
    int dni;
    int fecha;
public:
    Pedido();
    virtual ~Pedido();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(char* nombre);
    void GetNombre(char *) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void separarFecha(int, int &, int &, int &) const;
    bool operator ==(const class Pedido &);
};

void operator >>(ifstream &, class Pedido &);
void operator <<(ofstream &, const class Pedido &);

#endif /* PEDIDO_H */

