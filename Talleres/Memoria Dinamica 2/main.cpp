#include <iostream>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include "Funciones.cpp"

using namespace std;

int main()
{
    int MAX, i, *v, opcion, *x, *y, ***z;
    cout<<"Digite el tamaño maximo del vector V. ";
    cin>>MAX;
    v = new int[MAX];
    srand(time(0));
    for(i=0; i<MAX; i++){
        *(v + i) = (1 + rand() % 100);
    }
    do{
        cout<<"\n1. Crear el vector NUMERO. ";
        cout<<"\n2. Crear el vector NUMERO_OCURRENCIAS. ";
        cout<<"\n3. Crear Matriz. ";
        cout<<"\n4. Ordenar el vector V. ";
        cout<<"\n5. Salir. ";
        cout<<"\nDigite una opcion. ";
        cin>> opcion;
        switch(opcion){

            case 1: x = numeros(MAX, v);
                    break;

            case 2: y = ocurrencias(MAX, v, x);
                    break;

            case 3: z = matriz(MAX, v, x, y);
                    break;

            case 4: ordenar(MAX, v, x, y, z);
                    break;

            case 5: break;
            default: break;
        }
    }while(opcion != 5);
    return 0;
}

