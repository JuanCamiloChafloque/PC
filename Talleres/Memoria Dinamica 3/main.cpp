#include <iostream>
#include <stdlib.h>

using namespace std;

struct Equipo{
    string nombre;
    int posicion;
    int **partidos;
};
struct Campeonato{
    Equipo *equipos;
    unsigned int tam;
};
void almacenar(Campeonato *ptrCam, unsigned int N);
int promedio(Campeonato *ptrCam, unsigned int N, string buscarEq);
string campeon(Campeonato *ptrCam, unsigned int N);
int main()
{
    unsigned int N;
    int prom, **matriz;
    string buscarEq, gan;
    Campeonato cam, *ptrCam;
    ptrCam = &cam;
    cout<<"\nDigite el numero de equipos en el campeonato (PONER 4). ";
    cin>> N;
    almacenar(ptrCam, N);
    cout<<"\nDigite el equipo (Millonarios-Santafe-Nacional-Envigado) del campeonato a buscar. ";
    cin>> buscarEq;
    prom = promedio(ptrCam, N, buscarEq);
    cout<<"\nEl promedio de puntos del equipo "<<buscarEq<<" es: "<<prom<<endl;
    gan = campeon(ptrCam, N);
    cout<<"\nEl equipo campeon del campeonato es: "<<gan<<endl;

    return 0;
}
void almacenar(Campeonato *ptrCam, unsigned int N){

    ptrCam->tam = N;
    ptrCam->equipos = new Equipo[N];
    for(int i=0; i<N; i++){
            (((ptrCam->equipos) + i)->partidos) = new int*[2];
            for(int j=0; j<2; j++){
                *((((ptrCam->equipos) + i)->partidos) + j) = new int[N-1];
            }
    }
    //EN CASO DE QUE LOS DATOS NO SEAN DETERMINADOS, SE DIGITAN ACA:
    /*for(int i=0; i<N; i++){
        cout<<"\nDigite el nombre del equipo #"<<i+1<<": ";
        cin>> ((ptrCam->equipos) + i)->nombre;
        cout<<"\nDigite la posicion que ocupo el equipo #"<<i+1<<" en el campeonato: ";
        cin>> ((ptrCam->equipos) + i)->posicion;
        for(int k=0; k<N-1; k++){
                for(j=0; j<2; j++){
                   cout<<"\nDigite el # del partido que se jugo y el total de puntos obtenidos. ";
                   cin>> *((*(((ptrCam->equipos) + i)->partidos) + k) + j);
                }
        }
    }*/
    ((ptrCam->equipos) + 0)->nombre = "Millonarios";
    ((ptrCam->equipos) + 1)->nombre = "Santafe";
    ((ptrCam->equipos) + 2)->nombre = "Nacional";
    ((ptrCam->equipos) + 3)->nombre = "Envigado";
    ((ptrCam->equipos) + 0)->posicion = 3;
    ((ptrCam->equipos) + 1)->posicion = 1;
    ((ptrCam->equipos) + 2)->posicion = 2;
    ((ptrCam->equipos) + 3)->posicion = 4;

    *((*(((ptrCam->equipos) + 0)->partidos) + 0) + 0) = 1;
    *((*(((ptrCam->equipos) + 0)->partidos) + 1) + 0) = 2;
    *((*(((ptrCam->equipos) + 0)->partidos) + 2) + 0) = 3;

    *((*(((ptrCam->equipos) + 1)->partidos) + 0) + 0) = 1;
    *((*(((ptrCam->equipos) + 1)->partidos) + 1) + 0) = 2;
    *((*(((ptrCam->equipos) + 1)->partidos) + 2) + 0) = 3;

    *((*(((ptrCam->equipos) + 2)->partidos) + 0) + 0) = 1;
    *((*(((ptrCam->equipos) + 2)->partidos) + 1) + 0) = 2;
    *((*(((ptrCam->equipos) + 2)->partidos) + 2) + 0) = 3;

    *((*(((ptrCam->equipos) + 3)->partidos) + 0) + 0) = 1;
    *((*(((ptrCam->equipos) + 3)->partidos) + 1) + 0) = 2;
    *((*(((ptrCam->equipos) + 3)->partidos) + 2) + 0) = 3;

    *((*(((ptrCam->equipos) + 0)->partidos) + 0) + 1) = 3;
    *((*(((ptrCam->equipos) + 0)->partidos) + 1) + 1) = 0;
    *((*(((ptrCam->equipos) + 0)->partidos) + 2) + 1) = 3;

    *((*(((ptrCam->equipos) + 1)->partidos) + 0) + 1) = 3;
    *((*(((ptrCam->equipos) + 1)->partidos) + 1) + 1) = 3;
    *((*(((ptrCam->equipos) + 1)->partidos) + 2) + 1) = 3;

    *((*(((ptrCam->equipos) + 2)->partidos) + 0) + 1) = 3;
    *((*(((ptrCam->equipos) + 2)->partidos) + 1) + 1) = 3;
    *((*(((ptrCam->equipos) + 2)->partidos) + 2) + 1) = 1;

    *((*(((ptrCam->equipos) + 3)->partidos) + 0) + 1) = 0;
    *((*(((ptrCam->equipos) + 3)->partidos) + 1) + 1) = 0;
    *((*(((ptrCam->equipos) + 3)->partidos) + 2) + 1) = 3;

}
int promedio(Campeonato *ptrCam, unsigned int N, string buscarEq){


    int puntaje = 0;
    cout<<endl<<endl;
    for(int i=0; i<N; i++){
        if(buscarEq == ((ptrCam->equipos) + i)->nombre){
            for(int k=0; k<N-1; k++){
                puntaje += *((*(((ptrCam->equipos) + i)->partidos) + k) + 1);
            }
        }
    }
    for(int i=0; i<N; i++){
        cout<<endl;
        cout<<((ptrCam->equipos) + i)->nombre;
        cout<<"\nSu posicion es: "<<((ptrCam->equipos) + i)->posicion;
        cout<<"\n------------------";
        cout<<"\nPuntaje de los partidos jugados. "<<endl;
        for(int k=0; k<N-1; k++){
                cout<<k + 1<<"     "<< *((*(((ptrCam->equipos) + i)->partidos) + k) + 1)<<"\t"<<endl;
        }
        cout<<endl<<endl;
    }
    cout<<endl;
    return puntaje;
}
string campeon(Campeonato *ptrCam, unsigned int N){

    string camp;
    for(int i=0; i<N; i++){
        if(((ptrCam->equipos) + i)->posicion == 1){
            camp = ((ptrCam->equipos) + i)->nombre;
        }
    }
    return camp;
}
