#pragma once
#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <string>

using std::string;

class Empleado {
	friend std::ostream& operator<<(std::ostream&, const Empleado&);

public:
	Empleado();
	Empleado(int, std::string, float);
	//void ImprimirEmpleado();

private:
	int codigoEmpleado;
	string nombreEmpleado;
	float salarioEmpleado;
};

#endif // !EMPLEADO_H
