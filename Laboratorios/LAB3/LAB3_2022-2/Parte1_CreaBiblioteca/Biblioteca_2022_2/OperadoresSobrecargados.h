/* 
 * Proyecto:    Fuentes_Biblioteca_2022_2
 * Archivo:     OperadoresSobrecargados.h
 * Autor:       CosmoDev
 *
 * Creado el 27 de abril de 2023, 10:56 PM
 */

#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H

bool operator >>(ifstream &, struct StMedico &);
void asignarEspecialidad(struct StMedico &);
bool operator >>(ifstream &, struct StPaciente &);
int operator >>(ifstream &, struct StCita &);
int juntarFecha(int, int, int);
bool operator <=(struct StCita &, struct StMedico []);
int buscarMedico(struct StMedico [], int);
void operator +=(struct StPaciente &, struct StCita);
void operator ++(struct StPaciente &);
void operator <<(ofstream &arch, struct StPaciente);
void imprimirCabeceraPaciente(ofstream &, struct StPaciente);
void imprimirFecha(ofstream &, int);
void separarFecha(int, int &, int &, int &);

#endif /* OPERADORESSOBRECARGADOS_H */

