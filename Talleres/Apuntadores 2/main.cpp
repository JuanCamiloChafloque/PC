#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#include <time.h>

using namespace std;

void unionn (int a[], int b[], int tamm, int tamn);
void interseccion(int a[], int b[], int tamm, int tamn);
void diferencia(int a[], int b[], int tamm, int tamn);
void intercalar(int a[], int b[], int tamm, int tamn);
int main()
{
    int opcion, a[10], b[10], tamm, tamn, i;
    //SE DIGITAN LOS TAMAÑOS RESPECTIVOS DE LOS VECTORES A Y B.
    cout<<"\nDigite el tamaño del vector A. ";
    cin>> tamm;
    cout<<"\nDigite el tamaño del vector B. ";
    cin>> tamn;
    srand(time(0));
    //SE GENERAN LOS VECTORES A Y B CON NUMEROS ALEATORIOS DEL 1 AL 10.
    for(i=0; i<tamm; i++){
          *(a+i) = (1 + rand() % 10);
    }
    for(i=0; i<tamn; i++){
          *(b+i) = (1 + rand() % 10);
    }
    //SE IMPRIMEN LOS VECTORES A Y B CON SUS NUMEROS ALEATORIOS.
    cout<<"\nEl vector A es: ";
    for(i=0; i<tamm; i++){
        cout<<*(a+i)<<"  ";
    }
    cout<<endl<<endl;
    //SE GENERA EL VECTOR B ALEATORIAMENTE.
    cout<<"\nEl vector B es: ";
    for(i=0; i<tamn; i++){
        cout<<*(b+i)<<"  ";
    }
    cout<<endl<<endl;
    //SE GENERA UN MENU QUE PERMITA AL USUARIO REALIZAR CUALQUIERA DE LOS PUNTOS HECHOS.
    do{
    cout<<"\n1. Generar Union. ";
    cout<<"\n2. Generar Interseccion. ";
    cout<<"\n3. Generar Diferencia. ";
    cout<<"\n4. Ordenar e intercalar vectores. ";
    cout<<"\n5. Salir. "<<endl;
    cout<<"\nDigite una opcion. ";
    cin>> opcion;
      switch(opcion){

            case 1: unionn(a, b, tamm, tamn);
                    break;

            case 2: interseccion(a, b, tamm, tamn);
                    break;

            case 3: diferencia(a, b, tamm, tamn);
                    break;

            case 4: intercalar(a,b,tamm,tamn);
                    break;

            case 5: break;
            default: break;
      }
    }while(opcion != 5);
    return 0;
}
// FUNCION PARA EL PUNTO 2: GENERAR EN EL VECTOR C LA UNION DEL VECTOR A CON EL VECTOR B.
void unionn(int a[], int b[], int tamm, int tamn){

    int i, j, c[20],k = 0;


    cout<<"\nLa union de los vectores A y B en el vector C es: ";
    //LOS VALORES DEL VECTOR A SON PUESTOS EN EL NUEVO VECTOR C.
    for(i=0; i<tamm; i++){
            *(c+k) = *(a+i);
            k++;
    }
    //LOS VALORES DEL VECTOR B SON PUESTOS EN EL NUEVO VECTOR C.
    for(i=0; i<tamn; i++){
            *(c+k) = *(b+i);
            k++;
    }
    //SE IMPRIME EL NUEVO VECTOR C CON LA UNION.
    for(i=0; i<k; i++){
        cout<<*(c+i)<<"  ";
    }
    cout<<endl<<endl;
}

