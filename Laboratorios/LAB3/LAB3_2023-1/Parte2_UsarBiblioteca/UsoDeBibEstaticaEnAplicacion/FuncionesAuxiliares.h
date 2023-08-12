/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: alulab14
 *
 * Created on 28 de abril de 2023, 09:29 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerCursos(struct StCurso [], const char *);
void leerAlumnos(struct StAlumno [], const char *);
void leerMatricula(struct StCurso [], struct StAlumno [], const char *);
void calcularTotales(struct StAlumno [], struct StCurso [], const char *);
void leerEscalas(ifstream &arch, double escalas[])

#endif /* FUNCIONESAUXILIARES_H */

