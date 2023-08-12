/* 
 * Proyecto:    Lista
 * Archivo:     Persona.cpp
 * Autor:       CosmoDev
 *
 * Creado el 10 de julio de 2023, 08:33 PM
 */

#include <iomanip>
#include <cstring>
using namespace std;

#include "Persona.h"

Persona::Persona() {
    nombre = nullptr;
}

Persona::Persona(const Persona& orig) {
    nombre = nullptr;
    *this = orig;
}

Persona::~Persona() {
}

void Persona::SetSueldo(double sueldo) {
    this->sueldo = sueldo;
}

double Persona::GetSueldo() const {
    return sueldo;
}

void Persona::SetNombre(const char* nombre) {
    if (this->nombre) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Persona::GetNombre(char *nombre) const {
    if (this->nombre==nullptr) nombre[0]=0;
    else strcpy(nombre, this->nombre);
}

void Persona::SetDni(int dni) {
    this->dni = dni;
}

int Persona::GetDni() const {
    return dni;
}

void Persona::operator =(const class Persona &per) {
    dni = per.dni;
    char nomb[60];
    per.GetNombre(nomb);
    SetNombre(nomb);
    sueldo = per.sueldo;
}

bool Persona::operator >(const class Persona &per) {
    return strcmp(nombre, per.nombre)>0;
}

bool Persona::operator <(const class Persona &per) {
    return strcmp(nombre, per.nombre)<0;
}

ifstream & operator >>(ifstream &arch, class Persona &persona) {
    int dni;
    char nombre[100];
    double sueldo;
    arch>>dni;
    if (arch.eof()) return arch;
    arch.get();
    arch.getline(nombre, 100, ',');
    arch>>sueldo;
    persona.SetDni(dni);
    persona.SetNombre(nombre);
    persona.SetSueldo(sueldo);
    return arch;
}

ofstream & operator <<(ofstream &arch, const class Persona &persona) {
    char nombre[100];
    arch.precision(2);
    arch<<fixed;
    persona.GetNombre(nombre);
    arch<<left<<setw(10)<<persona.GetDni()<<setw(40)<<nombre<<right<<setw(10)
            <<persona.GetSueldo()<<endl;
    return arch;
}

