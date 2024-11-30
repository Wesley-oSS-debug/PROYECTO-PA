#include "cliente.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Constructor Cliente
Cliente::Cliente() {
	nombre="";
	DNI="";
	direccion="";
	telefono="";
	correo="";
	nCuentas=0;
}
//Asignar cuenta bancaria
void Cliente::asignarCuenta() {
	int num;
	string t;
	string m;
	ofstream archivo2;
	//generador de numero de cuenta
	srand(time(0));
	int min=1000000000;
    int max=1999999999;
	num=min+(rand()%(max-min+1));
	
	archivo2.open("cuentasB.txt",ios::app);
	cout<<"Ingrese el tipo de cuenta: "; cin>>t;
	cout<<"Ingrese la moneda de la cuenta: "; cin>>m;
	archivo2<<nombre<<" "<<t<<" "<<m<<" ";
	
	cuentas[nCuentas]= new CuentaBancaria(t,m);
	cuentas[nCuentas]->asignarNumero(num);
	archivo2<<cuentas[nCuentas]->obtenerNumero()<<endl;
	archivo2.close();
	nCuentas++;
	
}
//Cargar datos del txt
void Cliente::cargarCliente(ifstream& archivo,ifstream& archivo2) {
	string name,t,m;
	int num;
	//cargar Clientes
	archivo>>nombre>>DNI>>direccion>>telefono>>correo>>nCuentas;
	//cargar cuentas bancarias
	for (int i=0;i<nCuentas;i++) {
		archivo2>>name>>t>>m>>num;
		cuentas[i]= new CuentaBancaria(t,m);
		cuentas[i]->asignarNumero(num);
	}	
}

void Cliente::asignarCliente() {
	cin.ignore();
	cout<<"Ingrese el nombre del cliente: "; getline(cin,nombre);
	cout<<"Ingrese su DNI: "; cin>>DNI;
	cin.ignore();
	cout<<"Ingrese su direccion: "; getline(cin,direccion);
	cout<<"Ingrse su telefono: "; cin>>telefono;
	cout<<"Ingrese su correo: "; cin>>correo;
	asignarCuenta();
	
}
//GUARDAR CLIENTE
void Cliente::guardarCliente() {
	ofstream archivo;
	archivo.open("clientes.txt",ios::app);
	archivo<<nombre<<" "<<DNI<<" "<<direccion<<" "<<telefono<<" "<<correo<<" "<<nCuentas<<endl;
	archivo.close();
	
}
//MOSTRAR CLIENTE
void Cliente::mostrarCliente() {
	cout<<"  Nombre: "<<nombre<<endl
		<<"  DNI: "<<DNI<<endl
		<<"  Direccion: "<<direccion<<endl
		<<"  Telefono: "<<telefono<<endl
		<<"  Correo: "<<correo<<endl;
		cout<<"\n  El cliente tiene las siguientes cuentas: "<<endl;
		for (int i=0;i<nCuentas;i++) {
			cuentas[i]->mostrarCuenta();
		}
		cout<<"\n----------------------------------------------------------------"<<endl;
}