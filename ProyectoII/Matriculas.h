#pragma once
#ifndef MATRICULAS_H
#define MATRICULAS_H

#include <iostream>
#include <vector>
#include <numeric>

using std::cout;
using std::cin;
using std::vector;

struct matricula {
	int codigo;
	short int nota;
	int año;
	short int periodo;

	int cantidadHijas;
	matricula** hijas;

	matricula(int _codigo, int _nota, int _año, int _periodo) {
		codigo = _codigo;
		nota = _nota;
		año = _año;
		periodo = _periodo;

		cantidadHijas = 0;
		hijas = nullptr;
	}
};

class Matriculas {
public:
	Matriculas(int);

	void agregarMatriculaPorAño(int, int, int, int);
	void agregarMatriculaPorPeriodo(int, int, int, int);

	void imprimir();
	matricula* buscarAño(int);

	int getNumCuenta();
	void setNumCuenta(int);

	double getPromedio();

private:
	matricula** años;
	int cantidadAños;
	int numCuenta = 0;
	
	vector<int> notas;

	bool estaVacio();
	void imprimirRec(matricula*);
};

#endif // !MATRICULAS_H
