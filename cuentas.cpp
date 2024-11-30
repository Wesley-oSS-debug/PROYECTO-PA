#include "cuentas.h"
#include <iostream>


using namespace std;

CuentaBancaria::CuentaBancaria(string _tipo,string _moneda) {
	tipo=_tipo;
	moneda=_moneda;
}

void CuentaBancaria::asignarNumero(int num) {
	numero=num;
}

void CuentaBancaria::mostrarCuenta() {
	cout<<endl;
	cout<<"  Numero de cuenta: "<<numero<<endl
		<<"  Tipo: "<<tipo<<endl
		<<"  Moneda: "<<moneda<<endl
		<<"  Saldo actual: "<<saldo<<endl;
}

string CuentaBancaria::obtenerTipo() {
	return tipo;
}

string CuentaBancaria::obtenerMoneda() {
	return moneda;
}

int CuentaBancaria::obtenerNumero() {
	return numero;
}

