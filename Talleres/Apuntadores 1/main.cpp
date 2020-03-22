#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
    int *p[10];
    int datos[10], i, j , *aux;
    srand(time(0));

    for(i=0; i<10; i++){
        datos[i] = (1 + rand() % 100);
    }

    cout<<"\nEl vector datos con los numeros aleatorios es: ";
    for(i=0; i<10; i++){
        cout<<*(datos+i)<<"   ";
    }
    cout<<endl<<endl;

    cout<<"\nEl vector con las direcciones de los datos es: "<<endl;
    for(i=0; i<10; i++){
        cout<<(datos+i)<<endl;
    }
    cout<<endl<<endl;



    for(i=0; i<10; i++){
        *(p+i) = (datos+i);
    }

    cout<<"\nLos valores del vector apuntador son: "<<endl;
    for(i=0; i<10; i++){
        cout<<*(p+i)<<endl;
    }
    cout<<endl<<endl;

    cout<<"\nLos valores del vector datos con respecto al vector apuntador son: "<<endl;
    for(i=0; i<10; i++){
        cout<<**(p+i)<<"   ";
    }
    cout<<endl<<endl;

    for(i=0; i<9; i++){
        for(j=i+1; j<10; j++){
            if(**(p+i) > **(p+j)){
             aux = *(p+i);
             *(p+i) = *(p+j);
             *(p+j) = aux;
            }
        }
    }

    cout<<"\nEl vector datos ordenado desde el vector apuntador es: "<<endl;
    for(i=0; i<10; i++){
        cout<<**(p+i)<<"   ";
    }
    cout<<endl<<endl;

    cout<<"\nPara comprobar que el vector datos original no se modifico: "<<endl;
    for(int i=0;i<10; i++){
        cout<<*(datos+i)<<"   ";
    }
    cout<<endl<<endl;

    return 0;
}




