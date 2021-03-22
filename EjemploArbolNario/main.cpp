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

	plan.imprimir();

}