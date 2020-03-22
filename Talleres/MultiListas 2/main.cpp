#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstring>
#include <string.h>
#include "Funciones.cpp"

using namespace std;

int main()
{
    int opcion;
    Paquete structPaquete;
    MultiLista * multi = new MultiLista;
    multi->cab = NULL;
    multi->tam = 0;
    do{
      cout<<"\n1. Generar Paquete. ";
      cout<<"\n2. Generar Lista de protocolos (Se debe digitar esta opcion cada vez que se cree un paquete). ";
      cout<<"\n3. Imprimir Lista de protocolos. ";
      cout<<"\n4. Mensaje Secreto. ";
      cout<<"\n5. Salir. ";
      cout<<"\nDigite una opcion. "<<endl;
      cin>>opcion;
      switch(opcion){

            case 1: system("cls");

                    for(int i=0; i<20; i++){
                        structPaquete.auxDestino[i] = '\0';
                        structPaquete.auxOrigen[i] = '\0';
                        structPaquete.auxProtocolo[i] = '\0';
                    }
                    for(int i=0; i<3; i++){
                        structPaquete.auxTam[i] = '\0';
                    }
                    for(int i=0; i<100; i++){
                        structPaquete.auxMensaje[i] = '\0';
                    }
                    cout<<"\nCreacion de Paquetes. ";
                    cout<<"\n-----------------------"<<endl;
                    cout<<"\nDigite la direccion de destino. ";
                    cin.ignore();
                    cin.getline(structPaquete.auxDestino, 20);
                    cout<<"\nDigite la direccion de origen. ";
                    cin.getline(structPaquete.auxOrigen, 20);
                    cout<<"\nDigite el mensaje. ";
                    cin.getline(structPaquete.auxMensaje, 100);
                    cout<<"\nDigite el nombre del protocolo. ";
                    cin.getline(structPaquete.auxProtocolo, 20);
                    cout<<"\nDigite el tamaño. ";
                    cin.getline(structPaquete.auxTam, 3);
                    cout<<endl;
                    cout<<"\nEl paquete se creo exitosamente. ";
                    cout<<"\nDigitar la OPCION #2 para implementarla en la lista. "<<endl<<endl;
            break;

            case 2: system("cls");
                    generarLista(multi, structPaquete);
            break;

            case 3: system("cls");
                    imprimir(multi);
                    system("pause");
            break;

            case 4: system("cls");
                    mensajeSecreto(multi);
                    system("pause");
            break;

            case 5: break;
            default: break;
      }
    }while(opcion != 5);

    return 0;
}
