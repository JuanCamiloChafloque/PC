#ifndef FUNCIONES_H
#define FUNCIONES_H
struct Nodo{
       Nodo *sig;
       int info;
};
struct Lista{
       Nodo *cab;
       int tam;
};
struct MultiNodo{
       MultiNodo *sig;
       int info;
       Lista *dato;
};
struct MultiLista{
        MultiNodo *cab;
        int tam;
};
void imprimir(Lista *);
void imprimirMulti(MultiLista *);
void insertar(Lista *);
void insertarEnUnaPosicion (MultiLista*);
bool vacia(Lista *);
void generarMulti(Lista* lista, MultiLista *);
#endif // FUNCIONES_H
