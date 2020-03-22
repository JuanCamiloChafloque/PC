#include <iostream>
#include <stdlib.h>
#include "Funciones.h"

using namespace std;

Lista * crearLista(){
      Lista * lista = new Lista;
      lista->tam = 0;
      lista->cab = NULL;
      return lista;
}

void imprimir(Lista * lista){
     if(vacia(lista)){
          cout<<"La Lista no tiene Informacion"<<endl;
     }
     else{
         cout<<"La informacion de la Lista es:"<<endl;
         Nodo * aux;
         aux = lista->cab;
         int pos = 1;
         while(aux != NULL){
                   cout<<"Info "<<pos<<": "<<aux->info<<endl;
                   aux = aux->sig;
                   pos++;
         }
     }
}
void insertar(Lista * lista){
     Nodo * nuevo;
     int op, infoNueva;
     do{
        cout<<"\nDigite el dato que quiere ingresar. ";
        cin>> infoNueva;
        nuevo = new Nodo;
        nuevo->info = infoNueva;
        nuevo->ant = NULL;
        nuevo->sig = NULL;
        if(lista->tam == 0){
            lista->cab = nuevo;
            lista->tam++;
        }
        else{
            Nodo *aux;
            aux = lista->cab;
            while(aux->sig != NULL){
                aux = aux->sig;
            }
            aux->sig = nuevo;
            nuevo->ant = aux;
            lista->tam++;
        }
        cout<<"\nDesea ingresar otro dato? (SI: 0 / NO: -1). ";
        cin>> op;
     }while(op != -1);
}
bool vacia(Lista * lista){
     if(lista->tam == 0){
         return true;
     }
     else{
         return false;
     }
}
void invertirLista(Lista * lista){

    Nodo *auxInv;
    auxInv = lista->cab;
    while (auxInv->sig !=NULL){
        auxInv = auxInv->sig;
    }
    cout<<"La informacion de la Lista invertida es:"<<endl;
    Nodo * aux;
    aux = auxInv;
    int pos = 1;
    while(aux != NULL){
        cout<<"Info "<<pos<<": "<<aux->info<<endl;
        aux = aux->ant;
        pos++;
    }
}

