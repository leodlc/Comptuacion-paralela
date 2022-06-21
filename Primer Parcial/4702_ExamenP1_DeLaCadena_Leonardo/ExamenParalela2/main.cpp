#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<time.h>
#include "Matriz.h"
#include <inttypes.h>
#include <sys/time.h>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int main(int argc, char** argv) {


	int d;
	//int p=4;
	cout << "Ingrese el tamanio de las matrices: ";
	cin >> d;
    struct timeval start, end;
	Matriz<int> m1(d);
	Matriz<int> m2(d);
	Matriz<int> mr(d);
    Matriz<int> m3(d);
	Matriz<int> m4(d);
	Matriz<int> mr2(d);
	Matriz<int> p=8;

	m1.segmentar();
	m2.segmentar();
	mr.segmentar();

	m3.segmentar();
	m4.segmentar();
	mr2.segmentar();

	m1.encerar();
	m2.encerar();
	mr.encerar();

    m3.encerar();
	m4.encerar();
	mr2.encerar();

	m1.ingresar();
	m2.ingresar();

	m3.ingresar();
	m4.ingresar();
    /*
    m1.imprimir();
    printf("\n\n");
    m2.imprimir();
    */
	printf("\n\n");

	cout<<"En secuencial: "<<endl;


    gettimeofday(&start, NULL);
	mr = m1.procesar(m2);
	gettimeofday(&end, NULL);
    double delta = ((end.tv_sec  - start.tv_sec) * 1000000u +
         end.tv_usec - start.tv_usec) / 1.e6;
    std::cout << "Tiempo en segundos con metodo secuencial: " << delta << std::endl;
    /* POR SI QUEREMOS IMPRIMIR LA MATRIZ RESULTANTE
    cout<<"Matriz resultante de la multiplicacion de las dos anteriores: "<<endl;
    mr.imprimir();
    */
    //METODO EN NANOSEGUNDOS
    /*
    auto start = chrono::high_resolution_clock::now();

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    mr = m1.procesar(m2);

    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    cout << "Tiempo en segundos con paralelismo : " << fixed
         << time_taken << setprecision(9);
    cout<<endl;
    */
    cout<<"En paralelo: "<<endl;


    gettimeofday(&start, NULL);
	mr=m2.procesarParalelo(m1);
	gettimeofday(&end, NULL);


    double delta2 = ((end.tv_sec  - start.tv_sec) * 1000000u +
         end.tv_usec - start.tv_usec) / 1.e6;
    std::cout << "Tiempo en segundos con paralelismo: " << delta2 << std::endl;

    //METODO EN NANOSEGUNDOS
    /*
    auto start2 = chrono::high_resolution_clock::now();

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    mr=m2.procesarParalelo(m1);

    end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken2 =
      chrono::duration_cast<chrono::nanoseconds>(end - start2).count();

    time_taken2 *= 1e-9;

    cout << "Tiempo en segundos con paralelismo : " << fixed
         << time_taken2 << setprecision(9);
    */

    return 0;



}


