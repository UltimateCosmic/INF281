/* 
 * Proyecto:    Vector
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 10 de julio de 2023, 02:16 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

#include "Persona.h"

int main(int argc, char** argv) {

    //vector<int>vInt {23, 56, 12, 83, 102, 66};
    //vector<int>vInt (10);
    //vector<int>vInt (10, 33);
    /*vector<int>vInt;
        
    int dato1, dato2;
    vInt.push_back(99);     // Inserta elementos en el vector     
    vInt.push_back(33);     
    vInt.push_back(22);     
    vInt.push_back(77);     
    vInt.push_back(11);     
    vInt.push_back(10);     
    vInt.push_back(15);     
    vInt.push_back(21);     
    vInt.push_back(59);
    vInt.shrink_to_fit();   // Borra el espacio no utilizado
    
    //vInt.pop_back();        // Borra el último elemento
    /*dato1 = vInt.front();   // Retorna el primer elemento (no borra)
    dato2 = vInt.back();    // Retorna el último elemento (no borra)
    cout<<dato1<<setw(5)<<dato2<<endl;*/
    
    /*for (int i=0; i<vInt.size(); i++)
        cout<<setw(5)<<vInt[i];
    cout<<endl;*/
    
    /*for (int i: vInt)   // for i in vInt
        cout<<setw(5)<<i;
    cout<<endl;*/
    
    // Manejo de iteradores (usa punteros)    
    /*for(vector<int>::iterator it=vInt.begin(); it!=vInt.end(); it++)
        cout<<setw(5)<<*it;
    cout<<endl;
    
    vector<int>::iterator it=vInt.begin();
    vector<int>::iterator it2=vInt.begin();
    it+=3;      // Lo ubicamos en el elemento con i=3 (77)
    it2+=6;     // Lo ubicamos en el elemento con i=6 (15)
    cout<<*it<<endl<<*it2<<endl;
    vInt.erase(it);     // Borra el elemento y acomoda el vector por si solo
    cout<<*it<<endl<<*it2<<endl;
    
    it+=3;
    cout<<setw(5)<<*it<<endl;
    vInt.insert(it,101);*/        // Inserta el elemento 101 en la posicion it
        
    /*vector<int>::iterator it2=vInt.begin();
    vector<int>::iterator it=vInt.begin();
    it2+=6;
    it+=3;
    
    cout<<"Numero de elementos: "<<vInt.size()<<endl;
    cout<<"Capacidad inicial: "<<vInt.capacity()<<endl<<endl;
    
    for (int i: vInt)
        cout<<setw(5)<<i;
    cout<<endl;
    
    //sort(vInt.begin(), vInt.end());     // Se usa la biblioteca algorithm
    vInt.clear();                       // Vacía el vector
    it2--;    
    //vInt.erase(it, it2);
    
    if (vInt.empty()) cout<<"Esta vacia"<<endl;
    else cout<<"Tiene datos"<<endl;
    
    for (int i: vInt)
        cout<<setw(5)<<i;
    cout<<endl;*/
    
    vector<class Persona>vPer;    
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
    class Persona per;
    while (true) {
        arch>>per;
        if (arch.eof()) break;
        vPer.push_back(per);     
    }    
    // Se debe sobrecargar el operador <
    sort(vPer.begin(), vPer.end());
    for (Persona i: vPer)
        archRep<<i;
    
    return 0;
}

