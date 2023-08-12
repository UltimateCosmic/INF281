/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: alulab14
 *
 * Created on 14 de abril de 2023, 08:03 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void imprimirReporteDeListadoDeClase();
void imprimirCabeceraPrincipal();
void imprimirInformacionCurso(int, char [], char [], char [], int, double, 
        double &);
void imprimirCabeceraCurso(int, char [], char [], char [], int, double);
void imprimirLinea(char, int);
void corregirNombreCurso(char []);
char convertirMayuscula(char);
void corregirNombreUsuario(char []);
char convertirMinuscula(char);
void imprimirAlumnosMatriculados(double, double &);
void imprimirCabeceraAlumnos();
void leerDatosDeModalidad(char &, int &);
void imprimirAlumno(int, int, int, char [], int, char, double, double &, 
        double &, double &, double);
void imprimirCodigoString(int);
double pagoPorEscala(int);
bool verificarFinDeAlumnos();
void imprimirRecaudacionPorModalidad(double, double, double);
void imprimirTotalGeneral(double);

#endif /* FUNCIONESAUXILIARES_H */

