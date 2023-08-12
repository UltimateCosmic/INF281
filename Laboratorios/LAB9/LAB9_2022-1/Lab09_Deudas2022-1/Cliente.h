/* 
 * Proyecto:    Lab09_Deudas2022-1
 * Archivo:     Cliente.h
 * Autor:       CosmoDev
 *
 * Creado el 21 de junio de 2023, 11:08 PM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente {
private:
    int dni;
    char categoria;
    char* nombre;
    int cantped;
    double totalped;
public:
    Cliente();
    virtual ~Cliente();
    void SetTotalped(double totalped);
    double GetTotalped() const;
    void SetCantped(int cantped);
    int GetCantped() const;
    void SetNombre(const char*);
    void GetNombre(char*) const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
};

#endif /* CLIENTE_H */

