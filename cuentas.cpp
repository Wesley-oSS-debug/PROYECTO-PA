#include "cuentas.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

CuentaBancaria::CuentaBancaria(string _tipo,string _moneda) {
	//generador de numero de cuenta
	srand(time(0));
	int min=1000000000;
    int max=1999999999;
	numero=min+(rand()%(max-min+1));
	tipo=_tipo;
	moneda=_moneda;
}

void CuentaBancaria::mostrarCuenta() {
	cout<<"  Numero de cuenta: "<<numero<<endl
		<<"  Tipo: "<<tipo<<endl
		<<"  Moneda: "<<moneda<<endl
		<<"  Saldo actual: "<<saldo<<endl;
}
