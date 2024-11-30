#include "funciones.h"
#include "cliente.h"
#include "cuentas.h"
#include <fstream>
#include <iostream>
using namespace std;

void depositar(Cliente[],int);
void crearCuenta(Cliente[],int);

//Cantidad de clientes
int nClientes() {
	ifstream archivo;
	string linea;
	int n=0;
	//Calcular lineas del archivo
	archivo.open("clientes.txt");
	while (getline(archivo,linea)) {
		n++;
	}
	archivo.close();
	
	return n;
}

//Cargar datos de Clientes / Cuentas del txt
void cargar(Cliente obj[],int n) {
	ifstream archivo;
	ifstream archivo2;
	
	archivo2.open("cuentasB.txt");
	archivo.open("clientes.txt");
	for (int i=0;i<n;i++) {
		obj[i].cargarCliente(archivo,archivo2);
	}
	archivo.close();
	archivo2.close();
}

//Actualizar datos de los archivos txt
void actualizarDatos(Cliente obj[],int n){
	//eliminar datos
	remove("cuentasB.txt");
	remove("clientes.txt");
	//guardar datos actualizados
	for (int i=0;i<n;i++) {
		obj[i].guardarCliente();
	}
}

//1. Registrar cliente
void registrarClientes(Cliente obj[],int &n) {
	system("cls");
	obj[n].asignarCliente();
	obj[n].guardarCliente();
	n++;
	cout<<"numero cliente: "<<n<<endl;
	system("pause");
}

//2. Listar Clientes
void listarClientes(Cliente obj[],int n) {
	system("cls");

	for (int i=0;i<n;i++) {
		cout<<"Cliente ["<<i+1<<"]:\n"<<endl;
		obj[i].mostrarCliente();
	}

	system("pause");
}

//3. Realizar una operacion
void operaciones(Cliente obj[],int n) {
	int op;
	cout<<"OPERACIONES"<<endl
		<<"1. Crear cuenta Bancaria"<<endl
		<<"2. Depositar dinero a una cuenta"<<endl
		<<"3. Retirar dinero de una cuenta"<<endl
		<<"4. Volver al menu"<<endl
		<<"Ingrese una opcion: "; cin>>op;
	switch (op) {
		case 1:
			crearCuenta(obj,n);
			break;
		case 2:
			depositar(obj,n);
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			cout<<"Ingrese una opcion valida"<<endl;
	}
}

//3.1 Crear cuenta bancaria
void crearCuenta(Cliente obj[],int n) {
	int selec,indice;
	cout<<"Clientes:\n"<<endl;
	for (int i=0;i<n;i++) {
		cout<<"Cliente ["<<i+1<<"]:\n"<<endl;
		obj[i].mostrarCliente();
	}
	cout<<"Seleccione un cliente: "; cin>>selec;
	indice=selec-1;
	cout<<"Cliente seleccionado"<<endl;
	obj[indice].asignarCuenta();
	actualizarDatos(obj,n);
}

//3.2 Depositar dinero a una cuenta
void depositar(Cliente obj[],int n) {
	int selec,indice;
	cout<<"Clientes:\n"<<endl;
	for (int i=0;i<n;i++) {
		cout<<"Cliente ["<<i+1<<"]:\n"<<endl;
		obj[i].mostrarCliente();
	}
	cout<<"Seleccione un cliente: "; cin>>selec;
	indice=selec-1;
	cout<<"Cliente seleccionado"<<endl;
	obj[indice].asignarDinero();
	actualizarDatos(obj,n);
}