#ifndef CUENTAS_H
#define CUENTAS_H
#include <string>

using namespace std;

class CuentaBancaria{
	private:
		string tipo;
		string moneda;
		float saldo;
		long int numero;
	public:
		CuentaBancaria(string,string);
		void mostrarCuenta();
};


#endif