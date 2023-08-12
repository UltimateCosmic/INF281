/* 
 * Proyecto:    Lista
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 10 de julio de 2023, 05:00 PM
 */

#include <iostream>
#include <iomanip>
#include <list>
#include <iterator>
#include <fstream>
using namespace std;

#include "Persona.h"

int main(int argc, char** argv) {

    list<double>lDbl {123.456,73.87, 9.736, 103.64};
    list<double>lDbl2 {1.1,2.2,3.3,4.4};

    /*cout.precision(2);
    cout<<fixed;

    for(double x: lDbl)
        cout<<setw(8)<<x;
    cout<<endl;*/
    
    /*for(double x: lDbl2)
        cout<<setw(8)<<x;
    cout<<endl;*/
    
    /*for (list<double>::iterator it=lDbl.begin(); it!=lDbl.end(); it++)
        cout<<setw(8)<<*it;
    cout<<endl;*/
    
    /*list<double>::iterator it=lDbl.end();
    it--;    
    while(true){
        cout<<setw(8)<<*it;
        if(it==lDbl.begin())break;
        it--;
    }
    cout<<endl;**/
    
    /*double primero, ultimo;
        
    lDbl.push_back(111.11);     // Inserta al final
    lDbl.push_front(7777.77);   // Inserta al inicio
    for(list<double>::iterator it=lDbl.begin(); it!=lDbl.end(); it++)
        cout<<setw(8)<<*it;
    cout<<endl;*/

    /*primero = lDbl.front();
    ultimo = lDbl.back();
    cout<<setw(8)<<primero<<setw(8)<<ultimo<<endl;*/
    
    /* lDbl.merge(lDbl2);      // Pasa todo lDbl2 al inicio de lDbl    
    lDbl.sort();
    
    for (double x: lDbl)
        cout<<setw(8)<<x;
    cout<<endl;*/
    
    ifstream arch("personalLL.csv", ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo personalLL.csv"<<endl;
        exit(1);
    }
    ofstream archRep("Reporte.txt", ios::out);
    if (not archRep.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    
    list<class Persona>lPer;
    class Persona per;
    while (true) {
        arch>>per;
        if (arch.eof()) break;
        lPer.push_back(per);
    }
    lPer.sort();
    for (Persona i: lPer)
        archRep<<i;
    
    return 0;
}

