#ifndef FUNCIONES_H
#define FUNCIONES_H
struct Nodo
{
    Nodo * sig;
    Nodo * ant;
    int info;
};
struct Lista
{
    Nodo * cab;
    int tam;
};
Lista * crearLista();
void imprimir(Lista *);
void insertar(Lista *);
bool vacia(Lista *);
void invertirLista(Lista *);
#endif // FUNCIONES_H
