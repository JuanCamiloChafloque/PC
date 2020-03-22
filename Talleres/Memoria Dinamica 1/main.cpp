#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

int main()
{
    int i, j, N, cifras, *numeros, exp, **matriz, mod, k = 0;
    cout<<"\nDigite el numero de cifras (MAX: 3) para los elementos del vector. ";
    cin>> cifras;
    cout<<"\nDigite la longitud del vector. ";
    cin>> N;
    numeros = new int[N];
    matriz = new int*[10];
    for(i=0; i<10; i++){
        matriz[i] = new int[N];
    }
    srand(time(0));
    //VARIABLE PARA PODER GENERAR LOS NUMEROS ALEATORIOS CON LAS CIFRAS DESEADAS.
    exp = pow(10,cifras);
    //SE CREAN ALEATORIAMENTE LOS VALORES ENTEROS DEL VECTOR NUMEROS DEPENDIENDO DEL NUMERO DE CIFRAS QUE SE PREGUNTÓ.
    for(i=0; i<N; i++){
        *(numeros + i) = (1 + rand() % exp);
    }
    //SE IMPRIMEN LOS VALORES ALEATORIOS DEL VECTOR.
    cout<<"\nLos numeros del vector son: ";
    for(i=0; i<N; i++){
        cout<<*(numeros + i)<<"   ";
    }
    cout<<endl<<endl;
    //SE INICIALIZA LA MATRIZ EN NULL.
    for(i=0; i<10; i++){
        for(j=0; j<N; j++){
            *(*(matriz + i) + j) = NULL;
        }
    }
    //SE RECORRE EL VECTOR Y SE UBICAN LOS VALORES EN LA MATRIZ (POR FILA) DEPENDIENDO DE SUS UNIDADES.
    for(i=0; i<N; i++){
        mod = (*(numeros + i) % 10);
        if(*(*(matriz + mod) + k) == NULL){
            *(*(matriz + mod) + k) = *(numeros + i);
        }else{
            do{
                k++;
            }while(*(*(matriz + mod) + k) != NULL);
            *(*(matriz + mod) + k) = *(numeros + i);
            k = 0;
         }
    }
    cout<<"\nLa matriz ordenada con los numeros dependiendo de sus unidades: "<<endl;
    for(i=0; i<10; i++){
            cout<<endl;
        for(j=0; j<N; j++){
            cout<<*(*(matriz + i) + j)<<"\t";
        }
    }
    cout<<endl<<endl;
    //SE RECORRE LA MATRIZ POR FILAS Y SE TRASLADAN AL VECTOR.
    k = 0;
    for(i=0; i<10; i++){
        for(j=0; j<N; j++){
            if(*(*(matriz + i) + j) != NULL){
                *(numeros + k) = *(*(matriz + i) + j);
                k++;
            }
        }
    }
    cout<<"\nEl vector NUMEROS ordenado dependiendo de sus unidades: ";
    for(i=0; i<N; i++){
        cout<<*(numeros + i)<<"  ";
    }
    cout<<endl<<endl;
    k = 0;
    //SE UBICAN LOS VALORES DEL VECTOR EN LA MATRIZ (POR FILA) DEPENDIENDO DE LAS DECENAS QUE TIENE EL NUMERO.
    for(i=0; i<10; i++){
        for(j=0; j<N; j++){
            *(*(matriz + i) + j) = NULL;
        }
    }
    int var = 0, dec = 0;
    for(i=0; i<N; i++){
        mod = (*(numeros + i) % 10);
        var = ((*(numeros + i)) - mod);
        var = var % 100;
        dec = var / 10;
        if(*(*(matriz + dec) + k) == NULL){
            *(*(matriz + dec) + k) = *(numeros + i);
        }else{
            do{
                k++;
            }while(*(*(matriz + dec) + k) != NULL);
            *(*(matriz + dec) + k) = *(numeros + i);
            k = 0;
         }
    }
    cout<<"\nLa matriz ordenada con los numeros dependiendo de sus decenas: "<<endl;
    for(i=0; i<10; i++){
            cout<<endl;
        for(j=0; j<N; j++){
            cout<<*(*(matriz + i) + j)<<"\t";
        }
    }
    cout<<endl<<endl;
    //SE RECORRE LA MATRIZ POR FILAS Y SE TRASLADAN AL VECTOR NUEVAMENTE.
    k = 0;
    for(i=0; i<10; i++){
        for(j=0; j<N; j++){
            if(*(*(matriz + i) + j) != NULL){
                *(numeros + k) = *(*(matriz + i) + j);
                k++;
            }
        }
    }
    cout<<"\nEl vector NUMEROS ordenado dependiendo de sus decenas: ";
    for(i=0; i<N; i++){
        cout<<*(numeros + i)<<"  ";
    }
    cout<<endl<<endl;
    k = 0;
    //SE UBICAN LOS VALORES DEL VECTOR EN LA MATRIZ (POR FILA) DEPENDIENDO DE LAS CENTENAS QUE TIENE EL NUMERO.
    for(i=0; i<10; i++){
        for(j=0; j<N; j++){
            *(*(matriz + i) + j) = NULL;
        }
    }
    int cent = 0;
    for(i=0; i<N; i++){
        mod = (*(numeros + i) % 10);
        var = ((*(numeros + i)) - mod);
        var = var % 100;
        dec = var / 10;
        var = ((*(numeros + i)) - (dec * 10) - mod);
        cent = var / 100;
        if(*(*(matriz + cent) + k) == NULL){
            *(*(matriz + cent) + k) = *(numeros + i);
        }else{
            do{
                k++;
            }while(*(*(matriz + cent) + k) != NULL);
            *(*(matriz + cent) + k) = *(numeros + i);
            k = 0;
         }
    }
    cout<<"\nLa matriz ordenada con los numeros dependiendo de sus centenas: "<<endl;
    for(i=0; i<10; i++){
            cout<<endl;
        for(j=0; j<N; j++){
            cout<<*(*(matriz + i) + j)<<"\t";
        }
    }
    cout<<endl<<endl;
    //SE RECORRE LA MATRIZ POR FILAS Y SE TRASLADAN AL VECTOR.
    k = 0;
    for(i=0; i<10; i++){
        for(j=0; j<N; j++){
            if(*(*(matriz + i) + j) != NULL){
                *(numeros + k) = *(*(matriz + i) + j);
                k++;
            }
        }
    }
    //SE IMPRIME EL VECTOR CON LOS VALORES ORDENADOS DE MENOR A MAYOR.
    cout<<"\nEl vector NUMEROS final ordenado de menor a mayor es: ";
    for(i=0; i<N; i++){
        cout<<*(numeros + i)<<"  ";
    }
    cout<<endl<<endl;
    for(i=0; i<N; i++){
        delete (matriz + i);
    }
    delete matriz;
    delete numeros;
    return 0;
}
