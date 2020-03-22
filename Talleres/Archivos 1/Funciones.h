#ifndef FUNCIONES_H
#define FUNCIONES_H
struct Empleado{
    char codigo[20];
    char apellido[20];
    char nombre[20];
    char celular[20];
};
void imprimirArchivo(Empleado *empleado, Empleado *archivoSalida, int cont);
void generarArchivo(Empleado *empleado, int cont);
void adicionarEmpleado(Empleado *aux, Empleado *empleado, int cont);
#endif // FUNCIONES_H
