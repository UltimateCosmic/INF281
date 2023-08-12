/* 
 * File:   main.cpp
 * Author: aml
 *
 * Created on 26 de junio de 2023, 09:30 AM
 */

#include <iostream>
using namespace std;

#include "Promociones.h"

int main(int argc, char** argv) {
    Promociones pro;
    
    pro.leepedidos();
    //pro.actualizapedidos();
    pro.imprimepedidos();
    return 0;
}

