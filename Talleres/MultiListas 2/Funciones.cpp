#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstring>
#include <string.h>
#include "Funciones.h"

using namespace std;
void generarLista(MultiLista *multi, Paquete structPaquete){

    MultiNodo *multiNodo;
    Nodo *datosP;
    int cont = 0;
    //VERIFICAR SI EL PROTOCOLO YA SE ENCUENTRA EN LA LISTA PARA NO REPETIRLO. SI CONT INCREMENTA SIGNIFICA QUE EL PROTOCOLO YA EXISTE.
    if(multi->tam != 0){
        MultiNodo *verificar;
        verificar = multi->cab;
        while(verificar->sig != NULL){
            if(strcmp(verificar->protocolo, structPaquete.auxProtocolo) == 0){
                cont++;
            }
            verificar = verificar->sig;
        }
    }
    //SE CREA EL NODO EN EL CUAL SE VAN A GUARDAR LOS DATOS DEL PAQUETE. ESTE NODO SERA UBICADO DEPENDIENDO DE SU PROTOCOLO.
    datosP = new Nodo;
    datosP->sig = NULL;
    strcpy(datosP->destino, structPaquete.auxDestino);
    strcpy(datosP->mensaje, structPaquete.auxMensaje);
    strcpy(datosP->tamReal, structPaquete.auxTam);

    //EN CASO DE QUE NO SE ENCUENTRE EL PROTOCOLO EN LA LISTA. SE CREA UNO NUEVO.
    if(cont == 0){
        multiNodo = new MultiNodo;
        multiNodo->sig = NULL;
        multiNodo->dato = new Lista;
        multiNodo->dato->cab = NULL;
        multiNodo->dato->tam = 0;
        strcpy(multiNodo->protocolo, structPaquete.auxProtocolo);
        multiNodo->dato->cab = datosP;
        multiNodo->dato->tam++;
    }
    //SE LE ASIGNA EL NUEVO PROTOCOLO A LA LISTA.
    if(multi->tam == 0){
        multi->cab = multiNodo;
        multi->tam++;
    }else{
        MultiNodo *auxMulti;
        auxMulti = multi->cab;
        if(cont == 0){
            while(auxMulti->sig != NULL){
                auxMulti = auxMulti->sig;
            }
            auxMulti->sig = multiNodo;
        }
    }
    if(cont != 0){
        MultiNodo *aux;
        aux = multi->cab;
        while(aux->sig != NULL){
            if(strcmp(aux->protocolo, structPaquete.auxProtocolo) == 0){
                if(multiNodo->dato->tam == 0){
                    multiNodo->dato->cab = datosP;
                    multiNodo->dato->tam++;
                }else{
                    Nodo *auxL;
                    auxL = aux->dato->cab;
                    while(auxL != NULL){
                        auxL = auxL->sig;
                    }
                    auxL->sig = datosP;
                }
            }
            aux = aux->sig;
        }
    }
    cout<<"\nLa Lista se creo exitosamente. "<<endl<<endl;
}
void imprimir(MultiLista *multi){

    Nodo *auxLista;
    MultiNodo *auxMul;
    auxMul = multi->cab;
    cout<<"\nLa Lista de Protocolos es: "<<endl<<endl;
    while(auxMul != NULL){
        cout<<"\nProtocolo: "<<auxMul->protocolo;
        cout<<"\n--------------"<<endl;
        auxLista = auxMul->dato->cab;
        while(auxLista != NULL){
            cout<<"\nMaquina de Destino: "<<auxLista->destino;
            cout<<"\nMensaje: "<<auxLista->mensaje;
            cout<<"\nTamaño real: "<<auxLista->tamReal<<endl;
            auxLista = auxLista->sig;
        }
        auxMul = auxMul->sig;
        cout<<endl;
    }
    cout<<endl<<endl<<endl;
}
void mensajeSecreto(MultiLista *multi){

    char *auxiliar;
    auxiliar = new char[64];
    for(int i=0; i<64; i++){
        auxiliar[i] = '\0';
    }
    int cont = 0;
    int tam;
    Nodo *auxLista;
    MultiNodo *auxMulti;
    auxMulti = multi->cab;
    //SE RECORRE LA LISTA DE PROTOCOLOS HASTA ENCONTRAR EL PROTOCOLO SECRET MESSAGE.
    while(auxMulti != NULL){
        if(strcmp(auxMulti->protocolo, "Secret Message") == 0){
           cont++;
           strcpy(auxiliar, auxMulti->dato->cab->mensaje);
           tam = strlen(auxiliar);
           break;
        }else{
            auxMulti = auxMulti->sig;
        }
    }
    char *finalT;
    finalT = new char[tam + 1];
    for(int i=0; i<tam + 1; i++){
        finalT[i] = '\0';
    }
    for(int i=0; i<tam + 1; i++){
        if(auxiliar[i] == '1'){
                finalT[i] = 'a';
        }else if(auxiliar[i] == '2'){
                finalT[i] = 'e';
        }else if(auxiliar[i] == '3'){
                finalT[i] = 'i';
        }else if(auxiliar[i] == '4'){
                finalT[i] = 'o';
        }else if(auxiliar[i] == '5'){
                finalT[i] = 'u';
        }else{
                finalT[i] = auxiliar[i];
        }
    }
    if(cont == 0){
        cout<<"\nEn la lista no se encuentra el protocolo SECRET MESSAGE. "<<endl;
    }
    cout<<"\nEl mensaje de texto del protocolo SECRET MESAJE codificado es: "<<endl;
    cout<<finalT;
    cout<<endl<<endl;
}
