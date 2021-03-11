#pragma once
#ifndef PLAN_ESTUDIO_H
#define PLAN_ESTUDIO_H

#include <iostream>
using std::cout;

struct materia {
	int codigo;
	short int uv;
	char* nombre;
	int cantidadHijos;
	materia** hijos; //array of pointers :O

	materia(int _codigo, int _uv, const char* _nombre) {
		codigo = _codigo;
		uv = _uv;
		nombre = new char[strlen(_nombre)];
		strcpy_s(nombre, strlen(_nombre) + 1, _nombre);
		cantidadHijos = 0;
		hijos = nullptr;
	}

};

class PlanEstudio {
public:
	PlanEstudio ();
	void agregarMateria(int, int, int, const char*);
	void eliminarMateria(int);
	void editarMateria(int);
	void imprimir();
	materia* buscarMateria(int);

private:
	materia* raiz;

	bool estaVacio();

	materia* buscarMateriasRec(materia*, int);
	materia* buscarPadreRec(int, materia*);
	void imprimirRec(materia*);
};

#endif // !PLAN_ESTUDIO_H
