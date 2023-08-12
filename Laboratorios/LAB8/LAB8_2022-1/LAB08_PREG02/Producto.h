/* 
 * Proyecto:    LAB08_PREG01
 * Archivo:     Producto.h
 * Autor:       CosmoDev
 *
 * Creado el 16 de junio de 2023, 02:39 AM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
private:
    int codprod;
    char *nombre;
    double precio;
    int stock;
public:
    Producto();
    virtual ~Producto();
    void SetStock(int);
    int GetStock() const;
    void SetPrecio(double);
    double GetPrecio() const;
    void SetNombre(const char *);
    void GetNombre(char *) const;
    void SetCodprod(int);
    int GetCodprod() const;
};

#endif /* PRODUCTO_H */

