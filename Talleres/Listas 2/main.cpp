#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Funciones.cpp"

using namespace std;

int main()
{
    int opcion, valor;
    Lista * listap1 = new Lista;
    listap1->tam = 0;
    listap1->cab = NULL;

    Lista * listap2 = new Lista;
    listap2->tam = 0;
    listap2->cab = NULL;

    Lista * listaf = new Lista;
    listaf->tam = 0;
    listaf->cab = NULL;

    do{
    cout<<"\n1. Ingresar los datos de los polinomios. ";
    cout<<"\n2. Imprimir Polinomios. ";
    cout<<"\n3. Realizar la suma de los polinomios. ";
    cout<<"\n4. Evaluar el polinomio. ";
    cout<<"\n5. Salir. ";
    cout<<"\nDigite una opcion. ";
    cin>> opcion;
    switch(opcion){

        case 1: insertar(listap1, listap2);
        break;

        case 2: imprimir(listap1, listap2);
        break;

        case 3: sumarPolinomios(listap1, listap2, listaf);
        break;

        case 4: evaluarPolinomio(listaf);
        break;

        case 5: break;
        default: break;
    }
    }while(opcion != 5);
    return 0;
}
