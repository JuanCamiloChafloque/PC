#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Funciones.cpp"

using namespace std;

int main()
{
    int opcion;
    Lista * lista = new Lista;
    lista->tam = 0;
    lista->cab = NULL;

    MultiLista * multi = new MultiLista;
    multi->cab = NULL;
    multi->tam = 0;
    do{
        cout<<"\n1. Crear Lista. ";
        cout<<"\n2. Imprimir Lista. ";
        cout<<"\n3. Generar Multilista. ";
        cout<<"\n4. Imprimir Multilista. ";
        cout<<"\n5. Agregar Dato. ";
        cout<<"\n6. Salir. ";
        cout<<"\nDigite una opcion. "<<endl;
        cin>> opcion;
        switch(opcion){

            case 1: system("cls");
                    insertar(lista);
            break;

            case 2: system("cls");
                    imprimir(lista);
            break;

            case 3: system("cls");
                    generarMulti(lista, multi);
            break;

            case 4: system("cls");
                    imprimirMulti(multi);
                    system("pause");
            break;

            case 5: system("cls");
                    insertarEnUnaPosicion (multi);
                    system("pause");
            break;

            case 6: break;
            default: break;
        }
    }while(opcion != 6);
    return 0;
}
