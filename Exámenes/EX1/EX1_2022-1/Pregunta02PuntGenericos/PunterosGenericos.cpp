#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "PunterosGenericos.h"
#include "MuestraPunteros.h"
#include "AperturaDeArchivos.h"
#define MAX 100
#define MAX_LINEA 100

enum EProducto {COD, DES, PRE, CAN};
enum EPedido {P_COD, P_DES, P_CAN, P_DNI, P_FEC, P_EST};

void cargaproductos(void *&productos) {
    ifstream archProductos;
    abrirArchivoLectura(archProductos, "productos2.csv");
    leerProductos(archProductos, productos);
}

void leerProductos(ifstream &arch, void *&prod) {
    void **productos;
    int buffCod[MAX], buffCant[MAX], numDat=0;
    char *buffDesc[MAX];
    double buffPrecio[MAX];
    while (true) {
        arch>>buffCod[numDat];
        if (arch.eof()) break;
        arch.get();
        buffDesc[numDat] = leerCadena(arch, ',');
        arch>>buffPrecio[numDat];
        arch.get();
        arch>>buffCant[numDat];
        numDat++;
    }
    productos = new void*[numDat+1];
    for (int i=0; i<numDat; i++)
        productos[i] = cargarProducto(buffCod[i], buffDesc[i], buffPrecio[i], 
                buffCant[i]);   
    productos[numDat] = nullptr;
    prod = productos;    
}

char *leerCadena(ifstream &arch, char delim='\n') {
    char buff[60], *cad;
    arch.getline(buff, 60, delim);
    cad = new char[strlen(buff)+1];
    strcpy(cad, buff);
    return cad;
}

void *cargarProducto(int codigo, char *descripcion, double precio, int cantidad) {
    void **registro = new void*[4];
    int *cod = new int, *can = new int;
    char *des = descripcion;
    double *pre = new double;
    *cod = codigo;
    *can = cantidad;
    *pre = precio;
    registro[COD] = cod;
    registro[DES] = des;
    registro[PRE] = pre;
    registro[CAN] = can;
    return registro;
}

void cargapedidos(void *&pedidos) {
    ifstream archPedidos;
    abrirArchivoLectura(archPedidos, "pedidos2.csv");
    leerPedidos(archPedidos, pedidos);    
}

void leerPedidos(ifstream &arch, void *&ped) {
    void **pedidos;
    int buffCod[200], buffCant[200], buffDni[200], buffFecha[200], numDat=0, 
            dd, mm, aaaa;
    char *buffDesc[200], buffEstado[200], c;
    while (true) {
        arch>>buffCod[numDat];               
        if (arch.eof()) break;
        arch.get();
        buffDesc[numDat] = leerCadena(arch, ',');
        arch>>buffCant[numDat];
        arch.get();
        arch>>buffDni[numDat];
        arch.get();
        arch>>dd>>c>>mm>>c>>aaaa;
        buffFecha[numDat] = juntarFecha(dd, mm, aaaa);
        buffEstado[numDat] = 'N';
        numDat++;
    }    
    pedidos = new void*[numDat+1];
    for (int i=0; i<numDat; i++)       
        pedidos[i] = cargarPedido(buffCod[i], buffDesc[i], buffCant[i], 
                buffDni[i], buffFecha[i], buffEstado[i]);   
    pedidos[numDat] = nullptr;
    ped = pedidos;
}

int juntarFecha(int dd, int mm, int aaaa) {
    return aaaa*10000 + mm*100 + dd;    
}

void *cargarPedido(int codigo, char *descripcion, int cantidad, int dni, 
        int fecha, char estado) {
    void **reg = new void*[6];
    int *cod = new int, *cant = new int, *dnip = new int, *fechap = new int;
    char *est = new char, *desc = descripcion;
    *cod = codigo;
    *cant = cantidad;
    *dnip = dni;
    *fechap = fecha;
    *est = estado;
    reg[P_COD] = cod;
    reg[P_CAN] = cant;
    reg[P_DNI] = dnip;
    reg[P_FEC] = fechap;
    reg[P_EST] = est;
    reg[P_DES] = desc;
    return reg;
}

void procesaclientes(void *productos, void *pedidos, void *&clientes) {
    atenderPedidos(productos, pedidos);
    colocarDatosClientes(clientes, pedidos);
}

void atenderPedidos(void *prod, void *ped) {    
    void **pedidos=(void **)ped;
    for (int i=0; pedidos[i]; i++)
        procesarPedido(pedidos[i], prod);
}

void procesarPedido(void *ped, void *prod) {
    void **pedidos = (void **)ped, **productos = (void **)prod;
    int *codigo = (int *)pedidos[P_COD], *cantidad = (int *)pedidos[P_CAN], pos;
    char *estado = (char *)pedidos[P_EST];
    pos = buscarPosProducto(*codigo, prod);
    if (pos==-1) return;
    int *stock = retornarStock(productos[pos]);
    if (*stock-*cantidad>=0) {
        *stock -= *cantidad;
        *estado = 'A';
    }
}

