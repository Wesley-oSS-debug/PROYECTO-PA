#include "cliente.h"
#include <iostream>

using namespace std;

Cliente::Cliente() {
	nombre="";
	DNI="";
	direccion="";
	telefono="";
	correo="";
}

void Cliente::asignarCuenta() {
	
	string t;
	string m;
	cout<<"Ingrese el tipo de cuenta: "; cin>>t;
	cout<<"Ingrese la moneda de la cuenta: "; cin>>m;
	cuentas= new CuentaBancaria(t,m); 
}

void Cliente::asignarCliente() {
	cin.ignore();
	cout<<"Ingrese el nombre del cliente: "; getline(cin,nombre);
	cout<<"Ingrese su DNI: "; cin>>DNI;
	cin.ignore();
	cout<<"Ingrese su direccion: "; getline(cin,direccion);
	cout<<"Ingrese su telefono: "; cin>>telefono;
	cout<<"Ingrese su correo: "; cin>>correo;
}

void Cliente::mostrarCliente() {
	cout<<"Nombre: "<<nombre<<endl
		<<"DNI: "<<DNI<<endl
		<<"Direccion: "<<direccion<<endl
		<<"Telefono: "<<telefono<<endl
		<<"Correo: "<<correo<<endl;
		cout<<"El cliente tiene las siguientes cuentas: "<<endl;
		cuentas->mostrarCuenta();
		cout<<"----------------------------------------------------------------"<<endl;
}