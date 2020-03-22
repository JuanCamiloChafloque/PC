#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstring>
#include <string.h>
#include <fstream>
#include "Funciones.h"
using namespace std;
void imprimirArchivo(Empleado *empleado, Empleado *archivoSalida, int cont){

    //GENERAR EL ARCHIVO BINARIO CON EL NOMBRE CODIGO Y CELULAR DE LOS EMPLEADOS.
    ofstream salidaArchivo("DatosB.dat", ios::binary);
    strcpy((archivoSalida + 0)->codigo, "1021");
    strcpy((archivoSalida + 0)->apellido, "Zapata Diaz");
    strcpy((archivoSalida + 0)->nombre, "Teresa");
    strcpy((archivoSalida + 0)->celular, "3102114426");
    strcpy((archivoSalida + 1)->codigo, "1064");
    strcpy((archivoSalida + 1)->apellido, "Sanchez Gomez");
    strcpy((archivoSalida + 1)->nombre, "Elizabeth");
    strcpy((archivoSalida + 1)->celular, "3164201520");
    strcpy((archivoSalida + 2)->codigo, "1052");
    strcpy((archivoSalida + 2)->apellido, "Correa Cruz");
    strcpy((archivoSalida + 2)->nombre, "Carolina");
    strcpy((archivoSalida + 2)->celular, "3000284740");
    strcpy((archivoSalida + 3)->codigo, "1033");
    strcpy((archivoSalida + 3)->apellido, "Arias Mendez");
    strcpy((archivoSalida + 3)->nombre, "Adriana");
    strcpy((archivoSalida + 3)->celular, "3174850043");
    strcpy((archivoSalida + 4)->codigo, "1005");
    strcpy((archivoSalida + 4)->apellido, "Duarte Garcia");
    strcpy((archivoSalida + 4)->nombre, "Diana Maria");
    strcpy((archivoSalida + 4)->celular, "3165346171");
    salidaArchivo.write((char*)(archivoSalida + 0), sizeof(Empleado));
    salidaArchivo.write((char*)(archivoSalida + 1), sizeof(Empleado));
    salidaArchivo.write((char*)(archivoSalida + 2), sizeof(Empleado));
    salidaArchivo.write((char*)(archivoSalida + 3), sizeof(Empleado));
    salidaArchivo.write((char*)(archivoSalida + 4), sizeof(Empleado));
    salidaArchivo.close();
    int i = 0;
    //LEER EL ARCHIVO BINARIO DE LOS EMPLEADOS.
    ifstream entradaArchivo("DatosB.dat", ios::binary);
    if(!entradaArchivo.is_open()){
        cout<<"\nError en la apertura del Archivo. "<<endl;
    }else{
        while(!entradaArchivo.eof()){
            entradaArchivo.read((char*)(empleado + i), sizeof(Empleado));
            i++;
        }
    }
    entradaArchivo.close();
    for(int i=0; i<5; i++){
        cout<<"\nCodigo: "<<(empleado + i)->codigo;
        cout<<"\nApellido: "<<(empleado + i)->apellido;
        cout<<"\nNombre: "<<(empleado + i)->nombre;
        cout<<"\nCelular: "<<(empleado + i)->celular<<endl;
    }
    cout<<endl<<endl<<endl;
}
void generarArchivo(Empleado *empleado, int cont){

    Empleado *auxiliar;
    auxiliar = new Empleado;
    ofstream escribirArchivo;
    escribirArchivo.open("datos.txt", ios::out);
    for(int i=0; i<cont - 1; i++){
        for(int j=i+1; j<cont; j++){
            if(strcmp((empleado + i)->apellido,(empleado + j)->apellido) == 1){
                  *auxiliar = *(empleado + i);
                  *(empleado + i) = *(empleado + j);
                  *(empleado + j) = *auxiliar;
            }
        }
    }
    for(int i=0; i<cont; i++){
        escribirArchivo<<(empleado + i)->apellido<<", "<<(empleado + i)->nombre<<", "<<(empleado + i)->celular<<endl;
    }
    escribirArchivo.close();
    cout<<"\nArchivo alfabetico creado exitosamente. "<<endl<<endl;
}
void adicionarEmpleado(Empleado *aux, Empleado *empleado, int cont){

    cout<<"\nDigite el codigo del nuevo empleado. ";
    cin>> aux->codigo;
    cout<<"\nDigite el apellido del nuevo empleado. ";
    cin>> aux->apellido;
    cout<<"\nDigite el nombre del nuevo empleado. ";
    cin>> aux->nombre;
    cout<<"\nDigite el celular del nuevo empleado. ";
    cin>> aux->celular;
    strcpy((empleado + cont)->codigo, aux->codigo);
    strcpy((empleado + cont)->apellido, aux->apellido);
    strcpy((empleado + cont)->nombre, aux->nombre);
    strcpy((empleado + cont)->celular, aux->celular);
    ofstream salidaArchivo("DatosB.dat", ios::binary);
    salidaArchivo.write((char*) aux, sizeof(Empleado));
    salidaArchivo.close();
    cout<<"\nSe agrego a la lista binaria el nuevo empleado. "<<endl<<endl;
    cont++;
}
