/* 
 * Proyecto:    Vector
 * Archivo:     Persona.cpp
 * Autor:       CosmoDev
 *
 * Creado el 10 de julio de 2023, 04:28 PM
 */

#include <iomanip>
#include <fstream>
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
    if (nombre!=nullptr) delete nombre;
}

void Persona::SetSueldo(double sueldo) {
    this->sueldo = sueldo;
}

double Persona::GetSueldo() const {
    return sueldo;
}

void Persona::SetNombre(const char* nombre) {
    if (this->nombre!=nullptr) delete this->nombre;
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
    char nomb[100];
    dni = per.dni;
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

ifstream & operator >>(ifstream &arch, class Persona &per) {
    int dni;
    char nombre[100];
    double sueldo;
    arch>>dni;
    if (arch.eof()) return arch;
    arch.get();
    arch.getline(nombre, 100, ',');
    arch>>sueldo;
    per.SetDni(dni);
    per.SetNombre(nombre);
    per.SetSueldo(sueldo);   
    return arch;
}

ofstream & operator <<(ofstream &out, const class Persona &per) {
    char nombre[100];
    per.GetNombre(nombre);    
    out<<left<<setw(10)<<per.GetDni()<<setw(40)<<nombre<<right<<setw(10)
            <<per.GetSueldo()<<endl;
    return out;
}