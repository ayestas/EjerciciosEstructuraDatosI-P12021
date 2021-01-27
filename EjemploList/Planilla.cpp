#include "Planilla.h"
#include <iostream>
#include <list>

using namespace std;

void Planilla::AgregarEmpleados(int _codigo, std::string _nombre, float _salario) {
	Empleado nuevo(_codigo, _nombre, _salario);

	listaEmpleados.push_back(nuevo);

	cout << "Empleado agregado a la panilla!!\n";
}

void Planilla::ImprimirEmpleado() {
	/*for (list<Empleado>::iterator iter = listaEmpleados.begin(); iter != listaEmpleados.end(); iter++) {
		cout << *iter;
	}*/
	for (list<Empleado>::iterator i = listaEmpleados.begin(); i != listaEmpleados.end(); i++) {
		i->ImprimirEmpleado();
	}
}

bool Planilla::EstaVacia() {
	return listaEmpleados.empty();
}

int Planilla::ObtenerCantidadEmpleados() {
	return listaEmpleados.size();
}

float Planilla::ObtenerTotalSalarios() {
	float salarios = 0;

	for (Empleado e : listaEmpleados) {
		salarios += e.getSalario();
	}
	
	return salarios;
}

void Planilla::ObtenerSalarioMayor() {
	float salarioMayor = 0;
	Empleado empleadoSalarioMayor;

	for (Empleado e : listaEmpleados) {
		if (e.getSalario() > salarioMayor) {
			salarioMayor = e.getSalario();
			empleadoSalarioMayor = e;
		}
	}

	cout << "\nEl empleado con el mayor salario es: \n";
	empleadoSalarioMayor.ImprimirEmpleado();
}

Empleado Planilla::BuscarEmpleado(int _codigo) {
	
	for (Empleado e : listaEmpleados) {
		if (e.getCodigo() == _codigo) {
			return e;
		}
	}

	return Empleado();
}


