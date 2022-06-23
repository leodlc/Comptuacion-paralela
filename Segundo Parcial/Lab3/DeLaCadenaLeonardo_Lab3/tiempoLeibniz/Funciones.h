#include <stdio.h>
#include <iostream>
#include <omp.h>
#include <sys/time.h>

using namespace std;

double leibnizSecuencial(int numItera){
     double respuesta=0.0;
     bool esIndicePar = true;
        for(long indice=0;indice <= numItera;indice++){
            if(esIndicePar == true){
                respuesta += 4.0 / (2.0 * indice + 1.0);
            }else{
                respuesta -= 4.0 / (2.0 * indice + 1.0);

            }
            esIndicePar = !esIndicePar;
            //printf("La respuesta es: %8f\n", respuesta);
        }
        //printf("%8f ", respuesta);
        return (respuesta);
}

double leibnizParaleloOptimizado(int numItera){
    int numHilos = 8, idHilo;
    omp_set_num_threads(numHilos);
    double respuesta= 0.0 , sumParciales[numHilos];
    #pragma omp parallel //private(idHilo) shared(SumParciales)
    {
        idHilo = omp_get_thread_num();
        sumParciales[idHilo] = 0.0;
        #pragma omp for

            for (long indice = idHilo; indice < numItera; indice+=numHilos){
                if (indice%2==0){
                    sumParciales[idHilo] += 4.0/(2.0 * indice + 1.0);
                } else{
                    sumParciales[idHilo] -= 4.0/(2.0 * indice + 1.0);
                }
            }
        #pragma omp for

              for(int indice1 = 0; indice1 < numHilos; indice1++){
                respuesta += sumParciales[indice1];
              }
        //printf("%8f ", respuesta);
    }
    return (respuesta);

}

double leibnizParalelo(int numItera ){
    int numHilos=4,idHilo;
    double respuesta;
    omp_set_num_threads(numHilos);
    double SumParciales[numHilos];
        #pragma omp parallel private(idHilo) shared(SumParciales)
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
            //printf("Hilo %d %.8f\n", idHilo,SumParciales[idHilo]);
        }
    }
     for(long indice1=0; indice1<numHilos;indice1++){
        respuesta+=SumParciales[indice1];
     }
    return(respuesta);

}
