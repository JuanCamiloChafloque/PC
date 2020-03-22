#include <iostream>
#include <stdlib.h>
#include "Funciones.cpp"

using namespace std;

int main()
{
    int opcion, valor;
    bool verifica;
    Lista * listap1 = new Lista;
    listap1->tam = 0;
    listap1->cab = NULL;

    Lista * listap2 = new Lista;
    listap2->tam = 0;
    listap2->cab = NULL;

    do{
    cout<<"\n1. Ingresar datos a los conjuntos. ";
    cout<<"\n2. Eliminar datos de los conjuntos. ";
    cout<<"\n3. Imprimir los conjuntos. ";
    cout<<"\n4. Realizar union de los conjuntos. ";
    cout<<"\n5. Realizar interseccion de los conjuntos. ";
    cout<<"\n6. Realizar diferencia de los conjuntos. ";
    cout<<"\n7. Salir. ";
    cout<<"\nDigite una opcion. ";
    cin>> opcion;
    switch(opcion){

        case 1: system("cls");
                insertar(listap1, listap2);
                system("pause");
        break;

        case 2: system("cls");
                verifica = eliminar(listap1, listap2);
                if(verifica == false){
                    cout<<"\nLa posicion no se puede eliminar. No existe. "<<endl;
                }
                system("pause");
        break;

        case 3: system("cls");
                imprimir(listap1, listap2);
                system("pause");
        break;

        case 4: system("cls");
                realizarUnion(listap1, listap2);
                system("pause");
        break;

        case 5: system("cls");
                realizarInt(listap1, listap2);
                system("pause");
        break;

        case 6: system("cls");
                realizarDif(listap1, listap2);
                system("pause");

        case 7: break;
        default: break;
    }
    }while(opcion != 7);
    return 0;
}
