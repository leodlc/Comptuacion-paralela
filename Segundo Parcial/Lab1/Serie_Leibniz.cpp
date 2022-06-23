#include <stdio.h>
#include <iostream>

using namespace std;


int main(){
    double respuesta;
    long numItera;
    cout<<"Programa SECUENCIAL serie de Leibniz"<<endl;
    cout<<"Ingrese el numero de iteraciones : ";
    cin>>numItera;

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
    cout<<"La respuesta es: "<<respuesta<<endl;
    return 0;
}
