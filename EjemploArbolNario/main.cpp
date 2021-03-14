#include <iostream>
#include <conio.h>
#include "PlanEstudio.h"

using std::cout;

int main() {
	PlanEstudio plan;

	plan.agregarMateria(0, 100, 1, "Introduccion al Algebra");
	plan.agregarMateria(100, 101, 4, "Introduccion a la Computacion");
	plan.agregarMateria(100, 102, 4, "Algebra");
	plan.agregarMateria(100, 103, 4, "Calculo 1");
	plan.agregarMateria(100, 104, 3, "Programacion 1");
	plan.agregarMateria(100, 105, 4, "Estadistica 1");

	plan.agregarMateria(0, 200, 1, "Frances I");
	plan.agregarMateria(200, 201, 4, "Frances II");
	plan.agregarMateria(200, 202, 4, "Frances III");
	plan.agregarMateria(200, 203, 4, "Frances IV");


	plan.imprimir();

	plan.eliminarMateria(102);

	cout << "\n";

	plan.imprimir();

	_getch();
}