//Para calcular el Numero de pi
//Programa de la Serie Leibniz(secuencial)
#include <stdio.h>
#include <omp.h>

int main(){
    int numHilos=4,idHilo;
    omp_set_num_threads(numHilos);
    double respuesta=0.0,SumParciales[numHilos];
    long numItera;
    printf("PROGRAMA Paralelo serie Leibniz\n");

    printf("Ingrese el numero de iteraciones:");
    scanf("%d",&numItera);
        #pragma omp parallel
    {
         //printf ("Saludos\n");
         idHilo=omp_get_thread_num();
         SumParciales[idHilo]=0.0;
         for(long indice=idHilo; indice<numItera;indice+=numHilos){
            if(indice%2==0){
                SumParciales[idHilo]+=4.0/(2.0*indice+1.0);

            }else{
                SumParciales[idHilo]-=4.0/(2.0*indice+1.0);
            }
            printf("Hilo %d %.8f\n", idHilo,SumParciales[idHilo]);
        }
    }
     for(long indice1=0; indice1<numHilos;indice1++){
        respuesta+=SumParciales[indice1];
     }

    printf("La respuesta es: %8f\n", respuesta);
    return 0;
}
