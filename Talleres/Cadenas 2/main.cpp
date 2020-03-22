#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;
void calcularHoja(char ***hojaInicial, int tamC, int tamF, int **hojaFinal);
int main()
{
    char ***hojaInicial;
    int **hojaFinal, tamC, tamF;
    char F,C;

    cout<<"\nDigite el tamaño de columnas de la hoja de calculo. ";
    cin>> tamC;
    cout<<"\nDigite el tamaño de filas de la hoja de calculo. ";
    cin>> tamF;
    hojaInicial = new char **[tamC];
    for(int i=0; i<tamC; i++){
        *(hojaInicial + i) = new char *[tamF];
    }
    for(int i=0; i<tamF; i++){
        for(int j=0; j<tamC; j++){
            (*(*(hojaInicial + i) + j)) = new char[30];
        }
    }
    for(int i=0; i<tamF; i++){
        for(int j=0; j<tamC; j++){
            *(*(*(hojaInicial + i) + j)) = '\0';
        }
    }

    F='1';
    for(int i=0; i<tamF; i++){
        C='A';
        for(int j=0; j<tamC; j++){
            cin.ignore();
            cout<<"\nDigite los valor de la posicion "<<C<<F<<": ";
            cin.getline((*(*(hojaInicial + i) + j)), 20);
            C++;
        }
        F++;
    }
    for(int i=0; i<tamF; i++){
        cout<<endl;
        for(int j=0; j<tamC; j++){
            cout<<(*(*(hojaInicial + i) + j))<<"\t";
        }
    }
    cout<<endl;
    calcularHoja(hojaInicial, tamC, tamF, hojaFinal);

    return 0;
}
void calcularHoja(char ***hojaInicial, int tamC, int tamF, int **hojaFinal){

    hojaFinal = new int *[tamC];
    for(int i=0; i<tamC; i++){
        *(hojaFinal + i) = new int[tamF];
    }
    for(int i=0; i<tamF; i++){
        for(int j=0; j<tamC; j++){
            *(*(hojaFinal + i) + j) = NULL;
        }
    }
    for(int i=0; i<tamF; i++){
        for(int j=0; j<tamC; j++){
            if( *(*(*(hojaInicial + i) + j)) == '='){
                int N = 0;
                char *temp;
                (*(*(hojaInicial + i) + j))=strtok((*(*(hojaInicial + i) + j)),"=+");
                while(  (*(*(hojaInicial + i) + j)) != NULL ){
                    char *T;
                    int C;
                    int F;
                    temp = (*(*(hojaInicial + i) + j));
                    T = temp;
                    if( *T>= '0' && *T<= '9'){
                        F= atoi(T);
                        N = N + F;
                        (*(*(hojaInicial + i) + j)) = strtok(NULL,"=+ ");
                        system("pause");
                        continue;
                    }
                    C = *T-'A';
                    F= *(T+1)-'1';
                    N= N  + *(*(hojaFinal + F) + C);
                    (*(*(hojaInicial + i) + j)) = strtok(NULL,"=+ ");
                }
                *(*(hojaFinal + i) + j) = N;
            }
            else{
                *(*(hojaFinal + i) + j) = atoi( (*(*(hojaInicial + i) + j)) );
            }
        }
    }
    for(int i=0; i<tamF; i++){
        cout<<endl;
        for(int j=0; j<tamC; j++){
            cout<<*(*(hojaFinal + i) + j)<<"\t";
        }
    }
}
