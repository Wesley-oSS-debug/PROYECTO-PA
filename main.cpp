#include <iostream>
#include "cliente.h"

using namespace std;
int main() {
	
	int op;
	Cliente obj[10000];
	int n=0; //numero de clientes

	do{
		system("cls");
		cout<<"\tGESTION BANCARIA"<<endl
			<<"1. Registrar Cliente"<<endl
			<<"2. Listar Clientes"<<endl
			<<"3. Actualizar Cliente"<<endl
			<<"4. Eliminar Cliente"<<endl
			<<"5. Salir del programa"<<endl
			<<"Seleccione una opcion: "; cin>>op;
		switch (op) {
			case 1:
				system("cls");
				obj[n].asignarCliente();
				obj[n].asignarCuenta();
				n++;
				system("pause");
				break;
			case 2:
				system("cls");
				for (int i=0;i<n;i++) {
					obj[i].mostrarCliente();
				}
				system("pause");
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
	} while (op!=5);
	
	return 0;
}