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

struct clases {
	int codigo;
	char* nombre;
	short int uv;
	int añoPlan;
	short int periodo;
	int requisito;
};

class PlanEstudioUniversidad {
public:
	PlanEstudioUniversidad ();

	void agregarPlanEstudio(int, const char*, int, int);
	void agregarMateriaPadre(Materias*, int);
	void agregarMateria(Materias*, int);
	
	void consultarPlanEstudio(int);
	void imprimirClases(int);
	
	Materias* getPlan(int);

	bool BuscarPlanEstudio(int);

private:
	vector<int> codigos;
	vector<Materias*> VecClases;
};

#endif // !PLAN_ESTUDIO_UNIVERSIDAD_H
