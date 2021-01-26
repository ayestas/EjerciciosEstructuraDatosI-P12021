#pragma once
#ifndef PLANILLA_H
#define PLANILLA_H

#include "Empleado.h"
#include <list>
#include <iostream>

using std::list;

class Planilla {
public:
	void AgregarEmpleados(int, std::string, float);
	void ImprimirEmpleado();

private:
	list<Empleado> listaEmpleados;
};

#endif // !PLANILLA_H
