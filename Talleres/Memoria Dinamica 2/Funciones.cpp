#include <iostream>
#include "Funciones.h"

using namespace std;

int* numeros(int MAX, int *v){

    int cont = 1, *numero;
    for(int i=0; i<MAX; i++){
        int sirve = -1;
        if (i == 0) continue;
        for(int j=0; j<i; j++ ){
            if( *(v + j) == *(v + i) ){
                sirve = 1;
            }
        }
        if(sirve == -1){
            cont++;
        }
    }
    numero = new int[cont];
    int temp = 1;
    *(numero + 0) = *(v + 0);
    for(int i=1; i<MAX; i++){
        int sirve = -1;
        for(int j=0; j<i; j++){
            if( *(v + j) == *(v + i) ){
                sirve = 1;
            }
        }
        if(sirve == -1){
            *(numero + temp) = *(v + i);
            temp++;
        }
    }
    cout<<"\nEl vector V es: "<<endl;
    for(int i=0; i<MAX; i++){
        cout<<*(v + i)<<"  ";
    }
    cout<<endl<<endl;
    cout<<"\nEl vector NUMERO es: "<<endl;
    for(int i=0; i<cont; i++){
        cout<<*(numero + i)<<"  ";
    }
    cout<<endl<<endl;
    return numero;
}
int *ocurrencias(int MAX, int *v, int *numero){

    int *numerocur, cont = 1;
    for(int i=0; i<MAX; i++){
        int sirve = -1;
        if (i == 0) continue;
        for(int j=0; j<i; j++ ){
            if( *(v + j) == *(v + i) ){
                sirve = 1;
            }
        }
        if(sirve == -1){
            cont++;
        }
    }
    numerocur = new int[cont];
    for(int i=0; i<cont; i++){
        int temp1 = 0;
        for (int j=0; j<MAX; j++){
            if(*(numero + i) == *(v + j)){
                temp1++;
            }
        }
        *(numerocur + i) = temp1;
    }
    cout<<"\nEl vector NUMERO_OCURRENCIAS es: "<<endl;
    for(int i=0; i<cont; i++){
        cout<<*(numerocur + i)<<"  ";
    }
    cout<<endl<<endl;
    return numerocur;
}
int ***matriz(int MAX, int *v, int *numero, int *numerocur){

    int ***pos;
    int cont = 1;
    for(int i=0 ; i<MAX ; i++){
        int sirve = -1;
        if (i == 0) continue;
        for(int j=0 ; j<i ; j++ ){
            if( *(v+j) == *(v+i) ){
                sirve = 1;
            }
        }
        if(sirve == -1){
            cont++;
        }
    }
    int mayor=0;
    for( int i=0 ;i<cont ; i++){
        if( *(numerocur+i) > mayor){
            mayor = *(numerocur+i);
        }
    }
    pos = new int**[cont];
    for(int i=0; i<cont; i++){
        *(pos + i) = new int*[mayor];
    }
    for(int i=0; i<mayor; i++){
        for(int j=0; j<cont; j++){
            *(*(pos + i) + j) = NULL;
        }
    }
    for(int j=0; j<cont; j++){
      for(int i=0; i<mayor; i++){
        do{
         for(int k=0; k<MAX; k++){
            if(*(numero + j) == *(v + k)){
                *(*(pos + i) + j) = (v + k);
                i++;
            }
         }
        }while(i < *(numerocur + j));
      }
    }
    cout<<"\nEl vector V con sus valores, indices y direcciones. "<<endl;
    cout<<"\nValor"<<"\t"<<"Indice"<<"\t"<<"Direccion"<<endl;
    for(int i=0; i<MAX; i++){
        cout<<*(v + i)<<"\t"<<i<<"\t"<<(v + i)<<endl;
    }
    cout<<endl<<endl;
    cout<<"\nLa matriz POS que contiene las direcciones del vector V es: "<<endl;
    for(int i=0; i<mayor; i++){
        cout<<endl;
        for(int j=0; j<cont; j++){
            cout<<*(*(pos + i) + j)<<"\t";
            if(*(*(pos + i) + j) == NULL){
                cout<<"        ";
            }
        }
    }
    cout<<endl<<endl;
    return pos;
}
void ordenar(int MAX, int *v, int *numero, int *numerocur, int ***pos){

    int cont = 1;
    for(int i=0 ; i<MAX ; i++){
        int sirve = -1;
        if (i == 0) continue;
        for(int j=0 ; j<i ; j++ ){
            if( *(v+j) == *(v+i) ){
                sirve = 1;
            }
        }
        if(sirve == -1){
            cont++;
        }
    }
    int mayor=0;
    for( int i=0 ;i<cont ; i++){
        if( *(numerocur+i) > mayor){
            mayor = *(numerocur+i);
        }
    }
    cout<<"\nEl vector V ordenado de menor a mayor es: ";
    for(int i=0; i<MAX; i++){
        cout<<*(v + i)<<"\t";
    }
    cout<<endl<<endl;
}

