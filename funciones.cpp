#include "funciones.h"
#include "cliente.h"
#include "cuentas.h"
#include <fstream>
#include <iostream>
using namespace std;
//cantidad de clientes
int nClientes() {
	ifstream archivo;
	string linea;
	int n=0;
	
	archivo.open("clientes.txt");
	while (getline(archivo,linea)) {
		n++;
	}
	archivo.close();
	
	return n;
}
void registrarClientes(Cliente obj[],int &n) {
	system("cls");
	obj[n].asignarCliente();
	obj[n].guardarCliente();
	n++;
	cout<<"numero cliente: "<<n<<endl;
	system("pause");
}
//cargar clientes del txt
void cargar(Cliente obj[],int n) {
	ifstream archivo;
	ifstream archivo2;
	//cargar Clientes / Cuentas
	archivo2.open("cuentasB.txt");
	archivo.open("clientes.txt");

	for (int i=0;i<n;i++) {
		obj[i].cargarCliente(archivo,archivo2);
	}
	
	archivo.close();
	archivo2.close();

	
}

void listarClientes(Cliente obj[],int n) {
	system("cls");

	for (int i=0;i<n;i++) {
		cout<<"Cliente ["<<i+1<<"]:\n"<<endl;
		obj[i].mostrarCliente();
	}

	system("pause");
}
