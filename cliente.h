#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include "cuentas.h"

using namespace std;

class Cliente{
	private:
		string nombre;
		string DNI;
		string direccion;
		string telefono;
		string correo;
		int nCuentas;
		CuentaBancaria* cuentas[10];
	public:
		Cliente();
		void asignarCuenta();
		void mostrarCliente();
		void guardarCliente();
		void cargarCliente(ifstream&,ifstream&);
		void asignarCliente();
		void depositarDinero();
		void retirarDinero();
		void modificarCuenta();
};

#endif