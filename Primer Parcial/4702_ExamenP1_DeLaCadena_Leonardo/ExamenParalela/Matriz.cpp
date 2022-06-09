#include "Matriz.h"

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <omp.h>
using namespace std;

template <class T>
Matriz<T>::Matriz(T _dimension)
{
	this->d = _dimension;
}
template <class T>
Matriz<T>::Matriz()
{

}

template <class T>
void Matriz<T>::setDimension(T _dimension)
{
	this->d = _dimension;
}

template <class T>
void Matriz<T>::setMatriz(T** matri)
{
	this->mat=matri;
}

template <class T>
T Matriz<T>::getDimension()
{
	return d;
}

template <class T>
T** Matriz<T>::getMatriz()
{
	return mat;
}
template <class T>
void Matriz<T>::setProceso(T _proceso)
{
	this->p = _proceso;
}
template <class T>
T Matriz<T>::getProceso()
{
	return p;
}
////@brief Reserva memoria para la matriz
////*
template <class T>
void Matriz<T>::segmentar()
{
	mat = (T**)malloc(d * sizeof(T*));
	for (int j = 0; j < d; j++)
		*(mat + j) = (T*)malloc(d * sizeof(T));
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			*(*(mat + i) + j) = 0;
		}
	}
}
///**
//	 * @brief Inicializa la matriz en cero
//	 *
//	 */
template <class T>
void Matriz<T>::encerar()
{
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			*(*(mat + i) + j) = 0;
		}
	}
	return;
}

///**
//	 * @brief Asigna Valores a la matriz

template <class T>
void Matriz<T>::ingresar()
{
	srand(time(NULL));
	T dato;

	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++) {
			dato = 1 + rand() % (11 - 1);
			//cout << "Posicion de [" << i + 1 << "][" << j + 1 << "]: ";
			//cout <<"numero "<< dato << endl;
			*(*(mat + i) + j) = dato;
		}

}
//**
// * @brief Impresion de la matriz
// */
template <class T>
void Matriz<T>::imprimir()
{
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++)
		{
			cout << *(*(mat + i) + j);
			printf("%*s", j + 5, "");
		}
		printf("\n");
	}
}
//	 * @brief  Multiplicacion de Matrices
//	 */
template<class T>
Matriz<T> Matriz<T>::procesar(Matriz<T> matrizTmp)
{
	Matriz<T> mr(d);
	mr.segmentar();
	T** res = mr.getMatriz();
	T** mtemp = matrizTmp.getMatriz();
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			for (int h = 0; h < d; h++) {
				*(*(res + i) + j) = *(*(res + i) + j) + (*(*(mat + i) + h)) * (*(*(mtemp + h) + j));
			}
		}
	}
	return mr;
}
/*
template<class T>
Matriz<T> Matriz<T>::procesarParalelo(Matriz<T> matrizTmp, T p)
{
    #pragma omp parallel
    {
        Matriz<T> mr(d);

        mr.segmentar();
        T** res = mr.getMatriz();
        T** mtemp = matrizTmp.getMatriz();
        int first = omp_get_thread_num()*d/p;
        int last = first + d/p;
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                for (int h = 0; h < d; h++) {
                    *(*(res + i) + j) = *(*(res + i) + j) + (*(*(mat + i) + h)) * (*(*(mtemp + h) + j));
                }
            }
        }
        return mr;
    }

}
*/

template class Matriz<int>;
template class Matriz<float>;
template class Matriz<double>;
