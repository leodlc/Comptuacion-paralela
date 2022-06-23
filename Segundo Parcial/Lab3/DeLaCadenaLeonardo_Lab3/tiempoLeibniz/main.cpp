#include <iostream>
#include "Funciones.h"
using namespace std;

int main()
{
     struct timeval start, end;
    int numItera;
    cout << "PROGRAMA SERIE DE LEIBNIZ" << endl;
    cout<< "Ingrese el numero de iteraciones"<<endl;
    scanf("%ld", &numItera);

    cout<<"Respuesta de secuencial: ";
    gettimeofday(&start, NULL);
    leibnizSecuencial(numItera);
    gettimeofday(&end, NULL);
    cout<<leibnizSecuencial(numItera);
    cout<<endl;
    double delta = ((end.tv_sec  - start.tv_sec) * 1000000u +
    end.tv_usec - start.tv_usec) / 1.e6;
    std::cout << "Tiempo en segundos con metodo secuencial: " << delta << std::endl;
    cout<<"Respuesta de paralelo: ";
    gettimeofday(&start, NULL);
    leibnizParalelo(numItera);
    gettimeofday(&end, NULL);
    cout<<leibnizParalelo(numItera);
    cout<<endl;
    double delta2 = ((end.tv_sec  - start.tv_sec) * 1000000u +
    end.tv_usec - start.tv_usec) / 1.e6;
    std::cout << "Tiempo en segundos con paralelismo: " << delta2 << std::endl;
    cout<<"Respuesta de paralelo optimizado: ";
    gettimeofday(&start, NULL);
    leibnizParaleloOptimizado(numItera);
    gettimeofday(&end, NULL);
    cout<<leibnizParalelo(numItera);
    cout<<endl;
    double delta3 = ((end.tv_sec  - start.tv_sec) * 1000000u +
    end.tv_usec - start.tv_usec) / 1.e6;
    std::cout << "Tiempo en segundos con paralelismo optimizado: " << delta3 << std::endl;

    return 0;
}
