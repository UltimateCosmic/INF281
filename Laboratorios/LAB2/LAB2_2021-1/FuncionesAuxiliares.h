/* 
 * Proyecto:    LAB2_2021-1
 * Archivo:     FuncionesAuxiliares.h
 * Autor:       CosmoDev
 *
 * Creado el 17 de abril de 2023, 09:09 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void crearPrimerosBinarios(const char *, const char *, const char *);
void leerConductores(ifstream &, ofstream &, ofstream &);
void omitirInfracciones(ifstream &, ofstream &, ofstream &, int);
int juntarFecha(int, int, int);
void elegirGravedad(char *, char);
void escribirConductores(ofstream &, char *, int, int, char *, int, double);
bool verificarFinInfracciones(ifstream &);
void escribirInfracciones(ofstream &, int, double);
void crearReporteDeVerificacion(const char *, const char *, const char *);
void imprimirReporteDeVerificacion(ofstream &, ifstream &, ifstream &);
void imprimirConductores(ofstream &, ifstream &);
void leerArchivoConductores(ifstream &, int &, char *, int &, int &, int &, 
        double &, double &, double &, double &) ;
void imprimirFaltas(ofstream &, ifstream &);
void leerArchivoFaltas(ifstream &, char *, int &, int &, char *, int &, double &);
void imprimirFecha(ofstream &, int);
void separarFecha(int, int &, int &, int &);
void crearArchInfracciones(const char *, const char *);
void leerInfracciones(ifstream &, ofstream &);
void escribirDetallesDeInfracciones(ofstream &, int, char *, char *, double);
void crearReporteDeInfracciones(const char *, const char *);
void imprimirReporteDeInfracciones(ofstream &, ifstream &);
void leerDetallesDeInfracciones(ifstream &, int &, char *, char *, double &);
void completarBinarios(const char *, const char *, const char *);
void llenarMultaFaltas(fstream &, ifstream &);
double buscarMulta(int, ifstream &);
void modificarArchConductores(fstream &, fstream &);
void buscarFaltas(int, int &, int &, int &, double &, double &, double &, 
        fstream &);

#endif /* FUNCIONESAUXILIARES_H */

