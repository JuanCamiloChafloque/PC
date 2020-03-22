#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

struct Esp{
    char *palabraE;
    int codigoE;
};
struct Ing{
    char *palabraI;
    int codigoI;
};
char* traducir(Esp *ptrEspanol, Ing *ptrIngles, int tamE, int tamI, char *frase, int tamF);
int main()
{
    Esp esp, *ptrEspanol;
    Ing ing, *ptrIngles;
    ptrEspanol = &esp;
    ptrIngles = &ing;
    int tamE, tamI, tamF;
    char *frase, *fraseFin;
    tamF=50;
    frase = new char[tamF];
    fraseFin = new char[tamF];
    cout<<"\nDigite cuantas palabras tiene el diccionario de Español. ";
    cin>> tamE;
    cout<<"\nDigite cuantas palabras tiene el diccionario de Ingles. ";
    cin>> tamI;
    ptrEspanol = new Esp[tamE];
    ptrIngles = new Ing[tamI];
    for(int i=0; i<tamE; i++){
         (ptrEspanol + i)->palabraE = new char[50];
    }
    for(int i=0; i<tamI; i++){
         (ptrIngles + i)->palabraI = new char[50];
    }
    for(int i=0; i<tamE; i++){
        cout<<"\nDigite la palabra en español #"<<i+1<<": ";
        cin>>(ptrEspanol + i)->palabraE;
        cout<<"\nDigite el codigo de la palabra #"<<i+1<<": ";
        cin>>(ptrEspanol + i)->codigoE;
    }
    for(int i=0; i<tamI; i++){
        cout<<"\nDigite la palabra en ingles #"<<i+1<<": ";
        cin>>(ptrIngles + i)->palabraI;
        cout<<"\nDigite el codigo de la palabra #"<<i+1<<": ";
        cin>>(ptrIngles + i)->codigoI;
    }
    cout<<"\nDigite la frase a traducir. ";
    cin.ignore();
    cin.getline(frase,tamF);
    tamF = strlen(frase);
    cout<<endl<<endl;
    fraseFin = traducir(ptrEspanol, ptrIngles, tamE, tamI, frase,tamF);
    cout<<"La frase Final traducida es: "<<fraseFin<<endl<<endl;
    return 0;
}
char* traducir(Esp *ptrEspanol, Ing *ptrIngles, int tamE, int tamI, char *frase, int tamF){


    char *copiaF;
    int tamFF=100;
    copiaF = new char[tamF];
    strcpy(copiaF, frase);
    strtok(copiaF," ");
    char *frasefinal;
    frasefinal = new char[tamFF];
    for(int i=0; i<tamFF; i++)
       *(frasefinal + i) = '\0';
    while(copiaF != NULL){
        int cont=1;
        int tempCodigo;
        for(int i=0 ; i<tamE ; i++){
            int temp;
            temp = strcmp(copiaF, (ptrEspanol+i)->palabraE);
            if( temp == 0 ){
                tempCodigo = (ptrEspanol+i)->codigoE;
            }
        }
        for(int i=0 ; i<tamI ; i++){
            if( tempCodigo == (ptrIngles+i)->codigoI ){
                strcat(frasefinal,((ptrIngles+i)->palabraI));
            }
        }
        *(frasefinal+strlen(frasefinal))=char(32);
        copiaF=strtok(NULL," ");
    }
    return frasefinal;
}
