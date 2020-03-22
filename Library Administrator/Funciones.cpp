#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <windows.h>
#include "Funciones.h"
using namespace std;
void generarSucursales(MultiListaSucursal *listaSucursal){

    //SE AGREGAN TRES SUCURSALES POR DEFECTO.
    for(int i=0; i<3; i++){
        MultiNodoSucursal *nodoSucursal = new MultiNodoSucursal;
        nodoSucursal->siguiente = NULL;
        nodoSucursal->info = new MultiListaGenero;
        nodoSucursal->info->cabeza = NULL;
        nodoSucursal->info->tamGenero = 0;
        nodoSucursal->nombre = new char[100];
        for(int k=0; k<100; k++){
            nodoSucursal->nombre[k] = '\0';
        }
        if(listaSucursal->tamSucursal == 0){
            listaSucursal->cabeza = nodoSucursal;
            listaSucursal->tamSucursal++;
        }else{
            MultiNodoSucursal *auxSucursal;
            auxSucursal = listaSucursal->cabeza;
            while(auxSucursal->siguiente != NULL){
                auxSucursal = auxSucursal->siguiente;
            }
            auxSucursal->siguiente = nodoSucursal;
            listaSucursal->tamSucursal++;
        }
    }
    //PARA CADA SUCURSAL SE AGREGAN 3 GENEROS Y PARA CADA GENERO SE AGREGAN 2 LIBROS.
    MultiNodoSucursal *auxSucursal2;
    auxSucursal2 = listaSucursal->cabeza;
    while(auxSucursal2 != NULL){
        for(int i=0; i<3; i++){
            MultiNodoGenero *nodoGenero = new MultiNodoGenero;
            nodoGenero->siguiente = NULL;
            nodoGenero->info = new ListaLibro;
            nodoGenero->info->cabeza = NULL;
            nodoGenero->info->tamLibro = 0;
            nodoGenero->nombre = new char[100];
            for(int k=0; k<100; k++){
                nodoGenero->nombre[k] = '\0';
            }
            if(auxSucursal2->info->tamGenero == 0){
                auxSucursal2->info->cabeza = nodoGenero;
                auxSucursal2->info->tamGenero++;
            }else{
                MultiNodoGenero *auxGenero;
                auxGenero = auxSucursal2->info->cabeza;
                while(auxGenero->siguiente != NULL){
                    auxGenero = auxGenero->siguiente;
                }
                auxGenero->siguiente = nodoGenero;
                auxSucursal2->info->tamGenero++;
            }
        }
        auxSucursal2 = auxSucursal2->siguiente;
    }
    //SE COMIENZA A CREAR LOS LIBROS PARA CADA GENERO
    MultiNodoSucursal *auxSucursal3;
    MultiNodoGenero *auxGenero2;
    auxSucursal3 = listaSucursal->cabeza;
    int cont = 0;
    while(auxSucursal3 != NULL){
        auxGenero2 = auxSucursal3->info->cabeza;
        while(auxGenero2 != NULL){
            for(int i=0; i<2; i++){
                NodoLibro *nodoLibro = new NodoLibro;
                nodoLibro->siguiente = NULL;
                nodoLibro->info.nombre = new char[100];
                nodoLibro->info.autor = new char[100];
                for(int k=0; k<100; k++){
                    nodoLibro->info.nombre[k] = '\0';
                    nodoLibro->info.autor[k] = '\0';
                }
                if(auxGenero2->info->tamLibro == 0){
                    auxGenero2->info->cabeza = nodoLibro;
                    auxGenero2->info->tamLibro++;
                }else{
                    NodoLibro *auxLibro;
                    auxLibro = auxGenero2->info->cabeza;
                    while(auxLibro->siguiente != NULL){
                        auxLibro = auxLibro->siguiente;
                    }
                    auxLibro->siguiente = nodoLibro;
                    auxGenero2->info->tamLibro++;
                }
            }
            auxGenero2 = auxGenero2->siguiente;
        }
        auxSucursal3 = auxSucursal3->siguiente;
    }
}
void llenarDatos(MultiListaSucursal *listaSucursal){

    MultiNodoGenero *auxGenero;
    NodoLibro *auxLibro;
    char *lineaEntrada = new char[100];
    for(int i=0; i<100; i++){
        *(lineaEntrada + i) = '\0';
    }
    //SE LLENA LA LISTA DE SUCURSALES, GENEROS Y LIBROS CON DATOS DEL ARCHIVO INFORMACION.TXT.
    ifstream entradaArchivo;
    entradaArchivo.open("Informacion.txt", ios::in);
    if(!entradaArchivo.is_open()){
        cout<<"\nLo sentimos no se pudieron llenar los datos en la libreria. ";
    }else{
            MultiNodoSucursal *auxSucursal;
            auxSucursal = listaSucursal->cabeza;
            while(auxSucursal != NULL){
                entradaArchivo.getline(lineaEntrada, 100);
                strcpy(auxSucursal->nombre, lineaEntrada);
                auxGenero = auxSucursal->info->cabeza;
                while(auxGenero != NULL){
                    entradaArchivo.getline(lineaEntrada, 100);
                    strcpy(auxGenero->nombre, lineaEntrada);
                    auxLibro = auxGenero->info->cabeza;
                    while(auxLibro != NULL){
                        entradaArchivo.getline(lineaEntrada, 100);
                        char *auxiliar = new char[100];
                        char *auxCant = new char[10];
                        char *auxPrecio = new char[20];
                        strcpy(auxiliar, lineaEntrada);
                        strtok(auxiliar, ",");
                        strcpy(auxLibro->info.nombre, auxiliar);
                        auxiliar = strtok(NULL, ",");
                        strcpy(auxLibro->info.autor, auxiliar);
                        auxiliar = strtok(NULL, ",");
                        strcpy(auxCant, auxiliar);
                        auxLibro->info.cantidad = atoi(auxCant);
                        auxiliar = strtok(NULL, ",");
                        strcpy(auxPrecio, auxiliar);
                        auxLibro->info.precio = atoi(auxPrecio);
                        auxLibro = auxLibro->siguiente;
                    }
                    auxGenero = auxGenero->siguiente;
                }
                auxSucursal = auxSucursal->siguiente;
            }
    }entradaArchivo.close();
}
void verLibros(MultiListaSucursal *listaSucursal){

    MultiNodoSucursal *auxSucursal;
    MultiNodoGenero *auxGenero;
    NodoLibro *auxLibro;
    //SE RECORRE LA LISTA DE SUCURSALES, GENEROS Y LIBROS Y SE IMPRIMEN PARA QUE EL USUARIO PUEDA VER LOS LIBROS DISPONIBLES EN LAS DIFERENTES SUCURSALES
    auxSucursal = listaSucursal->cabeza;
    while(auxSucursal != NULL){
        cout<<"\nSucursal: "<<auxSucursal->nombre;
        cout<<"\n---------------------------------"<<endl;
        auxGenero = auxSucursal->info->cabeza;
        while(auxGenero != NULL){
            cout<<"\nGenero: "<<auxGenero->nombre<<endl;
            cout<<"\nLibros. "<<endl;
            auxLibro = auxGenero->info->cabeza;
            while(auxLibro != NULL){
                cout<<"\nTitulo: "<<auxLibro->info.nombre;
                cout<<"\nAutor: "<<auxLibro->info.autor;
                cout<<"\nCantidad Disponible en la Sucursal: "<<auxLibro->info.cantidad;
                cout<<"\nPrecio: "<<auxLibro->info.precio<<endl<<endl;
                auxLibro = auxLibro->siguiente;
            }
            auxGenero = auxGenero->siguiente;
        }
        auxSucursal = auxSucursal->siguiente;
    }
}
void editarSucursal(MultiListaSucursal *listaSucursal){

    int sucur, cont = 0, igual = 0;
    char *agregar = new char[100];
    char *eliminar = new char[100];
    for(int i=0; i<100; i++){
        *(agregar + i) = '\0';
        *(eliminar + i) = '\0';
    }
    //SE AGREGAN O ELIMINAN SUCURSALES
    cout<<"\nDesea Agregar o eliminar una sucursal?. "<<endl;
    cout<<"\n1. Agregar. ";
    cout<<"\n2. Eliminar. ";
    cout<<"\nDigite una opcion. "<<endl;
    cin>> sucur;
    if(sucur == 1){
        cout<<"\nDigite el nombre de la sucursal a agregar. ";
        cin.ignore();
        cin.getline(agregar, 100);
        MultiNodoSucursal *auxSucursal;
        auxSucursal = listaSucursal->cabeza;
        while(auxSucursal != NULL){
            if(strcmp(auxSucursal->nombre, agregar) == 0){
                igual++;
            }
            auxSucursal = auxSucursal->siguiente;
        }
        if(igual == 0){
            MultiNodoSucursal *nodoSucursal = new MultiNodoSucursal;
            nodoSucursal->info = new MultiListaGenero;
            nodoSucursal->info->cabeza = NULL;
            nodoSucursal->info->tamGenero = 0;
            nodoSucursal->siguiente = NULL;
            nodoSucursal->nombre = new char[100];
            strcpy(nodoSucursal->nombre, agregar);
            MultiNodoSucursal *auxSucursal;
            auxSucursal = listaSucursal->cabeza;
            while(auxSucursal->siguiente != NULL){
                auxSucursal = auxSucursal->siguiente;
            }
            auxSucursal->siguiente = nodoSucursal;
            cout<<"\nLa sucursal fue agregada exitosamente. "<<endl;
        }else{
            cout<<"\nLa sucursal que se quiere agregar ya se encuentra en el sistema. "<<endl;
        }
    }
    if(sucur == 2){
        cout<<"\nDigite el nombre de la sucursal a eliminar. ";
        cin.ignore();
        cin.getline(eliminar, 100);
        MultiNodoSucursal *auxSucursal;
        auxSucursal = listaSucursal->cabeza;
        while(auxSucursal != NULL){
            if(strcmp(auxSucursal->nombre, eliminar) == 0){
                if(auxSucursal == listaSucursal->cabeza){
                    MultiNodoSucursal *temp;
                    temp = listaSucursal->cabeza;
                    listaSucursal->cabeza = temp->siguiente;
                    temp->siguiente = NULL;
                    delete temp;
                    listaSucursal->tamSucursal--;
                    cont++;
                    cout<<"\nLa sucursal fue eliminada exitosamente. "<<endl;
                    break;
                }else{
                    MultiNodoSucursal *temp;
                    temp = listaSucursal->cabeza;
                    while(strcmp(temp->siguiente->nombre, eliminar ) !=  0){
                        temp = temp->siguiente;
                    }
                    MultiNodoSucursal *auxS;
                    auxS = temp->siguiente;
                    temp->siguiente = auxS->siguiente;
                    auxS->siguiente = NULL;
                    delete auxS;
                    listaSucursal->tamSucursal--;
                    cont++;
                    cout<<"\nLa sucursal fue eliminada exitosamente. "<<endl;
                    break;
                }
            }
            auxSucursal = auxSucursal->siguiente;
        }
    }
    if((cont == 0) && (sucur == 2)){
        cout<<"\nNo se puede eliminar la sucursal, no existe. "<<endl;
    }

}
void editarLibros(MultiListaSucursal *listaSucursal){

    int lib, cont = 0, igual = 0;
    char *agregar = new char[100];
    char *eliminar = new char[100];
    char *sucursal = new char[100];
    char *genero = new char[100];
    for(int i=0; i<100; i++){
        *(agregar + i) = '\0';
        *(eliminar + i) = '\0';
        *(sucursal + i) = '\0';
        *(genero + i) = '\0';
    }
    //SE AGREGAN O ELIMINAN LIBROS
    cout<<"\nDesea Agregar o eliminar un libro?. "<<endl;
    cout<<"\n1. Agregar. ";
    cout<<"\n2. Eliminar. ";
    cout<<"\nDigite una opcion. "<<endl;
    cin>> lib;
    if(lib == 1){
        cout<<"\nDigite el nombre del libro a agregar. ";
        cin.ignore();
        cin.getline(agregar, 100);
        cout<<"\nDigite el nombre de la sucursal de la cual se quiere agregar el libro. ";
        cin.getline(sucursal, 100);
        cout<<"\nDigite el genero al que pertence el libro. ";
        cin.getline(genero, 100);
        MultiNodoSucursal *auxSucursal;
        auxSucursal = listaSucursal->cabeza;
        while(auxSucursal != NULL){
            if(strcmp(auxSucursal->nombre, sucursal) == 0){
                MultiNodoGenero *auxGenero;
                auxGenero = auxSucursal->info->cabeza;
                while(auxGenero != NULL){
                    if(strcmp(auxGenero->nombre, genero) == 0){
                        NodoLibro *auxLibro;
                        auxLibro = auxGenero->info->cabeza;
                        while(auxLibro != NULL){
                            if(strcmp(auxLibro->info.nombre, agregar) == 0){
                                igual++;
                            }
                            auxLibro = auxLibro->siguiente;
                        }
                    }
                    auxGenero = auxGenero->siguiente;
                }
            }
            auxSucursal = auxSucursal->siguiente;
        }
        if(igual == 0){
            NodoLibro *nodoLibro = new NodoLibro;
            nodoLibro->siguiente = NULL;
            nodoLibro->info.nombre = new char[100];
            strcpy(nodoLibro->info.nombre, agregar);
            nodoLibro->info.autor = new char[100];
            cout<<"\nDigite el nombre del autor. ";
            cin.getline(nodoLibro->info.autor, 100);
            cout<<"\nDigite la cantidad a agregar. ";
            cin>> nodoLibro->info.cantidad;
            cout<<"\nDigite El precio del libro. ";
            cin>> nodoLibro->info.precio;
            MultiNodoSucursal *auxSucursal;
            auxSucursal = listaSucursal->cabeza;
            while(auxSucursal != NULL){
                if(strcmp(auxSucursal->nombre, sucursal) == 0){
                    MultiNodoGenero *auxGenero;
                    auxGenero = auxSucursal->info->cabeza;
                    while(auxGenero != NULL){
                        if(strcmp(auxGenero->nombre, genero) == 0){
                            if(auxGenero->info->tamLibro == 0){
                                auxGenero->info->cabeza = nodoLibro;
                                auxGenero->info->tamLibro++;
                                cout<<"\nEl libro fue agregado a la sucursal exitosamente. "<<endl;
                            }else{
                                NodoLibro *auxLibro;
                                auxLibro = auxGenero->info->cabeza;
                                while(auxLibro->siguiente != NULL){
                                    auxLibro = auxLibro->siguiente;
                                }
                                auxLibro->siguiente = nodoLibro;
                                auxGenero->info->tamLibro++;
                                cout<<"\nEl libro fue agregado a la sucursal exitosamente. "<<endl;
                            }
                        }
                        auxGenero = auxGenero->siguiente;
                    }
                }
                auxSucursal = auxSucursal->siguiente;
            }
        }else{
            MultiNodoSucursal *auxSucursal;
            auxSucursal = listaSucursal->cabeza;
            while(auxSucursal != NULL){
                if(strcmp(auxSucursal->nombre, sucursal) == 0){
                    MultiNodoGenero *auxGenero;
                    auxGenero = auxSucursal->info->cabeza;
                    while(auxGenero != NULL){
                        if(strcmp(auxGenero->nombre, genero) == 0){
                            NodoLibro *auxLibro;
                            auxLibro = auxGenero->info->cabeza;
                            while(auxLibro != NULL){
                                if(strcmp(auxLibro->info.nombre, agregar) == 0){
                                    auxLibro->info.cantidad++;
                                    cout<<"\nEl libro fue agregado a la sucursal exitosamente. "<<endl;
                                }
                                auxLibro = auxLibro->siguiente;
                            }
                        }
                        auxGenero = auxGenero->siguiente;
                    }
                }
                auxSucursal = auxSucursal->siguiente;
            }
        }
    }
    if(lib == 2){
        cout<<"\nDigite el nombre del libro a eliminar. ";
        cin.ignore();
        cin.getline(eliminar, 100);
        cout<<"\nDigite el nombre de la sucursal de la cual se quiere eliminar el libro. ";
        cin.getline(sucursal, 100);
        MultiNodoSucursal *auxSucursal;
        auxSucursal = listaSucursal->cabeza;
        while(auxSucursal != NULL){
            if(strcmp(auxSucursal->nombre, sucursal) == 0){
                MultiNodoGenero *auxGenero;
                auxGenero = auxSucursal->info->cabeza;
                while(auxGenero != NULL){
                    NodoLibro *auxLibro;
                    auxLibro = auxGenero->info->cabeza;
                    while(auxLibro != NULL){
                        if(strcmp(auxLibro->info.nombre, eliminar) == 0){
                                if(auxLibro == auxGenero->info->cabeza){
                                        NodoLibro *temp;
                                        temp = auxGenero->info->cabeza;
                                        auxGenero->info->cabeza = temp->siguiente;
                                        temp->siguiente = NULL;
                                        delete temp;
                                        auxGenero->info->tamLibro--;
                                        cont++;
                                        cout<<"\nEl libro fue eliminado de la sucursal exitosamente. "<<endl;
                                        break;
                                }else{
                                    NodoLibro *temp;
                                    temp = auxGenero->info->cabeza;
                                    while(strcmp(temp->siguiente->info.nombre, eliminar) != 0){
                                        temp = temp->siguiente;
                                    }
                                    NodoLibro *auxS;
                                    auxS = temp->siguiente;
                                    temp->siguiente = auxS->siguiente;
                                    auxS->siguiente = NULL;
                                    delete auxS;
                                    auxGenero->info->tamLibro--;
                                    cont++;
                                    cout<<"\nEl libro fue eliminado de la sucursal exitosamente. "<<endl;
                                    break;
                                }
                        }
                        auxLibro = auxLibro->siguiente;
                    }
                    auxGenero = auxGenero->siguiente;
                }
            }
            auxSucursal = auxSucursal->siguiente;
        }
    }
    if((cont == 0) && (lib == 2)){
        cout<<"\nNo se puede eliminar el libro, no existe. "<<endl;
    }
}
void editarGeneros(MultiListaSucursal *listaSucursal){

    int gen, cont = 0, igual = 0;
    char *agregar = new char[100];
    char *eliminar = new char[100];
    char *sucursal = new char[100];
    for(int i=0; i<100; i++){
        *(agregar + i) = '\0';
        *(eliminar + i) = '\0';
        *(sucursal + i) = '\0';
    }
    //SE AGREGAN O ELIMINAN GENEROS
    cout<<"\nDesea Agregar o eliminar un genero. "<<endl;
    cout<<"\n1. Agregar. ";
    cout<<"\n2. Eliminar. ";
    cout<<"\nDigite una opcion. "<<endl;
    cin>> gen;
    if(gen == 1){
        cout<<"\nDigite el nombre del genero a agregar. ";
        cin.ignore();
        cin.getline(agregar, 100);
        cout<<"\nDigite el nombre de la sucursal a la cual se quiere agregar el genero. ";
        cin.getline(sucursal, 100);
        MultiNodoSucursal *auxSucursal;
        auxSucursal = listaSucursal->cabeza;
        while(auxSucursal != NULL){
            if(strcmp(auxSucursal->nombre, sucursal) == 0){
                MultiNodoGenero *auxGenero;
                auxGenero = auxSucursal->info->cabeza;
                while(auxGenero != NULL){
                    if(strcmp(auxGenero->nombre, agregar) == 0){
                        igual++;
                    }
                    auxGenero = auxGenero->siguiente;
                }
            }
            auxSucursal = auxSucursal->siguiente;
        }
        if(igual == 0){
            MultiNodoSucursal *auxSucursal;
            auxSucursal = listaSucursal->cabeza;
            while(auxSucursal != NULL){
                if(strcmp(auxSucursal->nombre, sucursal) == 0){
                    MultiNodoGenero *nodoGenero = new MultiNodoGenero;
                    nodoGenero->info = new ListaLibro;
                    nodoGenero->info->cabeza = NULL;
                    nodoGenero->info->tamLibro = 0;
                    nodoGenero->siguiente = NULL;
                    nodoGenero->nombre = new char[100];
                    strcpy(nodoGenero->nombre, agregar);
                    MultiNodoGenero *temp;
                    if(auxSucursal->info->tamGenero == 0){
                        auxSucursal->info->cabeza = nodoGenero;
                        auxSucursal->info->tamGenero++;
                        cout<<"\nEl genero fue agregado a la sucursal exitosamente. "<<endl;

                    }else{
                        temp = auxSucursal->info->cabeza;
                        while(temp->siguiente != NULL){
                            temp = temp->siguiente;
                        }
                        temp->siguiente = nodoGenero;
                        auxSucursal->info->tamGenero++;
                        cout<<"\nEl genero fue agregado a la sucursal exitosamente. "<<endl;
                    }
                }
                auxSucursal = auxSucursal->siguiente;
            }
        }else{
            cout<<"\nEl genero que se quiere agregar a la sucursal ya existe en el sistema. "<<endl;
        }
    }
    if(gen == 2){
        cout<<"\nDigite el nombre del genero a eliminar. ";
        cin.ignore();
        cin.getline(eliminar, 100);
        cout<<"\nDigite el nombre de la sucursal de la cual se quiere eliminar el genero. ";
        cin.getline(sucursal, 100);
        MultiNodoSucursal *auxSucursal;
        auxSucursal = listaSucursal->cabeza;
        while(auxSucursal != NULL){
            if(strcmp(auxSucursal->nombre, sucursal) == 0){
                MultiNodoGenero *auxGenero;
                auxGenero = auxSucursal->info->cabeza;
                while(auxGenero != NULL){
                    if(strcmp(auxGenero->nombre, eliminar) == 0){
                        if(auxGenero = auxSucursal->info->cabeza){
                            MultiNodoGenero *temp;
                            temp = auxSucursal->info->cabeza;
                            auxSucursal->info->cabeza = temp->siguiente;
                            temp->siguiente = NULL;
                            delete temp;
                            auxSucursal->info->tamGenero--;
                            cont++;
                            cout<<"\nEl genero fue eliminado de la sucursal exitosamente. "<<endl;
                            break;
                        }else{
                            MultiNodoGenero *temp;
                            temp = auxSucursal->info->cabeza;
                            while(strcmp(temp->siguiente->nombre, eliminar) != 0){
                                temp = temp->siguiente;
                            }
                            MultiNodoGenero *auxS;
                            auxS = temp->siguiente;
                            temp->siguiente = auxS->siguiente;
                            auxS->siguiente = NULL;
                            delete auxS;
                            auxSucursal->info->tamGenero--;
                            cont++;
                            cout<<"\nEl genero fue eliminado de la sucursal exitosamente. "<<endl;
                            break;
                        }
                    }
                    auxGenero = auxGenero->siguiente;
                }
            }
            auxSucursal = auxSucursal->siguiente;
        }
    }
    if((cont == 0) && (gen == 2)){
        cout<<"\nNo se pudo eliminar el genero, no existe. "<<endl;
    }
}
void comprarLibro(MultiListaSucursal *listaSucursal){

    int cont = 0;
    ofstream salidaArchivo;
    char *fecha, *genero, *titulo, *sucursal, *usuario;
    fecha = new char[20];
    genero = new char[100];
    titulo = new char[100];
    sucursal = new char[100];
    usuario = new char[100];
    cout<<"\nDigite la fecha del dia de hoy. AAAA/MM/DD "<<endl;
    cin.ignore();
    cin.getline(fecha, 20);
    cout<<"\nDigite su Nombre-Apellido. ";
    cin.getline(usuario, 100);
    cout<<"\nDigite el genero para buscar recomendaciones. ";
    cin.getline(genero, 100);
    MultiNodoSucursal *auxSucursal;
    auxSucursal = listaSucursal->cabeza;
    while(auxSucursal != NULL){
        MultiNodoGenero *auxGenero;
        auxGenero = auxSucursal->info->cabeza;
        while(auxGenero != NULL){
            if(strcmp(auxGenero->nombre, genero) == 0){
                NodoLibro *auxLibro;
                auxLibro = auxGenero->info->cabeza;
                cout<<"\nSucursal: "<<auxSucursal->nombre<<endl;
                while(auxLibro != NULL){
                     cout<<"\nTitulo: "<<auxLibro->info.nombre;
                     cout<<"\nAutor: "<<auxLibro->info.autor;
                     cout<<"\nCantidad Disponible: "<<auxLibro->info.cantidad;
                     cout<<"\nPrecio: "<<auxLibro->info.precio;
                     cout<<endl;
                     cont++;
                     auxLibro = auxLibro->siguiente;
                }
            }
            auxGenero = auxGenero->siguiente;
        }
        auxSucursal = auxSucursal->siguiente;
    }
    cout<<endl;
    if(cont == 0){
        cout<<"\nSu busqueda no obtuvo resultados, el genero ingresado no esta en la base de datos. ";
    }
    cout<<"\nDigite el nombre del libro para realizar su compra. ";
    cin.getline(titulo, 100);
    cout<<"\nDigite el nombre de la sucursal para realizar la factura. ";
    cin.getline(sucursal, 100);
    MultiNodoSucursal *auxSucursal2;
    auxSucursal2 = listaSucursal->cabeza;
    while(auxSucursal2 != NULL){
       if(strcmp(auxSucursal2->nombre, sucursal) == 0){
            MultiNodoGenero *auxGenero2;
            auxGenero2 = auxSucursal2->info->cabeza;
            while(auxGenero2 != NULL){
                if(strcmp(auxGenero2->nombre, genero) == 0){
                    NodoLibro *auxLibro2;
                    auxLibro2 = auxGenero2->info->cabeza;
                    while(auxLibro2 != NULL){
                        if(strcmp(auxLibro2->info.nombre, titulo) == 0){
                            if(auxLibro2->info.cantidad > 0){
                                cout<<"\nSu compra se realizo exitosamente. ";
                                auxLibro2->info.cantidad--;
                                salidaArchivo.open("Factura.txt",ios::out | ios::app);
                                salidaArchivo<<fecha<<","<<usuario<<","<<auxLibro2->info.nombre<<","<<auxLibro2->info.autor<<","<<auxLibro2->info.precio<<","<<auxSucursal2->nombre<<endl;
                                salidaArchivo.close();
                            }else{
                                cout<<"\nEl libro a comprar no esta disponible en la sucursal: "<<auxSucursal2->nombre<<endl;
                            }
                        }
                        auxLibro2 = auxLibro2->siguiente;
                    }
                }
                auxGenero2 = auxGenero2->siguiente;
            }
       }
       auxSucursal2 = auxSucursal2->siguiente;
    }
}
void consultarTop(MultiListaSucursal *listaSucursal){

    int cont = 0, i = 0, aux = 0;
    char *lineaEntrada = new char[200];
    ifstream entradaArchivo;
    entradaArchivo.open("Factura.txt", ios::in);
    if(!entradaArchivo.is_open()){
        cout<<"\nNo se pudo abrir el archivo. "<<endl;
    }else{
        while(!entradaArchivo.eof()){
            entradaArchivo.getline(lineaEntrada, 200);
            cont++;
        }
    }entradaArchivo.close();
    Factura *fact, *temp;
    fact = new Factura[cont];
    for(int j=0; j<cont; j++){
        (fact + j)->autor = new char[100];
        (fact + j)->titulo = new char[100];
    }
    ifstream entradaArchivo2;
    entradaArchivo2.open("Factura.txt", ios::in);
    if(!entradaArchivo2.is_open()){
        cout<<"\nNo se pudo abrir el archivo. "<<endl;
    }else{
        while(!entradaArchivo2.eof()){
            entradaArchivo2.getline(lineaEntrada, 200);
            char *auxiliar = new char[200];
            temp = new Factura;
            temp->titulo = new char[200];
            temp->autor = new char[200];
            strcpy(auxiliar, lineaEntrada);
            strtok(auxiliar, ",");
            auxiliar = strtok(NULL, ",");
            auxiliar = strtok(NULL, ",");
            strcpy(temp->titulo, auxiliar);
            auxiliar = strtok(NULL, ",");
            strcpy(temp->autor, auxiliar);
            auxiliar = strtok(NULL, ",");
            temp->precio = atoi(auxiliar);
            if(i == 0){
                *(fact + i) = *temp;
                (fact + i)->ejemplarV++;
                i++;
            }else{
                for(int j=0; j<i; j++){
                    if(strcmp((fact + j)->titulo, temp->titulo)== 0){
                        aux++;
                        break;
                    }
                }
                if(aux != 0){
                    for(int j=0; j<i; j++){
                       if(strcmp((fact + j)->titulo, temp->titulo)== 0){
                            (fact + j)->precio = (fact + j)->precio + temp->precio;
                            (fact + j)->ejemplarV++;
                            aux = 0;
                       }
                    }
                }
                else{
                    *(fact + i) = *temp;
                    (fact + i)->ejemplarV++;
                    i++;
                }
            }

        }
        entradaArchivo2.close();
    }
    //ORDENAR LA ESTRUCTURA POR CANTIDAD DE DINERO RECAUDADO.
    Factura *auxiliar = new Factura;
    for(int j=0; j<i-1; j++){
       for(int k=j+1; k<i; k++){
            if((fact + j)->precio < (fact + k)->precio){
                *auxiliar = *(fact + j);
                *(fact + j) = *(fact + k);
                *(fact + k) = *auxiliar;
            }
        }
    }
    for(int j=0; j<i; j++){
        (fact + j)->imagen = new char[100];
    }
    //AGREGAR A LA ESTRUCTURA FACTURA LA IMAGEN DE CADA LIBRO.
    ifstream entradaArchivo3;
    char *lineaEnt = new char[100];
    entradaArchivo3.open("Portada.txt", ios::in);
    if(!entradaArchivo3.is_open()){
        cout<<"\nNo se pudo abrir el archivo de imagenes. "<<endl;
    }else{
        while(!entradaArchivo3.eof()){
            entradaArchivo3.getline(lineaEnt, 100);
            char *auxArchivo = new char[100];
            char *tempArchivo = new char[100];
            strcpy(auxArchivo, lineaEnt);
            strtok(auxArchivo, ",");
            strcpy(tempArchivo, auxArchivo);
            auxArchivo = strtok(NULL, ",");
            for(int j=0; j<i; j++){
                if(strcmp((fact + j)->titulo, tempArchivo) == 0){
                    strcpy((fact + j)->imagen, auxArchivo);
                    break;
                }
            }
        }
        entradaArchivo3.close();
    }
    //GUARDAR LA ESTRUCTURA FACTURA EN UN ARCHIVO TEXTO.
    ofstream salidaArchivo;
    salidaArchivo.open("Catalogo.txt", ios::out);
    if(!salidaArchivo.is_open()){
        cout<<"\nNo se pudo generar el archivo de catalogos. "<<endl;
    }else{
        for(int j=0; j<10; j++){
            salidaArchivo<<(fact + j)->titulo<<","<<(fact + j)->autor<<","<<(fact + j)->precio<<","<<(fact + j)->ejemplarV<<","<<(fact + j)->imagen<<endl;
        }
        salidaArchivo.close();
    }
    //GENERAR LA PAGINA CON LA TABLA
    ifstream entradaArchivo4("Catalogo.txt", ios::in);
    ofstream salidaArchivo2("Top10.html", ios::out);
    salidaArchivo2<<"<HTML> \n <TITLE> Top 10 Libros Vendidos </TITLE>"<<endl;
    salidaArchivo2<<"<TABLE BORDER=2 WIDTH=500>" <<endl;
    char *linea = new char[100];
    char *auxiliarTabla = new char[100];
    while(!entradaArchivo4.eof()){
        entradaArchivo4.getline(linea, 100);
        strcpy(auxiliarTabla, linea);
        strtok(auxiliarTabla, ",");
        salidaArchivo2<<"<TR>"<<endl;
        salidaArchivo2<<"<TD  width=250 BGCOLOR=""red"" >"<<auxiliarTabla<<"</TD>"<<endl;
        auxiliarTabla = strtok(NULL, ",");
        salidaArchivo2<<"<TR>"<<endl;
        salidaArchivo2<<"<TD  width=250 BGCOLOR=""red"" >"<<auxiliarTabla<<"</TD>"<<endl;
        auxiliarTabla = strtok(NULL, ",");
        salidaArchivo2<<"<TR>"<<endl;
        salidaArchivo2<<"<TD  width=250 BGCOLOR=""red"" >"<<auxiliarTabla<<"</TD>"<<endl;
        auxiliarTabla = strtok(NULL, ",");
        salidaArchivo2<<"<TR>"<<endl;
        salidaArchivo2<<"<TD  width=250 BGCOLOR=""red"" >"<<auxiliarTabla<<"</TD>"<<endl;
        auxiliarTabla = strtok(NULL, ",");
        salidaArchivo2<<"<TD BGCOLOR=""blue"">"<<"<IMG SRC="""<<auxiliarTabla<<""" WIDTH=250 HEIGHT=180 BORDER=2 VSPACE=3 HSPACE=3> </TD>"<<endl;
        salidaArchivo2<<"</TR>"<< endl;
    }
    salidaArchivo2<<"</TABLE>"<<endl;
    salidaArchivo2<<"</HTML>"<<endl;
    entradaArchivo4.close();
    salidaArchivo2.close();
    cout<<"\nSe genero la pagina HTML con la tabla del TOP 10 mas vendido. "<<endl;
}
void consultarLibro(MultiListaSucursal *listaSucursal){

    int opcion, cont = 0, aux = 1;
    char *titulo, *autor, *sucursal;
    titulo = new char[100];
    autor = new char[100];
    sucursal = new char[100];
    //DADO UN TITULO VERIFICA EN QUE SUCURSALES ESTA.
    //DADO UN AUTOR Y UNA SUCURSAL VERIFICA SI EL LIBRO EXISTE.
    cout<<"\nDigite el metodo de busqueda. ";
    cout<<"\n1. Por Titulo. ";
    cout<<"\n2. Por Autor. ";
    cout<<"\n3. Consultar ejemplares disponibles. ";
    cout<<"\nDigite una opcion. ";
    cin>> opcion;
    if(opcion == 1){
        cout<<"\nDigite el titulo del libro a consultar. ";
        cin.ignore();
        cin.getline(titulo, 100);
        MultiNodoSucursal *auxSucursal;
        auxSucursal = listaSucursal->cabeza;
        while(auxSucursal != NULL){
            MultiNodoGenero *auxGenero;
            auxGenero = auxSucursal->info->cabeza;
            while(auxGenero != NULL){
                NodoLibro *auxLibro;
                auxLibro = auxGenero->info->cabeza;
                while(auxLibro != NULL){
                    if(strcmp(auxLibro->info.nombre, titulo) == 0){
                        cout<<"\nEl libro: "<<auxLibro->info.nombre<<" se encuentra en la sucursal: "<<auxSucursal->nombre;
                        cout<<endl<<endl;
                        cont++;
                    }
                    auxLibro = auxLibro->siguiente;
                }
                auxGenero = auxGenero->siguiente;
            }
            auxSucursal = auxSucursal->siguiente;
        }
    }
    if(opcion == 2){
        cout<<"\nDigite el autor a buscar. ";
        cin.ignore();
        cin.getline(autor, 100);
        cout<<"\nDigite la sucursal en la cual quiere buscar. ";
        cin.getline(sucursal, 100);
        MultiNodoSucursal *auxSucursal;
        auxSucursal = listaSucursal->cabeza;
        while(auxSucursal != NULL){
            if(strcmp(auxSucursal->nombre,sucursal) == 0){
                MultiNodoGenero *auxGenero;
                auxGenero = auxSucursal->info->cabeza;
                while(auxGenero != NULL){
                    NodoLibro *auxLibro;
                    auxLibro = auxGenero->info->cabeza;
                    while(auxLibro != NULL){
                        if(strcmp(auxLibro->info.autor, autor) == 0){
                            cout<<"\nEl autor: "<<auxLibro->info.autor<<" tiene el siguiente libro en la sucursal: "<<auxSucursal->nombre<<endl;
                            cout<<"\nTitulo: "<<auxLibro->info.nombre;
                            cout<<"\nPrecio: "<<auxLibro->info.precio;
                            cout<<endl<<endl;
                            cont++;
                        }
                        auxLibro = auxLibro->siguiente;
                    }
                    auxGenero = auxGenero->siguiente;
                }
            }
            auxSucursal = auxSucursal->siguiente;
        }
    }
    if(opcion == 3){
        cout<<"\nDigite el titulo del libro a consultar. ";
        cin.ignore();
        cin.getline(titulo, 100);
        cout<<"\nDigite la sucursal para realizar la consulta. ";
        cin.getline(sucursal, 100);
        MultiNodoSucursal *auxSucursal;
        auxSucursal = listaSucursal->cabeza;
        while(auxSucursal != NULL){
            if(strcmp(auxSucursal->nombre, sucursal) == 0){
                MultiNodoGenero *auxGenero;
                auxGenero = auxSucursal->info->cabeza;
                while(auxGenero != NULL){
                    NodoLibro *auxLibro;
                    auxLibro = auxGenero->info->cabeza;
                    while(auxLibro != NULL){
                        if(strcmp(auxLibro->info.nombre, titulo) == 0){
                            if(auxLibro->info.cantidad > 0){
                                cout<<"\nEl libro: "<<titulo<<" tiene "<<auxLibro->info.cantidad<<" ejemplares disponibles en la sucursal "<<sucursal<<endl;
                                cont++;
                            }else{
                                cout<<"\nEl libro: "<<titulo<<" no tiene ejemplares disponibles en la sucursal "<<sucursal<<endl;
                                aux = 0;
                            }
                        }
                        auxLibro = auxLibro->siguiente;
                    }
                    auxGenero = auxGenero->siguiente;
                }
            }
            auxSucursal = auxSucursal->siguiente;
        }
    }
    if(aux == 0){
        MultiNodoSucursal *auxSucursal2;
        auxSucursal2 = listaSucursal->cabeza;
        while(auxSucursal2 != NULL){
            if((strcmp(auxSucursal2->nombre, sucursal) == 1) || (strcmp(auxSucursal2->nombre, sucursal) == -1)){
                    MultiNodoGenero *auxGenero2;
                    auxGenero2 = auxSucursal2->info->cabeza;
                    while(auxGenero2 != NULL){
                        NodoLibro *auxLibro2;
                        auxLibro2 = auxGenero2->info->cabeza;
                        while(auxLibro2 != NULL){
                            if(strcmp(auxLibro2->info.nombre, titulo) == 0){
                                if(auxLibro2->info.cantidad > 0){
                                    cout<<"\nEl libro consultado se puede encontrar en la sucursal "<<auxSucursal2->nombre<<" donde tiene "<<auxLibro2->info.cantidad<<" ejemplares disponibles. "<<endl;
                                    cont++;
                                }
                            }
                            auxLibro2 = auxLibro2->siguiente;
                        }
                        auxGenero2 = auxGenero2->siguiente;
                    }
            }
            auxSucursal2 = auxSucursal2->siguiente;
        }
    }
    if(cont == 0){
        cout<<"\nSu busqueda no obtuvo resultados. "<<endl;
    }
}
void consultarCompras(MultiListaSucursal *listaSucursal){

    int cont = 0;
    char *inicio, *fin, *auxiliar, *lineaEntrada;
    inicio = new char[20];
    fin = new char[20];
    auxiliar = new char[200];
    lineaEntrada = new char[200];
    cout<<"\nDigite la fecha inicial para consultar. ";
    cin.ignore();
    cin.getline(inicio, 20);
    cout<<"\nDigite la fecha final para consultar. ";
    cin.getline(fin, 20);
    ifstream entradaArchivo;
    entradaArchivo.open("Factura.txt", ios::in);
    if(!entradaArchivo.is_open()){
        cout<<"\nError en la apertura de las facturas. ";
    }else{
        while(!entradaArchivo.eof()){
            entradaArchivo.getline(lineaEntrada, 100);
            char *auxiliar = new char[100];
            strcpy(auxiliar, lineaEntrada);
            strtok(auxiliar, ",");
            if((strcmp(auxiliar,inicio) == 1) && (strcmp(auxiliar,fin) == -1) || (strcmp(auxiliar,inicio) == 0) || (strcmp(auxiliar, fin) == 0)){
                char *temp = new char [200];
                strcpy(temp,lineaEntrada);
                strtok(temp,",");
                temp = strtok(NULL,",");
                cout<<"Nombre Comprador: "<<temp<<endl;
                temp = strtok(NULL,",");
                cout<<"Titulo Libro: "<<temp<<endl;
                temp = strtok(NULL,",");
                cout<<"Autor Libro: "<<temp<<endl;
                temp = strtok(NULL,",");
                cout<<"Precio Libro: "<<temp<<endl;
                cont++;
                cout<<endl<<endl<<endl;
            }
        }
    }
    cout<<"\nLa cantidad de personas que compraron libros entre las fechas dadas es de: "<<cont<<endl;
}
void consultarIngresos(MultiListaSucursal *listaSucursal){

    char *inicio, *fin, *auxiliar, *lineaEntrada;
    inicio = new char[20];
    fin = new char[20];
    auxiliar = new char[200];
    lineaEntrada = new char[200];
    cout<<"\nDigite la fecha inicial para consultar. ";
    cin.ignore();
    cin.getline(inicio, 20);
    cout<<"\nDigite la fecha final para consultar. ";
    cin.getline(fin, 20);
    MultiNodoSucursal *auxSucursal;
    auxSucursal = listaSucursal->cabeza;
    while(auxSucursal != NULL){
        int cont = 0;
        ifstream entradaArchivo;
        entradaArchivo.open("Factura.txt", ios::in);
        if(!entradaArchivo.is_open()){
            cout<<"\nError en la apertura de las facturas. ";
        }else{
            while(!entradaArchivo.eof()){
                entradaArchivo.getline(lineaEntrada, 100);
                char *auxiliar = new char[100];
                strcpy(auxiliar, lineaEntrada);
                strtok(auxiliar, ",");
                if((strcmp(auxiliar,inicio) == 1) && (strcmp(auxiliar,fin) == -1) || (strcmp(auxiliar,inicio) == 0) || (strcmp(auxiliar, fin) == 0)){
                    char  *temp = new char [200];
                    strcpy(temp,lineaEntrada);
                    strtok(temp,",");
                    temp = strtok(NULL,",");
                    temp = strtok(NULL,",");
                    temp = strtok(NULL,",");
                    temp = strtok(NULL,",");
                    temp = strtok(NULL,",");
                    if(strcmp(temp, auxSucursal->nombre) == 0){
                        char *temp2 = new char[200];
                        int ingresos;
                        strcpy(temp2,lineaEntrada);
                        strtok(temp2, ",");
                        temp2 = strtok(NULL,",");
                        temp2 = strtok(NULL,",");
                        temp2 = strtok(NULL,",");
                        temp2 = strtok(NULL,",");
                        ingresos = atoi(temp2);
                        cont = cont + ingresos;
                    }
                }
            }
        }
        cout<<"las ventas de la sucursal "<<auxSucursal->nombre<<" en el rango de fechas ingresados fueron: "<<cont;
        auxSucursal = auxSucursal->siguiente;
        cout<<endl;
        cont = 0;
    }
}


