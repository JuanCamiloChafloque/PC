#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Funciones.h"

using namespace std;

void imprimir(Lista *listap1, Lista *listap2){

      cout<<"El Polinomio #1 es:"<<endl;
      Nodo * aux;
      aux = listap1->cab;
      int pos = 1, p = listap1->tam;
      while(pos < p){
            cout<<aux->base<<"X^"<<aux->exp<<" + ";
            aux = aux->sig;
            pos++;
      }
      cout<<aux->base<<"X^"<<aux->exp;
      cout<<endl<<endl;
      cout<<"El Polinomio #2 es:"<<endl;
      Nodo * aux2;
      aux2 = listap2->cab;
      int pos2 = 1, p2 = listap2->tam;
      while(pos2 < p2){
            cout<<aux2->base<<"X^"<<aux2->exp<<" + ";
            aux2 = aux2->sig;
            pos2++;
      }
      cout<<aux2->base<<"X^"<<aux2->exp;
      cout<<endl<<endl;
}
void insertar(Lista *listap1, Lista *listap2){

     Nodo * poli1, *poli2;
     int op, infoBase, infoExp;
     cout<<"\nPolinomio #1. ";
     cout<<"\n-------------- "<<endl;
     do{
        poli1 = new Nodo;
        cout<<"\nDigite el valor de la base. ";
        cin>> infoBase;
        cout<<"\nDigite el valor del exponente. ";
        cin>> infoExp;
        poli1->base = infoBase;
        poli1->exp = infoExp;
        poli1->sig = NULL;
        if(listap1->tam == 0){
            listap1->cab = poli1;
            listap1->tam++;
        }
        else{
            Nodo *aux;
            aux = listap1->cab;
            while(aux->sig != NULL){
                aux = aux->sig;
            }
            aux->sig = poli1;
            listap1->tam++;
        }
        cout<<"\nDesea ingresar otro dato? (Si: 0, No: -1). ";
        cin>> op;
     }while(op != -1);

     cout<<"\nPolinomio #2. ";
     cout<<"\n-------------- "<<endl;
     do{
        poli2 = new Nodo;
        cout<<"\nDigite el valor de la base. ";
        cin>> infoBase;
        cout<<"\nDigite el valor del exponente. ";
        cin>> infoExp;
        poli2->base = infoBase;
        poli2->exp = infoExp;
        poli2->sig = NULL;
        if(listap2->tam == 0){
            listap2->cab = poli2;
            listap2->tam++;
        }
        else{
            Nodo *aux2;
            aux2 = listap2->cab;
            while(aux2->sig != NULL){
                aux2 = aux2->sig;
            }
            aux2->sig = poli2;
            listap2->tam++;
        }
        cout<<"\nDesea ingresar otro dato? (Si: 0, No: -1). ";
        cin>> op;
     }while(op != -1);
}
void sumarPolinomios(Lista *listap1, Lista *listap2, Lista *listaf){

    Nodo *auxp1, *auxp2, *pfinal, *cond1, *cond2;
    auxp1 = listap1->cab;
    auxp2 = listap2->cab;
    cond1 = listap1->cab;
    cond2 = listap2->cab;
    int cont = 0;
    while(auxp1 != NULL){
        while(auxp2 != NULL){
            if(auxp1->exp == auxp2->exp){
                cont++;
                pfinal = new Nodo;
                pfinal->base = auxp1->base + auxp2->base;
                pfinal->exp = auxp1->exp;
                pfinal->sig = NULL;
                if(listaf->tam == 0){
                    listaf->cab = pfinal;
                    listaf->tam++;
                }
                else{
                    Nodo * aux;
                    aux = listaf->cab;
                    while(aux->sig != NULL){
                        aux = aux->sig;
                }
                aux->sig = pfinal;
                listaf->tam++;
                }
            }
            auxp2 = auxp2->sig;
        }
        if(cont == 0){
                pfinal = new Nodo;
                pfinal->base = auxp1->base;
                pfinal->exp = auxp1->exp;
                pfinal->sig = NULL;
                if(listaf->tam == 0){
                        listaf->cab = pfinal;
                        listaf->tam++;
                }
                else{
                    Nodo * aux;
                    aux = listaf->cab;
                    while(aux->sig != NULL){
                            aux = aux->sig;
                    }
                    aux->sig = pfinal;
                    listaf->tam++;
                }
        }
        auxp2 = listap2->cab;
        auxp1 = auxp1->sig;
        cont = 0;
    }
    cont = 0;
    while(cond2 != NULL){
        while(cond1 != NULL){
            if(cond2->exp == cond1->exp){
                cont++;
            }
            cond1 = cond1->sig;
        }
        if(cont == 0){
            pfinal = new Nodo;
            pfinal->base = cond2->base;
            pfinal->exp = cond2->exp;
            pfinal->sig = NULL;
            if(listaf->tam == 0){
                    listaf->cab = pfinal;
                    listaf->tam++;
            }
            else{
                Nodo * aux;
                aux = listaf->cab;
                while(aux->sig != NULL){
                        aux = aux->sig;
                }
                aux->sig = pfinal;
                listaf->tam++;
            }
        }
        cond1 = listap1->cab;
        cond2 = cond2->sig;
        cont = 0;
    }
    cout<<endl<<endl;
    cout<<"El Polinomio Final es:"<<endl;
    Nodo * auxFinal;
    auxFinal = listaf->cab;
    int pos = 1, p = listaf->tam;
    while(pos < p){
        cout<<auxFinal->base<<"X^"<<auxFinal->exp<<" + ";
        auxFinal = auxFinal->sig;
        pos++;
    }
    cout<<auxFinal->base<<"X^"<<auxFinal->exp;
    cout<<endl<<endl;
}
void evaluarPolinomio(Lista *listaf){

    int valor, total = 0;
    Nodo *aux;
    aux = listaf->cab;
    cout<<"\nDigite el valor de X a evaluar. ";
    cin>> valor;
    while(aux != NULL){
        total += (pow(valor, aux->exp) * aux->base);
        aux = aux->sig;
    }
    cout<<"\nEl resultado del polinomio evaluado en "<<valor<<" es: "<<total<<endl;
}
