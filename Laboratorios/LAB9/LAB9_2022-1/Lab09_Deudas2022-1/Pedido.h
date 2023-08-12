/* 
 * Proyecto:    Lab09_Deudas2022-1
 * Archivo:     Pedido.h
 * Autor:       CosmoDev
 *
 * Creado el 21 de junio de 2023, 11:23 PM
 */

#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido {
private:
    int codigo;
    int cantidad; 
    int dni;
    int fecha;
    double total;
public:
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};

void operator >>(ifstream &, class Pedido &);

#endif /* PEDIDO_H */

