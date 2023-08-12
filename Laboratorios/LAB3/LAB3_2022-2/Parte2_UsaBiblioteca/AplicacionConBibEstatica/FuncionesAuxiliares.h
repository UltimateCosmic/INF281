/* 
 * Proyecto:    AplicacionConBibEstatica
 * Archivo:     FuncionesAuxiliares.h
 * Autor:       CosmoDev
 *
 * Creado el 28 de abril de 2023, 12:30 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerMedicos(struct StMedico [], int &, const char *);
void leerPacientes(struct StPaciente [], int &, const char *);
void leerCitas(struct StMedico [], int, struct StPaciente [], int, const char *);
void completarInformacion(struct StCita &, struct StMedico [], int);
void agregarCita(int, struct StCita, struct StPaciente [], int);
void emitirReporte(struct StPaciente [], int, const char *);
void imprimirCabeceraPrincipal(ofstream &);
void imprimirLinea(ofstream &, char, int);

#endif /* FUNCIONESAUXILIARES_H */

