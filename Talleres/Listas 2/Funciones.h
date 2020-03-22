#ifndef FUNCIONES_H
#define FUNCIONES_H
struct Nodo{
       Nodo * sig;
       int base;
       int exp;
};
struct Lista{
       Nodo * cab;
       int tam;
};
void imprimir(Lista *, Lista *);
void insertar(Lista *, Lista *);
void sumarPolinomios(Lista *, Lista *, Lista *);
void evaluarPolinomio(Lista *);
#endif // FUNCIONES_H
