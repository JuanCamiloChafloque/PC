#ifndef FUNCIONES_H
#define FUNCIONES_H
struct Nodo{
       Nodo *sig;
       char destino[20];
       char mensaje[100];
       char tamReal[3];
};
struct Lista{
       Nodo *cab;
       int tam;
};
struct MultiNodo{
       MultiNodo *sig;
       char protocolo[20];
       Lista *dato;
};
struct MultiLista{
        MultiNodo *cab;
        int tam;
};
struct Paquete{
    char auxOrigen[20];
    char auxDestino[20];
    char auxProtocolo[20];
    char auxMensaje[100];
    char auxTam[3];
};
void generarLista(MultiLista *, Paquete);
void imprimir(MultiLista *);
void mensajeSecreto(MultiLista *);
#endif // FUNCIONES_H
