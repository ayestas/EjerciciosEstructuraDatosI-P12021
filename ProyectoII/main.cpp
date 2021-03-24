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

	int menu = 0, codigo = 0, bloques = 0, clases = 0, raiz, subMenu = 0;
	int _numero = 0, _indice = 0, _clasesAprob = 0, _codigoPlan = 0;
	string _nombre = "";
	const char* nombre = new char[40];

	PlanEstudioUniversidad plan;

	do {
		cout << "\n\n*** M A T R I C U L A S  E  I N G R E S O  D E  C L A S E S ***"
			<< "\n1. Crear Plan de Estudio"
			<< "\n2. Iniciar/Cerrar Inscripcion de Clases"
			<< "\n3. Informe Academico"
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
			cout << "\n** INICIAR/CERRAR INSCRIPCION DE CLASES **\n1. Ingreso de nuevo alumno\n2. Matricula de clases\n"
				<< "Ingrese opcion: ";
			cin >> subMenu;

			switch (subMenu) {
			case 1:
				cout << "\n* INGRESO DE ALUMNOS *";
				cout << "\nIngrese el numero de cuenta: ";
				cin >> _numero;
				cout << "Ingrese el nombre del alumno: ";
				cin >> _nombre;
				cout << "Ingrese el indice del alumno: ";
				cin >> _indice;
				cout << "Ingrese el periodo de ingreso: ";
				cin >> _clasesAprob;
				cout << "Ingrese el codigo del plan de estudio: ";
				cin >> _codigoPlan;

				nombre = _nombre.c_str();

				if (plan.BuscarPlanEstudio(_codigoPlan)) {
					plan.ingresarAlumno(_numero, nombre, _indice, _clasesAprob, _codigoPlan);
				}
				break;

			case 2:
				plan.ingresarMatricula();
				break;
			}

			break;

		case 3:
			cout << "\n INFORMACION ACADEMICA **\n\nIngrese su numero de cuenta: ";
			cin >> _numero;

			plan.imprimirInfoAcademica(_numero);

			break;
		}
	} while (menu != 4);

	cout << "\n";

}