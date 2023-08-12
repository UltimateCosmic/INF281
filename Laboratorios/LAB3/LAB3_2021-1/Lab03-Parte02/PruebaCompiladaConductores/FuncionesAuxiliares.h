/* 
 * Proyecto:    PruebaCompiladaConductores
 * Archivo:     FuncionesAuxiliares.h
 * Autor:       CosmoDev
 *
 * Creado el 27 de abril de 2023, 09:35 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerConductores(const char *, struct ConductorSt [], int &);
void leerFaltas(const char *, struct ConductorSt [], int);
void asignarFalta(struct InfraccionSt, struct ConductorSt [], int);
void completarMulta(const char *, struct ConductorSt [], int);
void asignarMulta(struct InfraccionEstabSt, struct ConductorSt [], int);
void calculaMonto(struct ConductorSt [], int);
void emitirReporte(const char *, struct ConductorSt [], int);
void aplicarAmnistia(struct ConductorSt [], int);
int juntarFecha(int, int, int);

#endif /* FUNCIONESAUXILIARES_H */

