#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstring>
#include <string.h>
#include <fstream>
#include "Funciones.cpp"
using namespace std;
int main()
{
    int opcion;
    int cont = 5;
    Empleado *empleado, *archivoSalida, *aux;
    aux = new Empleado;
    empleado = new Empleado[10];
    archivoSalida = new Empleado[10];
    do{
        cout<<"\n1. Imprimir Archivos. ";
        cout<<"\n2. Generar Archivo 'Datos.txt'. ";
        cout<<"\n3. Adicionar empleado. ";
        cout<<"\n4. Salir. ";
        cout<<"\nDigite una opcion. "<<endl;
        cin>> opcion;
        switch(opcion){

            case 1: imprimirArchivo(empleado, archivoSalida, cont);
            break;

            case 2: generarArchivo(empleado, cont);
            break;

            case 3: adicionarEmpleado(aux, empleado, cont);
            break;

            case 4: break;
            default: break;
        }
    }while(opcion != 4);
    return 0;
}
