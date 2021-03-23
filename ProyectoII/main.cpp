#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include "PlanEstudioUniversidad.h"

using std::cout;
using std::cin;
using std::vector;
using std::string;

int main() {
	/*vector<PlanEstudioUniversidad> vecPlan;

	PlanEstudioUniversidad plan();

	vecPlan.push_back(plan);
	
	plan.agregarMateriaPadre(100, 4, 2001, 2, "Introduccion al Algebra", 000);
	plan.agregarMateriaPadre(200, 4, 2001, 2, "Ofimatica I", 000);
	plan.agregarMateriaPadre(300, 4, 2001, 2, "Programacion I", 000);

	plan.agregarMateria(100, 101, 4, 2001, 2, "Algebra", 100);
	plan.agregarMateria(100, 102, 4, 2001, 2, "Geo y Tri", 101);
	plan.agregarMateria(300, 301, 4, 2001, 2, "Programacion II", 300);
	plan.agregarMateria(200, 201, 4, 2001, 2, "Ofimatica II", 200);*/

	int menu = 0, codigo = 0, bloques = 0, clases = 0, raiz;
	string _nombre = "";
	const char* nombre = new char[40];

	PlanEstudioUniversidad plan;
	vector<PlanEstudioUniversidad> vecPlan;

	do {
		cout << "\n\n*** M A T R I C U L A S  E  I N G R E S O  D E  C L A S E S ***"
			<< "\n1. Crear Plan de Estudio"
			<< "\n2. Ver Planes de Estudio"
			<< "\n3. Imprimir Clases"
			<< "\n4. Salir"
			<< "\n\nIngrese opcion: ";
		cin >> menu;

		switch (menu) {
		case 1:
			cout << "\n** CREAR NUEVO PLAN DE ESTUDIO **\n\n";
			cout << "Ingrese codigo del Plan: ";
			cin >> codigo;
			cout << "Ingrese nombre del Plan: ";
			cin >> _nombre;
			cout << "Ingrese la cantidad de bloques de conocimiento del Plan: ";
			cin >> bloques;
			cout << "Ingrese la cantidad de clases: ";
			cin >> clases;
			
			nombre = _nombre.c_str();

			plan.agregarPlanEstudio(codigo, nombre, bloques, clases);
			
			break;

		case 2:
			cout << "\n** VER PLANES DE ESTUDIO **\n\nIngrese el codigo del plan de estudio: ";
			cin >> codigo;

			plan.consultarPlanEstudio(codigo);

			break;

		case 3:
			cout << "\n** CLASES DEL PLAN DE ESTUDIO **\n\nIngrese el codigo del plan de estudio: ";
			cin >> codigo;

			plan.imprimirClases(codigo);

			break;
		}
	} while (menu != 4);

	cout << "\n";

}