#include <iostream>
#include <stdlib.h>
#include "Funciones.cpp"

using namespace std;

int main()
{
    Lista * lista = crearLista();
    int opcion;
    do{
        cout<<"\n1. Insertar datos a la lista. ";
        cout<<"\n2. Imprimir lista. ";
        cout<<"\n3. Invertir lista. ";
        cout<<"\n4. Salir. ";
        cout<<"\nDigite una opcion. ";
        cin>> opcion;
        switch(opcion){

            case 1: system("cls");
                    insertar(lista);
                    system("pause");
            break;

            case 2: system("cls");
                    imprimir(lista);
                    system("pause");
            break;

            case 3: system("cls");
                    invertirLista(lista);
                    system("pause");
            break;

            case 4: break;
            default: break;
        }
    }while(opcion != 4);
    system("pause");
    return 0;
}
