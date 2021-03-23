#pragma once
#ifndef GRAFO_H
#define GRAFO_H
#include "grafo.h"
#include <iostream>
#include <iomanip>
#include <vector>
using std::setw;
using namespace std;

class Grafo {
public:
	Grafo();

	void agregarVertice(char);
	void agregarArista(char, char, int);

	vector< vector<int>> prim();

	void imprimir();
	void imprimirArbol(vector< vector<int>>);
private:
	int nVertices;
	char* vertices;
	int** aristas; //Matriz de Adyacencia

	vector< vector<int>> toVector();
	int getPesoMax(vector< vector<int>>, int);
	bool createsMST(int, int, vector<bool>);
	int obtenerIndiceVertice(char);
};

#endif // !GRAFO_H
