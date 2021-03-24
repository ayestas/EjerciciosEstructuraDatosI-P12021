#pragma once
#ifndef PLAN_ESTUDIO_UNIVERSIDAD_H
#define PLAN_ESTUDIO_UNIVERSIDAD_H

#include <iostream>
#include <string>
#include <vector>
#include "Materias.h"
#include "Matriculas.h"

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

struct alumnos {
	int numero;
	char* nombre;
	int codigoPlan;
	short int indice;
	short int clasesAprob;
};

class PlanEstudioUniversidad {
public:
	PlanEstudioUniversidad ();

	void agregarPlanEstudio(int, const char*, int, int);
	
	void consultarPlanEstudio(int);
	void imprimirClases(int);
	
	void ingresarAlumno(int, const char*, int, int, int);
	void ingresarMatricula();

	void imprimirInfoAcademica(int);

	bool BuscarPlanEstudio(int);
	bool BuscarAñoMatriculado(string);
	bool BuscarClaseMatriculada(string);
	bool BuscarAlumno(int);
	int getCodigoPlan(int);

private:
	vector<int> codigos;
	vector<int> numCuentas;
	vector<string> añosMatriculados;
	vector<string> codigoClasesMatriculadas;
	vector<Materias*> VecClases;
	vector<Matriculas*> VecMatriculadas;
};

#endif // !PLAN_ESTUDIO_UNIVERSIDAD_H
