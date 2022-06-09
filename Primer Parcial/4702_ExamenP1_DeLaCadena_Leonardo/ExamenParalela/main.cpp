#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<time.h>
#include "Matriz.h"
#include <sys/time.h>
using namespace std;

int main(int argc, char** argv) {


	int d;
	cout << "Ingrese el tamanio de las matrices: ";
	cin >> d;

	Matriz<int> m1(d);
	Matriz<int> m2(d);
	Matriz<int> mr(d);


	m1.segmentar();
	m2.segmentar();
	mr.segmentar();

	m1.encerar();
	m2.encerar();
	mr.encerar();

	m1.ingresar();
	m2.ingresar();

	//m1.imprimir();
	printf("\n\n");
	//m2.imprimir();

	cout << "\nLa multiplicacion de las matrices es: \n";
	struct timeval start, end;
	gettimeofday(&start, NULL);
	mr = m1.procesar(m2);
	gettimeofday(&end, NULL);
	double delta = ((end.tv_sec - start.tv_sec) * 1000000u +
		end.tv_usec - start.tv_usec) / 1.e6;
	std::cout << "Tiempo en segundos: " << delta << std::endl;
	//mr.imprimir();
	printf("\n\n");


}
