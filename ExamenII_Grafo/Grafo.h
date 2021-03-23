#pragma once
#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>

using std::vector;

class Grafo {
public:
	Grafo();
	void agregarVertice(char);
	void agregarArista(char, char);
	void imprimir();

	vector<vector<char>> obtenerListaAdy();
	void imprimirListaAdy();

private:
	int nVertices;
	char* vertices;
	int** aristas; //matriz de adyacencia

	int obtenerIndiceVertice(char);
};

#endif // !GRAFO_H
