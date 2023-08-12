/* 
 * Proyecto:    Lista
 * Archivo:     Persona.h
 * Autor:       CosmoDev
 *
 * Creado el 10 de julio de 2023, 08:33 PM
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <fstream>
using namespace std;

class Persona {
private:
    int dni;
    char *nombre;
    double sueldo;
public:
    Persona();
    Persona(const Persona& orig);
    virtual ~Persona();
    void SetSueldo(double sueldo);
    double GetSueldo() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *nombre) const;
    void SetDni(int dni);
    int GetDni() const;
    void operator =(const class Persona &per);
    bool operator >(const class Persona &per);
    bool operator <(const class Persona &per);
};

ifstream & operator >>(ifstream &arch, class Persona &persona);
ofstream & operator <<(ofstream &arch, const class Persona &persona);

#endif /* PERSONA_H */

