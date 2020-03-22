#ifndef FUNCIONES_H
#define FUNCIONES_H
struct Libro{
    char *nombre;
    char *autor;
    int cantidad;
    int precio;
};
struct NodoLibro{
    Libro info;
    NodoLibro *siguiente;
};
struct ListaLibro{
    NodoLibro *cabeza;
    int tamLibro;
};
struct MultiNodoGenero{
    ListaLibro *info;
    char *nombre;
    MultiNodoGenero *siguiente;
};
struct MultiListaGenero{
    MultiNodoGenero *cabeza;
    int tamGenero;
};
struct MultiNodoSucursal{
    MultiListaGenero *info;
    char *nombre;
    MultiNodoSucursal *siguiente;
};
struct MultiListaSucursal{
    MultiNodoSucursal *cabeza;
    int tamSucursal;
};
struct Factura{
    char *titulo;
    char *autor;
    int precio;
    int ejemplarV = 0;
    char *imagen;
};
void generarSucursales(MultiListaSucursal *listaSucursal);
void llenarDatos(MultiListaSucursal *listaSucursal);
void verLibros(MultiListaSucursal *listaSucursal);
void editarSucursal(MultiListaSucursal *listaSucursal);
void editarLibros(MultiListaSucursal *listaSucursal);
void editarGeneros(MultiListaSucursal *listaSucursal);
void comprarLibro(MultiListaSucursal *listaSucursal);
void consultarTop(MultiListaSucursal *listaSucursal);
void consultarLibro(MultiListaSucursal *listaSucursal);
void consultarCompras(MultiListaSucursal *listaSucursal);
void consultarIngresos(MultiListaSucursal *listaSucursal);
#endif // FUNCIONES_H
