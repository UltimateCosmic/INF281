/* 
 * Proyecto:    LAB2_2022-2
 * Archivo:     FuncionesAuxiliares.h
 * Autor:       CosmoDev
 *
 * Creado el 20 de abril de 2023, 02:14 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void crearBinarios(const char *, const char *);
void separarInformacion(const char *, const char *, const char *, const char *,
        const char *);
void leerMedicos(ifstream &, ofstream &, fstream &, ofstream &, fstream &);
void leerEspecialidad(char *, char *);
void escribirMedicos(ofstream &, char *, char *, char *);
void leerPacientes(ifstream &, fstream &, ofstream &, fstream &);
void escribirPacienes(fstream &, int, char *);
bool pacienteRepetido(int, fstream &);
int calcularTamArch(fstream &);
void leerConsultas(ifstream &, ofstream &, fstream &, int);
int juntarFecha(int, int, int);
void escribirConsultas(ofstream &, int, char *, int, int);
void leerMedicinas(int, ifstream &, ofstream &, fstream &);
void escribirCodigosMedicinas(int, ofstream &);
void escribirMedicamentos(fstream &, int, char *, double);
bool medicamentoRepetido(int, fstream &);
bool finDePacientes(ifstream &);
void imprimirReporteDeVerificacion(const char *, const char *, const char *,
        const char *, const char *);
void imprimirMedicos(ofstream &, ifstream &);
void imprimirEncabezadoMedicos(ofstream &);
void imprimirLinea(ofstream &, char, int);
void imprimirEncabezadoPacientes(ofstream &);
void imprimirPacientes(ofstream &, ifstream &);
void imprimirMedicinas(ofstream &, ifstream &);
void imprimirEncabezadoMedicinas(ofstream &);
void imprimirConsultas(ofstream &, ifstream &);
void imprimirEncabezadoConsultas(ofstream &);
void separarFecha(int &, int &, int &, int);
void imprimirFecha(ofstream &, int, int, int);
void imprimirCodigos(ofstream &, ifstream &, int);
void modificarPacientes(const char *, const char *, const char *);
void modificarGastos(ifstream &, ifstream &, fstream &);
double buscarPrecioMedicina(int, ifstream &);
void modificarRegistro(fstream &, double, int);

#endif /* FUNCIONESAUXILIARES_H */