int buscarPosProducto(int codigo, void *prod) {
    void **producto = (void **)prod;
    for (int i=0; producto[i]; i++)
        if (codigo==retornarCodigo(producto[i]))
            return i;
    return -1;
}

int retornarCodigo(void *prod) {
    void **producto = (void **)prod;
    int *codigo = (int *)producto[COD];
    return *codigo;
}

int *retornarStock(void *prod) {
    void **productos = (void **)prod;
    return (int *)productos[CAN];
}

void colocarDatosClientes(void *&clientes, void *pedidos) {
    ifstream archClientes;
    abrirArchivoLectura(archClientes, "clientes2.csv");
    leerClientes(archClientes, clientes, pedidos);
}

void leerClientes(ifstream &arch, void *&cli, void *pedidos) {
    void **clientes = (void **)cli;
    int numDat=0;
    void *buffCli[100], **auxCli;
    while (true) {
        buffCli[numDat] = leerRegCli(arch, pedidos);
        if (buffCli[numDat]==nullptr) break;
        numDat++;
    }
    auxCli = new void*[numDat+1]{};
    for (int i=0; i<numDat+1; i++)
        auxCli[i]=buffCli[i];
    clientes = auxCli;
    imprimerepfinal(clientes);
}

void *leerRegCli(ifstream &arch, void *ped) {
    int codigo, *cod;
    char *nombre;
    arch>>codigo;
    if (arch.eof()) return nullptr;
    cod = new int;
    *cod = codigo;
    arch.get();
    nombre = leerCadena(arch);    
    void **reg = new void*[3];
    reg[0] = cod;
    reg[1] = nombre;
    reg[2] = agregarPedidos(codigo, ped);
    return reg;
}

void *agregarPedidos(int dni, void *ped) {
    int numPed=0;
    void **pedido = (void **)ped, *buffPed[200]{}, **auxPed;
    for (int i=0; pedido[i]; i++)
        if (dni==retornarDni(pedido[i])) {
            buffPed[numPed] = agregarPedido(pedido[i]);
            numPed++;
        }
    auxPed = new void*[numPed+1];
    for (int i=0; i<numPed; i++)
        auxPed[i] = buffPed[i];
    auxPed[numPed]=nullptr;
    return auxPed;
}

int retornarDni(void *ped) {
    void **pedido = (void **)ped;
    return *((int *)pedido[P_DNI]);
}

void *agregarPedido(void *ped) {
    void **pedido = (void **)ped, **reg = new void*[4];
    reg[0] = (int *)pedido[P_FEC];
    reg[1] = (int *)pedido[P_COD];
    reg[2] = (char *)pedido[P_DES];
    reg[3] = (int *)pedido[P_CAN];
    return reg;
}

void imprimereporte(void *cli){
    ofstream reporte("ReporteDePedidos.txt", ios::out);
    if(not reporte.is_open()){
        cout<<"Error: No se pudo abrir el archivo ReporteDePedidos.txt"<<endl;
        exit(1);
    }
    void **clientes=(void **)cli;
    imprimirLinea(reporte, '=', MAX_LINEA);
    reporte<<"PEDIDOS ATENDIDOS POR CLIENTE:"<<endl;
    for(int i=0; clientes[i]; i++)
        imprimirCliente(reporte, clientes[i]);
}

void imprimirLinea(ofstream &reporte, char car, int n) {
    for(int i=0; i<n; i++) reporte<<car;
    reporte<<endl;
}

void imprimirCliente(ofstream &reporte, void *cli) {
    void **cliente=(void **)cli;
    int *dni=(int *)cliente[0];
    char *nombre=(char *)cliente[1];
    imprimirLinea(reporte, '=', MAX_LINEA);
    reporte<<left<<setw(20)<<"DNI"<<"Nombre"<<endl;
    reporte<<setw(20)<<*dni<<setw(60)<<nombre<<endl;
    imprimirLinea(reporte, '-', MAX_LINEA);
    reporte<<"Pedidos atendidos:"<<endl;
    imprimirLinea(reporte, '-', MAX_LINEA);
    reporte<<setw(14)<<"Fecha"<<setw(8)<<"Codigo"<<setw(60)
            <<"Descripcion del Producto"<<"Cantidad"<<endl;
    imprimirLinea(reporte, '-', MAX_LINEA);
    imprimirPedidos(reporte, cliente[2]);
}

void imprimirPedidos(ofstream &reporte, void *ped) {
    void **pedidos=(void **)ped;
    for(int i=0; pedidos[i]; i++)
        imprimirPedido(reporte, pedidos[i]);
}

void imprimirPedido(ofstream &reporte, void *ped) {
    void **pedido=(void **)ped;
    int *fecha=(int *)pedido[0];
    int *codProducto=(int *)pedido[1];
    char *nomProducto=(char *)pedido[2];
    int *cantidad=(int *)pedido[3];
    int dd, mm, aa;
    dd=*fecha%100;
    mm=(*fecha/100)%100;
    aa=*fecha/10000;
    reporte<<right<<setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)
            <<aa<<setfill(' ')<<setw(10)<<*codProducto<<"  "<<left<<setw(60)
            <<nomProducto<<right<<setw(4)<<*cantidad<<endl;
}

