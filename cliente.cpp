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
	//generador de numero de cuenta
	srand(time(0));
	int min=1222222222;
    int max=1999999999;
	num=min+rand()%(max-min+1);
	
	cout<<"Ingrese el tipo de cuenta: "; cin>>t;
	cout<<"Ingrese la moneda de la cuenta: "; cin>>m;
	
	cuentas[nCuentas]= new CuentaBancaria(t,m);
	cuentas[nCuentas]->asignarNumero(num);
	nCuentas++;
	
}

void Cliente::modificarCuenta() {
	string t;
	string m;
	int num;
	for (int i=0;i<nCuentas;i++) {
		cout<<"Cuenta ["<<i+1<<"]: "<<endl;
		cout<<"  Ingrese el tipo de cuenta: "; cin>>t;
		cout<<"  Ingrese la moneda de la cuenta: "; cin>>m;
		num= cuentas[i]->obtenerNumero();
		cuentas[i]=new CuentaBancaria(t,m);
		cuentas[i]->asignarNumero(num);
	}
}

//Cargar datos del txt
void Cliente::cargarCliente(ifstream& archivo,ifstream& archivo2) {
	string name,t,m;
	int num;
	float s;
	//cargar Clientes
	archivo>>nombre>>DNI>>direccion>>telefono>>correo>>nCuentas;
	//cargar cuentas bancarias
	for (int i=0;i<nCuentas;i++) {
		archivo2>>name>>t>>m>>num>>s;
		cuentas[i]= new CuentaBancaria(t,m);
		cuentas[i]->asignarNumero(num);
		cuentas[i]->depositarSaldo(s);
	}	
}

//Asignar Cliente
void Cliente::asignarCliente() {
	cin.ignore();
	cout<<"Ingrese el nombre del cliente: "; getline(cin,nombre);
	cout<<"Ingrese su DNI: "; cin>>DNI;
	cin.ignore();
	cout<<"Ingrese su direccion: "; getline(cin,direccion);
	cout<<"Ingrese su telefono: "; cin>>telefono;
	cout<<"Ingrese su correo: "; cin>>correo;
}

//Mostrar Cliente
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
//Asignar dinero
void Cliente::depositarDinero() {
	int selec,indice;
	float monto;
	cout<<"A que cuenta bancaria desea depositar?\n"<<endl;
	for (int i=0;i<nCuentas;i++) {
		cout<<"Cuenta ["<<i+1<<"]:"<<endl;
		cuentas[i]->mostrarCuenta();
		cout<<endl;
	}
	cout<<"\nIngrese una cuenta: "; cin>>selec;
	indice=selec-1;	
	cout<<"cuenta seleccionada"<<endl;
	cout<<"Ingrese el monto a depositar: "; cin>>monto;
	cuentas[indice]->depositarSaldo(monto);
	cout<<"Dinero depositado"<<endl;
}
//Retirar dinero
void Cliente::retirarDinero() {
	int selec,indice;
	float monto;
	cout<<"A que cuenta bancaria desea retirar?\n"<<endl;
	for (int i=0;i<nCuentas;i++) {
		cout<<"Cuenta ["<<i+1<<"]:"<<endl;
		cuentas[i]->mostrarCuenta();
		cout<<endl;
	}
	cout<<"\nIngrese una cuenta: "; cin>>selec;
	indice=selec-1;	
	cout<<"cuenta seleccionada"<<endl;
	cout<<"Ingrese el monto a retirar: "; cin>>monto;
	cuentas[indice]->retirarSaldo(monto);
	cout<<"Dinero depositado"<<endl;
}

//Guardar datos del Cliente en archivos txt
void Cliente::guardarCliente() {
	//guardar cliente
	ofstream archivo;
	archivo.open("clientes.txt",ios::app);
	archivo<<nombre<<" "<<DNI<<" "<<direccion<<" "<<telefono<<" "<<correo<<" "<<nCuentas<<endl;
	archivo.close();
	//guardar su cuenta bancaria
	string t,m;
	int num;
	float monto;
	ofstream archivo2;
	archivo2.open("cuentasB.txt",ios::app);
	for (int i=0;i<nCuentas;i++) {
		t=cuentas[i]->obtenerTipo();
		m=cuentas[i]->obtenerMoneda();
		num=cuentas[i]->obtenerNumero();
		monto=cuentas[i]->obtenerSaldo();
		archivo2<<nombre<<" "<<t<<" "<<m<<" "<<num<<" "<<monto<<endl;
	}
	archivo2.close();
}