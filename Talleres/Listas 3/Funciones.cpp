#include <iostream>
#include <stdlib.h>
#include "Funciones.h"

using namespace std;

void imprimir(Lista *listap1, Lista *listap2){

    cout<<"La informacion del conjunto #1 es:"<<endl;
    Nodo * aux;
    aux = listap1->cab;
    int pos = 1;
    while(aux != NULL){
        cout<<"Info "<<pos<<": "<<aux->info<<endl;
        aux = aux->sig;
        pos++;
         }
    cout<<endl<<endl;
    cout<<"La informacion del conjunto #2 es:"<<endl;
    Nodo * aux2;
    aux2 = listap2->cab;
    int pos2 = 1;
    while(aux2 != NULL){
        cout<<"Info "<<pos2<<": "<<aux2->info<<endl;
        aux2 = aux2->sig;
        pos2++;
    }
    cout<<endl<<endl;
}
void insertar(Lista *listap1, Lista *listap2){

     Nodo * con1, *con2;
     int op, infoNueva;
     cout<<"\nConjunto #1. ";
     cout<<"\n------------ "<<endl;
     do{
        con1 = new Nodo;
        cout<<"\nDigite el valor para el conjunto SIN REPETIR. ";
        cin>> infoNueva;
        con1->info = infoNueva;
        con1->sig = NULL;
        if(listap1->tam == 0){
            listap1->cab = con1;
            listap1->tam++;
        }
        else{
            Nodo *aux;
            aux = listap1->cab;
            while(aux->sig != NULL){
                aux = aux->sig;
            }
            aux->sig = con1;
            listap1->tam++;
        }
        cout<<"\nDesea ingresar otro dato? (Si: 0, No: -1). ";
        cin>> op;
     }while(op != -1);

     cout<<"\nConjunto #2. ";
     cout<<"\n------------ "<<endl;
     do{
        con2 = new Nodo;
        cout<<"\nDigite el valor para el conjunto SIN REPETIR. ";
        cin>> infoNueva;
        con2->info = infoNueva;
        con2->sig = NULL;
        if(listap2->tam == 0){
            listap2->cab = con2;
            listap2->tam++;
        }
        else{
            Nodo *aux2;
            aux2 = listap2->cab;
            while(aux2->sig != NULL){
                aux2 = aux2->sig;
            }
            aux2->sig = con2;
            listap2->tam++;
        }
        cout<<"\nDesea ingresar otro dato? (Si: 0, No: -1). ";
        cin>> op;
     }while(op != -1);
}
bool eliminar(Lista * listap1, Lista *listap2){

    int conjunto, elim1, elim2;
    cout<<"\nDigite el conjunto en el cual quiere hacer el cambio. (Conjunto #1: 1 - Conjunto#2: 2) ";
    cin>> conjunto;
    if(conjunto == 1){
        cout<<"\nDigite la posicion del conjunto 1 que quiere eliminar. ";
        cin>> elim1;
        if(listap1->tam > elim1){
            if(elim1 == 0){
                Nodo * temp;
                temp = listap1->cab;
                listap1->cab = temp->sig;
                temp->sig = NULL;
                delete temp;
                listap1->tam--;
                return true;
            }
            else{
                Nodo * aux;
                aux = listap1->cab;
                for(int i=0;i<elim1-1;i++){
                    aux = aux->sig;
                }
                Nodo *temp;
                temp = aux->sig;
                aux->sig = temp->sig;
                temp->sig = NULL;
                delete temp;
                listap1->tam--;
                return true;
            }
        }
        else{
            return false;
        }
    }
    if(conjunto == 2){
        cout<<"\nDigite la posicion del conjunto 2 que quiere eliminar. ";
        cin>> elim2;
        if(listap2->tam > elim2){
            if(elim1 == 0){
                Nodo * temp2;
                temp2 = listap2->cab;
                listap2->cab = temp2->sig;
                temp2->sig = NULL;
                delete temp2;
                listap2->tam--;
                return true;
            }else{
                Nodo * aux2;
                aux2 = listap2->cab;
                for(int i=0;i<elim2-1;i++){
                    aux2 = aux2->sig;
                }
                Nodo *temp2;
                temp2 = aux2->sig;
                aux2->sig = temp2->sig;
                temp2->sig = NULL;
                delete temp2;
                listap2->tam--;
                return true;
            }
        }
        else{
            return false;
        }
    }
}
void realizarUnion(Lista *listap1, Lista *listap2){

    Nodo *aux1, *aux2, *auxUnion;
    Lista * listaUnion = new Lista;
    listaUnion->tam = 0;
    listaUnion->cab = NULL;
    aux1 = listap1->cab;
    aux2 = listap2->cab;
    auxUnion = listaUnion->cab;

    while(aux1 != NULL){
        auxUnion = new Nodo;
        auxUnion->info = aux1->info;
        auxUnion->sig = NULL;
        if(listaUnion->tam == 0){
            listaUnion->cab = auxUnion;
            listaUnion->tam++;
        }
        else{
            Nodo *aux;
            aux = listaUnion->cab;
            while(aux->sig != NULL){
                aux = aux->sig;
            }
            aux->sig = auxUnion;
            listaUnion->tam++;
        }
        aux1 = aux1->sig;
    }
    while(aux2 != NULL){
        auxUnion = new Nodo;
        auxUnion->info = aux2->info;
        auxUnion->sig = NULL;
        if(listaUnion->tam == 0){
            listaUnion->cab = auxUnion;
            listaUnion->tam++;
        }
        else{
            Nodo *aux;
            aux = listaUnion->cab;
            while(aux->sig != NULL){
                aux = aux->sig;
            }
            aux->sig = auxUnion;
            listaUnion->tam++;
        }
        aux2 = aux2->sig;
    }
    cout<<"La Union de los dos conjuntos es:"<<endl;
    Nodo * auxU;
    auxU = listaUnion->cab;
    int pos = 1;
    while(auxU != NULL){
        cout<<"Union "<<pos<<": "<<auxU->info<<endl;
        auxU = auxU->sig;
        pos++;
    }
    cout<<endl<<endl;
}
void realizarInt(Lista *listap1, Lista *listap2){

    Nodo *aux1, *aux2, *auxInt;
    Lista * listaInt = new Lista;
    listaInt->tam = 0;
    listaInt->cab = NULL;
    aux1 = listap1->cab;
    aux2 = listap2->cab;
    auxInt = listaInt->cab;

    while(aux1 != NULL){
        while(aux2 != NULL){
            if(aux1->info == aux2->info){
                auxInt = new Nodo;
                auxInt->info = aux1->info;
                auxInt->sig = NULL;
                if(listaInt->tam == 0){
                    listaInt->cab = auxInt;
                    listaInt->tam++;
                }
                else{
                    Nodo *aux;
                    aux = listaInt->cab;
                    while(aux->sig != NULL){
                    aux = aux->sig;
                    }
                    aux->sig = auxInt;
                    listaInt->tam++;
                }
            }
            aux2 = aux2->sig;
        }
        aux2 = listap2->cab;
        aux1 = aux1->sig;
    }
    if(listaInt->tam > 0){
        cout<<"La Interseccion de los dos conjuntos es:"<<endl;
        Nodo * auxI;
        auxI = listaInt->cab;
        int pos = 1;
        while(auxI != NULL){
            cout<<"Interseccion "<<pos<<": "<<auxI->info<<endl;
            auxI = auxI->sig;
            pos++;
        }
    }
    else{
        cout<<"\nNo hay interseccion entre los conjuntos. ";
    }
    cout<<endl<<endl;
}
void realizarDif(Lista *listap1, Lista *listap2){

    Nodo *aux1, *aux2, *auxD;
    Lista * listaDif = new Lista;
    listaDif->tam = 0;
    listaDif->cab = NULL;
    aux1 = listap1->cab;
    aux2 = listap2->cab;
    auxD = listaDif->cab;
    int cont = 0;
    while(aux1 != NULL){
        while(aux2 != NULL){
            if(aux1->info == aux2->info){
                cont++;
            }
            aux2 = aux2->sig;
        }
        if(cont == 0){
            auxD = new Nodo;
            auxD->info = aux1->info;
            auxD->sig = NULL;
            if(listaDif->tam == 0){
                listaDif->cab = auxD;
                listaDif->tam++;
            }
            else{
                Nodo *aux;
                aux = listaDif->cab;
                while(aux->sig != NULL){
                aux = aux->sig;
                }
                aux->sig = auxD;
                listaDif->tam++;
            }
        }
        aux1 = aux1->sig;
        aux2 = listap2->cab;
        cont = 0;
    }
    if(listaDif->tam > 0){
        cout<<"La Diferencia de los dos conjuntos es:"<<endl;
        Nodo * auxDif;
        auxDif = listaDif->cab;
        int pos = 1;
        while(auxDif != NULL){
            cout<<"Diferencia "<<pos<<": "<<auxDif->info<<endl;
            auxDif = auxDif->sig;
            pos++;
        }
    }
    else{
        cout<<"\nNo hay Diferencia entre los conjuntos. ";
    }
    cout<<endl<<endl;
}
