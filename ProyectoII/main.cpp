#include <iostream>
#include <conio.h>
#include "PlanEstudioUniversidad.h"

using std::cout;

int main() {
	PlanEstudioUniversidad plan;

	plan.agregarMateriaPadre(100, 4, 2001, 2, "Introduccion al Algebra");
	plan.agregarMateriaPadre(200, 4, 2001, 2, "Introduccion a la Computacion");
	plan.agregarMateriaPadre(300, 4, 2001, 3, "Ofimatica I");

	plan.agregarMateria(300, 301, 4, 2001, 2, "Ofimatica II");
	plan.agregarMateria(300, 302, 4, 2001, 2, "Ofimatica III");
	plan.agregarMateria(100, 101, 4, 2001, 2, "Algebra");
	plan.agregarMateria(100, 102, 4, 2001, 2, "Geo y Tri");
	plan.agregarMateria(200, 201, 4, 2001, 2, "Programacion I");
	plan.agregarMateria(100, 201, 4, 2001, 2, "Programacion I");

	plan.imprimir();

	cout << "\n";

	_getch();
}