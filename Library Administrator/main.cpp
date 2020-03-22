#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <windows.h>
#include "Funciones.cpp"
using namespace std;
int main()
{
    //SE CREA EL APUNTADOR A LA MULTILISTA DE SUCURSALES.
    MultiListaSucursal *listaSucursal = new MultiListaSucursal;
    listaSucursal->cabeza = NULL;
    listaSucursal->tamSucursal = 0;
    generarSucursales(listaSucursal);
    llenarDatos(listaSucursal);
    int opcion;
    do{
        cout<<"\nBIENVENIDO A LA LIBRERIA. ";
        cout<<"\n------------------------"<<endl<<endl;
        cout<<"\n1. Ver Libros. ";
        cout<<"\n2. Editar Sucursal. ";
        cout<<"\n3. Editar libros. ";
        cout<<"\n4. Editar Generos. ";
        cout<<"\n5. Comprar Libro. ";
        cout<<"\n6. Ver Lista Top 10. ";
        cout<<"\n7. Consultar Libro. ";
        cout<<"\n8. Consultar Compras en una fecha. ";
        cout<<"\n9. Consultar Ingresos en una fecha. ";
        cout<<"\n10. Salir. ";
        cout<<"\nDigite una opcion. "<<endl;
        cin>> opcion;
        switch(opcion){
            case 1: system("cls");
                    verLibros(listaSucursal);
                    system("pause");
            break;
            case 2: system("cls");
                    editarSucursal(listaSucursal);
                    system("pause");
            break;
            case 3: system("cls");
                    editarLibros(listaSucursal);
                    system("pause");
            break;
            case 4: system("cls");
                    editarGeneros(listaSucursal);
                    system("pause");
            break;
            case 5: system("cls");
                    comprarLibro(listaSucursal);
                    system("pause");
            break;
            case 6: system("cls");
                    consultarTop(listaSucursal);
                    system("pause");
            break;
            case 7: system("cls");
                    consultarLibro(listaSucursal);
                    system("pause");
            break;
            case 8: system("cls");
                    consultarCompras(listaSucursal);
                    system("pause");
            break;
            case 9: system("cls");
                    consultarIngresos(listaSucursal);
                    system("pause");
            break;
            case 10: break;
            default: break;
        }
    }while(opcion != 10);
    return 0;
}
