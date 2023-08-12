/* 
 * File:   StructFalta.h
 * Author: alulab14
 *
 * Created on 25 de abril de 2023, 05:04 PM
 */

#ifndef STRUCTFALTA_H
#define STRUCTFALTA_H

struct FaltaSt {
    char placa[8];
    int fecha;    
    int codInf;
    double multa;
    char gravedad[20];
};

#endif /* STRUCTFALTA_H */

