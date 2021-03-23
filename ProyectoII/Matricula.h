#pragma once
#ifndef MATRICULA_H
#define MATRICULA_H

#include <iostream>
#include <string>
#include <vector>
#include "PlanEstudioUniversidad.h"
#include "Materias.h"

using std::cout;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::string;
using std::vector;

struct alumnos {
	int numero;
	char* nombre;
	int codigoPlan;
	short int indice;
	short int clasesAprob;
};

struct claseMatricula {
	int codigoClase;
	short int nota;
	int año;
	short int periodo;

	int cantidadHijas;
	claseMatricula** hijas;

	claseMatricula(int _codigoClase, int _nota, int _año, int _periodo) {
		codigoClase = _codigoClase;
		nota = _nota;
		año = _año;
		periodo = _periodo;

		cantidadHijas = 0;
		hijas = nullptr;
	}
};

class Matricula {
public:
	Matricula ();

	void ingresarAlumno();
	void ingresarMatricula();

	bool existeAlumno(int);
	int getCodigoPlan(int);

private:
	PlanEstudioUniversidad* planes;
	Materias* materias;
	claseMatricula** raices;

	vector<int> numCuentas;
};

#endif // !MATRICULA_H


