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

	int menu = 0, codigo = 0, bloques = 0, raiz;
	string _nombre = "";
	const char* nombre = new char[40];

	PlanEstudioUniversidad plan;
	vector<PlanEstudioUniversidad> vecPlan;

	do {
		cout << "\n\n*** M A T R I C U L A S  E  I N G R E S O  D E  C L A S E S ***"
			<< "\n1. Crear Plan de Estudio"
			<< "\n2. Agregar Materias al Plan"
			<< "\n3. Imprimir Clases"
			<< "\n4. Ver codigos de planes"
			<< "\n5. Salir"
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
			
			nombre = _nombre.c_str();

			plan.agregarPlanEstudio(codigo, nombre, bloques);
			
			break;

		case 2:
			cout << "\n** AGREGAR CLASE A PLAN DE ESTUDIO **\n\n";
			cout << "Ingrese codigo del Plan: ";
			cin >> codigo;

			if (plan.BuscarPlanEstudio(codigo)) {
				cout << "Ingrese bloque del plan donde desea agregar la clase: ";
				cin >> raiz;

				plan.agregarMateria(codigo, raiz);
			}

			break;

		case 3:
			cout << "\n** CLASES DEL PLAN DE ESTUDIO **\n\nIngrese el codigo del plan de estudio: ";
			cin >> codigo;

			plan.imprimirClases(codigo);

			break;

		case 4: 
			cout << "\n** PLANES DE ESTUDIO (CODIGOS)**\n\n";
			break;
		}
	} while (menu != 5);

	cout << "\n";

}