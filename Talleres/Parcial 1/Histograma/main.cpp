#include <iostream>
#include <stdlib.h>

using namespace std;
void histograma(int *visitas, int tam);
int main()
{
    int tam, *visitas;
    cout<<"\nDigite el tamaño del vector visitas. ";
    cin>> tam;
    visitas = new int[tam];
    for(int i=0; i<tam; i++){
        cout<<"\nDigite el numero de visitas que obtuvo la pagina web por dia. ";
        cin>> *(visitas + i);
    }
    cout<<"\nEl vector de visitas es: ";
    for(int i=0; i<tam; i++){
        cout<<*(visitas + i)<<"\t";
    }
    cout<<endl;
    histograma(visitas, tam);
    return 0;
}
void histograma(int *visitas, int tam){

    char **matriz;
    int mayor = 0, may = 0, k = 0;

    for(int i=0; i<tam; i++){
        if(*(visitas + i) > mayor){
            mayor = *(visitas + i);
        }
    }
    matriz = new char *[tam];
    for(int i=0; i<tam; i++){
        *(matriz + i) = new char[mayor - 1];
    }
    for(int i=0; i<mayor; i++){
        for(int j=0; j<tam; j++){
            *(*(matriz + i) + j) = NULL;
        }
    }
    may = mayor;
    k = (mayor - 1);
    do{
        for(int i=0; i<tam; i++){
            if(*(visitas + i) == mayor){
                if(*(*(matriz + k) + i) == NULL){
                    *(*(matriz + k) + i) = '*';
                    *(visitas + i) = (mayor - 1);
                }else{
                    do{
                        k--;
                    }while(*(*(matriz + k) + i) != NULL);
                    *(*(matriz + k) + i) = '*';
                    *(visitas + i) = (mayor - 1);
                    k = (may - 1);
                }
            }
        }
        mayor--;
    }while(mayor > 0);
    for(int i=0; i<may; i++){
        cout<<endl;
        for(int j=0; j<tam; j++){
            cout<<*(*(matriz + i) + j)<<"\t";
        }
    }
    for(int i=0; i<tam; i++){
        delete (matriz + i);
    }
    delete matriz;
}
