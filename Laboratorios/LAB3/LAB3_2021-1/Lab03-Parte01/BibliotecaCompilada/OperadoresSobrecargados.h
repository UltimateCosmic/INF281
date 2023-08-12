/* 
 * File:   OperadoresSobrecargados.h
 * Author: alulab14
 *
 * Created on 25 de abril de 2023, 05:09 PM
 */

#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H
#include <fstream>

bool operator >>(ifstream &, struct ConductorSt &);
bool operator >>(ifstream &, struct InfraccionSt &);
bool operator >>(ifstream &, struct InfraccionEstabSt &);
void operator +(struct ConductorSt &, struct InfraccionSt);
void operator +(struct ConductorSt &, struct InfraccionEstabSt);
void operator ++(struct ConductorSt &);
void operator *(struct ConductorSt &, int);
void desplazarFaltas(int, struct ConductorSt &);
void intercambiarFalta(struct FaltaSt &, struct FaltaSt &);
void operator <<(ofstream &, struct ConductorSt);
void imprimirConductor(ofstream &, char *, int);
void imprimirInfracciones(ofstream &, struct ConductorSt);
void imprimirCabeceraInfracciones(ofstream &);
void imprimirLinea(ofstream &, char, int);
void imprimirFecha(ofstream &, int);
void separarFecha(int, int &, int &, int &);
void imprimirResumen(ofstream &, struct ConductorSt);

#endif /* OPERADORESSOBRECARGADOS_H */