//FUNCION PARA EL PUNTO 2: GENERAR EN EL VECTOR D LA INTERSECCION DEL VECTOR A CON EL VECTOR B.
void interseccion(int a[], int b[], int tamm, int tamn){

    int i, j, k = 0, d[20], aux, cont = 0;

    //DEPENDIENDO SI LOS VALORES ENTRE VECTORES SON IGUALES, ESTE SE GUARDARA EN EL NUEVO VECTOR D.
    cout<<"\nLa interseccion de los vectores A y B en el vector D es: ";
    for(i=0; i<tamm ; i++){
       for(j=0; j<tamn; j++){
            if(*(a+i) == *(b+j)){
                  *(d+k) = *(a+i);
                  k++;
                  break;
            }
       }
    }
    //FOR QUE ELIMINARA ELEMENTOS REPETIDOS DEL NUEVO VECTOR D.
    for(i=0; i<k-1; i++){
        for(j=i+1; j<k; j++){
            if(*(d+i) == *(d+j)){
                for(aux=j; aux<k-1; aux++){
                        cont = *(d+j);
                        *(d+j) = *(d+(j+1));
                        *(d+(j+1)) = cont;
                }
                k--;
                j--;
            }
        }
    }

    //SE IMPRIME EL VECTOR D CON LA INTERSECCION DE LOS VECTORES A Y B.
    for(i=0; i<k; i++){
        cout<<*(d+i)<<"  ";
    }
    //EN CASO DE QUE NO HAYAN VALORES DE A Y B EN COMUN.
    if(k == 0){
        cout<<"\nNo hay interseccion entre los vectores A y B. ";
    }
    cout<<endl<<endl;
}
//FUNCION PARA EL PUNTO 2: GENERAR EN EL VECTOR E LA DIFERENCIA DEL VECTOR A CON EL VECTOR B.
void diferencia(int a[], int b[], int tamm, int tamn){

    int i, j, k = 0, e[20], cont = 0, aux;

    //DEPENDIENDO SI EL VALOR DEL VECTOR A CON RESPECTO AL VECTOR B SON DIFERENTES ESTE SE GUARDARA EN EL NUEVO VECTOR E.
    cout<<"\nLa diferencia de los vectores A y B en el vector E es: ";
    for(i=0; i<tamm; i++){
       for(j=0; j<tamn; j++){
            if(*(a+i) != *(b+j)){
                    cont++;
            }
       }
       if(cont == tamn){
                *(e+k) = *(a+i);
                k++;
       }
       cont = 0;
    }
    cont = 0;
    //FOR QUE ELIMINARA ELEMENTOS REPETIDOS DEL NUEVO VECTOR E.
    for(i=0; i<k-1; i++){
        for(j=i+1; j<k; j++){
            if(*(e+i) == *(e+j)){
                for(aux=j; aux<k-1; aux++){
                        cont = *(e+j);
                        *(e+j) = *(e+(j+1));
                        *(e+(j+1)) = cont;
                }
                k--;
                j--;
            }
        }
    }
    //SE IMPRIME EL VECTOR E CON LA DIFERENCIA DEL VECTOR A Y B.
    for(i=0; i<k; i++){
        cout<<*(e+i)<<"  ";
    }
    //EN CASO DE QUE TODOS LOS VALORES DE A ESTEN EN B.
    if(k == 0){
        cout<<"\nNo hay diferencia entre los vectores A y B. ";
    }
    cout<<endl<<endl;
}
//FUNCION PARA EL PUNTO 1: INTERCALAR DE MAYOR A MENOR LOS VECTORES A Y B EN EL NUEVO VECTOR C.
void intercalar(int a[], int b[], int tamm, int tamn){

    int i, j, c[20], aux, k = 0, numi = 0, numj = 0;

    //EL VECTOR A SE ORDENA DE MENOR A MAYOR.
    for(i=0; i<tamm-1; i++){
        for(j=i+1; j<tamm; j++){
            if(*(a+i) > *(a+j)){
                    aux = *(a+i);
                    *(a+i) = *(a+j);
                    *(a+j) = aux;
            }
        }
    }
    //EL VECTOR B SE ORDENA DE MENOR A MAYOR.
    for(i=0; i<tamn-1; i++){
        for(j=i+1; j<tamn; j++){
            if(*(b+i) > *(b+j)){
                    aux = *(b+i);
                    *(b+i) = *(b+j);
                    *(b+j) = aux;
            }
        }
    }
    //SE COMIENZAN A INTERCALAR LOS VECTORES A Y B, PONIENDO EN EL VECTOR C LOS VALORES DE LOS VECTORES DE MENOR A MAYOR.
    do{
        if((*(a+numi) < *(b+numj)) ||(*(a+numi) == *(b+numj))){
            *(c+k) = *(a+numi);
            k++;
            numi++;
        }
        if(*(b+numj) < *(a+numi)){

                    *(c+k) = *(b+numj);
                    k++;
                    numj++;
        }
        if(numj == tamn){
            for(i=numi; i<tamm; i++){
                *(c+k) = *(a+i);
                k++;
            }
        }
        if(numi == tamm){
            for(i=numj; i<tamn; i++){
                *(c+k) = *(b+i);
                k++;
            }
        }
    }while(k !=(tamm+tamn));
    //SE IMPRIME EL VECTOR C CON LOS VALORES DE LOS VECTORES A Y B INTERCALADOS DE MENOR A MAYOR.
    cout<<"\nEl vector A y B intercalado en el vector C de menor a mayor es: ";
    for(i=0; i<k; i++){
        cout<<*(c+i)<<"  ";
    }
    cout<<endl<<endl;
}



