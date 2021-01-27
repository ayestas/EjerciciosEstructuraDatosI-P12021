#include <iostream>
#include <conio.h>
#include "Planilla.h"

using namespace std;

int main() {
	Planilla p;
	p.AgregarEmpleados(1001, "Jose", 2500);
	p.AgregarEmpleados(1002, "Maria", 4000);
	p.AgregarEmpleados(1003, "Carlos", 3500);
	p.ImprimirEmpleado();

	cout << "\nCantidad de Empleados: " << p.ObtenerCantidadEmpleados();

	cout << "\nTotal de Salarios: " << p.ObtenerTotalSalarios();

	//Empleado con mayor Salario
	p.ObtenerSalarioMayor();

	Empleado e = p.BuscarEmpleado(1003);
	if (e.getCodigo() != 0) {
		cout << "\nEmpleado encontrado!\n";
		e.ImprimirEmpleado();
	}
	else {
		cout << "\nEmpleado NO encontrado!";
	}

	_getch();
}