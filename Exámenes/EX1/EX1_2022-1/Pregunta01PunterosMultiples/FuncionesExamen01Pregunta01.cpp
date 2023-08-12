#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "FuncionesExamen01Pregunta01.h"
#include "FuncionesDeArchivo.h"
#define MAX 200
#define CAD 60
#define INCREMENTO 5

void CargarProductosPedidos(int **&pro_Informacion, char **&pro_Descripcion, 
        int **&ped_Todo, const char *nombArch) {
    ifstream archPedidos;
    abrirArchivoLectura(archPedidos, nombArch);
    leerProductosPedidos(archPedidos, pro_Informacion, pro_Descripcion, ped_Todo);
}

void leerProductosPedidos(ifstream &arch, int **&pro_Informacion, 
        char **&pro_Descripcion, int **&ped_Todo) {  
    int *buffInfo[MAX], *buffTodo[MAX], codigo, pos, numProd=0, numPed=0;
    char *buffDesc[MAX];
    while (true) {  
        arch>>codigo;
        if (arch.eof()) break;
        pos = buscarPosProd(codigo, buffInfo, numProd);
        leerProductos(arch, codigo, buffInfo[pos], buffDesc[pos], 
                    buffTodo[numPed], pos, numProd);              
        if (pos==numProd) numProd++;
        numPed++;
    }
    cargarProductosExactos(pro_Informacion, pro_Descripcion, ped_Todo, 
            buffInfo, buffDesc, buffTodo, numProd, numPed);
}      

int buscarPosProd(int codigo, int **buffInfo, int numDat) {
    for (int i=0; i<numDat; i++) 
        if (codigo==retornarCod(buffInfo[i])) return i;
    return numDat;
}

int retornarCod(int *buffInfo) {
    return buffInfo[0];
}

void leerProductos(ifstream &arch, int codigo, int *&buffInfo, char *&buffDesc, 
        int *&buffTodo, int pos, int numProd) {    
    int dd, mm, aaaa;
    char c;
    double descuento, cantidad, precio, stock;    
    arch.get();
    if (pos==numProd) 
        buffDesc = leerCadena(arch, ',');
    else
        leerCadena(arch, ',');   
    buffTodo = new int[4];
    arch>>descuento;
    if (arch.get()!='%') {
        cantidad = descuento;
        descuento = 0;
    } else {
        arch.get();
        arch>>cantidad;
    }   
    arch.get();
    arch>>precio;    
    arch.get();
    arch>>stock;    
    arch.get();
    arch>>buffTodo[0];
    arch.get();
    arch>>dd>>c>>mm>>c>>aaaa;    
    if (pos==numProd) {
        buffInfo = new int[4];        
        buffInfo[0] = codigo;
        buffInfo[1] = descuento*100;
        buffInfo[2] = precio*100;
        buffInfo[3] = stock*100;
    }
    buffTodo[1] = juntarFecha(dd, mm, aaaa);
    buffTodo[2] = cantidad*100;    
    buffTodo[3] = codigo;    
}

char *leerCadena(ifstream &arch, char delim='\n') {
    char buff[CAD], *cad;
    arch.getline(buff, CAD, delim);
    cad = new char[strlen(buff)+1];
    strcpy(cad, buff);
    return cad;
}

int juntarFecha(int dd, int mm, int aaaa) {
    return aaaa*10000 +  mm*100 + dd;    
}

void cargarProductosExactos(int **&pro_Informacion, char **&pro_Descripcion, 
        int **&ped_Todo, int **buffInfo, char **buffDesc, int **buffTodo, 
        int numProd, int numPed) {
    pro_Informacion = new int*[numProd+1];
    pro_Descripcion = new char*[numProd+1];
    ped_Todo = new int*[numPed+1];
    for (int i=0; i<numProd; i++) {
        pro_Informacion[i] = buffInfo[i];
        pro_Descripcion[i] = buffDesc[i];
    }
    pro_Informacion[numProd]=nullptr;
    pro_Descripcion[numProd]=nullptr;
    for (int i=0; i<numPed; i++)
        ped_Todo[i] = buffTodo[i];
    ped_Todo[numPed]=nullptr;
}

void PruebaProductosPedidos(int **pro_Informacion, char **pro_Descripcion, 
        int **ped_Todo, const char *nombArch) {
    ofstream archReporte;
    abrirArchivoEscritura(archReporte, nombArch);
    imprimirProductosPedidos(archReporte, pro_Informacion, pro_Descripcion, ped_Todo);
}

void imprimirProductosPedidos(ofstream &arch, int **pro_Informacion, 
        char **pro_Descripcion, int **ped_Todo) {
    for (int i=0; pro_Informacion[i]; i++)
        imprimirProducto(arch, pro_Informacion[i], pro_Descripcion[i]);
    arch<<endl;
    for (int i=0; ped_Todo[i]; i++)
        imprimirPedido(arch, ped_Todo[i]);
}

void imprimirProducto(ofstream &arch, int *informacion, char *descripcion) {
    arch<<left<<setw(10)<<informacion[0]<<setw(50)<<descripcion<<setw(6)
            <<informacion[1]<<setw(6)<<informacion[2]<<informacion[3]<<endl;    
}

