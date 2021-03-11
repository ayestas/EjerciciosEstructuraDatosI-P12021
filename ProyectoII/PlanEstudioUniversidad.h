#pragma once
#ifndef PLAN_ESTUDIO_UNIVERSIDAD_H
#define PLAN_ESTUDIO_UNIVERSIDAD_H

#include <iostream>
using std::cout;

struct materia {
	int codigo;
	char* nombre;
	short int uv;
	int añoPlan;
	short int periodo;

	int cantidadHijos;
	materia** hijos; //array of pointers :O

	materia(int _codigo, const char* _nombre, int _uv, int _añoPlan, int _periodo) {
		codigo = _codigo;
		uv = _uv;
		añoPlan = _añoPlan;
		periodo = _periodo;

		nombre = new char[strlen(_nombre)];
		strcpy_s(nombre, strlen(_nombre) + 1, _nombre);

		cantidadHijos = 0;
		hijos = nullptr;
	}

};

class PlanEstudioUniversidad {
public:
	PlanEstudioUniversidad ();

	void agregarMateria(int, int, int, int, int, const char*);
	void eliminarMateria(int);
	void editarMateria(int);
	void imprimir();
	materia* buscarMateria(int);

private:
	materia** raices;

	int cantidadRaices;
	bool estaVacio();

	materia* buscarMateriasRec(materia*, int);
	materia* buscarPadreRec(int, materia**);
	void imprimirRec(materia**);
};

#endif // !PLAN_ESTUDIO_UNIVERSIDAD_H
