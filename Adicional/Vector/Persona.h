/* 
 * Proyecto:    Vector
 * Archivo:     Persona.h
 * Autor:       CosmoDev
 *
 * Creado el 10 de julio de 2023, 04:28 PM
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

ifstream & operator >>(ifstream &, class Persona &);
ofstream & operator <<(ofstream &, const class Persona &);

#endif /* PERSONA_H */