void imprimirPedido(ofstream &arch, int *pedido) {
    arch<<left<<setw(12)<<pedido[0]<<setw(12)<<pedido[1]<<setw(12)
            <<pedido[2]<<pedido[3]<<endl;    
}

void ordenarPedidos(int **&ped_Todo) {
    int numDat=0;
    while (ped_Todo[numDat]) numDat++;   
    quickSortPedidos(ped_Todo, 0, numDat-1);
}

void quickSortPedidos(int **&ped_Todo, int izq, int der) {
    if (izq>=der) return;
    int med = (izq+der)/2, limite=izq;
    cambiar(ped_Todo[izq], ped_Todo[med]);
    for (int i=izq+1; i<=der; i++)
        if (enDesordenFecha(ped_Todo[i], ped_Todo[izq]))
            cambiar(ped_Todo[++limite], ped_Todo[i]);
    cambiar(ped_Todo[izq], ped_Todo[limite]);
    quickSortPedidos(ped_Todo, izq, limite-1);
    quickSortPedidos(ped_Todo, limite+1, der);
}

void cambiar(int *&pedIzq, int *&pedMed) {
    int *aux = pedIzq;
    pedIzq = pedMed;
    pedMed = aux;    
}

bool enDesordenFecha(int *&pedA, int *&pedB) {
    if (pedA[1]<pedB[1])
        return true;
    else if (pedA[1]==pedB[1] && pedA[0]<pedB[0])
        return true;
    return false;
}

void asignarPedidos(int ***&cli_DniTelPed, int **pro_Informacion, int **ped_Todo) {
    int cap=0, numDat=0, pos, capP[100]{}, ndP[100]{}, posB;
    cli_DniTelPed = nullptr;
    for (int i=0; ped_Todo[i]; i++) {                
        pos = buscarPosDNI(ped_Todo[i], cli_DniTelPed);
        if (pos==-1) {  // No es repetido
            if (cap==numDat)
                agregarEspacios(cli_DniTelPed, cap, numDat);    
            cli_DniTelPed[numDat-1] = new int*[3];            
            cli_DniTelPed[numDat-1][0] = new int;
            cli_DniTelPed[numDat-1][0][0] = ped_Todo[i][0];            
            cli_DniTelPed[numDat-1][1] = new int;
            cli_DniTelPed[numDat-1][1][0] = buscarTelefono(ped_Todo[i][0], pro_Informacion);
            pos = numDat-1;            
            numDat++;
        }
        posB = buscarPosProd(pro_Informacion, ped_Todo[i][3]);
        if (pro_Informacion[posB][3]<ped_Todo[i][2]) {
            if (capP[pos]<=ndP[pos])
                agregarEspacios(cli_DniTelPed[pos][2], capP[pos], ndP[pos]);           
            cli_DniTelPed[pos][2][ndP[pos]-1] = ped_Todo[i][1];
            cli_DniTelPed[pos][2][ndP[pos]] = ped_Todo[i][2];
            cli_DniTelPed[pos][2][ndP[pos]+1] = ped_Todo[i][3];
            if (posB!=-1) {
                pro_Informacion[posB][3] -= cli_DniTelPed[pos][2][ndP[pos]];
                if (pro_Informacion[posB][3]<0)
                    pro_Informacion[posB][3]=0;
            }
            ndP[pos]+=3;        
        }
    }
}

int buscarPosDNI(int *ped_Todo, int ***cli_DniTelPed) {
    if (cli_DniTelPed==nullptr) return -1;
    int dni = ped_Todo[0], i;
    for (i=0; cli_DniTelPed[i]; i++)
        if (dni==retornarDNI(cli_DniTelPed[i]))        
            return i;
    return -1;
}

int retornarDNI(int **cli_DniTelPed) {
    return cli_DniTelPed[0][0];
}

void agregarEspacios(int ***&cli_DniTelPed, int &cap, int &nd) {
    int ***auxC;
    cap += INCREMENTO;
    if (cli_DniTelPed==nullptr) {
        cli_DniTelPed = new int**[cap]{};
        nd=1;
    } else {
        auxC = new int**[cap]{};
        for (int i=0; i<nd; i++)
            auxC[i] = cli_DniTelPed[i];
        delete cli_DniTelPed;
        cli_DniTelPed = auxC;
    }    
}

int buscarTelefono(int dni, int **pro_Informacion) {
    for (int i=0; pro_Informacion[i]; i++)
        if (dni==retornarDNI(pro_Informacion[i]))
            return retornarTelefono(pro_Informacion[i]);
}

int retornarDNI(int *pro_Informacion) {
    return pro_Informacion[0];
}

int retornarTelefono(int *pro_Informacion) {
    return pro_Informacion[1];
}

void agregarEspacios(int *&cli_DniTelPed, int &cap, int &nd) {    
    int *auxC;
    cap += INCREMENTO;
    if (cli_DniTelPed==nullptr) {
        cli_DniTelPed = new int[cap]{};
        nd=1;
    } else {
        auxC = new int[cap]{};
        for (int i=0; i<nd; i++)
            auxC[i] = cli_DniTelPed[i];
        delete cli_DniTelPed;
        cli_DniTelPed = auxC;
    }
}

int buscarPosProd(int **pro_Informacion, int codigo) {
    for (int i=0; pro_Informacion[i]; i++)
        if (codigo==pro_Informacion[i][0]) return i;
    return -1;
}

