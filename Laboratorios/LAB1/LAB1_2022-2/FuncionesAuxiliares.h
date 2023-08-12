/* 
 * Proyecto:    LAB1_2022-1
 * Archivo:     FuncionesAuxiliares.h
 * Autor:       CosmoDev
 *
 * Creado el 8 de abril de 2023, 06:52 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerEspecialidadesYFecha(char [], char [], int &);
void imprimirCabeceraPrincipal(char [], char [], int, int, int);
void imprimirLinea(char, int);
int juntarFecha(int, int, int);
void imprimirReporteDeEmpresa(char [], char [], int);
bool leerDatosMedico(char [], char []);
bool perteneceEspecialidad(char [], char []);
char convertirMayuscula(char);
void imprimirTablaDeMedico(char [], char [], int &, int &, int &, char [], int);
void imprimirCabeceraSecundaria(char [], char [], char []);
void imprimirPacientes(int &, int &, int &, int);
bool verificarFinPacientes();
void leerMedicamentos(int, int, char [], int &, int &, int, int);
void imprimirPaciente(int, int, char [], int);
void imprimirMedicamento(int, int, char [], int, int, int, int &, int);
void imprimirVencida(int, int, int &);

bool verificarFinMedicamentos();
void saltarHastaSiguienteMedico();
void imprimirResumen(int, int, int, int, int, int, char [], char []);
void imprimirResumenEspecialidad(int, int, int, char [], int);

#endif /* FUNCIONESAUXILIARES_H */

