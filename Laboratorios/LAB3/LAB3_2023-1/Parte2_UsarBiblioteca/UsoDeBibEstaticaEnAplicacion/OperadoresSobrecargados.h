/* 
 * File:   OperadoresSobrecargados.h
 * Author: alulab14
 *
 * Created on 28 de abril de 2023, 08:03 AM
 */

#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H

bool operator >>(ifstream &, struct StCurso &);
bool operator >>(ifstream &, struct StAlumno &);
void leerModalidad(ifstream &, char [], int &);
bool operator >>(ifstream &, struct StRegistroDeMatricula &);
void operator +=(struct StCurso [], struct StCurso);
void operator +=(struct StAlumno [], struct StAlumno);
void operator *=(struct StCurso [], struct StRegistroDeMatricula);
void operator *=(struct StAlumno [], struct StRegistroDeMatricula);
void operator <<(ofstream &, struct StCurso);
void separarCodigoYSemestre(int &, int &, int);
void operator <<(ofstream &, struct StAlumno);

#endif /* OPERADORESSOBRECARGADOS_H */

