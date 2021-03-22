#pragma once
#ifndef PLAN_ESTUDIO_UNIVERSIDAD_H
#define PLAN_ESTUDIO_UNIVERSIDAD_H

#include <iostream>
#include <string>
#include <vector>
#include "Materias.h"

using std::cout;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::string;
using std::vector;

struct archivo {
	int codigo; //4 bytes
	char* nombre; //40 bytes
	short int totalClases; //2 bytes
	short int totalUV; //2 bytes
	short int bloques; //2 bytes
}; //sizeof = 50 bytes

class PlanEstudioUniversidad {
public:
	PlanEstudioUniversidad ();

	void agregarPlanEstudio(int, const char*, int);
	void agregarMateriaPadre(int, int);
	void agregarMateria(int, int);
	
	void consultarPlanEstudio();
	void imprimirClases(int);

	bool BuscarPlanEstudio(int);

private:
	vector<int> codigos;
	vector<Materias*> VecClases;
};

#endif // !PLAN_ESTUDIO_UNIVERSIDAD_H
