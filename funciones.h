#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "cliente.h"

int nClientes();
void registrarClientes(Cliente[],int&);
void listarClientes(Cliente[],int);
void cargar(Cliente[],int);
void operaciones(Cliente[],int);
void actualizar(Cliente[],int);
void eliminarCliente(Cliente[],int&);

#endif