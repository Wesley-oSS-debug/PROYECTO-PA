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
		CuentaBancaria* cuentas;
	public:
		Cliente();
		void asignarCuenta();
		void mostrarCliente();
		void guardarCliente();
		void cargarCliente(ifstream&);
		void asignarCliente();
};

#endif