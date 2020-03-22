#ifndef FUNCIONES_H
#define FUNCIONES_H
struct Nodo{
       Nodo * sig;
       int info;
};
struct Lista{
       Nodo * cab;
       int tam;
};
void imprimir(Lista *, Lista *);
void insertar(Lista *, Lista *);
bool eliminar(Lista *, Lista *);
void realizarUnion(Lista *, Lista *);
void realizarInt(Lista *, Lista *);
void realizarDif(Lista *, Lista *);
#endif // FUNCIONES_H
