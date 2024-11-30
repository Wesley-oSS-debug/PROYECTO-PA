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
		string obtenerTipo();
		string obtenerMoneda();
		int obtenerNumero();
		void mostrarCuenta();
		void asignarNumero(int);
		void asignarSaldo(float);
		float obtenerSaldo();
};


#endif