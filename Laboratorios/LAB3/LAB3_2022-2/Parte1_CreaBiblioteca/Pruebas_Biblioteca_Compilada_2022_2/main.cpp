/* 
 * Proyecto:    Pruebas_Biblioteca_Compilada_2022_2
 * Archivo:     main.cpp
 * Autor:       CosmoDev
 *
 * Creado el 28 de abril de 2023, 12:20 AM
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "AperturaDeArchivos.h"
#include "OperadoresSobrecargados.h"
#include "Estructuras.h"

int main(int argc, char** argv) {
    
    ifstream archMedicos, archPacientes, archConsultas;
    ofstream archReporte;
    bool veracidad;
    int dni;

    // Lectura 1:
    struct StMedico medico;    
    AperturaDeUnArchivoDeTextosParaLeer(archMedicos, "MedicosLab3.txt");
    veracidad = archMedicos>>medico;
    cout<<medico.nombre<<endl<<medico.especialidad<<endl<<veracidad<<endl<<endl;
    
    // Lectura 2:
    struct StPaciente paciente;  
    AperturaDeUnArchivoDeTextosParaLeer(archPacientes, "PacientesLab3.txt");
    veracidad = archPacientes>>paciente;
    cout<<paciente.dni<<endl<<paciente.nombre<<endl<<paciente.telefono<<endl<<endl;
    
    // Lectura 3:
    struct StCita cita;  
    AperturaDeUnArchivoDeTextosParaLeer(archConsultas, "ConsultasLab3.txt");
    dni = archConsultas>>cita;
    cout<<dni<<endl<<cita.codigoDelMedico<<endl<<cita.fecha<<endl<<endl;
        
    // Busqueda:
    struct StMedico arregloMedico[100];
    for (int i=0; true; i++) if (not (archMedicos>>arregloMedico[i])) break;
    cita<=arregloMedico;
    cout<<cita.especialidad<<endl<<cita.tarifaPorConsulta<<endl<<endl;
    
    // AgregaciÃ³n:
    paciente+=cita;
    cout<<paciente.citas[0].codigoDelMedico<<endl<<paciente.citas[0].especialidad
            <<endl<<paciente.citas[0].fecha<<endl
            <<paciente.citas[0].tarifaPorConsulta<<endl<<endl;
    
    // Gastos:
    cout<<paciente.totalGastado<<endl;
    ++paciente;
    cout<<paciente.totalGastado<<endl<<endl;
    
    // ImpresiÃ³n:
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte, "Reporte.txt");
    archReporte<<paciente;
        
    return 0;
}

