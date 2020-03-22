#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Funciones.h"

using namespace std;
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
     int dato, op;
     do{
        nuevo = new Nodo;
        cout<<"\nDigite el dato de la lista. ";
        cin>> dato;
        nuevo->info = dato;
        nuevo->sig = NULL;
        if(lista->tam == 0){
        lista->cab = nuevo;
        lista->tam++;
        }
        else{
            Nodo * aux;
            aux = lista->cab;
            while(aux->sig != NULL){
                aux = aux->sig;
            }
            aux->sig = nuevo;
            lista->tam++;
        }
     cout<<"\nDesea ingresar otro dato? (Si: 0, No: -1). ";
     cin>> op;
     }while(op != -1);
}
void insertarEnUnaPosicion (MultiLista *multi){

     Nodo *nuevo;
     MultiNodo *auxMulti;
     auxMulti = multi->cab;
     int infoNueva;
     cout<<"\nDigite el dato que quiere insertar. ";
     cin>>infoNueva;
     nuevo = new Nodo;
     nuevo->info = infoNueva;
     nuevo->sig = NULL;
     while(auxMulti->sig != NULL){
            Nodo *auxLista;
            if((auxMulti->info <= infoNueva) && (auxMulti->sig->info >= infoNueva)){
                auxLista = auxMulti->dato->cab;
                while(auxLista != NULL){
                    if((auxLista->info <= infoNueva)&&(auxLista->sig->info >= infoNueva)){
                        nuevo->sig = auxLista->sig;
                        auxLista->sig = nuevo;
                        break;
                    }
                    if(auxLista->sig->sig == NULL){
                        auxLista->sig->sig = nuevo;
                        break;
                    }
                    auxLista = auxLista->sig;
                }
                break;
            }else if(auxMulti->sig->sig == NULL){
                    auxLista = auxMulti->sig->dato->cab;
                    while(auxLista != NULL){
                        if((auxLista->info <= infoNueva)&&(auxLista->sig->info >= infoNueva)){
                            nuevo->sig = auxLista->sig;
                            auxLista->sig = nuevo;
                            break;
                        }
                        if(auxLista->sig->sig == NULL){
                            auxLista->sig->sig = nuevo;
                            break;
                        }
                        auxLista = auxLista->sig;
                    }
                }
                auxMulti = auxMulti->sig;
     }
     cout<<"\nEl dato se agrego a la Multi Lista exitosamente. ";
     cout<<"\nVuelva a seleccionar la opcion 4 para ver el nuevo dato implementado en la lista. "<<endl<<endl;
}
bool vacia(Lista * lista){
     if(lista->tam == 0){
         return true;
     }
     else{
         return false;
     }
}
void generarMulti(Lista *lista, MultiLista *multi){

    if(lista->tam < 3){
        cout<<"\nNo se puede generar Multi Lista. La lista inicial debe tener minimo tres entradas "<<endl<<endl;
    }else{
        int cantidad, cont = 0;
        cantidad = (lista->tam) % 3;   //CANTIDAD DE NODOS EN LA MULTILISTA QUE VAN A TENER CUATRO DATOS.
        Nodo *auxlista;
        Nodo *multiDato;
        MultiNodo *multiNodo;
        auxlista = lista->cab;

        while(auxlista != NULL){
            multiNodo = new MultiNodo;
            multiNodo->info = auxlista->info;
            multiNodo->sig = NULL;
            multiNodo->dato = new Lista;
            multiNodo->dato->cab = NULL;
            multiNodo->dato->tam = 0;
            if(multi->tam == 0){
                multi->cab = multiNodo;
                multi->tam++;
            }else{
                MultiNodo *auxM;
                auxM = multi->cab;
                while(auxM->sig != NULL){
                    auxM = auxM->sig;
                }
                auxM->sig = multiNodo;
            }
            if(cont < cantidad){
                for(int i=0; i<4; i++){
                    multiDato = new Nodo;
                    multiDato->info = auxlista->info;
                    multiDato->sig = NULL;
                    if(multiNodo->dato->tam == 0){
                        multiNodo->dato->cab = multiDato;
                        multiNodo->dato->tam++;
                    }else{
                        Nodo *aux;
                        aux = multiNodo->dato->cab;
                        while(aux->sig != NULL){
                        aux = aux->sig;
                        }
                        aux->sig = multiDato;
                    }
                    auxlista = auxlista->sig;
                }
            }
            if(cont >= cantidad){
                for(int i=0; i<3; i++){
                    multiDato = new Nodo;
                    multiDato->info = auxlista->info;
                    multiDato->sig = NULL;
                    if(multiNodo->dato->tam == 0){
                        multiNodo->dato->cab = multiDato;
                        multiNodo->dato->tam++;
                    }else{
                        Nodo *aux;
                        aux = multiNodo->dato->cab;
                        while(aux->sig != NULL){
                        aux = aux->sig;
                        }
                        aux->sig = multiDato;
                    }
                    auxlista = auxlista->sig;
                }
            }
            cont++;
        }
        cout<<"\nLa Multi Lista se creo exitosamente. "<<endl<<endl;
    }
}
void imprimirMulti(MultiLista *multi){

    Nodo *auxLista;
    MultiNodo *auxMulti;
    auxMulti = multi->cab;
    cout<<"\nLa MultiLista generada es: "<<endl<<endl;
    while(auxMulti != NULL){
        cout<<auxMulti->info;
        auxLista = auxMulti->dato->cab;
        while(auxLista != NULL){
            cout<<" -> "<<auxLista->info;
            auxLista = auxLista->sig;
        }
        auxMulti = auxMulti->sig;
        cout<<endl;
    }
    cout<<endl<<endl<<endl;
}
