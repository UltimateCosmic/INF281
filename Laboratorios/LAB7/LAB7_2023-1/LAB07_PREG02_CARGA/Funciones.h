/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.h
 * Author: alulab14
 *
 * Created on 9 de junio de 2023, 09:22 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void cargaralumnos(class alumno *);
void cargarnotas(class alumnonota *);
void actualizarnotas(class alumno *, class alumnonota *);
int buscarPos(int, class alumno *);
int calcularCantVeces(char *, class alumno);
void imprimealumnos(class alumno *);

#endif /* FUNCIONES_H */

