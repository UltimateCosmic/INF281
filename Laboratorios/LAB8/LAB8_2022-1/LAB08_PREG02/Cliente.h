/* 
 * Proyecto:    LAB08_PREG01
 * Archivo:     Cliente.h
 * Autor:       CosmoDev
 *
 * Creado el 16 de junio de 2023, 02:32 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente {
private:
    int dni;
    char categoria;
    char *nombre;
public:
    Cliente();
    virtual ~Cliente();
    void SetNombre(const char*);
    void GetNombre(char *) const;
    void SetCategoria(char);
    char GetCategoria() const;
    void SetDni(int);
    int GetDni() const;
};

#endif /* CLIENTE_H */

