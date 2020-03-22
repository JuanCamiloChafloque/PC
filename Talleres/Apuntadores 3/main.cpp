#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int* generar(int num);
int* primosnull(int num, int *numeros);
void primos(int num, int *apuntprimos);
int main()
{
    int opcion, num, *perrin, *perrin2;
    cout<<"\nDigite cuantos numeros de perrin quiere mostrar. ";
    cin>> num;
    do{
       cout<<"\n1. Generar los numeros de Perrin. ";
       cout<<"\n2. Mostrar los numeros primos de Perrin. ";
       cout<<"\n3. Mostrar los numeros primos de Perrin sin NULL. ";
       cout<<"\n4. Salir. ";
       cout<<"\nDigite una opcion. "<<endl;
       cin>> opcion;
       switch(opcion){

            case 1: perrin = generar(num);
                    break;

            case 2: perrin2 = primosnull(num, perrin);
                    break;

            case 3: primos(num, perrin2);
                    break;

            case 4:break;
            default: break;

       }

    }while(opcion != 4);
    return 0;
}

int* generar(int num){

    system("cls");
    int i, *numeros;
    numeros = new int [num];
    //SE INICIALIZAN LAS PRIMERAS TRES POSICIONES DEL VECTOR CON LOS VALORES CONSTANTES.
    *(numeros + 0) = 3;
    *(numeros + 1) = 0;
    *(numeros + 2) = 2;
    //CON LA FORMULA DE PERRIN SE GENERAN LOS DEMAS VALORES DE LOS NUMEROS DE PERRIN.
    for(i=3; i<num; i++){
        *(numeros + i) = *(numeros + (i-2)) + *(numeros + (i-3));
    }
    //SE IMPRIMEN LOS PRIMEROS N NUMEROS DE PERRIN.
    cout<<"\nLos primeros "<<num<<" numeros de Perrin son: "<<endl<<endl;
    for(i=0; i<num; i++){
        cout<<*(numeros + i)<<"  ";
    }
    cout<<endl<<endl;
    system("pause");
    return numeros;
}

int* primosnull(int num, int *numeros){

    system("cls");
    int i, *apuntprimos, k = 0;
    apuntprimos = new int[num];
    //SE INICIALIZA EL VECTOR APUNTPRIMOS PARA QUE APUNTE A NULL.
    for(i=0; i<num; i++){
        *(apuntprimos + i) = NULL;
    }
    //DEPENDIENDO DE CIERTAS CONDICIONES SE GUARDAN EN EL VECTOR APUNTPRIMOS LOS NUMEROS PRIMOS DE PERRIN.
    for(i=2; i<num; i++){
        if((*(numeros + i) % i == 0) && (*(numeros + i) >= i)){
            *(apuntprimos + k) = *(numeros + i);
            k++;
        }
    }
    //SE IMPRIME EL VECTOR APUNTRIMOS CON LOS NUMEROS PRIMOS DE PERRIN Y LAS POSICIONES SOBRANTES CON NULL.
    cout<<"\nEl arreglo APUNTADORPRIMOS con los numeros primos de Perrin es: "<<endl;
    for(i=0; i<num; i++){
        cout<<*(apuntprimos + i)<<"  ";
    }
    cout<<endl<<endl;
    system("pause");

    delete numeros;
    return apuntprimos;
}

void primos(int num, int *apuntprimos){

    system("cls");
    int i, cont = 0;
    //SE CREA UN CONTADOR QUE GUARDE EL NUMERO DE POSICIONES DEL VECTOR APUNTPRIMOS QUE ESTAN APUNTANDO A NULL.
    for(i=0; i<num; i++){
        if(*(apuntprimos + i) == NULL){
            cont++;
        }
    }
    //SE IMPRIME EL VECTOR APUNTPRIMOS CON UN NUEVO TAMAÑO SIN LAS POSICIONES DE NULL.
    cout<<"\nEl vector APUNTADORPRIMOS sin los NULL es: "<<endl;
    for(i=0; i<(num-cont); i++){
        cout<<*(apuntprimos + i)<<"  ";
    }
    cout<<endl<<endl;

    delete apuntprimos;

    system("pause");
}

