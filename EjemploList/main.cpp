#include <iostream>
#include <conio.h>
#include "Planilla.h"

using namespace std;

int main() {
	Planilla p;
	p.AgregarEmpleados(101, "Jose", 3000);
	p.AgregarEmpleados(102, "Maria", 4000);
	p.AgregarEmpleados(103, "Carlos", 3500);
	p.ImprimirEmpleado();

	_getch();
}