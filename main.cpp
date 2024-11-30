#include <iostream>
#include "cliente.h"
#include <fstream>
#include "funciones.h"

using namespace std;
int main() {
	
	int op;
	Cliente obj[10000];
	int n;
	n=nClientes();
	//prueba n
	cout<<"n: "<<n<<endl;
	
	if (n>0) {
		cargar(obj,n);
	}
	
	
	do{
		//system("cls");
		cout<<"\tGESTION BANCARIA"<<endl
			<<"1. Registrar Cliente"<<endl
			<<"2. Listar Clientes"<<endl
			<<"3. Realizar una operacion"<<endl
			<<"4. Actualizar Cliente"<<endl
			<<"5. Eliminar Cliente"<<endl
			<<"0. Salir del programa"<<endl
			<<"Seleccione una opcion: "; cin>>op;
		switch (op) {
			case 1:
				registrarClientes(obj,n);
				break;
			case 2:
				listarClientes(obj,n);
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				cout<<"\nSaliendo del Programa...."<<endl;
				return 0;
				break;
			default:
				cout<<"Ingrese una opcion valida"<<endl;
				return 1;
		} 
	} while (op!=0);
	
	return 0;
}