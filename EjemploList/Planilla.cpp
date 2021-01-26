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
	for (list<Empleado>::iterator iter = listaEmpleados.begin(); iter != listaEmpleados.end(); iter++) {
		cout << *iter;
	}
}


