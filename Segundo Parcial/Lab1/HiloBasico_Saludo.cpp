//Laboratorio 02
//Ejemplos con OpenMP
#include <iostream>
#include <stdio.h>
#include <omp.h>
using namespace std;

int main()
{
    int numHilos;
    int numProcesadores;
    cout<<"Programa con manejo de Hilos con OpenMp"<<endl;
    numProcesadores = omp_get_num_procs();
    cout<<"Este computador usa "<<numProcesadores<< " procesadores"<<endl;
    cout<<"Ingrese el numero de hilos"<<endl;
    cin>>numHilos;
    omp_set_num_threads(numHilos);
    cout<<"En este ejemplo se desea usar "<<omp_get_max_threads()<<" hilos"<<endl;
    cout<<"Eb este momento se van a ejecutar "<<omp_get_num_threads()<<" hilos"<<endl;
    cout<<"Seccion Paralela"<<endl;
    #pragma omp parallel
    {

        int idHilo = omp_get_thread_num();
        cout<<"Hola soy hilo "<<idHilo<<", En este momento se ejecutan "<<omp_get_num_threads()<<" hilos"<<endl;
    }
    cout<<"Fin - Seccion Paralela"<<endl;
    cout<<"En este momento se estan ejecutando "<<omp_get_num_threads()<<" hilos"<<endl;
    return 0;

}
