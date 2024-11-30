#include "cuentas.h"
#include <iostream>

using namespace std;

CuentaBancaria::CuentaBancaria(string _tipo,string _moneda) {
	tipo=_tipo;
	moneda=_moneda;
}

void CuentaBancaria::mostrarCuenta() {
	cout<<"Numero de cuenta: "<<numero<<endl
		<<"Tipo: "<<tipo<<endl
		<<"Moneda: "<<moneda<<endl
		<<"Saldo actual: "<<saldo<<endl;
}
