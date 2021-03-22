#pragma once
#ifndef MATERIAS_H
#define MATERIAS_H

#include <iostream>
using std::cout;
using std::cin;

struct materia {
	int codigo;
	char* nombre;
	short int uv;
	int añoPlan;
	short int periodo;
	int requisito;

	int cantidadHijos;
	materia** hijos; //array of pointers :O

	materia(int _codigo, int _uv, int _añoPlan, int _periodo, const char* _nombre, int _requisito) {
		codigo = _codigo;
		uv = _uv;
		añoPlan = _añoPlan;
		periodo = _periodo;
		requisito = _requisito;

		nombre = new char[strlen(_nombre)];
		strcpy_s(nombre, strlen(_nombre) + 1, _nombre);

		cantidadHijos = 0;
		hijos = nullptr;
	}
};

class Materias {
public:
	Materias (int);

	void agregarMateriaPadre(int, int, int, int, const char*, int);
	void agregarMateria(int, int, int, int, int, const char*, int);

	void imprimir();
	materia* buscarRaiz(int);

	int getCodigoPlan();
	void setCodigoPlan(int);

private:
	materia** raices;
	int cantidadRaices;
	int codigoPlan = 0;

	bool estaVacio();
	void imprimirRec(materia*);
};
#endif // !MATERIAS_H
