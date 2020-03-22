#include <iostream>

using namespace std;

struct Canciones{
    string titulo;
    string autor;
    string interprete;
    float duracion;
};
Canciones * insertar(Canciones *can, int &N);
Canciones * ordenar(Canciones *can, Canciones *ordenado, int N);
void mostrar(Canciones *can, int &N);

int main()
{
    Canciones *can;
    Canciones *ordenado;
    can = new Canciones[1];
    int opcion, N = 0;

    do{
        cout<<"\n1. Insertar. ";
        cout<<"\n2. Ordenar. ";
        cout<<"\n3. Mostrar. ";
        cout<<"\n4. Salir. ";
        cout<<"\nDigite una opcion. ";
        cin>> opcion;
        switch(opcion){

                case 1: can= insertar(can, N);
                break;

                case 2: can =ordenar(can, ordenado, N);
                break;

                case 3: mostrar(can, N);
                break;

                case 4: cout<<"\nGracias por ingresar.\n";
                break;
                default:break;
        }
    }while(opcion !=4);

    return 0;
}
Canciones * insertar(Canciones *can, int &N){


    N++;
    Canciones *canN = new Canciones[N];

		for(int i=0; i<N-1; i++){
        	*(canN + i) = *(can + i);
    	}

        delete [] can;
        can = NULL;
        can = new Canciones[N];
        for(int i=0; i<N-1;i++)
            {
                *(can + i) = *(canN + i);
            }

         cout<<"\nDigite el titulo de la cancion. "<<endl;
         cin>> ((can + N-1)->titulo);
         cout<<"\nDigite el autor de la cancion. "<<endl;
         cin>> ((can + N-1)->autor);
         cout<<"\nDigite el interprete de la cancion. "<<endl;
         cin>> ((can + N-1)->interprete);
         cout<<"\nDigite la duracion de la cancion. "<<endl;
         cin>> ((can + N-1)->duracion);

    delete[] canN;
    return can;

}

Canciones * ordenar(Canciones *can, Canciones *ordenado, int N){

        Canciones *aux = new Canciones;

        for(int i =0; i<N; i++)
            {
                for(int j=i+1;j<N;j++)
                    {
                        if((can+i)->titulo > (can+j)->titulo )
                        {
                            *aux=*(can+j);
                            *(can+j)=*(can+i);
                            *(can+i)=*aux;
                        }
                    }
            }
            return can;
}

void mostrar(Canciones *can, int &N){

    for(int i=0; i<N; i++){
        cout<<"\nEl titulo de la cancion es: "<<((can + i)->titulo)<<endl;
        cout<<"El interprete de la cancion es: "<<((can + i)->interprete)<<endl;
        cout<<"El autor de la cancion es: "<<((can + i)->autor)<<endl;
        cout<<"La duracion de la cancion es: "<<((can + i)->duracion)<<endl<<endl<<endl;
    }


}
